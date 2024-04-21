#include <iostream>
#include "stonewt.h"
using std::cout;

int main(){
    Stonewt poppins(9, 2.8);
    double p_wt = poppins;
    cout << "Convert to double => ";
    cout << "Popins: " << p_wt << " pounds.\n";
    cout << "Convert to int => ";
    cout << "Popins: " << int(poppins) << " pounds.\n";
    return 0;
}