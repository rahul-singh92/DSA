#include <iostream>
#include <vector>
using namespace std;

//Brute where we find each pair and check it. O(n^2)
// int rev_pai(vector<int> vec, int n)
// {
//     int count = 0;
//     for(int i = 0;i < n;i++)
//     {
//         for(int j = i+1;j<n;j++)
//         {
//             if(vec[i] > 2*vec[j])
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

//Better O(2*n log n) space O(n) .. 
// In this we will make another function because of this condition of vec[i] > 2*vec[j] as merge only do vec[i] > vec[j].
void merge(vector<int> &vec, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(left <= mid && right <= high)
    {
        if(vec[left] <= vec[right])
        {
            temp.push_back(vec[left]);
            left++;
        }
        else
        {
            temp.push_back(vec[right]);
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(vec[left]);
        left++;
    }
    while(right <= high)
    {
        temp.push_back(vec[right]);
        right++;
    }

    for(int i = low;i<=high;i++)
    {
        vec[i] = temp[i - low];
    }
}
int countPairs(vector<int> &vec, int low, int mid, int high)
{
    int count = 0;
    int right = mid + 1;
    for(int i = low;i<=mid;i++)
    {
        while(right <= high && vec[i] > 2*vec[right]) right++;
        count += (right - (mid+1));
    }
    return count;
}
int mergeSort(vector<int> &vec, int low, int high)
{
    int count = 0;
    if(low >= high) return count;
    int mid = (low + high) / 2;
    count += mergeSort(vec,low, mid);
    count += mergeSort(vec, mid+1, high);
    count += countPairs(vec, low, mid, high);
    merge(vec, low, mid, high);
    return count;
}
int rev_pai(vector<int> &vec, int n)
{
    return mergeSort(vec, 0, n-1);
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
    int ans = rev_pai(vec,n);
    cout<<endl<<ans<<endl;
}