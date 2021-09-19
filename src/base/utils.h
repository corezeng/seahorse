#ifndef SEAHORSE_UTILS_H
#define SEAHORSE_UTILS_H
#include<cstdint>
#ifdef __cplusplus
namespace seahorse {

#if UINTPTR_MAX == 0xffffffff
/* 32-bit */
const auto POINTER_0X_LEN = 8;
#elif UINTPTR_MAX == 0xffffffffffffffff
/* 64-bit */
const auto POINTER_0X_LEN = 16;
#else
/* wtf */
#endif
const auto BIT32_POINTER_0X_LEN = 8;
const auto BIT64_POINTER_0X_LEN = 16;

class noncopyable {
public:
    noncopyable() = default;
    ~noncopyable() = default;
private:
    noncopyable(const noncopyable& src) = delete;
};
}
#endif
#endif