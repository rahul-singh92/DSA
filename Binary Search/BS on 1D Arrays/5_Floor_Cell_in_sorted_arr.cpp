#include <iostream>
#include <vector>
using namespace std;

int flo(vector<int> vec, int n, int x)
{
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2; //Prevent Overflow Condition
        if(vec[mid] <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}
int cei(vector<int> vec, int n, int x)
{
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high)
    {
        int mid = low + (high - low) / 2; //Prevent Overflow Condition
        if(vec[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}
vector<int> flo_cel(vector<int> vec, int n, int x)
{
    int flor = flo(vec ,n , x);
    int cel = cei(vec, n, x);
    return {flor, cel};
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
    vector<int> ans = flo_cel(vec, n, x);
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}