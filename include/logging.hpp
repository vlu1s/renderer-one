#ifndef _LOGGING_HPP_
#define _LOGGING_HPP_

#include <sys/types.h>
#include <cstdio>  /**< For console I/O */
#include <cstdlib>
#include <cstring>
#include <cstdint>

#include "operators.hpp"
#include "types.hpp"

#ifndef DEFAULT_COLOUR_FMT
/**
 * Options:
 *     - hexval   (char)
 *     - trihex   (char)
 *     - rgb      (rgb_t)    TODO: (Jeff) NOT AVAILABLE
 *     - rgba     (rgba_t)   TODO: (Jeff) NOT AVAILABLE
 */
#define DEFAULT_COLOUR_FMT hexval /** The applicable colour format */
#endif


/**
 * @typedef struct _RGB
 * @brief A struct that emulates an `RGB` object
 * @see `u_short`
 *
 * @field `u_short r` Red value (Default is 0)
 * @field `u_short g` Green value (Default is 0)
 * @field `u_short b` Blue value (Default is 0)
 */
typedef struct _RGB {
    u_short r = 0;
    u_short g = 0;
    u_short b = 0;
} rgb_t;


/**
 * @typedef struct _RGBA
 * @brief A struct that emulates an `RGBA` object
 * @see `rgb_t`
 *
 * @field `struct _RGB rgb`
 * @field `float a` Value of 'a'
 */
typedef struct _RGBA {
    struct _RGB rgb;  /*< FIXME: (Jeff) Use struct or use rgb fields separately?? */
    float a;
} rgba_t;

/**
 * @brief Colorscheme indexes
 */
enum
{
    /**< Non-bright terminal colors */
    LogBlack,
    LogRed,
    LogGreen,
    LogYellow,
    LogBlue,
    LogCyan,
    LogMagenta,
    LogGray,

    /**< Bright and/or bold terminal colors */
    LogBrBlack,
    LogBrRed,
    LogBrGreen,
    LogBrYellow,
    LogBrBlue,
    LogBrCyan,
    LogBrMagenta,
    LogWhite,

    /**< WARNING: (Jeff) The value below MUST always be the last one */
    LogColLast,
};


/**
 * @typedef `struct _col_t`
 * @brief [TODO: (Jeff) description]
 *
*/
typedef struct _col_t {
    char hexval[8];
    char trihex[5];
    /* rgb_t *rgb[4]; */
    /* rgba_t *rgba[3]; */
    char delim[4];
} colour_t;


static colour_t log_colours[LogColLast] = {
    /*                     <hex>     <trihex>     <delim> */

    /* LongBlack */    { "#222222",  "#222",       ".;."  },
    /* LogRed     */   { "#900000",  "#900",       ".`."  },
    /* LogGreen   */   { "#009000",  "#090",       ".~."  },
    /* LogYellow  */   { "#c0c040",  "#cc4",      ".\\."  },
    /* LogBlue    */   { "#2030b0",  "#23b",       ".^."  },
    /* LogCyan    */   { "#30c0b0",  "#3cb",       ".*."  },
    /* LogMagenta */   { "#803090",  "#839",       ".?."  },
    /* LogGray    */   { "#606060",  "#666",       ".!."  },
    /* LogBrBlack   */ { "#a0a0a0",  "#aaa",       ",;,"  },
    /* LogBrRed     */ { "#b02020",  "#b22",       ",`,"  },
    /* LogBrGreen   */ { "#20b020",  "#2b2",       ",~,"  },
    /* LogBrYellow  */ { "#e0e060",  "#ee6",      ",\\,"  },
    /* LogBrBlue    */ { "#4050d0",  "#45d",       ",^,"  },
    /* LogBrCyan    */ { "#50e0d0",  "#5ed",       ",*,"  },
    /* LogBrMagenta */ { "#b050b0",  "#b5b",       ",?,"  },
    /* LogWhite     */ { "#f0f0f0",  "#fff",       ",!,"  },
};

static char *fg = log_colours[LogWhite].DEFAULT_COLOUR_FMT;  /**< Initial value */
static char *bg = log_colours[LogBlack].DEFAULT_COLOUR_FMT;  /**< Initial value */

/**
 * @brief Reformat a string to enable a coloured output
 * @see `colour_t` type to format text
 *
 * @param `char *txt` To-be formatted text. This variable will be modified within the function
 */
void format_txt(char *txt);

/**
 * @brief Print an error message to `STDERR` and exit
 *
 * @param `const char *msg` Input text pointer
 * @param `const int status` Exit code status
 */
void die(const char *msg, const int status);

/**
 * @brief Print error messages to stderr, but without exiting
 *
 * @param `const char *msg` Message output
 * @param `const int error` Error signal
 */
void error_callback(const char *msg, const int error);

/**
 * @brief Print error messages to stderr, without exiting. Also with colors!
 * @see `uint`
 * @see `colour_t`
 *
 * @param `consnt char *msg`
 * @param `const colour_t *col_format`
 * @param `const uint severity`
 */
void color_warn(const char *msg, const colour_t *col_format, const uint severity);

#endif /*!_LOGGING_HPP_ */
