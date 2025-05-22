#pragma once

#if defined(__x86_64__) || defined(_M_X64)
    #include "arch/x86_64/bits/limits.h"
#elif defined(__i386__) || defined(_M_IX86)
    #include "arch/i386/bits/limits.h"
#elif defined(__x32__)
    #include "arch/x32/bits/limits.h"
#elif defined(__aarch64__)
    #include "arch/aarch64/bits/limits.h"
#elif defined(__arm__)
    #include "arch/arm/bits/limits.h"
#else
    #error "Unsupported architecture"
#endif