#pragma once

#ifdef _WIN32
    #define weak
    #define hidden
#else
    #define weak __attribute__((__weak__))
    #define hidden __attribute__((__visibility__("hidden")))
#endif

#define weak_alias(old, new)

#define _XOPEN_SOURCE 700


