#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
vector<string> tmpres;
vector<vector<string>> res;
void dfs(int n,int row,int pos[],vector<string> & tmpres)
{
    if(row==n)
    {//递归终止条件
        res.push_back(tmpres);
        return;
    }
    for(int i=0;i<n;i++)
    {//访问列数
        int j=0;
        for(;j<row;j++)
        {//访问之前的行数
            //判断是否和之前的列或者斜线有冲突
            if(pos[j]==i || abs(j-row)==abs(i-pos[j]))
                break;
        }
        if(j==row)
        {//说明之前均无冲突
            pos[row]=i;     //第row行第i列放置皇后
            tmpres[row][i]='Q';
            dfs(n,row+1,pos,tmpres);
            tmpres[row][i]='.';     //回溯
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    int pos[n];//存放第i行所在的列数
    memset(pos,0,sizeof pos);
    tmpres=vector<string>(n,string(n,'.'));
    dfs(n,0,pos,tmpres);
    return res;
}

