#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

int countGoodNumber(int index, int n)
{
    //If we have reached the end of the string return 1 as we have reached the end of the string
    if(index == n) return 1;

    int result = 0;

    if(index % 2 == 0)
    {
        for(int digit: {0,2,4,6,8})
        {
            result = (result + countGoodNumber(index + 1, n)) % MOD;
        }
    }
    else
    {
        for(int digit: {2,3,5,7})
        {
            result = (result + countGoodNumber(index + 1, n)) % MOD;
        }
    }
    return result;
}

int bet_wat(int index, int n)
{
    int result = 1;
    for(int i = index; i < n; i++)
    {
        if(i % 2 == 0) result *= 5;
        else result *= 4;
    }
    return result;
}

int main()
{
    int n;
    cin>>n;

    cout<<bet_wat(0, n) <<endl;
}