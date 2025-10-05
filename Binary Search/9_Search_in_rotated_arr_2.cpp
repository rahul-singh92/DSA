#include <iostream>
#include <vector>
using namespace std;

int sea_ele_rot(vector<int> vec, int n, int x)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + (high - low) / 2;
        if(vec[mid] == x) return mid;
        else if (vec[mid] < x && vec[high] <= x) high = mid - 1;
        else if(vec[mid] < x && vec[high] >= x) low  = mid + 1;
        else if(vec[mid] > x && vec[low] <= x) high = mid - 1;
        else low = mid + 1; 
    }
    return -1;
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
    int ans = sea_ele_rot(vec, n, x);
    if(ans != -1) cout<<"True"<<endl;
    else cout<<"False"<<endl;
}