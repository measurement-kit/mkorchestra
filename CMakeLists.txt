# Autogenerated by `mkbuild`; DO NOT EDIT!

cmake_minimum_required(VERSION 3.12.0)
project("mkorchestra")

include(CheckIncludeFileCXX)
include(CheckLibraryExists)
include(CheckCXXCompilerFlag)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

list(APPEND CMAKE_REQUIRED_LIBRARIES Threads::Threads)

if(("${WIN32}"))
  list(APPEND CMAKE_REQUIRED_LIBRARIES ws2_32 crypt32)
  if(("${MINGW}"))
    list(APPEND CMAKE_REQUIRED_LIBRARIES -static-libgcc -static-libstdc++)
  endif()
endif()

enable_testing()

if(("${WIN32}"))
  if(("${CMAKE_SIZEOF_VOID_P}" EQUAL 4))
    SET(MK_WIN32_ARCH "x86")
  elseif(("${CMAKE_SIZEOF_VOID_P}" EQUAL 8))
    SET(MK_WIN32_ARCH "x64")
  else()
    message(FATAL_ERROR "Neither 32 not 64 bit")
  endif()
endif()
if((${APPLE}))
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -I/usr/local/include")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/usr/local/lib")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -L/usr/local/lib")
endif()

#
# cacert.pem
#

message(STATUS "mkdirAll: ${CMAKE_BINARY_DIR}/.mkbuild/data")
execute_process(COMMAND
  ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/.mkbuild/data"
  RESULT_VARIABLE FAILURE_1402)
if("${FAILURE_1402}")
  message(FATAL_ERROR "${FAILURE_1402}")
endif()
message(STATUS "download: https://curl.haxx.se/ca/cacert.pem")
file(DOWNLOAD https://curl.haxx.se/ca/cacert.pem
  "${CMAKE_BINARY_DIR}/.mkbuild/data/cacert.pem"
  EXPECTED_HASH SHA256=c1fd9b235896b1094ee97bfb7e042f93530b5e300781f59b45edf84ee8c75000
  TLS_VERIFY ON)

#
# catch.hpp
#

message(STATUS "mkdirAll: ${CMAKE_BINARY_DIR}/.mkbuild/include")
execute_process(COMMAND
  ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/.mkbuild/include"
  RESULT_VARIABLE FAILURE_1954)
if("${FAILURE_1954}")
  message(FATAL_ERROR "${FAILURE_1954}")
endif()
message(STATUS "download: https://github.com/catchorg/Catch2/releases/download/v2.3.0/catch.hpp")
file(DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.3.0/catch.hpp
  "${CMAKE_BINARY_DIR}/.mkbuild/include/catch.hpp"
  EXPECTED_HASH SHA256=5eb8532fd5ec0d28433eba8a749102fd1f98078c5ebf35ad607fb2455a000004
  TLS_VERIFY ON)
LIST(APPEND CMAKE_REQUIRED_INCLUDES "${CMAKE_BINARY_DIR}/.mkbuild/include")
CHECK_INCLUDE_FILE_CXX("catch.hpp" MK_HAVE_HEADER_2471)
if(NOT ("${MK_HAVE_HEADER_2471}"))
  message(FATAL_ERROR "cannot find: catch.hpp")
endif()

