#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &ds,int low,int mid,int high)
{
	vector<int> temp;
	int left =low;
	int right=mid+1;
	while(left<=mid && right <=high)
	{
		if(ds[left]<=ds[right])
		{
			temp.push_back(ds[left]);
			left++;
		}
		else
		{
			temp.push_back(ds[right]);
			right++;
		}
	}
	while(left<=mid)
	{
		temp.push_back(ds[left]);
		left++;
	}
	while(right<=high)
	{
		temp.push_back(ds[right]);
		right++;
	}
	for(int i=low;i<=high;i++)
	{
		ds[i]=temp[i-low];
	}
}

void merge_sort(vector<int> &ds,int low,int high)
{
	if (low==high)
	{
		return;
	}
	int mid = (low+high)/2;
	merge_sort(ds,low,mid);
	merge_sort(ds,mid+1,high);
	merge(ds,low,mid,high);
}

int main(){
	int len;
	cout<<"Enter Number Of elements"<<endl;
	cin>>len;
	vector<int> arr;
	int temp;
	for(int i=0;i<len;i++)
	{
		cin>>temp;
		arr.push_back(temp);
	}
	merge_sort(arr,0,len-1);
	for(auto it : arr)
	{
		cout<<it<<" ";
	}
}

