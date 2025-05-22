#if defined(__x86_64__) || defined(_M_X64)
    #include "bits/x86_64/alltypes.h"
#elif defined(__i386__) || defined(_M_IX86)
    #include "bits/i386/alltypes.h"
#elif defined(__x32__)
    #include "bits/x32/alltypes.h"
#elif defined(__aarch64__)
    #include "bits/aarch64/alltypes.h"
#elif defined(__arm__)
    #include "bits/arm/alltypes.h"
#else
    #error "Unsupported architecture"
#endif
