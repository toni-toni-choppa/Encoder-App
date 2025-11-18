#ifndef ENCODER_VALIDATE_FILE_H
#define ENCODER_VALIDATE_FILE_H

#include "utilities/file_management.h"

namespace Encoder {
enum FileType {
    mp4,
    mov,
    Unknown
};

FileType validate_file_type(Utils::File& file);
}; // namespace Encoder

#endif // ENCODER_VALIDATE_FILE_H