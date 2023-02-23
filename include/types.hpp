#ifndef _TYPES_HPP_
#define _TYPES_HPP_

#include <cstdbool>
#include <cstddef>
#include <cstdint>

/**< FIXME: (Jeff) Why the need to rename `static`? */

/** Reserved for internal methods, prefferably */
#define internal static
/// FIXME: (Jeff) What's this?
#define local_persist static

/** Reserved for globally imported variables from header files */
#define global_variable static

#endif /**!_TYPES_HPP_ */
