#include <cstring>
#include <iostream>

using std::cout;

class Demo
{
public:
    Demo(const char* text)
    {
        ptr = new char[strlen(text + 1)];
        memcpy(ptr, text, strlen(text));
        cout << "   C-tor at " << this << " : ptr address = " << std::hex << static_cast<void*>(ptr)
             << " for " << ptr << '\n';
    }
    // Enable copy constructor, version 1
    /*
    Demo(const Demo& other)
    {
        ptr = new char[strlen(other.ptr) + 1];
        memcpy(ptr, other.ptr, strlen(other.ptr));
        cout << "Copy-tor at " << this << " : ptr address = " << std::hex << static_cast<void*>(ptr)
             << " for " << ptr << '\n';
    }
    */

    // Enable copy constructor, version 2
    /*
    Demo(const Demo& other) : Demo(other.ptr) {}
    */

    // Enable assign operator
    /*
    Demo& operator=(const Demo& other)
    {
        char* tmp = new char[strlen(other.ptr) + 1];
        memcpy(tmp, other.ptr, strlen(other.ptr));
        delete[] ptr;
        ptr = tmp;
        cout << "assign = at " << this << " : ptr address = " << std::hex << static_cast<void*>(ptr)
             << " for " << ptr << '\n';
        return *this;
    }
    */

    ~Demo()
    {
        cout << "   D-tor at " << this << " : ptr address = " << std::hex << static_cast<void*>(ptr)
             << " for " << ptr << '\n';
        delete[] ptr;
    }

    auto get() -> char* { return ptr; }

private:
    char* ptr{nullptr};
};

auto main() -> int
{
    std::cout << "Create a1\n";
    Demo a1("demo a1");
    {
        Demo b = a1;
    }
    cout << "After bad code demo = " << a1.get() << '\n';

    std::cout << "Create a2\n";
    Demo a2("demo a2");
    {
        Demo c("demo c");
        c = a2;
    }
    cout << "After bad code demo = " << a2.get() << '\n';
};
