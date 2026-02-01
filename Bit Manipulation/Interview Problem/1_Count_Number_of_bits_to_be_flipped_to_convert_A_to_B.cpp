#include <iostream>
using namespace std;

int minBitFlip(int n, int goal)
{
    int num = n ^ goal;
    int count = 0;

    for(int i = 0; i < 32; i++)
    {
        count += (num & 1);
        num = num >> 1;
    }
    return count;
}

int main()
{
    int n = 10, goal = 7;

    int ans = minBitFlip(n, goal);
    cout<<ans<<endl;
}