#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            Elem* p = new Elem;

            p->info = 1;
            p->link2 = new Elem;
            p->link2->info = 2;

            p->link2->link1 = p;
            p->link2->link2 = new Elem;
            p->link2->link2->info = 4;

            // Чек p
            assert(p->info == 1);
            assert(p->link2->info == 2);

            // Чек p->link2
            assert(p->link2->link1 == p);
            assert(p->link2->link2->info == 4);

            delete p->link2->link2;
            delete p->link2;
            delete p;
        }
    };
}