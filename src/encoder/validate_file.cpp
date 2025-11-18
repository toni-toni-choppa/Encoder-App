#include "encoder/validate_file.h"

#include <cstring>
#include "utilities/file_management.h"

Encoder::FileType Encoder::validate_file_type(Utils::File& file) {
    // Read the file header
    char header[12];
    if (!file.read(header, sizeof(header), 1)) {
        return Encoder::Unknown;
    }

    char box_size[4];
    char box_type[4];
    char major_brand[4];

    // Parse the box size and type
    std::memcpy(box_size, header, 4);
    std::memcpy(box_type, header + 4, 4);

    // Check if box type is 'ftyp'
    if (memcmp(box_type, "ftyp", 4) == 0) {
        std::memcpy(major_brand, header + 8, 4);
        // Check for MP4
        if (memcmp(major_brand, "isom", 4) == 0 ||
            memcmp(major_brand, "iso2", 4) == 0 ||
            memcmp(major_brand, "avc1", 4) == 0 ||
            memcmp(major_brand, "mp41", 4) == 0 ||
            memcmp(major_brand, "mp42", 4) == 0) {
            return Encoder::mp4;
        }
        // Check for QuickTime
        else if (memcmp(major_brand, "qt  ", 4) == 0) {
            return Encoder::mov;
        }
    }

    return Encoder::Unknown;
}