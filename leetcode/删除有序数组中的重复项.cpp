#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cstring>
using namespace std;
int work(vector<int>& nums, int k) {
    int len = 0;
    for(int i=0;i<nums.size();i++) {
        int num=nums[i];
        if (len < k || nums[len - k] != num)
            nums[len++] = num;
    }
    return len;
}
int removeDuplicates(vector<int>& nums) {
    return work(nums, 2);
}

int main(){

    vector<int> a={0,0,1,1,1,1,2,3,3};
    cout<<removeDuplicates(a);

}