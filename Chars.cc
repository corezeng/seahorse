#include "Chars.h"
#include <malloc.h>
#include <memory.h>
#include "Malloc.h"
#ifdef __cplusplus
using namespace seahorse;

chars::chars() {
    _data = nullptr;
    _length = 0;
}
chars ::~chars() {
    clean();
}

void chars::clean() {
    // if (_data != nullptr) {
    //     free(_data);
    //     _length = 0;
    // }
}

chars::chars(const char *c_str, const size_t length) {
    clean();
    _data = (char *)Malloc(length + 1);
    _length = length;
    memcpy(_data, c_str, length);
    _data[length] = '\0';
}

chars::chars(const tinychars &src) {
    _length = src.length();
    chars(src.c_str(), _length);
}

chars::chars(const char *c_str) {
    size_t len = strlen(c_str);
    chars(c_str, len);
}

chars::chars(const std::string &src) {
    chars(src.c_str(), src.length());
}

chars::chars(const bool boolen) {
    if (boolen) {
        chars(STR_TRUE, STR_TRUE_LEN);
    } else {
        chars(STR_FALSE, STR_FALSE_LEN);
    }
}

chars::chars(const char ch) {
    chars(&ch, 1);
}

chars::chars(const short num) {
    chars(std::to_string(num));
}

chars::chars(const int num) {
    chars(std::to_string(num));
}

chars::chars(const size_t num) {
    chars(std::to_string(num));
}

chars::chars(const float num) {
    chars(std::to_string(num));
}

chars::chars(const double num) {
    chars(std::to_string(num));
}

chars::chars(const void *ptr) {
    if (ptr != nullptr) {
        // TODO: 添加void* 数据转string
    } else {
        chars(STR_NULLPTR, STR_NULLPTR_LEN);
    }
}

const char *chars::c_str() const {
    return _data;
}

char *chars::release() {
    char *ptr = _data;
    _data = nullptr;
    _length = 0;
    return ptr;
}

void chars::hold_from(chars &src) {
    clean();
    _length = src._length;
    _data = src.release();
}

void chars::move_to(chars &dest) {
    dest.hold_from(*this);
}

const size_t chars::length() const {
    return _length;
}

chars *chars::dup_new() const { // TODO 最好的方式是返回一个栈对象unique_ptr，以避免调用者不持有返回值，详情见seahorse/cpp_test/unique_ptr_stack_object_life_cycle.cc
    return new chars(this);
}

chars &chars::operator=(const chars &obj) {
    clean();
    _data = (char *)Malloc(obj._length + 1);
    _length = obj._length;
    memcpy(_data, obj._data, obj._length);
    _data[_length] = '\0';
    return *this;
}

chars &chars::operator=(const tinychars &obj) {
    clean();
    _data = (char *)Malloc(obj.length() + 1);
    _length = obj.length();
    memcpy(_data, obj.c_str(), obj.length());
    _data[_length] = '\0';
    return *this;
}

chars &chars::operator=(const char *c_str) {
    if (c_str != nullptr) {
        size_t len = strlen(c_str);
        _data = (char *)Malloc(len + 1);
        _length = len;
        memcpy(_data, c_str, len);
        _data[_length] = '\0';
    }

    return *this;
}

const bool chars::operator==(const chars &obj) const {
    if (_length != obj._length) {
        return false;
    } else {
        if (obj._length == 0 || _length == 0) {
            return true;
        } else {
            return strcmp(_data, obj._data) == 0 ? true : false;
        }
    }
}

const bool chars::operator==(const char *c_str) const {
    size_t len = strlen(c_str);
    if (len != _length) {
        return false;
    } else {
        if (len == 0 || _length == 0) {
            return false;
        } else {
            return strcmp(c_str, _data) == 0 ? true : false;
        }
    }
}

tinychars::tinychars() {
    _data = nullptr;
}

void tinychars::clean() {
    if (_data != nullptr) {
        free(_data);
        _data = nullptr;
    }
}

tinychars::~tinychars() {
    clean();
}

tinychars::tinychars(const char *c_str, const size_t length) {
    clean();
    _data = (char *)Malloc(length + 1);
    memcpy(_data, c_str, length);
    _data[length] = '\0';
}

tinychars::tinychars(const tinychars &src) {
    tinychars(src._data, src.length());
}

tinychars::tinychars(const chars &src) {
    tinychars(src.c_str(), src.length());
}

tinychars::tinychars(const char *c_str) {
    tinychars(c_str, strlen(c_str));
}

tinychars::tinychars(const std::string &src) {
    tinychars(src.c_str(), src.length());
}

tinychars::tinychars(const bool boolen) {
    if (boolen) {
        tinychars(STR_TRUE, STR_TRUE_LEN);
    } else {
        tinychars(STR_FALSE, STR_FALSE_LEN);
    }
}

tinychars::tinychars(const char ch) {
    tinychars(&ch, 1);
}

tinychars::tinychars(const short num) {
    tinychars(std::to_string(num));
}

tinychars::tinychars(const int num) {
    tinychars(std::to_string(num));
}

tinychars::tinychars(const size_t num) {
    tinychars(std::to_string(num));
}

tinychars::tinychars(const float num) {
    tinychars(std::to_string(num));
}

tinychars::tinychars(const double num) {
    tinychars(std::to_string(num));
}

tinychars::tinychars(const void *ptr) {
    if (ptr != nullptr) {
        // TODO: 添加void* 数据转string
    } else {
        tinychars(STR_NULLPTR, STR_NULLPTR_LEN);
    }
}

const char *tinychars::c_str() const {
    return _data;
}

void tinychars::hold_from(tinychars &src) {
    clean();
    _data = src._data;
    src.clean();
}

void tinychars::move_to(tinychars &dest) {
    dest.hold_from(*this);
}

const size_t tinychars::length() const {
    if (_data != nullptr) {
        return strlen(_data);
    } else {
        return 0;
    }
}

tinychars *tinychars::dup_new() const {
    return new tinychars(*this);
}

tinychars &tinychars::operator=(const tinychars &obj) {
    tinychars(obj._data);
    return *this;
}

tinychars &tinychars::operator=(const chars &obj) {
    tinychars(obj.c_str(), obj.length());
    return *this;
}

tinychars &tinychars::operator=(const char *c_str) {
    if (c_str != nullptr) {
        size_t len = strlen(c_str);
        _data = (char *)Malloc(len + 1);
        memcpy(_data, c_str, len);
        _data[len] = '\0';
    } else {
        // TODO something else
    }
    return *this;
}

const bool tinychars::operator==(const tinychars &obj) const {
    if (_data != nullptr && obj._data != nullptr) {
        return strcmp(_data, obj._data) == 0 ? true : false;
    } else {
        if (_data == nullptr && obj == nullptr) {
            return true;
        } else {
            return false;
        }
    }
}

const bool tinychars::operator==(const char *c_str) const {
    if (_data != nullptr && c_str != nullptr) {
        return strcmp(_data, c_str) == 0 ? true : false;
    } else {
        if (_data == nullptr && c_str == nullptr) {
            return true;
        } else {
            return false;
        }
    }
}

#endif
#ifdef __libc
#endif