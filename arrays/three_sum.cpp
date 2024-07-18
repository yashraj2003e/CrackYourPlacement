class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++) {

            int first = nums[i];

            int second = i + 1;
            int third = nums.size()-1;

            while(second<third) {
                int sum = first+nums[second]+nums[third];
                if(sum == 0) {
                    result.push_back({first,nums[second],nums[third]});
                    int tempIndex1 = second, tempIndex2 = third;
                    while(second < third && nums[second] == nums[tempIndex1]) second++;
                    while(second < third && nums[third] == nums[tempIndex2]) third--;
                }                
                else if(sum>0) {
                    third--;
                }
                else {
                    second++;
                }
            }

            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }
    

        return result;


    }
};