#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int min_in_rot(vector<int> vec, int n)
{
    int low = 0;
    int high = n-1;
    int x = INT_MAX;

    
    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(vec[low] <= vec[high]) 
        {
            return x = min(x, vec[low]); 
            break;
        }

        if(vec[low] <= vec[mid]) 
        {
            x = min(x,vec[mid]);
            low = mid + 1;
        }
        else
        {
            x = min(x, vec[mid]);
            high = mid - 1;
        } 
    }
    return x;
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
    int ans = min_in_rot(vec, n);
    cout<<ans<<endl;
}