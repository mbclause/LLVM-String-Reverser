#include <LLVM-Tutorial/util.h>

#include <llvm/ADT/StringExtras.h>
#include <llvm/Support/raw_ostream.h>

namespace
{
	template <typename StreamWriterT>
	std::string writeToStream(const StreamWriterT& writer)
	{
		std::string result;

		llvm::raw_string_ostream os(result);

		writer(os);

		// str() flushes the stream automatically and returns a reference to the underlying
		// std::string.
		return os.str();
	}
} // namespace

std::string jvs::GetEscapedString(llvm::StringRef str)
{
	return writeToStream([=](llvm::raw_ostream& os)
		{
			llvm::printEscapedString(str, os);
		});
}