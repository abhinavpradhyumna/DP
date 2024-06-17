#include<bits/stdc++.h>
using namespace std;

int minimumcoins(vector<int> &coins,vector<int> &path , int index,int b)
{
	int min_cost=0;
	if(index==0)
	{
		return coins[index];
	}
	if (index<0) return 0;
	if(index==coins.size()-1) {path.push_back(index );}
	int ind=0;
	int cost=INT_MAX;
	for(int k=1;k<=b;k++)
	{
		if((index-k)>=0)
		{
			if(coins[index-k]==-1) continue;
			if(coins[index-k]<cost)
			{
				cost=coins[index-k];
				ind=index-k;
			}
		}
	}
	if (cost != INT_MAX){path.push_back(ind);}
	if(cost==INT_MAX) return cost;
	if(ind>=0){
		min_cost=cost+minimumcoins(coins,path,ind,b);
	}
	
	return min_cost;
}
int main()
{
	vector<int> coins={1,2,4,-1,2};
	int b=1;
	vector<int> path ={} ;
	int x=minimumcoins(coins,path,4,b);
	if(x==INT_MAX) {cout<<"PAth is empty";return 0;}
	for (int i : path) {
            cout << i << " ";
        }
	
}
/*#include<bits/stdc++.h>
using namespace std;

int minimumcoins(vector<int> &coins, vector<int> &path, int index, int b) {
    if (index == 0) {
        return coins[0];
    }
    if (index < 0 || coins[index] == -1) return INT_MAX;  // Invalid index or position

	if(index==coins.size()-1) path.push_back(index);

    int min_cost = INT_MAX;
    int best_ind = -1;

    // Check up to `b` steps back
    for (int k = 1; k <= b; k++) {
        int prev_index = index - k;
        if (prev_index >= 0 && coins[prev_index] != -1) {
            int cost = minimumcoins(coins, path, prev_index, b);
            if (cost < min_cost) {
                min_cost = cost;
                best_ind = prev_index;
            }
        }
    }

    if (best_ind != -1) {
        path.push_back(best_ind);
        return coins[index] + min_cost;
    }
    return INT_MAX;  // No valid path found
}

int main() {
    vector<int> coins = {1, 2, 4, -1, 2};
    int b = 2;
    vector<int> path;
    int min_cost = minimumcoins(coins, path, coins.size() - 1, b);
    
    if (min_cost == INT_MAX) {
        cout << "No valid path found" << endl;
    } else {
        reverse(path.begin(), path.end());
        cout << "Minimum cost: " << min_cost << endl;
        cout << "Path: ";
        for (int i : path) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}*/

