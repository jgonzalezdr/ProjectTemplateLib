/**
 * @file
 * @brief      Example of an example
 * @project    Project Template
 * @authors    Jesus Gonzalez <jgonzalez@gdr-sistemas.com>
 * @copyright  Copyright (c) 2020 Jesus Gonzalez. All rights reserved.
 * @license    See LICENSE.txt
 */

#include "ExamplePublicClass.hpp"

#include <iostream>

using namespace std;

int main( int argc, const char* argv[] )
{
    ExamplePublicClass c;

    int x = c.f1( 5, 229 );

    cout << "Result: x = " << x << endl;

    return 0;
}