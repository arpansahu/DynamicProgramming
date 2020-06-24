#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


struct Box {
    int length,breadth,height;
};

vector<Box> createRotationsOFBoxes(vector<Box> boxes){
    vector<Box> rotations;
    for(auto i : boxes){
        rotations.push_back(i);
        rotations.push_back({max(i.length,i.height),min(i.length,i.height),i.breadth});
        rotations.push_back({max(i.breadth,i.height),min(i.breadth,i.height),i.length});
    }
    return rotations;
}


int  maxHeight(vector<Box> boxes){
    vector<Box> rotations = createRotationsOFBoxes(boxes);

    sort(rotations.begin(),rotations.end(),[](const Box &  x,const Box &  y){return (x.length * x.breadth) > (y.length * y.breadth);});
    vector<int> max_height(rotations.size());

    // for(auto i : max_height) cout<<i<<" ";cout<<endl;   to proove that max_height is intiatlised with 0


    for (int i = 0; i < rotations.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (rotations[i].length < rotations[j].length && rotations[i].breadth < rotations[j].breadth) max_height[i] = max(max_height[i], max_height[j]);
        }
        max_height[i] += rotations[i].height;
    }

    //  for(auto i : rotations)cout<<i.length<<" "<<i.breadth<<" "<<i.height<<endl;cout<<endl;
    //  for(auto i : max_height) cout<<i<<endl;

    return *max_element(max_height.begin(),max_height.end());
}
int main()
{

    vector<Box> boxes {
            { 4, 2, 5 },
            { 3, 1, 6 },
            { 3, 2, 1 },
            { 6, 3, 8 }
    };

    cout << "The maximum height is " << maxHeight(boxes);

    return 0;
}