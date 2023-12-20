#include<bits/stdc++.h>
#include<iostream>
using namespace std;


int fib(int arr[],int n) // n - nth Fibonacci (0 indexed) 
{
	if(n==0) return 0;
	if(n==1) return 1;
	if(arr[n] !=-1) return arr[n];
	arr[n] = fib(arr,n-1) + fib(arr,n-2);
	
}

int main()
{
	int arr[] = {-1,-1,-1,-1,-1,-1};
	int ans = fib(arr,4);
	cout<<ans;
}
