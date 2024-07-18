class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> myMap;
        int prefix = 0;
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            prefix+=nums[i];
            if(prefix-k==0) count++;
            if(myMap.find(prefix-k)!=myMap.end()) {
                count+=myMap[prefix-k];
            }
            myMap[prefix]++;
        }
        return count;
    }
};