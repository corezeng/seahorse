#include "Chars.h"
#include <iostream>

int main() {
    char chs[] = "hellod2dd2e2da";
    char word = 'a';
    seahorse::chars chars1(word);
    seahorse::tinychars chars2("world");
    std::cout << chars1.c_str();
    std::cout << chars2.c_str();
    return 0;
}
