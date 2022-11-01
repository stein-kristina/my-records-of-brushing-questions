//
// Created by 86189 on 2022/8/30.
//

bool isMatch(string s, string p) {
    int m=s.size(),n=p.size();
    vector<vector<bool>> f(m+1,vector<bool>(n+1,false));
    f[0][0]= true;
    for(int j=1;j<=n;j++){
        if(j<n&&p[j]=='*'){
            f[0][j+1]=f[0][j-1];
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(p[j-1]=='*'){
                if(s[i-1]==p[j-2]||p[j-2]=='.')
                {
                    f[i][j]=f[i][j-2]||f[i-1][j];//分别是  重复0次；重复一次；重复1次及以上！！！
                }
                else//s[i-1] p[j-2]不匹配  *需要重复0次
                {
                    f[i][j]=f[i][j-2];
                }
            }
            else{
                if((s[i-1]==p[j-1])||(p[j-1]=='.')) f[i][j]=f[i-1][j-1];
            }
        }
    }
    return f[m][n];
}