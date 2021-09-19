#include <memory.h>
#include "malloc.h"
#include "chars.h"
#include "utils.h"

namespace seahorse {

inline constexpr size_t strlength(__restrict_arr const char *const c_str) {
    return strlen(c_str);
}
tinychars::tinychars() {
    init();
}

tinychars::~tinychars() {
    clear();
}

tinychars::tinychars(const tinychars &src) {
    init();
    copy_data(src._data, src.length());
}

tinychars::tinychars(const std::string &src) {
    init();
    copy_data(src.c_str(), src.length());
}

tinychars::tinychars(const char *&src) {
    init();
    if (src != nullptr) {
        copy_data(src, strlen(src));
    } else {
        copy_data("nullptr", strlength("nullptr"));
    }
}

tinychars::tinychars(const char &ch) {
    init();
    copy_data(&ch, 2);
    _data[1] = '\0';
}

tinychars::tinychars(int num) {
    init();
    chars tmp = chars::to_chars(num);
    assign(tmp._data);
    tmp._data = nullptr;
}

tinychars::tinychars(unsigned int num) {
    init();
    chars tmp = chars::to_chars(num);
    assign(tmp._data);
    tmp._data = nullptr;
}

tinychars::tinychars(ssize_t num) {
    init();
    chars tmp = chars::to_chars(num);
    assign(tmp._data);
    tmp._data = nullptr;
}

tinychars::tinychars(size_t num) {
    init();
    chars tmp = chars::to_chars(num);
    assign(tmp._data);
    tmp._data = nullptr;
}

tinychars::tinychars(const void *const ptr) {
    chars tmp = chars::to_chars(ptr);
    assign(tmp._data);
    tmp._data = nullptr;
}

tinychars::tinychars(tinychars &&robj) {
    init();
    if (robj._data != nullptr) {
        assign(robj._data);
        robj._data = nullptr;
    }
}

tinychars &tinychars::operator=(const tinychars &src) {
    if (&src != this) {
        clear();
        copy_data(src._data, src.length());
    }
    return *this;
}

tinychars &tinychars::operator=(tinychars &&src) {
    clear();
    assign(src._data);
    src._data = nullptr;
    return *this;
}

tinychars &tinychars::operator=(const std::string &src) {
    clear();
    copy_data(src.c_str(), src.length());
    return *this;
}

tinychars &tinychars::operator=(const char ch) {
    clear();
    copy_data(&ch, 2);
    _data[1] = '\0';
    return *this;
}

tinychars &tinychars::operator=(const char src[]) {
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

inline char *tinychars::release() {
    char *ret = _data;
    _data = nullptr;
    return ret;
}

inline const size_t tinychars::length() const {
    if (_data != nullptr) {
        return strlength(_data);
    } else {
        return 0;
    }
}

const char *tinychars::c_str() const {
    return _data;
}

inline void tinychars::copy_data(const char *const src, const size_t length) {
    clear();
    _data = (char *)Malloc(length);
    memcpy(_data, src, length);
}

inline void tinychars::assign(char *&src) {
    clear();
    _data = src;
    src = nullptr;
}

chars chars::to_chars(register unsigned int num) {
    chars obj;
    __restrict_arr char buf1[sizeof(unsigned int) * 4];
    __restrict_arr char buf2[sizeof(unsigned int) * 4];
    register int i = 0;
    register int j = 0;

    if (__glibc_unlikely(num == 0)) {
        buf1[i] = '0';
        ++i;
    }

    while (num > 0) {
        buf1[i] = num % 10 + '0';
        ++i;
        num /= 10;
    }

    buf1[i] = '\0';
    obj._length = i;
    i -= 1;
    while (i >= 0) {
        buf2[j] = buf1[i];
        ++j;
        --i;
    }

    buf2[j] = '\0';
    obj.copy_data(buf2, obj._length + 1);
    return obj;
}

chars chars::to_chars(register int num) {
    chars obj;
    __restrict_arr char buf1[sizeof(int) * 4];
    __restrict_arr char buf2[sizeof(ssize_t) * 4];
    register int i = 0;
    register int j = 0;
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
        ++i;
        num /= 10;
    }
    buf1[i] = '\0';
    obj._length = i;
    i -= 1;
    while (i >= 0) {
        buf2[j] = buf1[i];
        ++j;
        --i;
    }

    buf2[j] = '\0';
    obj.copy_data(buf2, obj._length);
    return obj;
}

chars chars::to_chars(register size_t num) {
    chars obj;
    register __restrict_arr char buf1[sizeof(size_t) * 4];
    __restrict_arr char buf2[sizeof(ssize_t) * 4];
    register int i = 0;
    register int j = 0;

    if (__glibc_unlikely(num == 0)) {
        buf1[i] = '0';
        ++i;
    }
    while (num > 0) {
        buf1[i] = num % 10 + '0';
        num /= 10;
        ++i;
    }
    buf1[i] = '\0';
    obj._length = i;
    i -= 1;
    while (i >= 0) {
        buf2[j] = buf1[i];
        ++j;
        --i;
    }

    buf2[j] = '\0';
    obj.copy_data(buf2, obj._length);
    return obj;
}

chars chars::to_chars(register ssize_t num) {
    chars obj;
    __restrict_arr char buf1[sizeof(ssize_t) * 4];
    __restrict_arr char buf2[sizeof(ssize_t) * 4];
    register int i = 0;
    register int j = 0;
    if (num < 0) {
        num = 0 - num;
        j = 1;
        buf2[0] = '-';
    }
    if (__glibc_unlikely(num == 0)) {
        buf1[i] = '0';
        ++i;
    }
    while (num > 0) {
        buf1[i] = num % 10 + '0';
        num /= 10;
        ++i;
    }
    buf1[i] = '\0';
    obj._length = i;
    i -= 1;
    while (i >= 0) {
        buf2[j] = buf1[i];
        ++j;
        --i;
    }

    buf2[j] = '\0';
    obj.copy_data(buf2, obj._length + 1);
    return obj;
}

chars chars::to_chars(register const void *const ptr) {
    chars obj;
    __restrict_arr char buf[POINTER_0X_LEN + 1];
#if UINTPTR_MAX == 0xffffffff
    snprintf(buf, POINTER_0X_LEN + 1, "%08p'\0", ptr);
#elif UINTPTR_MAX == 0xffffffffffffffff
    snprintf(buf, POINTER_0X_LEN + 1, "%016p'\0", ptr);
#else

#endif
    obj._length = strlen(buf);
    obj.copy_data(buf, obj._length + 1);
    return obj;
}

chars::chars() :
    tinychars() {
    _length = 0;
}

chars::~chars() {
    _length = 0;
}

size_t chars::length() const {
    return _length;
}

size_t chars::size() const {
    if (_length != 0) {
        return _length + 1;
    } else {
        return 0;
    }
}

chars chars::assign(tinychars &src) {
    chars ret;
    ret._data = tinychars::_data;
    ret._length = _length;

    tinychars::_data = src._data;
    _length = src.length();

    src._data = nullptr;

    return ret;
}

void chars::clear() {
    tinychars::clear();
    _length = 0;
}

char *chars::release() {
    _length = 0;
    return tinychars::release();
}

} // namespace seahorse