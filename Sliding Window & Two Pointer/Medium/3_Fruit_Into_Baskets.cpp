#include <iostream>
#include <set>
#include <map>
using namespace std;

int bru_way(vector<int>& arr)
{
    int maxLen = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        set<int> st;
        for(int j = i; j < arr.size(); j++)
        {
            st.insert(arr[j]);
            if(st.size() <= 2)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else break;
        }
    }
    return maxLen;
}

int bet_way(vector<int>& arr)
{
    int l = 0, r = 0;
    int maxLen = 0;
    map<int, int> mpp;

    while(r < arr.size())
    {
        mpp[arr[r]]++;

        while(mpp.size() > 2)
        {
            mpp[arr[l]]--;

            if(mpp[arr[l]] == 0) mpp.erase(arr[l]);

            l++;
        }
        
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

int op_way(vector<int>& arr)
{
    int l = 0, r = 0;
    int maxLen = 0;
    unordered_map<int, int> mpp;

    while(r < arr.size())
    {
        mpp[arr[r]]++;

        if(mpp.size() > 2)
        {
            mpp[arr[l]]--;

            if(mpp[arr[l]] == 0) mpp.erase(arr[l]);
            l++;
            r++;
        }
        else {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, 2};
    int ans =  op_way(arr);

    cout<<ans<<endl;
}