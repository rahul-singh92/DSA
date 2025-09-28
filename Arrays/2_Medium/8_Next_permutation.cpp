#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Brute Force --> First finding all permutations, then linear search and then getting the next permutation
// Time Complexity will be n! for all permuation and n for number of element so O(n! * n)

//Better is using next_permutation function in STL
// vector<int> next_per(vector<int> vec,int n)
// {
//     next_permutation(vec.begin(),vec.end());
//     return vec;
// }

//Implement the next_permutation function
vector<int> next_per(vector<int> vec, int n)
{
    int index = -1;

    //1. Start from forst possible break point like 1 2 3 4 <-- break point 5
    for(int i = n-2; i>=0;i--)
    {
        if(vec[i] < vec[i+1])
        {
            index = i;
            break;
        }
    }

    //2.If index is still -1 i.e. no break point so return the reverse of array 5 4 3 2 1 
    if(index == -1)
    {
        reverse(vec.begin(),vec.end());
        return vec;
    }

    //3.From behind find the first greater element than the break point element and swap it
    for(int i = n-1; i>index;i++)
    {
        if(vec[i] > vec[index])
        {
            swap(vec[i],vec[index]);
            break;
        }
    }

    //4. Reverse the arr from begin + index + 1 to end
    reverse(vec.begin() + index + 1, vec.end());
    return vec;
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
    vector<int> a = next_per(vec,n);
    for(auto it: a)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}