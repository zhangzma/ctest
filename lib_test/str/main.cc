// main.cc
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>

class Foo
{
public:
    Foo(){}
    virtual ~Foo() {}

    void set_name(int num) {
        char buffer[33];
        itoa(num, buffer, 10);
        std::string name = buffer;
        set_name(name.c_str());
    }
    void set_name(const char*name) {
        m_name = name;
    }

    std::string get_name() const {
        return m_name;
    }

private:
    std::string m_name;
};

int main(int argc, char *argv[])
{
    Foo foo;
    foo.set_name("foo1");
    std::cout << "foo's name is " << foo.get_name() << std::endl;
    foo.set_name(6003);
    std::cout << "foo's name is " << foo.get_name() << std::endl;
    
    return 0;
}

