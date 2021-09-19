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

constexpr size_t strlength(const char *const c_str);

/**
 *@brief a tiny char array class,
 *       do not use the pointer of tinychars point to the derived class
 */
class tinychars {
    friend class chars;

public:
    tinychars();
    ~tinychars();
    // copy constructor
    tinychars(const tinychars &src);
    tinychars(const std::string &src);
    tinychars(const char *&src);
    tinychars(const char &ch);

    explicit tinychars(int num);
    explicit tinychars(unsigned int num);
    explicit tinychars(ssize_t num);
    explicit tinychars(size_t num);

    tinychars(const void *const ptr);

    // move constructor
    tinychars(tinychars &&robj);

    tinychars &operator=(const tinychars &src);
    tinychars &operator=(tinychars &&src);
    tinychars &operator=(const std::string &src);
    tinychars &operator=(const char ch);
    tinychars &operator=(const char src[]);

    inline const size_t length() const;
    inline const char *c_str() const;

    inline void clear();
    inline char *release();
    inline void assign(char *&src);
    inline void copy_data(const char *const src, const size_t length);

protected:
    /**
   *@brief 只允许构造函数调用
   *
   */
    inline void init();

protected:
    char *_data;
};

class chars : public tinychars {
    friend class tinychars;

public:
    chars();
    ~chars();

    static chars to_chars(unsigned int num);
    static chars to_chars(int num);
    static chars to_chars(size_t num);
    static chars to_chars(ssize_t num);
    static chars to_chars(const void *const ptr);

    /**
    *@brief 
    *
    *@return size_t length of the string
     */
    inline size_t length() const;

    /**
    *@brief 
    *
    *@return size_t size of the memory
     */
    inline size_t size() const;

    /**
    *@brief release holded data, and hold new data from src
    *
    *@param src 
    *@return chars 
     */
    inline chars assign(tinychars &src);

    inline void clear();
    inline char *release();

private:
    // _length = size of memory -1, '\0' = 1 byte
    size_t _length;
};

} // namespace seahorse
#endif