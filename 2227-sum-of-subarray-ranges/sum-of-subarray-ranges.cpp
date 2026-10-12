class Solution {
public:
    vector<int> pse(vector<int> nums){
        int n=nums.size();
        stack<int> st;
        vector<int> vec(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            vec[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return vec;
    }

    vector<int> nsoee(vector<int> nums){
        int n=nums.size();
        stack<int> st;
        vector<int> vec(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>nums[i]){
                st.pop();
            }
            vec[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return vec;
    }

    vector<int> pge(vector<int> nums){
        int n=nums.size();
        stack<int> st;
        vector<int> vec(n);

        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<=nums[i]){
                st.pop();
            }
            vec[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return vec;
    }

    vector<int> ngoee(vector<int> nums){
        int n=nums.size();
        stack<int> st;
        vector<int> vec(n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<nums[i]){
                st.pop();
            }
            vec[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return vec;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> lmin = pse(nums);
        vector<int> rmin = nsoee(nums);

        vector<int> lmax = pge(nums);
        vector<int> rmax = ngoee(nums);

        long long min=0,max=0;

        for(int i=0;i<n;i++){
            min = min + (1LL *(i-lmin[i])*(rmin[i]-i)*nums[i]);
        }

        for(int i=0;i<n;i++){
            max = max + (1LL *(i-lmax[i])*(rmax[i]-i)*nums[i]);
        }

        return max-min;
    }
};