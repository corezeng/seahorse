#ifndef SEAHORSE_SOCKET_H
#define SEAHORSE_SOCKET_H

#include<utils.h>

namespace seahorse {
namespace network {

class Socket :public noncopyable {
public:
    Socket();
    ~Socket();
private:
    int _sock_fd;
};

}
}

#endif
