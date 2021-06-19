/**
 * @file Malloc.h
 * @author zengkaijun (zengkaijun@xdrsec.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef SEAHORSE_MALLOC_H
#define SEAHORSE_MALLOC_H

#ifdef __cplusplus
#include <malloc.h>
#include <cstddef>
#include <cstdint>
/**
 * @brief 封装的malloc，以提供错误处理
 * 
 * @param size 需要分配的内存大小
 * @return void* 已分配好的内存地址
 */
inline void *Malloc(const size_t size) {
    void *ptr = malloc(size);
    if (ptr != nullptr) {
        return ptr;
    } else {
        // TODO malloc failed
        return nullptr;
    }
}
#else
#endif

#endif