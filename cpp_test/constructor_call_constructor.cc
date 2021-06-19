#include <iostream>
#include <string>
class A {
public:
    A() {
        std::cout << "default constructor" << std::endl;
        A("not init");
    }
    A(const std::string &str) {
        std::cout << "string str constructor " << str << std::endl;
        _str = str;
    }

    A(const int num) {
        std::cout << "int num constructor " << std::endl;
        A(std::to_string(num));
    }

    ~A() {
        std::cout << "deconstructor" << std::endl;
        // A("delete..."); // endless loop
        // set_str("delete..."); // is OK
    }

    void set_str(const std::string &str) {
        std::cout << "set str member function " << std::endl;
        // A(str); //~ error
    }

    std::string _str;
};

int main() {
    {
        A a1;
        A a2(123);
        A a3("hello");
        std::cout << a1._str << std::endl;
    }

    return 0;
}