#include <iostream>
using namespace std;

int main()
{
    int n = 40;
    cout<<(n & (n-1))<<endl;   

    // 16 ---> 10000
    // 15 ---> 01111
    // if AND then it will change it rightmost bit
}