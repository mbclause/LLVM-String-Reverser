#include <LLVM-Tutorial/plugin-registration.h>

#include <LLVM-Tutorial/string-analysis.h>

#include <LLVM-Tutorial/string-reverser.h>

void jvs::RegisterPluginPasses(llvm::PassBuilder& passBuilder)
{
	passBuilder.registerAnalysisRegistrationCallback(jvs::StringAnalyzer::registerAnalysis);

	passBuilder.registerPipelineParsingCallback(jvs::StringAnalyzerPrinter::registerPipelinePass);

	passBuilder.registerPipelineParsingCallback(jvs::StringReverser::registerPipelinePass);
}


auto llvmGetPassPluginInfo() -> llvm::PassPluginLibraryInfo
{
	return
	{
		LLVM_PLUGIN_API_VERSION,	// API Version
		"LLVM-Tutorial",			// PluginName
		LLVM_VERSION_STRING,		// Plugin Version
		&jvs::RegisterPluginPasses	// register pass builder callbacks
	};
}