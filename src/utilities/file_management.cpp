#include "utilities/file_management.h"

Utils::File::File(const char* path) 
    : handle(nullptr), offset(0), is_open(false) {
    handle = std::fopen(path, "r+b");

    if (!handle) {
        handle = std::fopen(path, "w+b");
    }

    if (handle) {
        is_open = true;
    }
}

Utils::File::~File() {
    if (is_open) {
        std::fclose(handle);
        is_open = false;
    }
}

bool Utils::File::read(void* buffer, size_t size, size_t count) {
    if (!is_open) {
        return false;
    }

    size_t read_count = std::fread(buffer, size, count, handle);
    offset += read_count * size;
    return read_count == count;
}

bool Utils::File::write(const void* buffer, size_t size, size_t count) {
    if (!is_open) {
        return false;
    }

    size_t write_count = std::fwrite(buffer, size, count, handle);
    offset += write_count * size;
    return write_count == count;
}

bool Utils::File::close() {
    if (!is_open) {
        return false;
    }

    if (std::fclose(handle) == 0) {
        is_open = false;
        return true;
    }
    return false;
}

bool Utils::File::isOpen() {
    return is_open;
}