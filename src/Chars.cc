#include "Chars.h"
#include <malloc.h>
#include <memory.h>
#include "Malloc.h"
#ifdef __cplusplus
using namespace seahorse;

chars::chars() {
    init();
}
chars ::~chars() {
    clean();
}

void chars::init() {
    _data = nullptr;
    _length = 0;
}

void chars::set_data_length(const char *c_str, const size_t length) {
    if (length > 0) {
        if (c_str != nullptr) {
            clean();
            _data = (char *)Malloc(length + 1);
            _length = length;
            memcpy(_data, c_str, length);
            _data[length] = '\0';
        }
    } else {
        clean();
    }
}

void chars::clean() {
    if (_data != nullptr) {
        free(_data);
        _length = 0;
    }
}

chars::chars(const char *c_str, const size_t length) {
    init();
    set_data_length(c_str, length);
}

chars::chars(const tinychars &src) {
    init();
    _length = src.length();
    set_data_length(src.c_str(), _length);
}

chars::chars(const chars &src) {
    init();
    _length = src._length;
    set_data_length(src._data, src._length);
}

chars::chars(const char *c_str) {
    init();
    size_t len = strlen(c_str);
    set_data_length(c_str, len);
}

chars::chars(const std::string &src) {
    init();
    set_data_length(src.c_str(), src.length());
}

chars::chars(const bool boolen) {
    init();
    if (boolen) {
        set_data_length(STR_TRUE, STR_TRUE_LEN);
    } else {
        set_data_length(STR_FALSE, STR_FALSE_LEN);
    }
}

chars::chars(const char ch) {
    init();
    set_data_length(&ch, 1);
}

chars::chars(const short num) {
    init();
    std::string tmp = std::to_string(num);
    set_data_length(tmp.c_str(), tmp.length());
}

chars::chars(const int num) {
    init();
    std::string tmp = std::to_string(num);
    set_data_length(tmp.c_str(), tmp.length());
}

chars::chars(const size_t num) {
    init();
    std::string tmp = std::to_string(num);
    set_data_length(tmp.c_str(), tmp.length());
}

chars::chars(const float num) {
    init();
    std::string tmp = std::to_string(num);
    set_data_length(tmp.c_str(), tmp.length());
}

chars::chars(const double num) {
    init();
    std::string tmp = std::to_string(num);
    set_data_length(tmp.c_str(), tmp.length());
}

chars::chars(const void *ptr) {
    init();
    if (ptr != nullptr) {
        // TODO: 添加void* 数据转string
    } else {
        set_data_length(STR_NULLPTR, STR_NULLPTR_LEN);
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
    set_data_length(obj._data, obj._length);
    return *this;
}

chars &chars::operator=(const tinychars &obj) {
    clean();
    set_data_length(obj.c_str(), obj.length());
    return *this;
}

chars &chars::operator=(const char *c_str) {
    clean();
    if (c_str != nullptr) {
        size_t len = strlen(c_str);
        set_data_length(c_str, len);
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
    init();
}

void tinychars::init() {
    _data = nullptr;
}

void tinychars::clean() {
    if (_data != nullptr) {
        free(_data);
        _data = nullptr;
    }
}

void tinychars::set_data_length(const char
                                    *c_str,
                                const size_t length) {
    clean();
    _data = (char *)Malloc(length + 1);
    memcpy(_data, c_str, length);
    _data[length] = '\0';
}

tinychars::~tinychars() {
    clean();
}

tinychars::tinychars(const char *c_str, const size_t length) {
    init();
    set_data_length(c_str, length);
}

tinychars::tinychars(const tinychars &src) {
    init();
    set_data_length(src._data, src.length());
}

tinychars::tinychars(const chars &src) {
    init();
    set_data_length(src.c_str(), src.length());
}

tinychars::tinychars(const char *c_str) {
    init();
    set_data_length(c_str, strlen(c_str));
}

tinychars::tinychars(const std::string &src) {
    init();
    set_data_length(src.c_str(), src.length());
}

tinychars::tinychars(const bool boolen) {
    init();
    if (boolen) {
        set_data_length(STR_TRUE, STR_TRUE_LEN);
    } else {
        set_data_length(STR_FALSE, STR_FALSE_LEN);
    }
}

tinychars::tinychars(const char ch) {
    init();
    set_data_length(&ch, 1);
}

tinychars::tinychars(const short num) {
    init();
    std::string tmp = std::to_string(num);
    set_data_length(tmp.c_str(), tmp.length());
}

tinychars::tinychars(const int num) {
    init();
    std::string tmp = std::to_string(num);
    set_data_length(tmp.c_str(), tmp.length());
}

tinychars::tinychars(const size_t num) {
    init();
    std::string tmp = std::to_string(num);
    set_data_length(tmp.c_str(), tmp.length());
}

tinychars::tinychars(const float num) {
    init();
    std::string tmp = std::to_string(num);
    set_data_length(tmp.c_str(), tmp.length());
}

tinychars::tinychars(const double num) {
    init();
    std::string tmp = std::to_string(num);
    set_data_length(tmp.c_str(), tmp.length());
}

tinychars::tinychars(const void *ptr) {
    init();
    if (ptr != nullptr) {
        // TODO: 添加void* 数据转string
    } else {
        set_data_length(STR_NULLPTR, STR_NULLPTR_LEN);
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
    clean();
    set_data_length(obj._data, obj.length());
    return *this;
}

tinychars &tinychars::operator=(const chars &obj) {
    clean();
    set_data_length(obj.c_str(), obj.length());
    return *this;
}

tinychars &tinychars::operator=(const char *c_str) {
    clean();
    if (c_str != nullptr) {
        size_t len = strlen(c_str);
        set_data_length(c_str, len);
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