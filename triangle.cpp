class Solution {
public:
    int path(int index,int pos,vector<vector<int>>&dp , vector<vector<int>> &tri)
    {
        int same=0;
        int notsame=0;
        if (index==tri.size()-1)
        {
            return tri[index][pos];
        }
        if(pos>tri[index].size()-1) return 0;
        if(index>tri.size()-1) return 0;
        if(dp[index][pos]!=-1) return dp[index][pos];
        same=tri[index][pos]+path(index+1,pos,dp,tri);
        notsame=tri[index][pos]+path(index+1,pos+1,dp,tri);
        return dp[index][pos]=min(same,notsame);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>> dp (n+1,vector<int> (n+1,-1));
        return path(0,0,dp,triangle);
    }
};
