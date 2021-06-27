/**
*@file Inotify.h
*@author core zeng (corezeng@gmail.com)
*@brief 
*@version 0.1
*@date 2021-06-27
*
*@copyright Copyright (c) 2021
*
 */
#ifndef _SEAHORSE_SRC_UNIX_LIKE_LINUX_INOTIFY_H_
#define _SEAHORSE_SRC_UNIX_LIKE_LINUX_INOTIFY_H_

#include"Chars.h"
#include"Thread.h"
#include<functional>
#include<vector>
#ifdef __linux__
#include<sys/inotify.h>
#endif
namespace seahorse {

class Inotify{
#define self  Inotify
public:
    self();
    ~self();
    inline int addWatchFile(const seahorse::chars& filePath,
                            std::function<void(void*,const seahorse::chars&)> action);
    void watchAsThread();
private:
    std::unique_ptr<seahorse::Thread> _watchThread;
    int _inotifyFd;
    std::vector<seahorse::chars> _watchFiles;
#undef self
};
 
} // namespace seahorse
#endif // _SEAHORSE_SRC_UNIX_LIKE_LINUX_INOTIFY_H_