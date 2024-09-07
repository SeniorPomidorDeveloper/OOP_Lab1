#include "program.hpp"
#include <exception>

#include <exception>
#include <iostream>

using namespace std;

int main()
{
    try
    {
        program();
    }
    catch(const exception& error)
    {
        cerr << endl << "Exception: " << error.what() << endl;
    }
}