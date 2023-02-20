#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include <cmath>
#include <cstdlib>

#define PI 3.1415926535979

#define C_CAST(type, X) (type) x                /* Perform a C-like cast. */
#define C_PCAST(type, X) (type *)X              /* Perform a C-like cast (pointer version). */
#define ST_CAST(type, X) static_cast<type>(X)
#define CALC_PROPORTION(W, H) (W / H)           /* Specifically for aspect ratio purposes. */
#define DUAL_CHOICE(X, COND, Y) (COND ? X : Y)              /* A compression of the `... x = y ? a : x` */

#define FILL_SPACE(S, BYTES, TYPE) (TYPE)(std::malloc(S, ))

#endif // !OPERATORS_HPP
