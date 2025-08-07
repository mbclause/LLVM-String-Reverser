

#include <LLVM-Tutorial/string-reverser.h>

#include <algorithm>

#include <llvm/ADT/SmallVector.h>
#include <llvm/ADT/STLExtras.h>
#include <llvm/IR/Instruction.h>
#include <llvm/IR/User.h>
#include <llvm/IR/Attributes.h>
#include <llvm/Support/Casting.h>

#include <LLVM-Tutorial/string-analysis.h>
#include <LLVM-Tutorial/util.h>

#define DEBUG_TYPE "string-reverser"


namespace
{
	using GVStringRefPair = jvs::StringAnalyzer::Result::value_type;

	using GVStdStringPair = std::pair<llvm::GlobalVariable*, std::string>;

	bool isUsedInOptNone(llvm::GlobalVariable& gv) noexcept
	{
		auto gvInstUsers = llvm::map_range(gv.users(), [](const llvm::User* user)
			{
				return llvm::dyn_cast<llvm::Instruction>(user);
			});

		return llvm::any_of(gvInstUsers, [](const llvm::Instruction* inst)
			{
				return (inst != nullptr &&
					inst->getFunction()->hasFnAttribute(llvm::Attribute::OptimizeNone));
			});
	}

	GVStdStringPair toStdString(GVStringRefPair gvStringRefPair)
	{
		return { gvStringRefPair.first, gvStringRefPair.second.str() };
	}
}


llvm::PreservedAnalyses jvs::StringReverser::run(llvm::Module& m, llvm::ModuleAnalysisManager& am)
{
	auto results = llvm::PreservedAnalyses::all();

	auto globalStrings = llvm::to_vector(llvm::map_range(am.getResult<StringAnalyzer>(m), toStdString));

	if (run(std::move(globalStrings)))
	{
		// #TODO: update the preserved analyses
		results.intersect(llvm::PreservedAnalyses::allInSet<llvm::CFGAnalyses>());
	}

	return results;
}

bool jvs::StringReverser::run(llvm::SmallVectorImpl<GVStdStringPair>&& globalStrings)
{
	bool modified = false;

	while (!globalStrings.empty())
	{
		auto [gv, stringVal] = globalStrings.pop_back_val();

		if (stringVal.empty())
		{
			continue;
		}

		if (gv->hasAttribute(llvm::Attribute::OptimizeNone) || isUsedInOptNone(*gv))
		{
			continue;
		}

		auto& m = *gv->getParent();

		std::reverse(stringVal.begin(), stringVal.end());

		gv->setInitializer(llvm::ConstantDataArray::getString(m.getContext(), stringVal));
		
		modified = true;

		PASS_DEBUG("Replaced "
			<< gv->getNameOrAsOperand()
			<< "with \""
			<< GetEscapedString(stringVal)
			<< "\"\n"
		);
	}

	return modified;
}


bool  jvs::StringReverser::registerPipelinePass(llvm::StringRef name, llvm::ModulePassManager& mpm,
	llvm::ArrayRef < llvm::PassBuilder::PipelineElement> /*ignored*/)
{
	if (name == DEBUG_TYPE)
	{
		mpm.addPass(StringReverser{});

		return true;
	}

	return false;
}