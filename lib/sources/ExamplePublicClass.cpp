#include "ExamplePublicClass.hpp"
#include "ExamplePrivateClass.hpp"

int ExamplePublicClass::f1(int a, int b)
{
    ExamplePrivateClass c;

    return 2 * c.f2( a, b );
}
