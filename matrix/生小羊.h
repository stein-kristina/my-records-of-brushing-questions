#ifndef FUNCTION_H
#define FUNCTION_H
#include <string>

using namespace std;
#define maxn 120
class BigInt{
private:
    string s;
public:
    BigInt():s(""){
    }
    BigInt(const string& a):s(a){}
    BigInt operator+(const BigInt &right);
    BigInt operator[](const int &i);
    BigInt operator=(const int &i);
    BigInt &operator=(const BigInt &right);
    friend ostream & operator<<(ostream & os,const BigInt &a);
    ~BigInt(){}
};
extern BigInt dp[maxn];
BigInt BigInt::operator=(const int &i){
    s='1';
    return *this;
}

BigInt &BigInt::operator=(const BigInt &right) {
    s=right.s;
    return *this;
}
BigInt BigInt::operator+(const BigInt &right){
    string a;
    int len1=(this->s).size();
    int len2=(right.s).size();
    if(len1>len2)     a=this->s;
    else    a=right.s;//保证a是最长那个
    int min=len1>len2?len2:len1;
    if(a==(this->s)) {
        for (int i = 0; i < min; i++) a[i] += (right.s)[i]-48;
        //把短的加那里去
    }
    else{
        for (int i = 0; i < min; i++) a[i] += (this->s)[i]-48;
        //把短的加那里去
    }
    for (int i = 0; i < min -1; i++) {
        if (a[i] >= 58) {
            a[i] -= 10;
            a[i + 1] ++;
        }
    }//min防止进位
    if(a[min-1]>=58) {
        if (len1==len2){
            a.push_back('1');
            a[min-1]-=10;
        }
        else {
            a[min-1]-=10;
            a[min]++;
        }
    }
    BigInt b(a);
    return b;
}

BigInt BigInt::operator[](const int &i){
    return dp[i];
}

ostream & operator<<(ostream & os,const BigInt &a){
    int len=(a.s).size();
    for(int i=len-1;i>=0;i--) os<<(a.s)[i];
    return os;
}

#endif