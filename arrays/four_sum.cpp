class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int& k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i=0;i<nums.size();i++) {
            for(int j=i+1;j<nums.size();j++) {
                int left = j+1;
                int right = nums.size()-1;
                while(left<right) {
                    long long sum = (long long)(nums[i] + nums[j]) + (long long)(nums[left] + nums[right]);
                    if(sum == k) {
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        int tempIndex1 = left, tempIndex2 = right;
                        while(left < right && nums[left] == nums[tempIndex1]) left++;
                        while(left < right && nums[right] == nums[tempIndex2]) right--;
                    }
                    else if(sum>k) {
                        right--;
                    }
                    else {
                        left++;
                    }
                }
                while(j+1<nums.size() && nums[j]==nums[j+1]) j++;
            }
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }
        return result;
    }
};