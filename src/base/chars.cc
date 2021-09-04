
#include<memory.h>
#include"malloc.h"
#include<threads.h>
#include"chars.h"

#include<iostream>

namespace seahorse {

constexpr size_t strlength(const char* const c_str) {
    return strlen(c_str);
}

tinychars::tinychars() {
    init();
}

tinychars::~tinychars() {
    clear();
}

tinychars::tinychars(const tinychars& src) {
    init();
    copy_data(src._data, src.length());
}

tinychars::tinychars(const std::string& src) {
    init();
    copy_data(src.c_str(), src.length());
}

tinychars::tinychars(const chars& src) {
    init();
    copy_data(src._data, src.length());
}

tinychars::tinychars(const char*& src) {
    init();
    copy_data(src, strlen(src));
}

tinychars::tinychars(const char& ch) {
    init();
    copy_data(&ch, 2);
    _data[1] = '\0';
}

tinychars::tinychars(ssize_t num) {
    init();
    tinychars&& tmp = to_tinychars(num);
    hold_data(tmp._data, tmp.length());
}

tinychars::tinychars(size_t num) {
    init();
    tinychars&& tmp = to_tinychars(num);
    hold_data(tmp._data, tmp.length());
}

tinychars::tinychars(const void*& ptr) {

}

tinychars::tinychars(tinychars&& robj) {
    init();
    if (robj._data != nullptr) {
        hold_data(robj._data, robj.length());
        robj._data = nullptr;
    }
}

tinychars& tinychars::operator=(const tinychars& src) {
    if (&src != this) {
        clear();
        copy_data(src._data, src.length());
    }
    return *this;
}

tinychars& tinychars::operator=(tinychars&& src) {
    clear();
    hold_data(src._data, src.length());
    src._data = nullptr;
    return *this;
}

tinychars& tinychars::operator=(const std::string& src) {
    clear();
    copy_data(src.c_str(), src.length());
    return *this;
}

tinychars& tinychars::operator=(const chars& src) {
    clear();
    copy_data(src.c_str(), src.length());
    return *this;
}

tinychars& tinychars::operator=(chars&& src) {
    clear();
    hold_data(src._data, src.length());
    src._data = nullptr;
    src.clear();
    return *this;
}

tinychars& tinychars::operator=(const char ch) {
    clear();
    copy_data(&ch, 2);
    _data[1] = '\0';
    return *this;
}

tinychars& tinychars::operator=(const char src[]) {
    clear();
    copy_data(src, strlength(src));
    return *this;
}

inline void tinychars::init() {
    _data = nullptr;
}

inline void tinychars::clear() {
    if (_data != nullptr) {
        free(_data);
        _data = nullptr;
    }
}

inline const size_t tinychars::length() const {
    if (_data != nullptr) {
        return strlength(_data);
    }
    else {
        return 0;
    }
}

inline const char* tinychars::c_str()const {
    return _data;
}

inline void tinychars::copy_data(const char* const src, const size_t length) {
    clear();
    _data = (char*)Malloc(length);
    memcpy(_data, src, length);
}

inline void tinychars::hold_data(char*& src, const size_t length) {
    clear();
    _data = src;
    src = nullptr;
}

tinychars tinychars::to_tinychars(size_t num) {
    tinychars obj;
    if (obj.length() != 0) {
        obj.clear();
    }
    char buf1[sizeof(size_t) * 4];
    char buf2[sizeof(size_t) * 4];
    // snprintf(buf2, sizeof(size_t) * 4, "%lu", num);

    int i = 0, j = 0;

    if (num == 0) {
        buf1[i] = '0';
        ++i;
    }
    while (num > 0) {
        buf1[i] = num % 10 + '0';
        num /= 10;
        ++i;
    }
    buf1[i] = '\0';
    i -= 1;
    while (i >= 0) {
        buf2[j] = buf1[i];
        ++j;
        --i;
    }
    buf2[j] = '\0';
    obj = buf2;
    return obj;
}

tinychars tinychars::to_tinychars(ssize_t num) {
    tinychars obj;
    if (obj.length() != 0) {
        obj.clear();
    }
    char buf1[sizeof(ssize_t) * 4];
    char buf2[sizeof(ssize_t) * 4];
    int i = 0, j = 0;
    if (num < 0) {
        num = 0 - num;
        j = 1;
        buf2[0] = '-';
    }
    if (num == 0) {
        buf1[i] = '0';
        ++i;
    }
    while (num > 0) {
        buf1[i] = num % 10 + '0';
        num /= 10;
        ++i;
    }
    buf1[i] = '\0';
    i -= 1;
    while (i >= 0) {
        buf2[j] = buf1[i];
        ++j;
        --i;
    }
    buf2[j] = '\0';
    obj = buf2;
    return obj;
}


chars::chars() {
    this->init();
}

chars::~chars() {
    this->clear();
}

inline const size_t chars::length()const {
    return _length;
}

inline void chars::init() {
    _length = 0;
}

inline void chars::clear() {
    if (_length != 0) {
        tinychars::clear();
        _length = 0;
    }
}

}