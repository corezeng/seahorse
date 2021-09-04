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

class chars;

class tinychars {
public:
    tinychars();
    ~tinychars();
    // copy constructor
    tinychars(const tinychars& src);
    tinychars(const std::string& src);
    tinychars(const chars& src);
    tinychars(const char*& src);
    tinychars(const char& ch);

    explicit tinychars(ssize_t num);
    explicit tinychars(size_t num);

    tinychars(const void*& ptr);

    // move constructor 
    tinychars(tinychars&& robj);

    tinychars& operator=(const tinychars& src);
    tinychars& operator=(tinychars&& src);
    tinychars& operator=(const std::string& src);
    tinychars& operator=(const chars& src);
    tinychars& operator=(chars&& src);
    tinychars& operator=(const char ch);
    tinychars& operator=(const char src[]);

    const size_t length() const;
    const char* c_str() const;

    void clear();

    static tinychars to_tinychars(size_t num);
    static tinychars to_tinychars(ssize_t num);

private:
    /**
    *@brief 只允许构造函数调用
    *
     */
    inline void init();
    inline void copy_data(const char* const src, const size_t length);
    inline void hold_data(char*& src, const size_t length);

private:
    char* _data;
};

class chars : public tinychars {
public:
    chars();
    ~chars();

    const size_t length()const;
    void clear();

protected:
    void init();

private:
    size_t _length;
};

} // namespace seahorse
#endif