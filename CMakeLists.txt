cmake_minimum_required(VERSION 3.10)

project(dmath C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(MUSL_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/musl")

file(GLOB MUSL_MATH_SRC "${MUSL_ROOT}/src/math/*.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/fma.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/fmaf.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/fmal.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/llrint.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/llrintf.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/llrintl.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/lrint.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/lrintf.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/lrintl.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/nearbyint.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/nearbyintf.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/nearbyintl.c")

list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/ilogb.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/ilogbf.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/ilogbl.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/j0.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/j0f.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/j1.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/j1f.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/jn.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/jnf.c")
list(REMOVE_ITEM MUSL_MATH_SRC "${MUSL_ROOT}/src/math/tgamma.c")

add_library(${PROJECT_NAME} STATIC
    ${MUSL_MATH_SRC}
)

if(MSVC)
    if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /Ox")
        add_definitions(-DNDEBUG)
    endif()

    target_compile_options(${PROJECT_NAME} PRIVATE /Oi-
        /wd4244 /wd4723 /wd4146
        /wd4116
        /wd4305
        )
    target_link_options(${PROJECT_NAME} PRIVATE /NODEFAULTLIB)
else()
    if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
        add_definitions(-DNDEBUG)
    endif()

    target_compile_options(${PROJECT_NAME} PRIVATE -ffp-contract=off)
    target_link_options(${PROJECT_NAME} PRIVATE -nostdlib)
endif()

target_include_directories(${PROJECT_NAME} PRIVATE include/common)
target_include_directories(${PROJECT_NAME} INTERFACE include/public)

if(WIN32)
    target_include_directories(${PROJECT_NAME} PRIVATE include/win32)
else()
    target_include_directories(${PROJECT_NAME} PRIVATE include/linux)
endif()

option(BUILD_TESTS "Build tests" OFF)

if(BUILD_TESTS)
    add_executable(dmath_test tests/main.c)
    target_link_libraries(dmath_test dmath)
endif()
