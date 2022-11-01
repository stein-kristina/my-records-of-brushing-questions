//
// Created by 86189 on 2022/6/18.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size();) {
        int t = intervals[i][1];
        int j = i + 1;
        while (j < intervals.size() && intervals[j][0] <= t) {
            t = max(t, intervals[j][1]);
            j++;
        }//合并
        ans.push_back({ intervals[i][0], t });
        i = j;
    }
    return ans;
}
int main(){
    vector<vector<int>> a={{1,4},{3,3},{1,1}};
    vector<vector<int>> b= merge(a);

    for(auto c:b){
        for(auto d:c){
            cout<<d<<' ';
        }
        cout<<endl;
    }
}