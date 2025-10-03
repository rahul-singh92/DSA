#include <iostream>
#include <vector>
using namespace std;

//--> "Overflow case" : this is the case when the search space is INT_MAX, in this case if my both low and high 
//                      reaches to INT_MAX, then the mid = (low + high) / 2; will become 2*INT_MAX which can't be stored
//                      and size overflows.
//Solution:      1.Etiher use "long long" 
//               2.OR use mid = low + (high - low) / 2; i.e (2*low + high - low) / 2; which is (low+high)/2;
//                  This will cancel out the INT_MAX - INT_MAX and you can store that in int mid. 


//Iterative code  O(log 2 n)
// int bin_sea(vector<int> vec, int n, int target)
// {
//     int low = 0;
//     int high = n-1;
//     while(low <= high)
//     {
//         int mid = (low + high) / 2;
//         if(vec[mid] == target) return mid;
//         else if(vec[mid] < target) low = mid + 1;
//         else high = mid - 1;
//     }
//     return -1;
// }

//Recursive one. O(log 2 n)
int bin_sea(vector<int> vec, int low, int high, int target)
{
    int ans;
    if(low > high) return -1;
    int mid = (low + high) / 2;
    if(vec[mid] == target) return mid;
    else if(vec[mid] < target) return bin_sea(vec, mid+1, high,target);
    else return bin_sea(vec, low, mid - 1, target); 
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> vec(n,0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = bin_sea(vec,0,n-1,target);
    cout<<endl<<ans<<endl;
}