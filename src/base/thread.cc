#include "thread.h"
#include "log.h"
namespace seahorse {

Thread::Thread() :
    _thread_name(), _args(*this) {
}

Thread::~Thread() {
}

void *Thread::run_thread(void *args) {
    TLS_LOG_PRODUCER_INIT;

    return nullptr;
} // namespace seahorse

} // namespace seahorse