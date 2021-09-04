// /**
//  * @file Filesystem.h
//  * @author zengkaijun (zengkaijun@xdrsec.com)
//  * @brief 
//  * @version 0.1
//  * @date 2021-06-18
//  * 
//  * @copyright Copyright (c) 2021
//  * 
//  */

// #ifndef SEAHORSE_FILESYSTEM_H
// #define SEAHORSE_FILESYSTEM_H
// #ifdef __cplusplus
// #include <filesystem>
// #include "Chars.h"
// #include <vector>
// namespace seahorse {

// enum PathStat {
//     PS_NOT_EXISTS, // file or directory is not exists
//     PS_OK,
// };

// class Path {
// public:
//     Path(const chars &path);
//     ~Path();
//     std::filesystem::file_type type() const;
//     std::vector<seahorse::chars> travelAllFile();

// private:
//     seahorse::chars _registPath;
//     std::filesystem::path _path;
//     PathStat _stat;
// };

// } // namespace seahorse

// #else

// #endif
// #endif