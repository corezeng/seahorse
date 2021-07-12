#include "Chars.h"
#include <malloc.h>
#include <memory.h>
#include "Malloc.h"
#include "Utils.h"

#ifdef __cplusplus
using namespace seahorse;
tinychars::tinychars() {
    init();
}

tinychars::~tinychars() {
    clear();
}

tinychars::tinychars(const tinychars &src) {
    init();
    if (src._data != nullptr) {
        set_data(src._data, src.length());
    } else {
    }
}

tinychars::tinychars(const std::string &src) {
    init();
    const size_t srcLen = src.length();
    if (srcLen > 0) {
        set_data(src.c_str(), srcLen);
    } else {
        // TODO empty string object
    }
}

tinychars::tinychars(const char *const src) {
    init();
    if (src != nullptr) {
        set_data(src, strlen(src));
    } else {
        // TODO nullptr point to char
    }
}

tinychars::tinychars(const char &ch) {
    init();
    set_data(&ch, 1);
}

tinychars::tinychars(const short num) {
    init();
    std::string tmp = std::to_string(num); // TODO 此处可优化性能
    set_data(tmp.c_str(), tmp.length());
}

tinychars::tinychars(const unsigned short num) {
    init();
    std::string tmp = std::to_string(num); // TODO 此处可优化性能
    set_data(tmp.c_str(), tmp.length());
}

tinychars::tinychars(const int num) {
    init();
    std::string tmp = std::to_string(num); // TODO 此处可优化性能
    set_data(tmp.c_str(), tmp.length());
}
tinychars::tinychars(const unsigned int num) {
    init();
    std::string tmp = std::to_string(num); // TODO 此处可优化性能
    set_data(tmp.c_str(), tmp.length());
}

tinychars::tinychars(const void *const ptr) {
    init();
    char buf[BIT64_POINTER_0X_LEN + 1]; // TODO 最好需检查平台架构(32bit/64bit)
    snprintf(buf, sizeof(buf), "%016p", ptr);
    set_data(buf, BIT64_POINTER_0X_LEN);
}

void tinychars::init() {
    _data = nullptr;
}

void tinychars::set_data(const char *const src, const size_t length) {
    if (_data != nullptr) {
        clear();
    }
    _data = (char *)Malloc(length + 1);
    memcpy(_data, src, length);
    _data[length] = '\0';
}

const size_t tinychars::length() const {
    if (_data == nullptr) {
        return 0;
    } else {
        return strlen(_data);
    }
}

#endif