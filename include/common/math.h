#pragma once

#include "include/math.h"

#undef INFINITY
#undef NAN

#define INFINITY ((float)((1e+300 * 1e+300)))
#define NAN ((float)(INFINITY * 0.0F))