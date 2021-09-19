/**
*@file thread.h
*@author core zeng (corezeng@gmail.com)
*@brief 
*@version 0.1
*@date 2021-09-18
*
*@copyright Copyright (c) 2021
*
 */

#ifndef _SEAHORSE_BASE_THREAD_H_
#define _SEAHORSE_BASE_THREAD_H_

#include <pthread.h>
#include <memory>

#include "utils.h"
#include "chars.h"
// #include "log.h"

namespace seahorse {

class Thread;

template <typename T>
class ThreadLocal : noncopyable {
    ThreadLocal();
    ~ThreadLocal();
};

struct ThreadArgs : public noncopyable {
    friend class Thread;
    Thread &_this_thread;
    std::shared_ptr<void *> _shared_args;
    std::unique_ptr<void *> _unique_args;

private:
    ThreadArgs(Thread &thread) :
        _this_thread(thread), _shared_args(), _unique_args() {
    }
    ~ThreadArgs() {
    }
};

class Thread : public noncopyable {
public:
    Thread();
    ~Thread();

    inline void set_shared_args(std::shared_ptr<void> &shared_args);
    inline void set_unique_args(std::unique_ptr<void> &unique_args);

    void run();

    inline bool joinable();

    inline std::unique_ptr<void *> join();

private:
    inline void init();

    static void *run_thread(void *args);
    chars _thread_name;
    ThreadArgs _args;
    pthread_t _pthread;
};

} // namespace seahorse

#endif