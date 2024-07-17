class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> myMap;

        int prefix = 0;
        myMap[0] = 1;
        int total = 0;
        for(int i=0;i<nums.size();i++) {
            prefix+=nums[i];
            int rem = prefix%k;
            if(rem<0) rem+=k;
            if(myMap.find(rem)!=myMap.end()) {
                total+=myMap[rem];
            }
            myMap[rem]++;
        }

        return total;

    }
};