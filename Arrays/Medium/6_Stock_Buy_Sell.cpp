#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int max_pro(vector<int> vec, int n)
{
    int mini = INT_MAX;
    int max_pro = 0;
    for(int i = 0;i < n;i++)
    {
        mini = min(vec[i], mini);
        max_pro = max(max_pro,vec[i] - mini);
    }
    return max_pro;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        vec.push_back(x);
    }
    int a = max_pro(vec,n);
    cout<<a<<endl;
}