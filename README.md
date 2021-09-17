# seahorse
A common modern C++ library which born from work.

### How to install
1. run the build.sh
2. library and header files will install in `/usr/local`

### A fast integer transform into string

chars is a tiny class, it's power like std::string, and faster than std::to_string in some tests.

#### Test source code

**For seahors::chars::to_chars()**

```cpp
#include<seahorse/base/chars.h>
#include<cstdint>
int main() {
    for (int i = 0;i < 100000000;++i) {
        seahorse::chars th = seahorse::chars::to_chars(i);
    }
    return 0;
}
```

**For std::to_string()**

```cpp
#include<string>
#include<cstdint>
int main() {
    for (size_t i = 0;i < 100000000;++i) {
        std::string str = std::to_string(i);
    }
    return 0;
}
```

#### The result

- Environment: Debian 10 x86-64, gcc version 8.3.0 (Debian 8.3.0-6), virtual machine running on the MacBook Pro 2019 Intel(R) Core(TM) i5-8279U CPU @ 2.40GHz by VMware Fusion Player Version 12.1.2

- Compiler‘s command: 
    - `g++ test_to_tinychars.cc -lseahorse -O3 -o test_to_chars`
    - `g++ test_to_string.cc -O3 -o test_to_string`

| to_chars()                                                   | to_string()                                                  |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| real     0m0.473s<br/>user    0m0.472s<br/>sys      0m0.000s | real     0m5.888s<br/>user    0m5.879s<br/>sys      0m0.004s |



