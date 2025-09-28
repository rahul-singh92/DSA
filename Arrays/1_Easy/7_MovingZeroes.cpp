#include <iostream>
using namespace std;
void optimal(int *arr, int n)
{
    int i = 0,j = 1;
    while(j < n)
    {
        if(arr[i] == 0 && arr[j] != 0)
        {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++; j++;
        }
        else if(arr[i] != 0) i++;
        else if(arr[i] == 0 && arr[j] == 0) j++;
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    optimal(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}