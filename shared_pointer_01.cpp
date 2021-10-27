#include <iostream>
#include <memory>

using std::cout;
using std::endl;

struct Person {
    std::string name;
    Person()  = default;
    ~Person() = default;
};

void userFunction(std::shared_ptr<Person> e)
{
    e->name = "baki";
    cout << e.use_count() << endl;
}

int main(void)
{
    std::shared_ptr<Person> sharedPtr(new Person);
    userFunction(sharedPtr);
    cout << sharedPtr->name;
}
