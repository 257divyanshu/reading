#include <bits/stdc++.h>
using namespace std;

// 1️⃣ without virtual
// class Animal
// {
// public:
//     void speak()
//     {
//         cout << "Animal\n";
//     }
// };
// class Dog : public Animal
// {
// public:
//     void speak()
//     {
//         cout << "Bark\n";
//     }
// };
// int main()
// {
//     Animal *a = new Dog();
//     a->speak(); // ❌ prints "Animal"
//     return 0;
// };

// 2️⃣ with virtual
class Animal
{
public:
    virtual void speak()
    {
        cout << "Animal\n";
    }
};
class Dog : public Animal
{
public:
    void speak()
    {
        cout << "Bark\n";
    }
};
int main()
{
    Animal *a = new Dog();
    a->speak(); // ✔️ prints "Bark"
    return 0;
}