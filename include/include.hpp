#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#include <string>

inline int mean(std::vector<int> a)
{
    int f = 0;
    for (int i = 0; i < a.size(); i++)
    {
        f += a[i];
    }
    f = f / a.size();
    return f;
}

inline std::string reverseStr(std::string &input)
{
    std::string str = input;
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        std::swap(str[i], str[n - i - 1]);

    return str;
}

#endif