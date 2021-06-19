/**
 * @file Filesystem.h
 * @author zengkaijun (zengkaijun@xdrsec.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SEAHORSE_FILESYSTEM_H
#define SEAHORSE_FILESYSTEM_H
#ifdef __cplusplus
#include <filesystem>
#include "../seahorse/Chars.h"
namespace seahorse {

class Path {
public:
    Path(const tinychars &path);
    ~Path();
    std::filesystem::file_type type() const;

private:
    seahorse::tinychars _path;
};

} // namespace seahorse

#else

#endif
#endif