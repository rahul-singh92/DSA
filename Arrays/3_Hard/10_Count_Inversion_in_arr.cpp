#include <iostream>
#include <vector>
using namespace std;

//Brute where we find all possible inversion O(n^2)
// int cou_inv(vector<int> vec, int n)
// {
//     int count = 0;
//     for(int i = 0;i<n;i++)
//     {
//         for(int j = i+1;j<n;j++)
//         {
//             if(vec[j] < vec[i]) count++;
//         }
//     }
//     return count;
// }

//Here we will use the merge sort algorithm where on merge process we will add the count variable
int merge(vector<int> &vec,int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;
    
    int count = 0;
    while(left<=mid && right<=high)
    {
        if(vec[left] <= vec[right])
        {
            temp.push_back(vec[left]);
            left++;
        }
        else
        {
            temp.push_back(vec[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    while(left<=mid)
    {
        temp.push_back(vec[left]);
        left++;
    }

    while(right<=high)
    {
        temp.push_back(vec[right]);
        right++;
    }
    for(int i = low;i<=high;i++)
    {
        vec[i] = temp[i-low];
    }
    return count;
}
int mergeSort(vector<int> &vec,int low, int high)
{
    int count = 0;
    if(low >= high) return count;
    int mid = ( low + high ) / 2;
    count += mergeSort(vec,low,mid);
    count += mergeSort(vec,mid+1, high);
    count += merge(vec, low, mid, high);
    return count;
}
int cou_inv(vector<int> &vec, int n)
{
    return mergeSort(vec,0,n-1);
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n,0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = cou_inv(vec,n);
    cout<<endl<<ans<<endl;
}