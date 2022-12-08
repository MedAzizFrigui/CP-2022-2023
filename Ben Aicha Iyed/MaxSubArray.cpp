class Solution {
public:
    int n,T,F;
    int maxSubArray(vector<int>& nums){
        n=nums.size();
        T=F=nums[0];
        for(int i=1;i<n;++i){
            T=max(0,T)+nums[i];
            F=max(T,F);
        }
        return F;
    }
};
