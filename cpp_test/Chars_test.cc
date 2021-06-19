#include "../Chars.h"
#include <iostream>

int main() {
    char *chs = "hello";
    seahorse::chars chars1(chs);
    // seahorse::tinychars chars2("world");
    std::cout << chars1.c_str();
    // std::cout << chars2.c_str();
    return 0;
}