if(("${WIN32}"))

  #
  # windows-curl-7.61.1-1.tar.gz
  #

  message(STATUS "mkdirAll: ${CMAKE_BINARY_DIR}/.mkbuild/download")
  execute_process(COMMAND
    ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/.mkbuild/download"
    RESULT_VARIABLE FAILURE_2852)
  if("${FAILURE_2852}")
    message(FATAL_ERROR "${FAILURE_2852}")
  endif()
  message(STATUS "download: https://github.com/measurement-kit/prebuilt/releases/download//testing/windows-curl-7.61.1-1.tar.gz")
  file(DOWNLOAD https://github.com/measurement-kit/prebuilt/releases/download//testing/windows-curl-7.61.1-1.tar.gz
    "${CMAKE_BINARY_DIR}/.mkbuild/download/windows-curl-7.61.1-1.tar.gz"
    EXPECTED_HASH SHA256=424d2f18f0f74dd6a0128f0f4e59860b7d2f00c80bbf24b2702e9cac661357cf
    TLS_VERIFY ON)
  message(STATUS "Extract: ${CMAKE_BINARY_DIR}/.mkbuild/download/windows-curl-7.61.1-1.tar.gz")
  execute_process(COMMAND
    ${CMAKE_COMMAND} -E tar xf "${CMAKE_BINARY_DIR}/.mkbuild/download/windows-curl-7.61.1-1.tar.gz"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/.mkbuild/download"
    RESULT_VARIABLE FAILURE_3675)
  if("${FAILURE_3675}")
    message(FATAL_ERROR "${FAILURE_3675}")
  endif()
  LIST(APPEND CMAKE_REQUIRED_INCLUDES "${CMAKE_BINARY_DIR}/.mkbuild/download/MK_DIST/windows/curl/7.61.1-1/${MK_WIN32_ARCH}/include")
  CHECK_INCLUDE_FILE_CXX("curl/curl.h" MK_HAVE_HEADER_3920)
  if(NOT ("${MK_HAVE_HEADER_3920}"))
    message(FATAL_ERROR "cannot find: curl/curl.h")
  endif()
  CHECK_LIBRARY_EXISTS("${CMAKE_BINARY_DIR}/.mkbuild/download/MK_DIST/windows/curl/7.61.1-1/${MK_WIN32_ARCH}/lib/libcurl.lib" "curl_easy_init" "" MK_HAVE_LIB_4079)
  if(NOT ("${MK_HAVE_LIB_4079}"))
    message(FATAL_ERROR "cannot find: ${CMAKE_BINARY_DIR}/.mkbuild/download/MK_DIST/windows/curl/7.61.1-1/${MK_WIN32_ARCH}/lib/libcurl.lib")
  endif()
  LIST(APPEND CMAKE_REQUIRED_LIBRARIES "${CMAKE_BINARY_DIR}/.mkbuild/download/MK_DIST/windows/curl/7.61.1-1/${MK_WIN32_ARCH}/lib/libcurl.lib")
  LIST(APPEND CMAKE_REQUIRED_DEFINITIONS -DCURL_STATICLIB)
else()
  CHECK_INCLUDE_FILE_CXX("curl/curl.h" MK_HAVE_HEADER_4637)
  if(NOT ("${MK_HAVE_HEADER_4637}"))
    message(FATAL_ERROR "cannot find: curl/curl.h")
  endif()
  CHECK_LIBRARY_EXISTS("curl" "curl_easy_init" "" MK_HAVE_LIB_4796)
  if(NOT ("${MK_HAVE_LIB_4796}"))
    message(FATAL_ERROR "cannot find: curl")
  endif()
  LIST(APPEND CMAKE_REQUIRED_LIBRARIES "curl")
endif()

#
# mkcurl.hpp
#

message(STATUS "mkdirAll: ${CMAKE_BINARY_DIR}/.mkbuild/include")
execute_process(COMMAND
  ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/.mkbuild/include"
  RESULT_VARIABLE FAILURE_5192)
if("${FAILURE_5192}")
  message(FATAL_ERROR "${FAILURE_5192}")
endif()
message(STATUS "download: https://raw.githubusercontent.com/measurement-kit/mkcurl/v0.10.0/mkcurl.hpp")
file(DOWNLOAD https://raw.githubusercontent.com/measurement-kit/mkcurl/v0.10.0/mkcurl.hpp
  "${CMAKE_BINARY_DIR}/.mkbuild/include/mkcurl.hpp"
  EXPECTED_HASH SHA256=2248b8a1e597bd7d1970138291ecd9a7d0c2070a50431c82e8499cc9529480f1
  TLS_VERIFY ON)
LIST(APPEND CMAKE_REQUIRED_INCLUDES "${CMAKE_BINARY_DIR}/.mkbuild/include")
CHECK_INCLUDE_FILE_CXX("mkcurl.hpp" MK_HAVE_HEADER_5722)
if(NOT ("${MK_HAVE_HEADER_5722}"))
  message(FATAL_ERROR "cannot find: mkcurl.hpp")
endif()

#
# mkmock.hpp
#

message(STATUS "mkdirAll: ${CMAKE_BINARY_DIR}/.mkbuild/include")
execute_process(COMMAND
  ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/.mkbuild/include"
  RESULT_VARIABLE FAILURE_6055)
if("${FAILURE_6055}")
  message(FATAL_ERROR "${FAILURE_6055}")
endif()
message(STATUS "download: https://raw.githubusercontent.com/measurement-kit/mkmock/v0.2.0/mkmock.hpp")
file(DOWNLOAD https://raw.githubusercontent.com/measurement-kit/mkmock/v0.2.0/mkmock.hpp
  "${CMAKE_BINARY_DIR}/.mkbuild/include/mkmock.hpp"
  EXPECTED_HASH SHA256=f07bc063a2e64484482f986501003e45ead653ea3f53fadbdb45c17a51d916d2
  TLS_VERIFY ON)
LIST(APPEND CMAKE_REQUIRED_INCLUDES "${CMAKE_BINARY_DIR}/.mkbuild/include")
CHECK_INCLUDE_FILE_CXX("mkmock.hpp" MK_HAVE_HEADER_6583)
if(NOT ("${MK_HAVE_HEADER_6583}"))
  message(FATAL_ERROR "cannot find: mkmock.hpp")
