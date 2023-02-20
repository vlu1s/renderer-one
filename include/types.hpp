#ifndef _TYPES_HPP_
#define _TYPES_HPP_

#include <cstdbool>
#include <cstddef>
#include <cstdint>

#define natural unsigned int
#define long_natural unsigned long long
#define short_natural unsigned short
#define uchar unsigned char

/* Reserved for internal methods, prefferably. */
#define internal static
#define local_persist static
/* Reserved for globally imported variables from header files. */
#define global_variable static

#endif /* _TYPES_HPP_ */
