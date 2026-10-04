class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        vector<int> pos(n1,-1);
        for(int i=0;i<n1;i++){
            for(int j=0;j<nums2.size();j++){
                if(pos[i]!=-1) continue;
                if(nums2[j]==nums1[i]){
                    pos[i]=j;
                    break;
                }
            }
        }

        vector<int> st;
        for(int i=0;i<n1;i++){
            int cond =0;
            for(int j=pos[i];j<nums2.size();j++){
                if(nums2[j]>nums1[i]){
                    cond =1;
                    st.push_back(nums2[j]);
                    break;
                }
            }
            if(!cond) st.push_back(-1);
        }

        return st;
    }
};