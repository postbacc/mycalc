#include <iostream>
#include "../code/mycalc.h"

using namespace std;

int main(){

    // Do some printing
    int var;
    cout << "Hello World, please enter a number " << endl;
    cin >> var;
    cout << "your number was : " << var << endl;

    // create an object of mycalc and call its member function
    mycalc casio;
    casio.sub(var,2);
    
    return 0;
}