#ifndef UTILITIES_FILE_MANAGEMENT_H
#define UTILITIES_FILE_MANAGEMENT_H

#include <cstdio>
#include <cstddef>
#include <cstdint>

namespace Utils {
class File {
    public:
        File(const char* path);
        ~File();

        bool read(void* buffer, size_t size, size_t count);
        bool write(const void* buffer, size_t size, size_t count);
        bool isOpen();
        bool close();
    private:
        FILE* handle;
        uint64_t offset;
        bool is_open;
};
} // namespace Utils

#endif // UTILITIES_FILE_MANAGEMENT_H