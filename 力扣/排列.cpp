//
// Created by 86189 on 2022/7/22.
//
void backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len){
    // 所有数都填完了
    if (first == len) {
        res.emplace_back(output);
        return;
    }
    for (int i = first; i < len; ++i) {
        // 动态维护数组
        swap(output[i], output[first]);
        // 继续递归填下一个数
        backtrack(res, output, first + 1, len);
        // 撤销操作
        swap(output[i], output[first]);
    }
}
void backtrack(vector<int>& nums, vector<vector<int>>& ans, int idx, vector<int>& perm) {
    if (idx == nums.size()) {
        ans.emplace_back(perm);
        return;
    }
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])) {
            continue;
        }
        perm.emplace_back(nums[i]);
        vis[i] = 1;
        backtrack(nums, ans, idx + 1, perm);
        vis[i] = 0;
        perm.pop_back();
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > res;
    backtrack(res, nums, 0, (int)nums.size());
    return res;
}

