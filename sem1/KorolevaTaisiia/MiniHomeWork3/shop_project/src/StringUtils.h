#pragma once


#include <string>
#include <sstream>
#include <algorithm>
#include <vector>


inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

inline void split_line(const std::string &s, char delim, std::vector<std::string> &result) {
    result.clear();
    std::stringstream ss(s);
    std::string item;
    while (getline(ss, item, delim)) {
        trim(item);
        result.push_back(item);
    }
}
inline void to_lower_case(std::string &string) {
    std::transform(string.begin(), string.end(), string.begin(), ::tolower);
}
inline void centralize(std::string &string, size_t new_size) {
    trim(string);
    if (string.size() < new_size) {
        string = std::string((new_size - string.size()) / 2, ' ') + string +
                 std::string(new_size - string.size() - ((new_size - string.size()) / 2), ' ');
    }
}
