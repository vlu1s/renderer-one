#ifndef _LOGGING_HPP_
#define _LOGGING_HPP_

#include <cstdio>  /* For console I/O. */
#include <cstdlib>
#include <cstring>

#include "types.hpp"


#ifndef DEFAULT_COLOUR_FMT
/**
 * Options:
 *     - hexval   (char)
 *     - trihex   (char)
 *     - rgb      (rgb_t)    TODO(jeff): NOT AVAILABLE
 *     - rgba     (rgba_t)   TODO(jeff): NOT AVAILABLE
 */
#define DEFAULT_COLOUR_FMT hexval
#endif

/// TODO(Jeff): Add RGB and RGBA values.

typedef struct _RGB {
    char r[4];
    char g[4];
    char b[4];
} rgb_t;


typedef struct _RGBA {
    char r[4];
    char g[4];
    char b[4];
    float a;
} rgba_t;

enum
{
    /* Non-bright terminal colors. */
    LogBlack,
    LogRed,
    LogGreen,
    LogYellow,
    LogBlue,
    LogCyan,
    LogMagenta,
    LogGray,

    /* Bright and/or bold terminal colors.*/
    LogBrBlack,
    LogBrRed,
    LogBrGreen,
    LogBrYellow,
    LogBrBlue,
    LogBrCyan,
    LogBrMagenta,
    LogWhite,

    /* WARNING: The value below MUST always be the last one. */
    LogColLast,
};



typedef struct _colt {
    char hexval[8];
    char trihex[5];
    char delim[4];
    /* rgb_t *rgb[4]; */
    /* rgba_t *rgb[3]; */
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
    /* LogWhite     */ { "#f0f0f0",  "#fff",       ",!,"  }
};

static char *fg = log_colours[LogWhite].DEFAULT_COLOUR_FMT;  /// Initial value
static char *bg = log_colours[LogBlack].DEFAULT_COLOUR_FMT;  /// Initial value

/**
 * @brief Reformat a string to enable a coloured output.
 * @see `colour_t` type to format text.
 *
 * @param txt [TODO: Jeff]
 */
static void format_txt(char *txt);

/* Print an error message to STDERR and exit. */
void die(const char *msg, int status);

/**
 * @brief Print error messages to stderr, but without exiting.
 *
 * @param msg
 * @param col_format
 * @param severity
 */
void warn(const char *msg, const colour_t *col_format, const uint severity);

#endif /* !_LOGGING_HPP_ */
