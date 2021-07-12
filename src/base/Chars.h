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

#ifdef __cplusplus
#include <cstdint>
#include <cstddef>
#include <memory>
#include <cstring>
namespace seahorse {

const char STR_TRUE[] = "true";
const size_t STR_TRUE_LEN = strlen(STR_TRUE);
const char STR_FALSE[] = "false";
const size_t STR_FALSE_LEN = strlen(STR_FALSE);
const char STR_NULLPTR[] = "nullptr";
const size_t STR_NULLPTR_LEN = strlen(STR_NULLPTR);

class tinychars;

/**
 * @brief 
 * 
 */
class chars : public tinychars {
public:
private:
};

class tinychars {
public:
    tinychars();
    ~tinychars();
    tinychars(const tinychars &src);
    tinychars(const std::string &src);
    tinychars(const chars &src);

    tinychars(const char *const src);
    tinychars(const char &ch);

    tinychars(const short num);
    tinychars(const unsigned short num);

    tinychars(const int num);
    tinychars(const unsigned int num);

    tinychars(const void *const ptr);

    tinychars &operator=(const tinychars &src);
    tinychars &operator=(const std::string &src);
    tinychars &operator=(const chars &src);
    tinychars &operator=(const char ch);
    tinychars &operator=(const char src[]);

    inline const size_t length() const;
    static tinychars to_tinchars();

private:
    /**
    *@brief 只允许构造函数调用
    *
     */
    inline void init();
    /**
    *@brief 清空 _data 并将其设为 nullptr
    *
     */
    inline void clear();
    /**
    *@brief 将 src 中数据拷贝至 _data 
    *
    *@param src 源数据
    *@param length 
     */
    inline void set_data(const char *const src, const size_t length);
    char *_data;
};

} // namespace seahorse
#else // C interface

#endif
#endif