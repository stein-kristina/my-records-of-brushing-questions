#include "../point.h"
using namespace std;

int fraction::gcd(const int &a, const int &b) const {
    int oa=a,ob=b;
    if(a>b){
        int t=oa;
        oa=b;ob=t;
    }
    if(a==0) return b;
    if(oa<0) oa*=-1;
    if(ob<0) ob*=-1;
    return gcd(ob%oa,oa);
}

void fraction::simp() {
    if(_denominator==0) return;
    int g=gcd(_numerator,_denominator);
    if(_numerator<0&&_denominator<0){
        _numerator*=-1;
        _denominator*=-1;
    }
    _numerator/=g;
    _denominator/=g;
}
fraction::fraction(const int &a, const int &b):_numerator(a),_denominator(b){
    simp();
}
fraction::fraction(const fraction &a) {
    _numerator=a._numerator;
    _denominator=a._denominator;
}
void fraction::operator=(const fraction &a) {
    _numerator=a._numerator;
    _denominator=a._denominator;
}

fraction fraction::operator+(const fraction &a) const{
    if((a._denominator==0)||(_denominator==0)) return fraction(0,0);
    int gongyue=gcd(_denominator,a._denominator);
    int bei=_denominator*a._denominator/gongyue;//最小公倍数
    int newnum=(_numerator*a._denominator+_denominator*a._numerator)/gongyue;
    fraction b=fraction(newnum,bei);
    b.simp();
    return b;

}
fraction fraction::operator-(const fraction & a) const{
    if((a._denominator==0)||(_denominator==0)) return fraction(0,0);
    int gongyue=gcd(_denominator,a._denominator);
    int bei=_denominator*a._denominator/gongyue;//最小公倍数
    int newnum=(_numerator*a._denominator-_denominator*a._numerator)/gongyue;
    fraction b=fraction(newnum,bei);
    b.simp();
    return b;


}
fraction fraction::operator*(const fraction &a) const{
    if((a._denominator==0)||(_denominator==0)) return fraction(0,0);
    fraction b(_numerator*a._numerator,_denominator*a._denominator);
    b.simp();
    return b;
}
fraction fraction::operator/(const fraction &a) const{
    if((a._denominator==0)||(_denominator==0)) return fraction(0,0);
    fraction b(_numerator*a._denominator,_denominator*a._numerator);
    b.simp();
    return b;
}

void fraction::operator+=(const fraction &a){
    if(a._denominator==0||_denominator==0) return ;
    int gongyue=gcd(_denominator,a._denominator);
    int bei=_denominator*a._denominator/gongyue;//最小公倍数
    _numerator=(_numerator*a._denominator+_denominator*a._numerator)/gongyue;
    _denominator=bei;
    simp();
    return ;
}
void fraction::operator-=(const fraction &a){
    if(a._denominator==0||_denominator==0) return ;
    int gongyue=gcd(_denominator,a._denominator);
    int bei=_denominator*a._denominator/gongyue;//最小公倍数
    _numerator=(_numerator*a._denominator-_denominator*a._numerator)/gongyue;
    _denominator=bei;
    simp();
    return ;
}
void fraction::operator*=(const fraction &a){
    if(a._denominator==0||_denominator==0) return ;
    _numerator*=a._numerator;
    _denominator*=a._denominator;
    simp();
}
void fraction::operator/=(const fraction &a){
    if(a._denominator==0||_denominator==0) return ;
    _numerator*=a._denominator;
    _denominator*=a._numerator;
    simp();
}

// Comparison operators
bool fraction::operator==(const fraction & a) const{
    if((_numerator==a._numerator&&_denominator==a._denominator)||(_denominator==0&&a._denominator==0)){
        return true;
    }
    else return false;
}
bool fraction::operator!=(const fraction &a) const{
    if((_numerator==a._numerator&&_denominator==a._denominator)||(_denominator==0&&a._denominator==0)){
        return false;
    }
    else return true;
}
bool fraction::operator<(const fraction &a) const{
    if(_denominator==0||a._denominator==0) return false;
    int _nu=_numerator,_de=_denominator,_nua=a._numerator,_dea=a._denominator;
    if(_de<0){ _nu*=-1;_de*=-1;}
    if(_dea<0) {_nua*=-1; _dea*=-1;}
    if(_nu*_dea<_de*_nua){
        return  true;
    }
    else return false;

}
bool fraction::operator>(const fraction &a) const{
    if(_denominator==0||a._denominator==0) return false;
    int _nu=_numerator,_de=_denominator,_nua=a._numerator,_dea=a._denominator;
    if(_de<0){ _nu*=-1;_de*=-1;}
    if(_dea<0) {_nua*=-1; _dea*=-1;}
    if(_nu*_dea<=_de*_nua){
        return false;
    }
    else return true;

}
bool fraction::operator<=(const fraction &a) const{
    if(_denominator==0||a._denominator==0) return false;
    int _nu=_numerator,_de=_denominator,_nua=a._numerator,_dea=a._denominator;
    if(_de<0){ _nu*=-1;_de*=-1;}
    if(_dea<0) {_nua*=-1; _dea*=-1;}
    if(_nu*_dea<=_de*_nua){
        return  true;
    }
    else return false;

}
bool fraction::operator>=(const fraction &a) const{
    if(_denominator==0||a._denominator==0) return false;
    int _nu=_numerator,_de=_denominator,_nua=a._numerator,_dea=a._denominator;
    if(_de<0){ _nu*=-1;_de*=-1;}
    if(_dea<0) {_nua*=-1; _dea*=-1;}
    if(_nu*_dea<_de*_nua){
        return false;
    }
    else return true;

}

std::istream & operator>>(std::istream &is, fraction &a){
    is>>a._numerator>>a._denominator;
    a.simp();
    if(a._numerator<0&&a._denominator<0){
        a._denominator*=-1;
        a._numerator*=-1;
    }
    return is;
}
// Input Format: two integers with a space in it
// "a b" is correct. Not "a/b"
std::ostream & operator<<(std::ostream &os, const fraction &a){
    if(a._denominator==0){
        os<<"NaN";
    }
    else {
        if(a._numerator%a._denominator==0){
            os<< a._numerator/a._denominator;
        }
        else if(a._numerator>0&&a._denominator<0){
            os<<'-'<<a._numerator<<'/'<<a._denominator*(-1);
        }


        else os<<a._numerator<<'/'<<a._denominator;
    }
    return os;
}