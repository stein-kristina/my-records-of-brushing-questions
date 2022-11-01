//
// Created by 86189 on 2022/9/24.
//

int cal(string s,int &i){
    stack<int> ans;
    char x='+';
    int num=0;
    int sum=0;
    for(i;i<s.size();i++){
        //if(s[i]==' ') continue;
        if(isdigit(s[i])){
            num=num*10+(s[i]-'0');
        }

        if(s[i]=='('){
            num=cal(s,++i);
            i++;
        }

        if(((s[i]<'0'||s[i]>'9')&&s[i]!=' ')||i>=s.size()-1){
            int temp=0;
            switch(x){
                case '+':
                    ans.push(num);break;
                case '-':
                    ans.push(-num);break;
                case '*':
                    temp=ans.top();
                    ans.pop();
                    ans.push(temp*num);
                    break;
                case '/':
                    temp=ans.top();
                    ans.pop();
                    ans.push(temp/num);
                    break;

            }
            x=s[i];
            num=0;
        }
        if(s[i]==')') break;
    }
    while(!ans.empty()){
        int t=ans.top();
        ans.pop();
        sum+=t;
    }
    return sum;
}
int calculate(string s) {
    int begin=0;
    return cal(s,begin);
}