#include"log.h"

namespace seahorse {
namespace detail {

void clean_tls_log_producer(void *args) {
    if (tls_log_producer != nullptr) {
        delete tls_log_producer;
    }
}

}
} // namespace seahorse::detail