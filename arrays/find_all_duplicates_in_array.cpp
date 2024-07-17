class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for(int i=0;i<nums.size();i++) {

            int abs_num = abs(nums[i]);
            int n = abs_num-1;

            if(nums[n]<0) {
                result.push_back(abs_num);
            }

            nums[n]*=-1;
        }

        return result;


    }
};