#ifndef SEAHORSE_UTILS_H
#define SEAHORSE_UTILS_H
#ifdef __cplusplus
namespace seahorse {

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