#include <iostream>
#include <vector>
using namespace std;

int sea_in_po(vector<int> vec, int n, int x)
{
    int low = 0;
    int high = n-1;
    int  ans = n;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;  //Prevent overflow
        if(vec[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int main()
{
    int n, x;
    cin>>n>>x;
    vector<int> vec(n,0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = sea_in_po(vec,n,x);
    cout<<endl<<ans<<endl;
}