#include "Filesystem.h"
#include <vector>
#include <iostream>

int main() {
    seahorse::Path p("/root/code/seahorse/cpp_test");
    std::vector allFile = p.travelAllFile();
    for (auto itor = allFile.begin(); itor != allFile.end(); ++itor) {
        std::cout << itor->c_str() << std::endl;
    }
    return 0;
}