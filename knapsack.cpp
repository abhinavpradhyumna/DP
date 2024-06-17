#include<bits/stdc++.h>
using namespace std;

int maxsteal(vector<int> &dp , int index , int w ,vector<int> val , vector<int> wt)
{
	int pick = INT_MIN;
	int notpick = INT_MIN;
	if(w==0) return 0;
	if(index==0)
	{
		if(wt[index]<=w)
		{
			return val[index];
		}
		else return 0;
	}
	if(index<0) return INT_MIN;
	if(dp[index]!=-1) return dp[index];
	if(wt[index]<=w)
	{
		pick = val[index]+maxsteal(dp,index-1,w-wt[index],val,wt);
	}
	notpick=maxsteal(dp,index-1,w,val,wt);
	return dp[index]=max(pick,notpick);
}
int main()
{
	vector<int> wt={4,5,6};
	vector<int> val={1,2,3};
	int n=wt.size();
	vector<int> dp (n,-1);
	int w=3;
	cout<<maxsteal(dp,n-1,w,val,wt);
}
