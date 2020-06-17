#include <iostream>
using  namespace std;

#include <algorithm>
#include <vector>

void wordBreakRecursion(vector<string> dict,string input,string output){
    if(input.length() == 0){ cout<<output<<endl;  return;}

    for (int i = 1; i <= input.size() ; ++i) {
        string prefix = input.substr(0,i);
        if(find(dict.begin(), dict.end(), prefix) != dict.end()) wordBreakRecursion(dict,input.substr(i),output + prefix + " ");
    }
}
bool checkwordBreakableRecursive(vector<string> dict,string input){
    if(input.length() == 0) return true;

    for (int i = 1; i <= input.size() ; ++i) {
        string prefix = input.substr(0,i);
        if(find(dict.begin(), dict.end(), prefix) != dict.end() && checkwordBreakableRecursive(dict,input.substr(i))) return true ;
    }
    return false;
}

bool checkwordBreakableTabulisation(vector<string> dict,string str,vector<int> & lookup){

    int n = str.size();
    if(n == 0) return true;

    if(lookup[n] == -1){
        lookup[n] = 0;
        for (int i = 1; i <= n ; ++i) {
            string prefix = str.substr(0,i);

            if(find(dict.begin(),dict.end(),prefix) != dict.end() && checkwordBreakableTabulisation(dict,str.substr(i),lookup)) lookup[n] = 1;
        }
    }
    return lookup[n];
}

int main()
{

    vector<string> dict = { "this", "th", "is", "famous", "Word", "break",
                            "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };

    string str = "Wordbreakproblem";

    wordBreakRecursion(dict, str, "");
    if(checkwordBreakableRecursive(dict,str))cout<<"yes\n";
    else cout <<"No\n";
    cout<<endl<<endl;


    vector<int> lookup(str.length() + 1,-1);
    if(checkwordBreakableTabulisation(dict,str,lookup))cout<<"yes\n";
    else cout <<"No\n";

    return 0;
}