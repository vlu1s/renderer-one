#ifndef _TYPES_HPP_
#define _TYPES_HPP_

typedef unsigned int natural;
typedef unsigned long long long_natural;
typedef unsigned short short_natural;
typedef unsigned char uchar;

/**< FIXME: (Jeff) Why the need to rename `static`? */

/** Reserved for internal methods, prefferably */
#define internal static
/// FIXME: (Jeff) What's this?
#define local_persist static

/** Reserved for globally imported variables from header files */
#define global_variable static

#endif /**!_TYPES_HPP_ */
