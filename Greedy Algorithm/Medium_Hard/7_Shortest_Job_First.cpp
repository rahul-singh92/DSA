#include <iostream>
using namespace std;

float op_way(vector<int>& jobs)
{
    sort(jobs.begin(), jobs.end());

    float waitTime = 0;
    int totalTime = 0;
    int n = jobs.size();

    for(int i = 0; i< n; i++)
    {
        waitTime += totalTime;
        totalTime += jobs[i];
    }

    return waitTime / n;
}

int main()
{
    vector<int> jobs = {4, 3, 7, 1, 2};
    float ans = op_way(jobs);

    cout<<ans<<endl;
}