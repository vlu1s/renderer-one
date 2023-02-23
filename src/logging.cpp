#include "../include/logging.hpp"

void die(const char *txt, const int status)
{
    FILE *output = std::fopen("/dev/stderr", "w");
    char *err_msg = FILL_SPACE(txt, sizeof(char) * std);

    std::fprintf(output, "%s\n", txt);

    std::fclose(output);
    std::exit(status);
}
