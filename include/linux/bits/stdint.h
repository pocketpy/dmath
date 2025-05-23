#pragma once

#if defined(__x86_64__) || defined(_M_X64)
    #include "../../../musl/arch/x86_64/bits/stdint.h"
#elif defined(__i386__) || defined(_M_IX86)
    #include "../../../musl/arch/i386/bits/stdint.h"
#elif defined(__x32__)
    #include "../../../musl/arch/x32/bits/stdint.h"
#elif defined(__aarch64__)
    #include "../../../musl/arch/aarch64/bits/stdint.h"
#elif defined(__arm__)
    #include "../../../musl/arch/arm/bits/stdint.h"
#else
    #error "Unsupported architecture"
#endif