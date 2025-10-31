#include "Iter.hpp"

class MyClass {
public:
    int value;
    MyClass(int v) : value(v) {}
    void display() const { std::cout << value << " "; }
};

void printInt(int &n) {
    std::cout << n << " ";
}

void printString(std::string &s) {
    std::cout << s << " ";
}

void printChar(const char &c) {
    std::cout << c << " ";
}

void printMyClass(MyClass &obj) {
    obj.display();
}

int main() {

    std::cout << "=== Int Array test ===" << std::endl;

    int numbers[] = {1, 2, 3, 4, 5};
    std::cout << "Int array: ";
    iter(numbers, 5, printInt);
    std::cout << std::endl;

    std::cout << "=== String Array test ===" << std::endl;

    std::string words[] = {"hello", "world", "test"};
    std::cout << "String array: ";
    iter(words, 3, printString);
    std::cout << std::endl;

    std::cout << "=== Char Array test ===" << std::endl;

    const char chars[] = {'a', 'b', 'c'};
    std::cout << "Char array: ";
    iter(chars, 3, printChar); 
    std::cout << std::endl;

    std::cout << "=== Object Array test ===" << std::endl;

    MyClass objects[] = {MyClass(10), MyClass(20), MyClass(30)};
    std::cout << "MyClass array: ";
    iter(objects, 3, printMyClass);
    std::cout << std::endl;

    return 0;
}