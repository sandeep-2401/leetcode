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
                vec[i]=-1;
            }

            else {
                vec[i]=st.top();
            }

            st.push(nums2[i]);
        }

        unordered_map<int, int> mp;
        for(int i = 0; i < nums2.size(); i++){
            mp[nums2[i]] = vec[i];
        }
        
        vector<int> ans;
        
        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(mp[nums1[i]]);
        }
        

        return ans;
    }
};