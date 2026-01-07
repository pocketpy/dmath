#pragma once

#if defined(__x86_64__) || defined(_M_X64)
    #include "../../../musl/arch/x86_64/bits/float.h"
#elif defined(__x32__)
    #include "../../../musl/arch/x32/bits/float.h"
#elif defined(__aarch64__)
    #include "../../../musl/arch/aarch64/bits/float.h"
#elif defined(__arm__)
    #include "../../../musl/arch/arm/bits/float.h"
#else
    #error "Unsupported architecture"
#endif
