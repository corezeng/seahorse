/**
*@file socket.h
*@author core zeng (corezeng@gmail.com)
*@brief
*@version 0.1
*@date 2021-09-04
*
*@copyright Copyright (c) 2021
*
 */
#ifndef SEAHORSE_SOCKET_H
#define SEAHORSE_SOCKET_H

#include<utils.h>
namespace seahorse {
namespace network {
class Socket :public noncopyable {
public:
    Socket();
    Socket(const int domain, const int type, const int protocol);
    int bind();
    ~Socket();

private:
    int _sock_fd;
};

}
}

#endif
