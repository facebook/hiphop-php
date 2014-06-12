set (FREEBSD FALSE)
if("${CMAKE_SYSTEM_NAME}" STREQUAL "FreeBSD")
  set (FREEBSD TRUE)
endif()
set (LINUX FALSE)
if("${CMAKE_SYSTEM_NAME}" STREQUAL "Linux")
  set (LINUX TRUE)
endif()

# using Clang
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  exec_program(${CMAKE_C_COMPILER} ARGS "--version 2>&1 | grep version" OUTPUT_VARIABLE _clang_version_info)
  string(REGEX REPLACE "^.*([ ]version|based[ ]on[ ]LLVM)[ ]([0-9]+\\.[0-9]+).*" "\\2" CLANG_VERSION "${_clang_version_info}")
  if(CLANG_VERSION VERSION_EQUAL 3.3)
    message("-- Clang 3.3 detected, using strict GNU/C++11 features")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
  elseif(CLANG_VERSION VERSION_GREATER 3.3)
    message("-- Clang > 3.3 detected, enabling GNU/C++1y features")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++1y -D_CPP14")
  else()
    message(FATAL_ERROR "${PROJECT_NAME} requires clang 3.3 or later")
  endif()
  # libstdc++ deprecated
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -fno-gcse -fno-omit-frame-pointer -ftemplate-depth-180 -Woverloaded-virtual -Wno-deprecated -Wno-strict-aliasing -Wno-write-strings -Wno-invalid-offsetof -fno-operator-names -Wno-error=array-bounds -Wno-error=switch -Werror=format-security -Wno-unused-result -Wno-sign-compare -Wno-attributes -Wno-maybe-uninitialized -Wno-mismatched-tags -Wno-unknown-warning-option -Wno-return-type-c-linkage -Qunused-arguments")
  # CMAKE_BUILD_TYPE: http://www.cmake.org/Wiki/CMake_Useful_Variables#Compilers_and_Tools
  set (CMAKE_C_FLAGS_DEBUG            "-g")
  set (CMAKE_CXX_FLAGS_DEBUG          "-g")
  set (CMAKE_C_FLAGS_MINSIZEREL       "-Os -DNDEBUG")
  set (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
  set (CMAKE_C_FLAGS_RELEASE          "-O3 -DNDEBUG")
  set (CMAKE_CXX_FLAGS_RELEASE        "-O3 -DNDEBUG")
  set (CMAKE_C_FLAGS_RELWITHDEBINFO   "-O2 -g")
  set (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
# using GCC
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  execute_process(COMMAND ${CMAKE_CXX_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
  if(GCC_VERSION VERSION_GREATER 4.9 OR GCC_VERSION VERSION_EQUAL 4.9)
    message("-- g++ >= 4.9 detected, enabling GNU/C++1y features")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++1y -D_CPP14")
  elseif(GCC_VERSION VERSION_GREATER 4.8 OR GCC_VERSION VERSION_EQUAL 4.8)
    message("-- g++ >= 4.8 detected, using strict GNU/C++11 features")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
  else()
    message(FATAL_ERROR "${PROJECT_NAME} requires g++ 4.8 or later")
  endif()

  # ARM64
  set (GNUCC_PLAT_OPT "")
  if(NOT IS_AARCH64)
    # TODO: This should really only be set on X86/X64
    set (GNUCC_PLAT_OPT "-mcrc32")
  endif()

  # Use -Og with Debug builds in gcc >= 4.8
  set (CMAKE_C_FLAGS_DEBUG    "-Og -g")
  set (CMAKE_CXX_FLAGS_DEBUG  "-Og -g")

  # Generic GCC flags and Optional flags
  set (CMAKE_C_FLAGS_MINSIZEREL       "-Os -DNDEBUG")
  set (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
  set (CMAKE_C_FLAGS_RELEASE          "-O3 -DNDEBUG")
  set (CMAKE_CXX_FLAGS_RELEASE        "-O3 -DNDEBUG")
  set (CMAKE_C_FLAGS_RELWITHDEBINFO   "-O2 -g")
  set (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")
  set (CMAKE_C_FLAGS                  "-w")
  set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -fno-gcse -fno-omit-frame-pointer -ftemplate-depth-180 -Woverloaded-virtual -Wno-deprecated -Wno-strict-aliasing -Wno-write-strings -Wno-invalid-offsetof -fno-operator-names -Wno-error=array-bounds -Wno-error=switch -Werror=format-security -Wno-unused-result -Wno-sign-compare -Wno-attributes -Wno-maybe-uninitialized -Wno-unused-local-typedefs -fno-canonical-system-headers -Wno-deprecated-declarations ${GNUCC_PLAT_OPT}")
# using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
  set (CMAKE_C_FLAGS   "-no-ipo -fp-model precise -wd584 -wd1418 -wd1918 -wd383 -wd869 -wd981 -wd424 -wd1419 -wd444 -wd271 -wd2259 -wd1572 -wd1599 -wd82 -wd177 -wd593 -w")
  set (CMAKE_CXX_FLAGS "-no-ipo -fp-model precise -wd584 -wd1418 -wd1918 -wd383 -wd869 -wd981 -wd424 -wd1419 -wd444 -wd271 -wd2259 -wd1572 -wd1599 -wd82 -wd177 -wd593 -fno-omit-frame-pointer -ftemplate-depth-180 -Wall -Woverloaded-virtual -Wno-deprecated -w1 -Wno-strict-aliasing -Wno-write-strings -Wno-invalid-offsetof -fno-operator-names")
# using Visual Studio C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  message(FATAL_ERROR "${PROJECT_NAME} is not yet compatible with visual studio")
else()
  message("Warning: unknown/unsupported compiler, things may go wrong")
endif()
