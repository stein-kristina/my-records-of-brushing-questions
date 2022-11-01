bool valid(int x,int y,int n){
    if(x>=0&&x<n&&y>=0&&y<n) return true;
    return false;
}
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};
int paint(vector<vector<int>>&grid,int ix,int iy,int &key){
    queue<pair<int, int>> que;
    que.emplace(ix,iy);
    grid[ix][iy]=key;
    int area=1;
    int n=grid.size();
    while (!que.empty()) {
        int x = que.front().first, y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++) {
            int mx = x + dx[i], my = y + dy[i];
            if (valid(mx,my,n)&&grid[mx][my]==1) {
                que.emplace(mx, my);
                grid[mx][my]=key;
                area++;
            }
        }
    }
    return area;
}
int largestIsland(vector<vector<int>>& grid) {
    int n=grid.size(),key=2;
    map<int,int> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                m[key]=paint(grid,i,j,key);
                key++;
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++) {
        for (int j = 0; j < n; j++) {
            if(grid[i][j]==0){
                int nice=1;
                vector<bool> check(key+1,false);
                for (int k = 0; k < 4; k++) {
                    int mx = i + dx[k], my = j + dy[k];
                    if (valid(mx,my,n)&&grid[mx][my]!=0&&!check[grid[mx][my]]) {
                        nice+=m[grid[mx][my]];
                        check[grid[mx][my]]=true;
                    }
                }
                ans=max(ans,nice);
            }
        }
    }
    return ans;
}