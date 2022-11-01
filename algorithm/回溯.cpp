#include <iostream>
#include <string>
#include <math.h>
#include <cstring>
#include <vector>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void backstacking(int n,int k,int index){
    if(path.size()==k){
        result.push_back(path);
        return;
    }
    for(int i=index;i<=n;i++){
        path.push_back(i);
        backstacking(n,k,i+1);
        path.pop_back();
    }
}
int main() {
    backstacking(4,2,1);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<2;j++)
            cout<< result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}