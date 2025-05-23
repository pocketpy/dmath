#pragma once

#include "../../musl/include/math.h"

#undef INFINITY
#undef NAN

#define INFINITY ((float)((1e+300 * 1e+300)))
#define NAN ((float)(INFINITY * 0.0F))

#if FP_FAST_FMA || FP_FAST_FMAF || FP_FAST_FMAL
    #error "FMA flags must be disabled"
#endif
