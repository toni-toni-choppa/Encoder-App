#include <cstdio>

#include "utilities/parse_arguments.h"

int main(int argc, char* argv[]) {
    char* input = Utils::parse_argument<char*>("--input", argc, argv);
    if (!input) {
        std::printf("[ERROR] Input file not specified. Specify with --input <file>\n");
        return 1;
    }

    char* output = Utils::parse_argument<char*>("--output", argc, argv);
    if (!output) {
        std::printf("[ERROR] Output file not specified. Specify with --output <file>\n");
        return 1;
    }
    
    return 0;
}