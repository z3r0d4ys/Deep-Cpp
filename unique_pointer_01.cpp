#include <iostream>
#include <memory>

using std::cout;
using std::cin;

struct Person {
    std::string name;

    Person()  = default;
    ~Person() = default;
};

void userFunction(std::unique_ptr<Person> &e)
{
    e->name = "baki";
}

int main(void)
{
    std::unique_ptr<Person> uniquePtr(new Person);
    userFunction(uniquePtr);
    cout << uniquePtr->name;
}
