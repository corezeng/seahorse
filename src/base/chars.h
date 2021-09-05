/**
*@file Chars.h
*@author core zeng (corezeng@gmail.com)
*@brief 简单的 char 数组类
*@version 0.1
*@date 2021-07-12
*
*@copyright Copyright (c) 2021
*
 */

#ifndef SEAHORSE_CHARS_H
#define SEAHORSE_CHARS_H

#include <cstddef>
#include <string>

namespace seahorse {

constexpr size_t strlength(const char* const c_str);

class chars final {
public:
    chars();
    ~chars();
    // copy constructor
    chars(const chars& src);
    chars(const std::string& src);
    chars(const char*& src);
    chars(const char& ch);

    explicit chars(int num);
    explicit chars(unsigned int num);
    explicit chars(ssize_t num);
    explicit chars(size_t num);

    chars(const void* const ptr);

    // move constructor 
    chars(chars&& robj);

    chars& operator=(const chars& src);
    chars& operator=(chars&& src);
    chars& operator=(const std::string& src);
    chars& operator=(const char ch);
    chars& operator=(const char src[]);

    const size_t length() const;
    const char* c_str() const;

    void clear();
    char* release();

    static chars to_chars(unsigned int num);
    static chars to_chars(int num);
    static chars to_chars(size_t num);
    static chars to_chars(ssize_t num);
    static chars to_chars(const void* const ptr);

private:
    /**
    *@brief 只允许构造函数调用
    *
     */
    inline void init();
    inline void copy_data(const char* const src, const size_t length);
    inline void hold_data(char*& src);

private:
    char* _data;
};

} // namespace seahorse
#endif