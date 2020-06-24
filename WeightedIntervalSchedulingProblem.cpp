#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Job{
    int start,finish,profit;
};

int findLastNonConflictingJob(vector<Job> jobs,int n){
    for (int i = n-1; i >= 0 ; i--)  if(jobs[i].finish <= jobs[n].start) return i;
    return -1;
}


int findLastNonConflictingJobWithBinarySearch(vector<Job> jobs,int n){
    int low  = 0;
    int high = n;
    while(low <= high){
        int mid = (low + high)  / 2;
        if(jobs[mid].finish <= jobs[n].start){
            if(jobs[mid+1].finish <= jobs[n].start) low = mid +1;
            else return mid;
        }
        else high = mid -1;
    }
    return -1;
}

int maxProfitRecurisve(vector<Job> jobs,int n){
    if(n < 0)  return 0;
    if(n == 0) return jobs[0].profit;
    int index = findLastNonConflictingJob(jobs,n);
    int include = jobs[n].profit + maxProfitRecurisve(jobs,index);
    int exclude = maxProfitRecurisve(jobs,n-1);
    return max(include,exclude);
}

unordered_map<string,int>lookup;
int maxProfitMemoization(vector<Job> jobs,int n){
    if(n < 0)  return 0;
    if(n == 0) return jobs[0].profit;
    int index = findLastNonConflictingJob(jobs,n);
    string key = to_string(n) +  "|" + to_string(index);

    if(lookup.find(key) == lookup.end()){
        int include = jobs[n].profit + maxProfitMemoization(jobs,index);
        int exclude = maxProfitMemoization(jobs,n-1);
        lookup[key] = max(include,exclude);
    }
    return lookup[key];
}
int maxProfitTabulisation(vector<Job> jobs){
    int n = jobs.size();

    int lookup[n];
    lookup[0] = jobs[0].profit;

    for (int i = 1; i < n ; ++i) {
        int index = findLastNonConflictingJob(jobs,i);
        int include = jobs[i].profit;
        if(index != -1) include += lookup[index];
        lookup[i] = max(include,lookup[i-1]);
    }
    return lookup[n-1];
}

int main()
{
    vector<Job> jobs {
            { 0, 6, 60 },
            { 1, 4, 30 },
            { 3, 5, 10 },
            { 5, 7, 30 },
            { 5, 9, 50 },
            { 7, 8, 10 }
    };


    sort(jobs.begin(),jobs.end(),[](Job &x, Job &y) {return x.finish < y.finish;});
    cout << "The maximum profit is " << maxProfitRecurisve(jobs, jobs.size() - 1)<<endl;
    cout << "The maximum profit is " << maxProfitMemoization(jobs, jobs.size() - 1)<<endl;
    cout << "The maximum profit is " << maxProfitTabulisation(jobs)<<endl;

    return 0;
}