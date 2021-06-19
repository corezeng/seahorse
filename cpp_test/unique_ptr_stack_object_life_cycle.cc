#include <memory>
#include <iostream>

class TestClassA
{
public:
    TestClassA()
    {
        std::cout << "TestClassA constructor" << std::endl;
    }
    ~TestClassA()
    {
        std::cout << "TestClassA deconstructor" << std::endl;
    }
    std::unique_ptr<TestClassA> &dup_new()
    {
        std::unique_ptr<TestClassA> newobj = std::make_unique<TestClassA>();
        return newobj;
    }

    TestClassA *dup_ptr()
    {
        return new TestClassA();
    }
};

int main()
{
    TestClassA t1;
    // t1.dup_new();
    t1.dup_ptr();
    // std::unique_ptr<TestClassA> t2 = std::move(t1.dup_new());
    return 0;
}
