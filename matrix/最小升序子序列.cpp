//
// Created by 86189 on 2022/9/18.
//

string subsequence(const string & text){
    int siz=text.size();
    int a[siz],b[siz];//上个位置，链的长度
    string s=text;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    int ex=0;
    for(int i=siz-1;i>=0;i--){
        a[i]=0;
        b[i]=1;
        for(int j=i+1;j<siz;j++){
            if(s[i]>=s[j]) continue;
            if(b[i]<b[j]+1){
                a[i]=j;//记录下个位置
                b[i]=b[j]+1;//记录长度6
            }
        }
        cout<<a[i]<<' '<<b[i]<<endl;
        if(b[i]>=b[ex]) ex=i;
        cout<<ex<<endl;
    }
    string ans="";
    do{
        ans+=s[ex];
        ex=a[ex];
    }while(ex!=0);
    return ans;
}
//记录上个位置+最长长度
//测试用例：
//ooikuwiuanisdfcochuy
//        egjzxrghoelgjndjnbry
//btfpvuhaqniqwlduduvj
//        iogonakmmwglwngrvjxa
//eutlftopbzelvxmsdbhr
//        swjjqosoqluvhmhvcpxn
//yityzjuqdpkeeydczxnh
//        lztaihtvpynatcgzkegd
//zoxbvxkyusrisapsanvm
//        gacjocwsinekkyqewdng
