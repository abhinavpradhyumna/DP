#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int stairs(int dp[] , int n)
{
	if(dp[n]!=-1) return dp[n];
	if(n==0) {
		return 1;
		
	}
	if(n==1)
	{
		 return 1;
	 }
	dp[n]=stairs(dp,n-1)+stairs(dp,n-2);
}

int main()
{
	int n=2;//dynamically obtain no of stairs
	int arr[n+1]={-1,-1,-1};//dynamically obtain dp
	cout<<stairs(arr,n);
	return 0;
}







