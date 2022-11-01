#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;
int maxArea(vector<int>& height) {
    int begin=0,end=height.size()-1;//首末
    int maxarea=0;
    int area=0;
    int t1,t2;
    while(begin<end){
        area=min(height[begin],height[end])*(end-begin);
        maxarea=max(area,maxarea);
        if(height[begin]>height[end]) end--;
        else begin++;
    }
    return maxarea;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cout<<maxArea(a);
    return 0;
}