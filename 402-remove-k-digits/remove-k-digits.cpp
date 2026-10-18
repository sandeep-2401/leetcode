class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int len = num.size();

        for(int i=0;i<len;i++){
            while(!st.empty() && num[i]<st.top() && k){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while(k){
            st.pop();
            k--;
        }

        string s = "";

        while(!st.empty()){
            s+=st.top();
            st.pop();
        }

        reverse(s.begin(),s.end());

        int ind =0;

        while(ind <s.size() && s[ind]=='0'){
            ind++;
        }
        s.erase(0,ind);

        if(s.size()>=1){
            return s;
        }
        
        return "0";
    }
};