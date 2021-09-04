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

#ifndef SEAHORSE_LOG_H
#define SEAHORSE_LOG_H
namespace seahorse {

class LogConsumer;

class LogProducer {
public:
private:
};

class LogConsumer {
public:
private:
};

thread_local LogProducer log;

}
#endif