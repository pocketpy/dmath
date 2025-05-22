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

add_library(${PROJECT_NAME} STATIC
    ${MUSL_MATH_SRC}
)

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /Ox /Oi- /wd4244 /wd4723 /wd4146 /NODEFAULTLIB)
    message("MSVC set")
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -O2 -ffp-contract=off -nostdlib)
    message("GCC/Clang set")
endif()

target_include_directories(${PROJECT_NAME} PRIVATE
    include/common
    ${MUSL_ROOT}
    )

if(WIN32)
    target_include_directories(${PROJECT_NAME} PRIVATE include/win32)
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        # "weak=__attribute__((weak))"
        # "hidden=__attribute__((visibility(\"hidden\")))"
        "_XOPEN_SOURCE=700"
        )
    target_include_directories(${PROJECT_NAME} PRIVATE include/linux)
endif()

add_executable(dmath_test tests/main.c)

target_link_libraries(dmath_test dmath)