#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

//Brute: where we use 3rd array and put in it then again put in the array O(n+m)+O(n+m) and space O(n+m)
// void mer_two_sor(vector<int> &arr1, vector<int> &arr2, int n, int m)
// {
//     vector<int> arr3(n+m,0);
//     int i = 0;
//     int j = 0;
//     int index = 0;
//     while(i < n && j < m)
//     {
//         if(arr1[i] <= arr2[j])
//         {
//             arr3[index] = arr1[i];
//             index++;
//             i++;
//         }
//         else
//         {
//             arr3[index] = arr2[j];
//             index++;
//             j++;
//         }
//     }
//     while(i < n)
//     {
//         arr3[index] = arr1[i];
//         i++;
//         index++;
//     }
//     while(j < m)
//     {
//         arr3[index] = arr2[j];
//         j++;
//         index++;
//     }
//     for(int i = 0;i<n+m;i++)
//     {
//         if(i<n)
//         {
//             arr1[i] = arr3[i];
//         }        
//         else
//         {
//             arr2[i] = arr3[i - n];
//         }
//     }
// }

//Best
//we can reduce the space. We will keep two pointer one on end of 1st arr and second on 2nd array first and compare
//O(min(n,m)) + O(n log n) + O(m log m)
void mer_two_sor(vector<int> &arr1, vector<int> &arr2, int n, int m)
{
    int i = n-1;
    int j = 0;
    while(i >= 0 && j < m)
    {
        if(arr1[i] > arr2[j])
        {
            swap(arr1[i], arr2[j]);
            i--;
            j++;
        }
        else
        {
            break;
        }
    }
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());
}

//Not that good as sort is again and again done inside the loop
// void mer_two_sor(vector<int> &arr1, vector<int> &arr2, int n, int m)
// {
//     int i = 0;
//     int j = 0;
//     while(i < n)
//     {
//         if(arr1[i] > arr2[j])
//         {
//             swap(arr1[i], arr2[j]);
//             sort(arr2.begin(), arr2.end());
//         }
//         else
//         {
//             i++;
//         }
//     }
// }

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> arr1(n,0);
    vector<int> arr2(m,0);
    for(int i = 0;i<n;i++)
    {
        cin>>arr1[i];
    }
    for(int i = 0;i<m;i++)
    {
        cin>>arr2[i];
    }
    mer_two_sor(arr1,arr2,n,m);
    cout<<endl;
    for(auto it:arr1)
    {
        cout<<it<<" ";
    }
    for(auto it:arr2)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}