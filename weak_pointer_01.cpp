#include <iostream>
#include <memory>

using namespace std;

struct s
{
    int a;
    int c;
    string b;

    s() = default;
    ~s() = default;
};

void func(shared_ptr<s> e)
{
    e->a = 99;
    cout << "count of shared pointer:" << e.use_count() << endl;
}

int main()
{
    shared_ptr<s> sptr = std::make_shared<s>();

    func(sptr);

    cout << sptr->a << endl;

}
