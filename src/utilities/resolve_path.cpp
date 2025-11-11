#include "utilities/resolve_path.h"

#include <filesystem>

namespace fs = std::filesystem;

char* Utils::resolve_path(char* path) {
    // Attempt to resolve the absolute path with realpath
    char* resolved = realpath(path, nullptr);
    if (resolved) {
        return resolved;
    }
    
    // Fallback: use std::filesystem to get the absolute path
    fs::path p(path);
    fs::path abs_path = fs::absolute(p);
    std::string abs_path_str = abs_path.string();
    
    resolved = (char*)malloc(abs_path_str.size() + 1);
    std::strcpy(resolved, abs_path_str.c_str());
    
    if (resolved) {
        return resolved;
    } else {
        free(resolved);
        return nullptr;
    }
}