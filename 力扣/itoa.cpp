#include <iostream>
#include <string>
#include <math.h>
using namespace std;
void reverse(string &s);
int myAtoi(string s) {
    string s1;
    int fu=0,i=0,ie;
    for(i=0;s[i]<='0'||s[i]>'9';i++){
        if(s[i]=='-') break;
    }//找到第一个不是空格的
    //除去空格
    for(ie = s[i]=='-'?i+1:i;ie<s.size();ie++){
        if(s[ie]<'0'||s[ie]>'9') break;
    }
    ie--;
    if(s[i]=='-'){
        fu=1;
        s1=s.substr(i+1,ie-i);
    }
    else s1=s.substr(i,ie-i+1);
    int num=0,onum=0;
    int chao=0;
    for(int k=0;k<s1.size();k++){

        onum=num;

        if(onum>pow(2,31)/10){
            chao=1;
            num=pow(2,30)-1;
            break;
        }
        num*=10;
        num+=s1[k]-48;
    }
    if(fu) {
        num*=-1;
        if(chao) num=-(pow(2,31)-1)-1;
    }
    return num;
}

void reverse(string &s){//从0开始
    int len=s.size();
    char c;
    for(int i=0;i<len/2;i++){
        c=s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=c;
    }
}
int main(){    string s;
    getline(cin,s);
    cout<<myAtoi(s);
    return 0;
}