#include <iostream>
using namespace std;

int main()
{
    int n = 13, i = 2;
    //Using left shift
    if((n & (1 << i)) != 0) cout<<"Set\n";
    else cout<<"Not Set\n";

    //Using right shift
    if(((n >> i) & 1) != 0) cout<<"Set\n";
    else cout<<"Not Set\n";
}