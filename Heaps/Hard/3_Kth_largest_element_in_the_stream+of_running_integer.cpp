#include <iostream>
using namespace std;

class Solution
{
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

    public:
        Solution(int k, vector<int>& nums)
        {
            size = k;
            
            for(int i: nums)
            {
                minHeap.push(i);

                if(minHeap.size() > k)
                {
                    minHeap.pop();
                }
            }
        }

        int add(int val)
        {
            minHeap.push(val);

            if(minHeap.size() > size)
            {
                minHeap.pop();
            }

            return minHeap.top();
        }
    };

int main()
{
    vector<int> nums = {4, 5, 8, 2};
    Solution kthLargest(3, nums);
    cout << kthLargest.add(3) << endl;  
    cout << kthLargest.add(5) << endl;  
    cout << kthLargest.add(10) << endl; 
    cout << kthLargest.add(9) << endl;  
    cout << kthLargest.add(4) << endl;  
    return 0;   
}