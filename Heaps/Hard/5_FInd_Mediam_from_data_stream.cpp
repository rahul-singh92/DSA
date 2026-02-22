#include <iostream>
using namespace std;

// class MedianFinder
// {
//     private:
//         vector<int> nums;

//     public: 
//         MedianFinder() {}

//         void addNum(int num)
//         {
//             nums.push_back(num);
//         }

//         double findMedian()
//         {
//             sort(nums.begin(), nums.end());

//             int n = nums.size();

//             if(n % 2 == 1)
//             {
//                 return nums[n / 2];
//             }
//             return (nums[n / 2 - 1] + nums[n/2]) / 2.0;
//         }
// };


//OP way
class MedianFinder
{
    private:
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<int>> minHeap;
    
    public:
        MedianFinder() {}

        void addNum(int num)
        {
            maxHeap.push(num);

            minHeap.push(maxHeap.top());
            maxHeap.pop();

            if(minHeap.size() > maxHeap.size())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }

        double findMedian()
        {
            if(maxHeap.size() == minHeap.size())
            {
                return (maxHeap.top() + minHeap.top()) / 2.0;
            }

            return maxHeap.top();
        }
};
int main()
{
    //  MedianFinder mf;

    // mf.addNum(1);
    // mf.addNum(2);
    // mf.addNum(3);
    // cout << mf.findMedian() << endl; // Output: 2

    // return 0;   

    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << mf.findMedian() << endl; // Output: 1.5
    mf.addNum(3);
    cout << mf.findMedian() << endl; // Output: 2
    return 0;
}