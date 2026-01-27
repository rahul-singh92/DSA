#include <iostream>
using namespace std;

int countAllSub(int ind, int arr[], int c_s, int n, int sum)
{
    if(ind == n)
    {
        if(c_s == sum) return 1;
        else return 0;
    }

    c_s += arr[ind];
    int l = countAllSub(ind + 1, arr, c_s, n, sum);

    c_s -= arr[ind];
    int r = countAllSub(ind + 1, arr, c_s, n, sum);

    return l + r;
}

int main()
{
    int arr[] = {1, 2 , 1};
    int n = 3;
    int sum = 2;

    cout<<countAllSub(0, arr, 0, n, sum)<<endl;
}