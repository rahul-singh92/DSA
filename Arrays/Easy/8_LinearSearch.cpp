#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int num;
    cin>>num;
    int i;
    for(i = 0;i<n;i++)
    {
        if(arr[i] == num) cout<<num<<" present at "<<i<<"th index\n";
    }
    if(i>=n) cout<<"Not found\n"; 
}