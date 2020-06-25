#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct Pair{
    int start,finish;
};

int findNonConflictingJobsLength(vector<Pair> &jobs){
    sort(jobs.begin(),jobs.end(),[](const Pair & x,const Pair & y){ return x.start < y.start;});

    vector<int> lookup(jobs.size());

    for (int i = 0; i <jobs.size() ; ++i) {
        for (int j = 0; j < i; ++j) if(jobs[j].finish < jobs[i].start && lookup[i] < lookup[j]) lookup[i] = lookup[j];
        lookup[i]++;
    }
     return *max_element(lookup.begin(),lookup.end());
}

void printNonConflictingJobsLength(vector<Pair> &jobs){
    sort(jobs.begin(),jobs.end(),[](const Pair & x,const Pair & y){ return x.start < y.start;});

    vector<vector<Pair>> lookup(jobs.size());

    for (int i = 0; i <jobs.size() ; ++i) {
        for (int j = 0; j < i; ++j) if(jobs[j].finish < jobs[i].start && lookup[i].size() < lookup[j].size()) lookup[i] = lookup[j];
        lookup[i].push_back(jobs[i]);
    }

    vector<Pair> max ;

    for(auto i : lookup) if(i.size() > max.size()) max = i;

    for(auto i : max) cout<<i.start<<" "<<i.finish<<"   ";

}

int main(void)
{
    vector<Pair> jobs =
            {
                    {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
                    {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
            };

    cout << "The maximum number of non-conflicting jobs are "<< findNonConflictingJobsLength(jobs)<<endl;
    printNonConflictingJobsLength(jobs);
    return 0;
}
