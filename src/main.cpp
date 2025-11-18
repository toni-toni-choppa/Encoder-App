#include <cstdio>
#include <cstdlib>
#include <unistd.h>

#include "utilities/parse_arguments.h"
#include "utilities/resolve_path.h"
#include "utilities/file_management.h"
#include "encoder/validate_file.h"

int main(int argc, char* argv[]) {
    // Get Input Argument and File Path
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

    // Validate Input File Type
    if (realpath(input_path, nullptr) == nullptr) {
        std::printf("[ERROR] Input file does not exist: %s\n", input_path);
        return 1;
    }

    Utils::File input_file(input_path);
    if (!input_file.isOpen()) {
        std::printf("[ERROR] Unable to open input file: %s\n", input_path);
        return 1;
    }

    Encoder::FileType file_type = Encoder::validate_file_type(input_file);
    if (file_type == Encoder::Unknown) {
        std::printf("[ERROR] Unsupported input file type: %s\n", input_path);
        return 1;
    } else {
        std::printf("[INFO] '%s' is a(n) '%s' file\n", input_path,
            (file_type == Encoder::mp4) ? "MPEG-4 Part 14" : "QuickTime Movie");
    }

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