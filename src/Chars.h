/**
 * @file Chars.h
 * @author zengkaijun (zengkaijun@xdrsec.com)
 * @brief 一个轻量的char数组类
 * @version 0.1
 * @date 2021-06-17
 * 
 * @copyright Copyright (c) 2021
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
class chars {
public:
#define self chars
    explicit self();
    ~self();
    self(const tinychars &src);
    self(const chars &src);
    self(const char *c_str);
    self(const char *c_str, const size_t length);
    self(const std::string &src);
    self(const bool boolen);
    self(const char ch);
    self(const short num);
    self(const int num);
    self(const size_t num);
    self(const float num);
    self(const double num);
    self(const void *ptr);

    void hold_from(self &src);        // 持有一个chars的_data，会调用src的release()成员函数
    char *release();                  // 释放_data，但不清空_data指向的数据
    const char *c_str() const;        // 传出_data指针
    void clean();                     // 清除内容
    void move_to(self &dest);         // 将内部_data移动至dest中，免去深拷贝开销
    const size_t length() const;      // 获取内容长度，
    self *dup_new() const;            // 传出一个内容相同的tinychars栈对象
    self &operator=(const self &obj); // 将obj中的数据深拷贝至本对象
    self &operator=(const tinychars &obj);
    self &operator=(const char *c_str);             // 将c_str中的数据深拷贝至本对象
    const bool operator==(const self &obj) const;   // 比较obj与本对象中数据，相同返回true，否则返回false
    const bool operator==(const char *c_str) const; // 比较c_str与本对象中数据，相同返回true，否则返回false
private:
    inline void set_data_length(const char
                                    *c_str,
                                const size_t length);
    inline void init();
    char *_data;
    size_t _length;
#undef self
};

class tinychars {
public:
#define self tinychars
    self();
    ~self();
    self(const tinychars &src);
    self(const chars &src);
    self(const char *c_str);
    self(const char *c_str, const size_t length);
    self(const std::string &src);
    self(const bool boolen); //  "true" or "false"
    self(const char ch);
    self(const short num);
    self(const int num);
    self(const size_t num);
    self(const float num);     // "1.23"
    self(const double num);    // "1.23"
    self(const void *ptr);     // nullptr: "nullptr", or: "0x0EF123AA"
    const char *c_str() const; // 传出_data指针

    void clean(); // 清除内容
    void hold_from(self &src);
    void move_to(self &dest);         // 将内部_data移动至dest中，免去深拷贝开销
    const size_t length() const;      // 获取内容长度，请注意，内部实现为非缓存，请避免频繁调用
    self *dup_new() const;            // 传出一个内容相同的tinychars栈对象
    self &operator=(const self &obj); // 将obj中的数据深拷贝至本对象
    self &operator=(const chars &obj);
    self &operator=(const char *c_str);             // 将c_str中的数据深拷贝至本对象
    const bool operator==(const self &obj) const;   // 比较obj与本对象中数据，相同返回true，否则返回false
    const bool operator==(const char *c_str) const; // 比较c_str与本对象中数据，相同返回true，否则返回false

private:
    inline void set_data_length(const char
                                    *c_str,
                                const size_t length);
    inline void init();

    char *_data;
#undef self
};

} // namespace seahorse
#else // C interface

#endif
#endif