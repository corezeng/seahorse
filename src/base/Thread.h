/**
 * @file Thread.h
 * @author zengkaijun (zengkaijun@xdrsec.com)
 * @brief 
 * @version 0.1
 * @date 2021-06-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef SEAHORSE_THREAD_H
#define SEAHORSE_THREAD_H
#ifdef __cplusplus
#include <thread>
#include <mutex>
#include <atomic>
#include <condition_variable>
#include <chrono>
#include "Utils.h"
#include<functional>

namespace seahorse {

class Thread;

struct ThreadArg {
    Thread &_this;
    std::unique_ptr<void> _addOnArgs;
    std::atomic<int> _keepRuning; // 0: keep running, 1: exit at next loop, 2: exit right now
    ThreadArg(Thread &self,void* addOnArgs=nullptr,const int keepRunning=2) :
        _this(self),_addOnArgs(addOnArgs),_keepRuning(keepRunning){
    }
};

typedef std::function<void(ThreadArg* threadArg)> ThreadFunc;

class Thread : std::thread {
public:
#define self Thread
    self(ThreadFunc func,std::unique_ptr<void*> funcAddOnArg);
    ~self();
    inline void run(bool join = false);
    inline void stop(bool rightnow = true);
    inline void join();

protected:

private:
    std::atomic_bool _isRunning;
    std::atomic_bool _isBusy;
    ThreadArg _threadArg;
    std::unique_ptr<std::thread> _thread;
    ThreadFunc _func;
#undef self
};
} // namespace seahorse

#else // C interface
#endif
#endif