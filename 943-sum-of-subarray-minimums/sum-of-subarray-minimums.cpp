class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pse(vector<int> arr){
        stack<int> st;
        int n= arr.size();
        vector<int> pse(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return pse;
    }

    vector<int> nsoeq(vector<int> arr){
        stack<int> st;
        int n= arr.size();
        vector<int> nsoeq(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            nsoeq[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return nsoeq;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int s = arr.size();
        long long total = 0;

        vector<int> psev = pse(arr);
        vector<int> nsoeqv = nsoeq(arr);
        for(int i=0;i<s;i++){
            long long left = i-psev[i];
            long long right = nsoeqv[i]-i;
            total = (total +(1LL*right*left*arr[i]) % MOD) % MOD;
        }

        return total;
    }
};