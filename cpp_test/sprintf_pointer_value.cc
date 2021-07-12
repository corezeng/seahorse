#include <iostream>
#include <memory.h>

const char *TEST = "This is a test.";
const char *tp1 = (char *)0x0000000000000001;

void test() {
    char buf[10];
    memset(buf, 0x00, sizeof(buf));
    snprintf(buf, 16, "%016p", TEST);
    std::cout << "TEST address: " << buf << std::endl;
}

int main() {
    test();
    return 0;
}