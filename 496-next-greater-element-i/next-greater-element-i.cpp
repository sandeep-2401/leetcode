class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n2 = nums2.size();
        vector<int> vec(n2);
        stack<int> st;
        for(int i=n2-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }

            if(st.empty()) {
                st.push(nums2[i]);
                vec[i]=-1;
            }

            else if(nums2[i]<st.top()){
                vec[i]=st.top();
                st.push(nums2[i]);
            }
        }

        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]) {
                    ans.push_back(vec[j]);
                    break;
                }
            }
        }

        return ans;
    }
};