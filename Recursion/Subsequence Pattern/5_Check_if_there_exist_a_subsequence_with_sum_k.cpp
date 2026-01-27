#include <iostream>
using namespace std;

bool checkSub(int ind, int arr[], int c_s, int n, int s)
{
    if(ind == n)
    {
        if(c_s == s)
        {
            cout<<"Yes\n";
            return true;
        }
        else return false;
    }

    c_s += arr[ind];
    if(checkSub(ind + 1, arr, c_s, n, s) == true) return true;

    c_s -= arr[ind];
    if(checkSub(ind + 1, arr, c_s, n, s) == true) return true;
    return false;
}

int main()
{
    int arr[] = {1, 2, 1};
    int n = 3;
    int s = 2;

    if(checkSub(0, arr, 0, n, s) == false) cout<<"No\n";
}