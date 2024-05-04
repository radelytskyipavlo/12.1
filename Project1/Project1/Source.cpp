#include <iostream>
#include <cassert>
using namespace std;

struct Elem
{
    Elem* link1,
        * link2;
    int info;
};

int main()
{
    Elem* p;
    p = new Elem;
    p->info = 1;
    p->link1 = NULL;
    p->link2 = new Elem;  //1

    p->link2->info = 2;
    p->link2->link1 = p->link1;
    p->link2->link2 = new Elem;  //2

    p->link2->link2->info = 4;
    p->link2->link2->link1 = p;
    p->link2->link2->link2 = new Elem;  //4

    p->link2->link2->link2->info = 3;
    p->link2->link2->link2->link1 = p;
    p->link2->link2->link2->link2 = p->link2;  //3

    cout << (p->info) << endl;
    cout << (p->link2->info) << endl;
    cout << (p->link2->link2->info) << endl;
    cout << (p->link2->link2->link2->info) << endl;

    delete p->link2->link2->link2;
    delete p->link2->link2;
    delete p->link2;
    delete p;;

    return 0;
}