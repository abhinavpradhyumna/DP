class Solution {
public:

    int path(int row, int col , vector<vector<int>> &dp , vector<vector<int>> &ob)
    {
        if(row<0 || col <0) return 0;
        int up , left;
        if(row==0 && col==0)
        {
            if(ob[row][col]==1) return 0;
            return 1;
        }
        if(dp[row][col]!=-1) return dp[row][col];
        if(ob[row][col]==1) return 0;
        up=path(row-1,col,dp,ob);
        left=path(row,col-1,dp,ob);
        return dp[row][col]=up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp (row+1,vector<int>(col+1,-1));
        return path(row-1,col-1,dp,obstacleGrid);
    }
};
