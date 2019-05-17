#include "../code/mycalc.h"
#include <iostream>

using namespace std;

int main(){
    int var;
    cout << "Hello World, please enter a number " << endl;
    cin >> var;
    cout << "your number was : " << var << endl;

    mycalc o1;
    o1.sub(var,2);
    
    mycalc o2;
    o2.sum(var,var);
    
    return 0;
}