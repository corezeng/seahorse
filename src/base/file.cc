// #include "Filesystem.h"

// using namespace seahorse;

// Path::Path(const chars &path) :
//     _registPath(path), _path(path.c_str()) {
//     if (!std::filesystem::exists(_path)) {
//         _stat = PS_NOT_EXISTS;
//     }
//     _stat = PS_OK;
// }

// Path::~Path() {
// }
// std::filesystem::file_type Path::type() const {
//     // std::filesystem::file_status s(std::filesystem::status(_path));
//     return std::filesystem::file_status(std::filesystem::status(_path)).type();
// }

// std::vector<seahorse::chars> Path::travelAllFile() {
//     std::vector<seahorse::chars> allFiles;
//     if (_stat == PS_OK) {
//         for (auto itor = std::filesystem::directory_iterator(_path.c_str()); itor != std::filesystem::directory_iterator(); ++itor) {
//             switch (std::filesystem::file_status(itor->symlink_status()).type()) {
//             case std::filesystem::file_type::regular: {
//                 allFiles.push_back(seahorse::chars(itor->path()));
//                 break;
//             }
//             case std::filesystem::file_type::directory: {
//                 allFiles.push_back(seahorse::chars(itor->path()));
//                 break;
//             }
//             default: {
//                 // TODO 尚未包含的文件类型
//                 break;
//             }
//             }
//         }
//     } else {
//         return allFiles;
//     }
// }