endif()

#
# json.hpp
#

message(STATUS "mkdirAll: ${CMAKE_BINARY_DIR}/.mkbuild/include")
execute_process(COMMAND
  ${CMAKE_COMMAND} -E make_directory "${CMAKE_BINARY_DIR}/.mkbuild/include"
  RESULT_VARIABLE FAILURE_6914)
if("${FAILURE_6914}")
  message(FATAL_ERROR "${FAILURE_6914}")
endif()
message(STATUS "download: https://raw.githubusercontent.com/nlohmann/json/v3.5.0/single_include/nlohmann/json.hpp")
file(DOWNLOAD https://raw.githubusercontent.com/nlohmann/json/v3.5.0/single_include/nlohmann/json.hpp
  "${CMAKE_BINARY_DIR}/.mkbuild/include/json.hpp"
  EXPECTED_HASH SHA256=8a6dbf3bf01156f438d0ca7e78c2971bca50eec4ca6f0cf59adf3464c43bb9d5
  TLS_VERIFY ON)
LIST(APPEND CMAKE_REQUIRED_INCLUDES "${CMAKE_BINARY_DIR}/.mkbuild/include")
CHECK_INCLUDE_FILE_CXX("json.hpp" MK_HAVE_HEADER_7466)
if(NOT ("${MK_HAVE_HEADER_7466}"))
  message(FATAL_ERROR "cannot find: json.hpp")
endif()

#
# Set restrictive compiler flags
#

macro(MKSetRestrictiveCompilerFlags)
  if(("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU") OR
     ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Werror")
    # https://www.owasp.org/index.php/C-Based_Toolchain_Hardening_Cheat_Sheet
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wall")
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wextra")
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wconversion")
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wcast-align")
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wformat=2")
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wformat-security")
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -fno-common")
    # Some options are only supported by GCC when we're compiling C code:
    if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
      set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wmissing-prototypes")
      set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wstrict-prototypes")
    else()
      set(MK_C_FLAGS "${MK_C_FLAGS} -Wmissing-prototypes")
      set(MK_C_FLAGS "${MK_C_FLAGS} -Wstrict-prototypes")
    endif()
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wmissing-declarations")
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wstrict-overflow")
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
      set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wtrampolines")
    endif()
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Woverloaded-virtual")
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wreorder")
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wsign-promo")
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -Wnon-virtual-dtor")
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} -fstack-protector-all")
    if(NOT "${APPLE}" AND NOT "${MINGW}")
      set(MK_LD_FLAGS "${MK_LD_FLAGS} -Wl,-z,noexecstack")
      set(MK_LD_FLAGS "${MK_LD_FLAGS} -Wl,-z,now")
      set(MK_LD_FLAGS "${MK_LD_FLAGS} -Wl,-z,relro")
      set(MK_LD_FLAGS "${MK_LD_FLAGS} -Wl,-z,nodlopen")
      set(MK_LD_FLAGS "${MK_LD_FLAGS} -Wl,-z,nodump")
    endif()
    add_definitions(-D_FORTIFY_SOURCES=2)
  elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    # TODO(bassosimone): add support for /Wall and /analyze
    set(MK_COMMON_FLAGS "${MK_COMMON_FLAGS} /WX /W4 /EHs")
    set(MK_LD_FLAGS "${MK_LD_FLAGS} /WX")
  else()
    message(FATAL_ERROR "Compiler not supported: ${CMAKE_CXX_COMPILER_ID}")
  endif()
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MK_COMMON_FLAGS} ${MK_C_FLAGS}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MK_COMMON_FLAGS} ${MK_CXX_FLAGS}")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${MK_LD_FLAGS}")
  set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} ${MK_LD_FLAGS}")
  if("${WIN32}")
    add_definitions(-D_WIN32_WINNT=0x0600) # for NI_NUMERICSERV and WSAPoll
  endif()
endmacro()

MKSetRestrictiveCompilerFlags()

#
# Prepare for compiling targets
#

add_definitions(${CMAKE_REQUIRED_DEFINITIONS})
include_directories(${CMAKE_REQUIRED_INCLUDES})

#
# mkorchestra
#

add_library(
  mkorchestra
  mkorchestra.cpp
)
target_link_libraries(
  mkorchestra
  ${CMAKE_REQUIRED_LIBRARIES}
)

#
# integration-tests
#

add_executable(
  integration-tests
  integration-tests.cpp
)
target_link_libraries(
  integration-tests
  mkorchestra
  ${CMAKE_REQUIRED_LIBRARIES}
)

#
# test: integration_tests
#

add_test(
  NAME integration_tests COMMAND integration-tests
)
