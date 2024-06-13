#include<bits/stdc++.h>
using namespace std;
 int paintHouse(int index,vector<int> &dp , vector<vector<int>> A,int opt=3)
 {
     int red=999;
     int blue=999;
     int green=999;
     if (index==0)
	 {
	 	int mini=INT_MAX;
	 	for(int i=0;i<=2;i++)
	 	{
	 		if(i==opt) continue;
	 		else
	 		{
	 			mini=min(A[index][i],mini);
			 }
		 }
		 return mini;
	 }
     if(index<0) return 0;
     if(dp[index]!=-1) return dp[index];
     if(opt==0 or opt==3)
     {
     green= A[index][1]+paintHouse(index-1,dp,A,1);
     blue= A[index][2]+paintHouse(index-1,dp,A,2);
     }
     if(opt==1 or opt==3)
     {
         red= A[index][0]+paintHouse(index-1,dp,A,0);
         blue= A[index][2]+paintHouse(index-1,dp,A,2);
     }
     if(opt==2 or opt==3)
     {
         red= A[index][0]+paintHouse(index-1,dp,A,0);
         green= A[index][1]+paintHouse(index-1,dp,A,1);
     }
     dp[index]=min(red,green);
     dp[index]=min(dp[index],blue);
     return dp[index];
}
 
int main() {
	vector<vector<int>>costs = { { 14, 2, 11 },
                      { 11, 14, 5 },
                      { 14, 3, 10 } };
    int n= costs.size();
    vector<int> dp (n,-1);
    cout<<paintHouse(n-1,dp,costs,3);
    
}
