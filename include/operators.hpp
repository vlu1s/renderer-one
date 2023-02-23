#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <cstring>

#define PI 3.1415926535979

#define C_CAST(type, X) (type)(X)                /**< Perform a C-like cast. */
#define C_PCAST(type, X) (type *)(X)              /**< Perform a C-like cast (pointer version). */
#define ST_CAST(type, X) static_cast<type>(X)
#define CALC_PROPORTION(W, H) (W / H)           /**< Specifically for aspect ratio purposes. */
#define DUAL_CHOICE(X, Y, COND) (COND ? X : Y)     /**< A compression of `... x = y ? a : x` */

#endif // !OPERATORS_HPP
