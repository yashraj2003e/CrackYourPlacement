class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(),a.end());
    
    long long min_diff = INT_MAX;
    for(int i=m-1;i<a.size();i++){
        min_diff = min(min_diff,a[i]-a[i-m+1]);
    }
    return min_diff;
    
    }   
};