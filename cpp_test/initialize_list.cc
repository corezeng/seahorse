/**
*@file initialize_list.cc
*@author core zeng (corezeng@gmail.com)
*@brief 测试初始化列表中传递this
*@version 0.1
*@date 2021-06-27
*
*@copyright Copyright (c) 2021
*
 */

#include<iostream>

class B;
class A{
public:
    A(B& b):_b(b){
        std::cout<<"A constructor,"<<"class B: "<<&_b<<std::endl;
    }
private:
    B& _b;
};

class B{
public:
    B():_a(*this){
        std::cout<<"B constructor,"<<"class B: "<<this<<std::endl;
    }
private:
    A _a;
};

int main(){
    B b;
    return 0;
}