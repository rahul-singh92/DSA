#include <iostream>
#include <set>
using namespace std;

vector<int> bru_way(vector<int> &nums1, vector<int> &nums2, int k)
{
    // List to store all possible pair sums
    vector<int> allSums;

    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            allSums.push_back(nums1[i] + nums2[j]);
        }
    }
    sort(allSums.begin(), allSums.end(), greater<int>());
    vector<int> result(allSums.begin(), allSums.begin() + k);
    return result;
}

vector<int> op_way(vector<int> &nums1, vector<int> &nums2, int k)
{
    sort(nums1.begin(), nums1.end(), greater<int>());
    sort(nums2.begin(), nums2.end(), greater<int>());

    priority_queue<tuple<int, int, int>> maxHeap;

    set<pair<int, int>> visited;

    maxHeap.push({nums1[0] + nums2[0], 0, 0});
    visited.insert({0, 0});

    vector<int> result;

    while (k-- && !maxHeap.empty())
    {
        auto [sum, i, j] = maxHeap.top();
        maxHeap.pop();

        result.push_back(sum);

        if (i + 1 < nums1.size() && !visited.count({i + 1, j}))
        {
            maxHeap.push({nums1[i + 1] + nums2[j], i + 1, j});
            visited.insert({i + 1, j});
        }

        if (j + 1 < nums2.size() && !visited.count({i, j + 1}))
        {
            maxHeap.push({nums1[i] + nums2[j + 1], i, j + 1});
            visited.insert({i, j + 1});
        }
    }
    return result;
}

int main()
{
    vector<int> nums1 = {7, 3};
    vector<int> nums2 = {1, 6};

    vector<int> result = op_way(nums1, nums2, 2);

    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
}