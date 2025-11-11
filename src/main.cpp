#include <cstdio>

#include "utilities/parse_arguments.h"
#include "utilities/resolve_path.h"

int main(int argc, char* argv[]) {
    char* input = Utils::parse_argument<char*>("--input", argc, argv);
    if (!input) {
        std::printf("[ERROR] Input file not specified. Specify with --input <file>\n");
        return 1;
    }
    
    char* input_path = Utils::resolve_path(input);
    if (!input_path) {
        std::printf("[ERROR] Failed to resolve input file path: %s\n", input);
        return 1;
    }
    std::printf("[INFO] Resolved input path: %s\n", input_path);

    char* output = Utils::parse_argument<char*>("--output", argc, argv);
    if (!output) {
        std::printf("[ERROR] Output file not specified. Specify with --output <file>\n");
        return 1;
    }

    char* output_path = Utils::resolve_path(output);
    if (!output_path) {
        std::printf("[ERROR] Failed to resolve output file path: %s\n", output);
        return 1;
    }
    std::printf("[INFO] Resolved output path: %s\n", output_path);

    return 0;
}