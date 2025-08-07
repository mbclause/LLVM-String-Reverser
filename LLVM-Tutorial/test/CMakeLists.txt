if (NOT CMAKE_C_COMPILER_ID STREQUAL "Clang")
	message(WARNING "Clang must be used as C Compiler for this test")
	return()

endif()

set(p )

# Check for clang-cl use.
if(CMAKE_C_COMPILER_FRONTEND_VARIANT STREQUAL "msvc")
	set(p "/clang:")

endif()

#add_custom_command(
#	OUTPUT hello.ll
#	COMMAND
#		${CMAKE_C_COMPILER} ${p}-emit-llvm ${p}-S -Xclang -disable-O0-optnone
#			${CMAKE_CURRENT_LIST_DIR}/hello.c -o hello.ll
#)

add_custom_target(HelloTest ALL
	DEPENDS hello.ll
	COMMENT "generating hello.ll for testing"
)


