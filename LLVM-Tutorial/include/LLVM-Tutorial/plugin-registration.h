#pragma once
#if !defined(LLVM_TUTORIAL_PLUGIN_REGISTRATION_H_)
#define LLVM_TUTORIAL_PLUGIN_REGISTRATION_H_

#include <llvm/Passes/PassBuilder.h>
#include <llvm/Passes/PassPlugin.h>

//#include <llvm/llvm/llvm/include/llvm/Passes/PassBuilder.h>
//#include <llvm/llvm/llvm/include/llvm/Passes/PassPlugin.h>

namespace jvs
{

	void RegisterPluginPasses(llvm::PassBuilder& passBuilder);

} // namespace jvs

extern "C" LLVM_ATTRIBUTE_WEAK auto llvmGetPassPluginInfo() -> llvm::PassPluginLibraryInfo;




#endif // !LLVM_TUTORIAL_PLUGIN_REGISTRATION_H_
