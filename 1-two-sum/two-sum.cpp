class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>final;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    final.push_back(i);
                    final.push_back(j);
                    return {i,j};
                }

            }
        }
        return {};
    }
};