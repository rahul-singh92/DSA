#include <iostream>
#include <unordered_set>
using namespace std;

vector<int> bru_way(vector<int>& arr)
{
    vector<int> rankArr;

    for(int i = 0; i < arr.size(); i++)
    {
        unordered_set<int> smaller;
        for(int j = 0; j < arr.size(); j++)
        {
            if(arr[j] < arr[i])
            {
                smaller.insert(arr[j]);
            }
        }

        int rank = smaller.size() + 1;

        rankArr.push_back(rank);
    }

    return rankArr;
}

vector<int> bet_way(vector<int>& arr)
{
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    unordered_map<int, int> rankMap;

    int rank = 1;
    for(int num: sortedArr)
    {
        if(rankMap.find(num) == rankMap.end())
        {
            rankMap[num] = rank;
            rank++;
        }
    }

    vector<int> res;
    for(int n: arr)
    {
        res.push_back(rankMap[n]);
    }
    return res;
}

int main()
{
    vector<int> arr = {20, 15, 26, 2, 98, 6};

    vector<int> result = bet_way(arr);

    for(int r: result)
    {
        cout<<r<<" ";
    }
    cout<<endl;
}