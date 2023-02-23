#include <cstdlib>
#include <logging.hpp>

static void die(const char *txt, const int status)
{
    std::fprintf(stderr, "%s\n", txt);
    std::exit(status);
}

static void color_warn(const char *msg, const colour_t *col_format, const uint severity)
{
    if (!col_format || col_format == NULL)
    {
        die(msg, severity);
    }

    // WIP.
    char *newmsg = (char *) std::malloc(sizeof(msg) * 8);
    char delim[4] = "\0\0\0";
    int ci;

    for (int i = 0; i < (sizeof(msg) * 8) - 3; i++) {
        for(ci = 0; ci < 4; ci++) {
            delim[ci] = msg[i];
            if (delim[ci] != col_format->delim[ci])
            {
                delim[0] = delim[1] = delim[2] = '\0';
                break;
            }

            /** TODO: (Jeff) Find out how to lower complexity than O(i ** ci) */
        }
    }

    std::fprintf(stderr, "%s\n", newmsg);
    return;
}
