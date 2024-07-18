class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int lsum = 0;
        int rsum = 0;

        for(int i=0;i<k;i++) lsum+=cardPoints[i];
        int maxi = lsum;
        int i = k-1;
        int j = cardPoints.size()-1;

        while(i>-1) {
            lsum-=cardPoints[i];
            rsum+=cardPoints[j];
            i--,j--;
            maxi = max(maxi,lsum+rsum);
        }

        return maxi;




    }
};