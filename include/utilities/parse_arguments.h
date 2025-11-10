#ifndef UTILITIES_PARSE_ARGUMENTS_H
#define UTILITIES_PARSE_ARGUMENTS_H

namespace Utils {
template <typename T>
T parse_argument(const char* arg, int argc, char* argv[]);

template <>
char* parse_argument<char*>(const char* arg, int argc, char* argv[]);
} // namespace Utils

#endif // UTILITIES_PARSE_ARGUMENTS_H