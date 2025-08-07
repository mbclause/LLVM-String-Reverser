# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("LLVM-Tutorial")

set(debugEnable OFF)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	set(debugEnable ON)
endif()

option(ENABLE_TESTS "Enable tests" ${debugEnable})

add_compile_definitions(_CRT_USE_BUILTIN_OFFSETOF)




# Find LLVM
find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}: ${LLVM_INSTALL_PREFIX}")
list(APPEND C_MAKE_MODULE_PATH "${LLVM_CMAKE_DIR}")
include(AddLLVM)

# Plugins have to be explicitely enabled for windows
set(LLVM_ENABLE_PLUGINS TRUE)

# disable RTTI if llvm was built without it.
if (NOT LLVM_ENABLE_RTTI)
	if (MSVC)
		string(APPEND CMAKE_CXX_FLAGS " /GR-")
	else()
		string(APPEND CMAKE_CXX_FLAGS " -fno-rtti")
	endif()
endif()

include_directories(${LLVM_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)
separate_arguments(LLVM_DEFINITIONS_LIST NATIVE_COMMAND ${LLVM_DEFINITIONS})
add_definitions(${LLVM_DEFINITIONS_LIST})


add_subdirectory(lib)

if(ENABLE_TESTS)
	#add_subdirectory(test)

endif()
