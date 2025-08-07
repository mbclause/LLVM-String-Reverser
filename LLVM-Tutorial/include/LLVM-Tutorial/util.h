#pragma once
#if !defined(LLVM_TUTORIAL_UTIL_H_)
#define LLVM_TUTORIAL_UTIL_H_

#include <string>
#include <llvm/ADT/StringRef.h>
#include <llvm/Support/Debug.h>

#define PASS_DEBUG(x) LLVM_DEBUG(llvm::dbgs() << DEBUG_TYPE " : " << x)

namespace jvs
{
	std::string GetEscapedString(llvm::StringRef str);
} // namespace jvs

#endif // !LLVM_TUTORIAL_UTIL_H_
