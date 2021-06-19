/**
 * @file Thread.h
 * @author zengkaijun (zengkaijun@xdrsec.com)
 * @brief 暂时不可用
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

namespace seahorse {

class Thread;

struct ThreadArg {
    Thread &_this;
    volatile int keepRuning; // 0: keep running, 1: exit at next loop, 2: exit right now
    ThreadArg(Thread &self) :
        _this(self) {
    }
};

class Thread : std::thread {
public:
#define self Thread
    self();
    ~self();
    void run(bool join = no);
    void stop(bool rightnow = yes);

protected:
    static void threadFunc();

private:
    ThreadArg _arg;
#undef self
};
} // namespace seahorse

#else // C interface
#endif
#endif