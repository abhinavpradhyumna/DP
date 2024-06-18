class Solution {
public:

    int path(int row,int col,vector<vector<int>> &dp , vector<vector<int>> &grid)
    {
        int up , left ;
        if(row<0 || col<0) return 1e9;
        if(row==0 && col==0)
        {
            return grid[0][0];
        }
        if(dp[row][col]!=-1) return dp[row][col];
        up=grid[row][col]+path(row-1,col,dp,grid);
        left=grid[row][col]+path(row,col-1,dp,grid);
        return dp[row][col]=min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int row= grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp (row+1,vector<int> (col+1,-1));
        return path(row-1,col-1,dp,grid);

    }
};
