#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int jump(int dp[],int energy[],int n)
{
	if(n==0)
	{
		return 0;
	}
	if(dp[n]!=-1)
	{
		return dp[n];
	}
	if(n==1)
	{
		dp[n]=jump(dp,energy,n-1)+abs(energy[1]-energy[0]);
	}
	
	
	if(n>1){
		dp[n]=min(jump(dp,energy,n-1)+abs(energy[n]-energy[n-1]),jump(dp,energy,n-2)+abs(energy[n]-energy[n-2]));	
	}

	return dp[n];
}
int main()
{
	int n=5;
	int arr[] = {30,10,60,10,60,50};
	int dp[n+1]={-1,-1,-1,-1,-1,-1};
	cout<<jump(dp,arr,n);
}
