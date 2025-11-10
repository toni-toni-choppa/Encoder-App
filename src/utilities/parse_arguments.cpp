#include "utilities/parse_arguments.h"

#include <cstring>

template <>
char* Utils::parse_argument<char*>(const char* arg, int argc, char* argv[]) {
    for (int i = 1; i < argc - 1; ++i) {
        if (std::strcmp(argv[i], arg) == 0) {
            return argv[i + 1];
        }
    }
    return nullptr;
}