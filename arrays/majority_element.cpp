class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int element = nums[0];
        for(int i=0;i<nums.size();i++) {
            if(element == nums[i]) {
                count++;
            }
            else {
                count--;
                if(count==0) {
                    count = 1;
                    element = nums[i];
                }
            }
        }
        return element;
    }
};