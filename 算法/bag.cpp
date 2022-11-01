#include <iostream>
#include <vector>
using namespace std;

int bag(){
    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int bagWeight = 4;
    vector<vector<int>> dp(weight.size() , vector<int>(bagWeight + 1, 0));
    for(int i=0;i<weight.size();i++) dp[i][0]=0;
    for(int j=weight[0];j<bagWeight+1;j++) dp[0][j]=value[0];
    for(int i=1;i<weight.size();i++){
        for(int j=1;j<bagWeight+1;j++){
            if(j<weight[i]) dp[i][j]=dp[i-1][j];
            else dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
        }
    }
    return dp[weight.size()-1][bagWeight];
}

int main(){
    cout<<bag();
}