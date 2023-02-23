#include "../include/logging.hpp"

void die(const char *txt, const int status)
{
    std::fprintf(stderr, "%s\n", txt);
    std::exit(status);
}

void error_callback(const char *msg, const int error)
{
    std::fprintf(stderr, "Error: %s\n", msg);
}

void color_warn(const char *msg, const colour_t *col_format, const uint severity)
{
    // TODO: (Jeff) Define the function.
}
