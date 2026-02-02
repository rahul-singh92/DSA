#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 2, 4, 3, 1, 4};

    int xor_ = 0;
    for(int i = 0; i < 7; i++)
    {
        xor_ ^= arr[i];
    }
    cout<<xor_<<endl;
}