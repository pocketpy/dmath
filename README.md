# dmath

<p>
<!-- Build -->
<a title="Build" href="https://github.com/pocketpy/dmath/actions/workflows" >
<img src="https://github.com/pocketpy/dmath/actions/workflows/main.yml/badge.svg" /></a>
<!-- C11 -->
<a href="https://en.wikipedia.org/wiki/C11_(C_standard_revision)">
<img alt="Python" src="https://img.shields.io/badge/C-11-blue.svg"></a>
<!-- License -->
<a href="https://github.com/pocketpy/dmath/blob/main/LICENSE">
<img alt="GitHub" src="https://img.shields.io/github/license/pocketpy/dmath.svg?color=blue"></a>
<!-- Github Release -->
<a href="https://github.com/pocketpy/dmath/releases">
<img alt="GitHub release" src="https://img.shields.io/github/release/pocketpy/dmath.svg"></a>
</p>

`dmath` is a deterministic math library for game projects that running on standard mobile (Android/iOS) and desktop platforms (Windows/Linux/MacOS).

`dmath` is a drop-in replacement for the math library in C11, based on [musl-libc v1.2.5](https://musl.libc.org/) with modifications to ensure that all floating-point operations are deterministic across different platforms and compilers. Although musl-libc is primarily designed for Linux, `dmath` can be used on Windows and MacOS.
[pocketpy](https://github.com/pocketpy/dmath) uses `dmath` as its math library when compiled with `-DPK_ENABLE_DETERMINISM=ON`.

> `dmath` is not designed for embedded systems.

## Installation

First clone this repo recursively:

```bash
git clone --recursive https://github.com/pocketpy/dmath
```

Then add the following line to your `CMakeLists.txt`:

```cmake
add_subdirectory(<path_to_dmath_repo>)

target_link_libraries(<your_target> dmath)

if(MSVC)
    # Force multiple definitions to be allowed in MSVC.
    target_link_options(<your_target> PRIVATE /FORCE:MULTIPLE)
endif()
```

## Usage

```c
// CMakeLists.txt will redirect <math.h> to "dmath/include/public/math.h".
// You don't need to modify your existing code.
#include <math.h>

#include <stdio.h>

int main(){

// You can check this macro to ensure that `dmath` is used.
#ifndef _DMATH_H
    abort();
#endif

    double x = log(10);
    printf("log(10) = %f\n", x);
    return 0;
}
```

## Tested Platforms

We have tested `dmath` on the following platforms and configurations.

| Job                    | OS           | Arch    | Compiler |
| ---------------------- | ------------ | ------- | -------- |
| build_ubuntu           | Ubuntu 22.04 | x86_64  | gcc      |
|                        |              |         | clang    |
| build_ubuntu_multiarch | Ubuntu 22.04 | x86     | gcc      |
|                        |              |         | clang    |
|                        |              | aarch64 | gcc      |
|                        |              |         | clang    |
|                        |              | armv7   | gcc      |
|                        |              |         | clang    |
| build_macos            | MacOS 14     | x86_64  | clang    |
| build_win32            | Windows 2022 | x86_64  | cl       |

## References

https://box2d.org/posts/2024/08/determinism/

## License

MIT License