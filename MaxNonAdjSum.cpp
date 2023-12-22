#include <bits/stdc++.h> 

int maxNonAdj(vector<int> &nums , int index,vector<int> &dp)
{
    int pick;
    int notpick;
    if(dp[index]!=-1)
    {
        return dp[index];
    }
    if(index==0)
    {
        return nums[index];
    }
    if(index<0) return 0;
    pick = nums[index]+maxNonAdj(nums,index-2,dp);
    notpick= maxNonAdj(nums,index-1,dp);
    dp[index] = max(pick,notpick);
    return dp[index];

}


int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    vector<int> dp;
    for(int i=0;i<nums.size();i++)
    {
        dp.push_back(-1);
    }
    return maxNonAdj(nums,nums.size()-1,dp);
}
