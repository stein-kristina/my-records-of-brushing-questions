//
// Created by 86189 on 2022/10/9.
//
string robotWithString(string s) {
    vector<int> alp(26,0);
    int l=s.length();
    string p;
    for(int i=0;i<l;i++){
        alp[s[i]-'a']++;
    }
    int minone=0;
    stack<char> st;
    for(int i=0;i<l;i++){
        alp[s[i]-'a']--;
        while(minone<26&&!alp[minone]) minone++;
        st.push(s[i]);
        while(!st.empty()&&st.top()-'a'<=minone){
            p+=st.top();
            st.pop();
        }
    }
    return p;
}
