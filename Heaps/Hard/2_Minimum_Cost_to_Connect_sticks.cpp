#include <iostream>
using namespace std;

int op_way(vector<int>& arr)
{
    if(arr.size() <= 1) return 0;
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

    int ans = 0;
    while(pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int cu =  first + second;
        ans += cu;

        pq.push(cu);
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 8, 3, 5};

    int ans = op_way(arr);
    cout<<ans<<endl;
}