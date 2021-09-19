/**
*@file Log.h
*@author core zeng (corezeng@gmail.com)
*@brief Multi thread log module
*@version 0.1
*@date 2021-09-04
*
*@copyright Copyright (c) 2021
*
 */

#ifndef _SEAHORSE_BASE_LOG_H_
#define _SEAHORSE_BASE_LOG_H_

#include <threads.h>

#include "chars.h"
#include "thread.h"
#include "buffer.h"

namespace seahorse {

// default log level, use to decide log action in compile time.
#ifndef DEFAULT_LOG_LEVEL
#define DEFAULT_LOG_LEVEL 5
#endif

#ifndef LOG
#define LOG(severity) COMPACT_LOG##severity.stream()
#endif

class LogProducer;
class LogConsumer;

/**
*@brief use macro TLS_LOG_PRODUCER_INIT to initialize it befor use.
*
 */
__restrict_arr __thread LogProducer *tls_log_producer = nullptr;

namespace detail {
void clean_tls_log_producer(void *args);

}

#ifndef TLS_LOG_PRODUCER_INIT
#define TLS_LOG_PRODUCER_INIT                                                          \
    do {                                                                               \
        if (tls_log_producer == nullptr) {                                             \
            tls_log_producer = new LogProducer();                                      \
            pthread_cleanup_push(::seahorse::detail::clean_tls_log_producer, nullptr); \
            pthread_cleanup_pop(1);                                                    \
        }                                                                              \
    } while (0)

#endif

class LogProducer {
    friend class LogConsumer;

public:
    LogProducer();
    ~LogProducer();

    inline void set_msg_title(const chars &title);
    inline void set_buffer_size(const size_t size);

    /**
    *@brief roll out buffer right now
    *
     */
    inline void flush();

    /**
    *@brief Get the log consumer object, with mutex
    *
    *@return LogConsumer& 
     */
    inline LogConsumer &log_consumer();

    size_t get_buffer_size() const;

    LogProducer &operator<<(const chars &msg);
    LogProducer &operator<<(const char *&msg);
    LogProducer &operator<<(const char word);
    LogProducer &operator<<(const bool boolen);
    LogProducer &operator<<(const short num);
    LogProducer &operator<<(const unsigned int num);
    LogProducer &operator<<(const int num);

    LogProducer &operator<<(const size_t num);
    LogProducer &operator<<(const ssize_t num);
    LogProducer &operator<<(const void *ptr);

private:
    static LogConsumer _log_consumer;

    Buffer _buf; // buffer use to cache messages
};

class LogConsumer {
    friend class LogProducer;

public:
    LogConsumer();
    ~LogConsumer();

private:
    /**
    *@brief Get the log consumer object, with mutex
    *
    *@return LogConsumer& this
     */
    inline LogConsumer &get_log_consumer();

    int _mutex;

    // Thread _thread;
};

} // namespace seahorse
#endif