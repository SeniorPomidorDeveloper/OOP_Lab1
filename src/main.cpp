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
    catch(const exception& e)
    {
        cerr << endl << "Exception: " << e.what() << endl;
    }
}