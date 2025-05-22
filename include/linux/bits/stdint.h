#pragma once

#if defined(__x86_64__)
    #include "arch/x86_64/bits/stdint.h"
#elif defined(__i386__)
    #include "arch/i386/bits/stdint.h"
#elif defined(__x32__)
    #include "arch/x32/bits/stdint.h"
#elif defined(__aarch64__)
    #include "arch/aarch64/bits/stdint.h"
#elif defined(__arm__)
    #include "arch/arm/bits/stdint.h"
#else
    #error "Unsupported architecture"
#endif