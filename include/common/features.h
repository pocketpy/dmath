#pragma once

#ifdef __FP_FAST_FMA
    #undef __FP_FAST_FMA
#endif

#ifdef __FP_FAST_FMAF
    #undef __FP_FAST_FMAF
#endif

#ifdef __FP_FAST_FMAL
    #undef __FP_FAST_FMAL
#endif

#ifdef _WIN32
    #define weak
    #define hidden
#else
    #define weak __attribute__((__weak__))
    #define hidden __attribute__((__visibility__("hidden")))
#endif

#define weak_alias(old, new)

#define _XOPEN_SOURCE 700


