/**
*@file buffer.h
*@author core zeng (corezeng@gmail.com)
*@brief a buffer class
*@version 0.1
*@date 2021-09-17
*
*@copyright Copyright (c) 2021
*
 */
#ifndef _SEAHORSE_BASE_BUFFER_H_
#define _SEAHORSE_BASE_BUFFER_H_

#include "chars.h"

namespace seahorse {
class Buffer {
public:
    Buffer();
    Buffer(const size_t max_size);
    ~Buffer();

    /**
    *@brief return C style buffer (char*), for some C functions
    *
    *@return char* 
     */
    inline char *c_buf();

    inline void set_max_size(const size_t max_size);

    inline size_t get_current_size() const;

    inline size_t get_max_size() const;

    Buffer &operator<<(const chars &msg);
    Buffer &operator<<(const char &word);
    Buffer &operator<<(const char *&msg);
    Buffer &operator<<(const bool boolen);
    Buffer &operator<<(const short num);
    Buffer &operator<<(const unsigned int num);
    Buffer &operator<<(const int num);
    Buffer &operator<<(const size_t num);
    Buffer &operator<<(const ssize_t num);
    Buffer &operator<<(const void *ptr);

private:
    char *_data;
    // 用于存放 _data 无法存下的数据
    char *_trailer;
    size_t _current_size;
    size_t _max_size;
};
} // namespace seahorse

#endif