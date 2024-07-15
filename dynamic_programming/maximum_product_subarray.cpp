class Solution {
public:
    int maxProduct(vector<int>& nums) {
        double max_pos = 1,max_neg = 1;
        double cur_pos = INT_MIN;
        double cur_neg = INT_MIN;

        for(int i=0;i<nums.size();i++) {
            if(max_pos==0) {
                max_pos = 1;
            }
            max_pos*=nums[i];
            cur_pos = max(cur_pos,max_pos);
        }
        for(int i=nums.size()-1;i>-1;i--) {
            if(max_neg==0) {
                max_neg = 1;
            }
            max_neg*=nums[i];
            cur_neg = max(cur_neg,max_neg);
        }

        return (int)max(cur_pos,cur_neg);

    }
};