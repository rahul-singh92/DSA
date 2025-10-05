#include <iostream>
#include <vector>
using namespace std;

int las(vector<int> vec, int n, int x)
{
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2; //Overflow Conditions
        if(vec[mid] == x)
        {
            ans = mid;
            low = mid + 1;
        }
        else if(vec[mid] < x) low = mid + 1;
        else high = mid - 1;

    }
    return ans;
}
int fir(vector<int> vec, int n,  int x)
{
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2; //Overflow Conditions
        if(vec[mid] == x)
        {
            ans = mid;
            high = mid - 1;
        }
        else if(vec[mid] < x) low = mid + 1;
        else high = mid - 1;

    }
    return ans;
}
int fir_las_occ(vector<int> vec, int n, int x)
{
    return (las(vec, n, x) - fir(vec, n, x) + 1);
}

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> vec(n,0);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    int ans = fir_las_occ(vec, n, x);
    cout<<ans<<endl;
    cout<<endl;
}