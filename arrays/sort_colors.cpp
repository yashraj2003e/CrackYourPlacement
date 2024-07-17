class Solution {
public:
    void sortColors(vector<int>& nums) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int zero = -1;
        int two = -1;

        int i = 0;
        int j = nums.size()-1;

        while(i<=j) {
            while(j>-1 && nums[j]!=0) j--;
            while(i<nums.size()-1 && nums[i]==0) i++;
            if(i>j) break;
            swap(nums[i],nums[j]);
            i++;j--;
        }

        i = 0;
        j = nums.size()-1;

        while(i<=j) {
            while(j>-1 && nums[j]!=1) j--;
            while(i<nums.size()-1 && nums[i]!=2) i++;
            if(i>j) break;
            swap(nums[i],nums[j]);
            i++;j--;
        } 
    }
};