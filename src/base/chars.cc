#include<memory.h>
#include"malloc.h"
#include"chars.h"
#include"utils.h"


namespace seahorse {

inline constexpr size_t strlength(__restrict_arr const char* const c_str) {
    return strlen(c_str);
}
chars::chars() {
    init();
}

chars::~chars() {
    clear();
}

chars::chars(const chars& src) {
    init();
    copy_data(src._data, src.length());
}

chars::chars(const std::string& src) {
    init();
    copy_data(src.c_str(), src.length());
}

chars::chars(const char*& src) {
    init();
    if (src != nullptr) {
        copy_data(src, strlen(src));
    }
    else {
        copy_data("nullptr", strlength("nullptr"));
    }
}

chars::chars(const char& ch) {
    init();
    copy_data(&ch, 2);
    _data[1] = '\0';
}

chars::chars(int num) {
    init();
    chars&& tmp = to_chars(num);
    hold_data(tmp._data);
    tmp._data = nullptr;
}

chars::chars(unsigned int num) {
    init();
    chars&& tmp = to_chars(num);
    hold_data(tmp._data);
    tmp._data = nullptr;
}

chars::chars(ssize_t num) {
    init();
    chars&& tmp = to_chars(num);
    hold_data(tmp._data);
    tmp._data = nullptr;
}

chars::chars(size_t num) {
    init();
    chars&& tmp = to_chars(num);
    hold_data(tmp._data);
    tmp._data = nullptr;
}

chars::chars(const void* const ptr) {
    chars&& tmp = to_chars(ptr);
    hold_data(tmp._data);
    tmp._data = nullptr;
}

chars::chars(chars&& robj) {
    init();
    if (robj._data != nullptr) {
        hold_data(robj._data);
        robj._data = nullptr;
    }
}

chars& chars::operator=(const chars& src) {
    if (&src != this) {
        clear();
        copy_data(src._data, src.length());
    }
    return *this;
}

chars& chars::operator=(chars&& src) {
    clear();
    hold_data(src._data);
    src._data = nullptr;
    return *this;
}

chars& chars::operator=(const std::string& src) {
    clear();
    copy_data(src.c_str(), src.length());
    return *this;
}

chars& chars::operator=(const char ch) {
    clear();
    copy_data(&ch, 2);
    _data[1] = '\0';
    return *this;
}

chars& chars::operator=(const char src[]) {
    clear();
    copy_data(src, strlength(src));
    return *this;
}

inline void chars::init() {
    _data = nullptr;
}

inline void chars::clear() {
    if (_data != nullptr) {
        free(_data);
        _data = nullptr;
    }
}

inline char* chars::release() {
    char* ret = _data;
    _data = nullptr;
    return ret;
}

inline const size_t chars::length() const {
    if (_data != nullptr) {
        return strlength(_data);
    }
    else {
        return 0;
    }
}

const char* chars::c_str()const {
    return _data;
}

inline void chars::copy_data(const char* const src, const size_t length) {
    clear();
    _data = (char*)Malloc(length);
    memcpy(_data, src, length);
}

inline void chars::hold_data(char*& src) {
    clear();
    _data = src;
    src = nullptr;
}

chars chars::to_chars(register unsigned int num) {
    chars obj;
    __restrict_arr char buf1[sizeof(unsigned int) * 4];
    register __restrict_arr char* buf2 = (char*)Malloc(sizeof(unsigned int) * 4);
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

    i -= 1;
    while (i >= 0) {
        buf2[j] = buf1[i];
        ++j;
        --i;
    }

    buf2[j] = '\0';
    obj.hold_data(buf2);
    return obj;
}

chars chars::to_chars(register int num) {
    chars obj;
    __restrict_arr char buf1[sizeof(int) * 4];
    register __restrict_arr char* buf2 = (char*)Malloc(sizeof(unsigned int) * 4);
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
    i -= 1;
    while (i >= 0) {
        buf2[j] = buf1[i];
        ++j;
        --i;
    }
    buf2[j] = '\0';
    obj.hold_data(buf2);
    return obj;
}

chars chars::to_chars(register size_t num) {
    chars obj;
    register __restrict_arr char buf1[sizeof(size_t) * 4];
    register __restrict_arr char* buf2 = (char*)Malloc(sizeof(unsigned int) * 4);
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
    i -= 1;
    while (i >= 0) {
        buf2[j] = buf1[i];
        ++j;
        --i;
    }
    buf2[j] = '\0';
    obj.hold_data(buf2);
    return obj;
}

chars chars::to_chars(register ssize_t num) {
    chars obj;
    __restrict_arr char buf1[sizeof(ssize_t) * 4];
    register __restrict_arr char* buf2 = (char*)Malloc(sizeof(unsigned int) * 4);
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
    i -= 1;
    while (i >= 0) {
        buf2[j] = buf1[i];
        ++j;
        --i;
    }
    buf2[j] = '\0';
    obj.hold_data(buf2);
    return obj;
}

chars chars::to_chars(register const void* const ptr) {
    chars obj;
    __restrict_arr char buf[POINTER_0X_LEN + 1];
#if UINTPTR_MAX == 0xffffffff
    snprintf(buf, POINTER_0X_LEN + 1, "%08p'\0", ptr);
#elif UINTPTR_MAX == 0xffffffffffffffff
    snprintf(buf, POINTER_0X_LEN + 1, "%016p'\0", ptr);
#else

#endif
    obj.copy_data(buf, POINTER_0X_LEN + 1);
    return obj;
}

}