#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a;cin>>n>>a;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());
	vector<vector<int>>dp(n+1,vector<int>(a+1,INT_MAX));
	for(int i=0;i<n+1;i++){
		dp[i][0]=0;
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<a+1;j++){
			if(v[i-1]<=j&& dp[i][j - v[i - 1]] != INT_MAX){
			   dp[i][j]=min(dp[i-1][j],1+dp[i][j-v[i-1]]);
			}
			else dp[i][j]=dp[i-1][j];
		}
	}
	
	cout<<((dp[n][a]==INT_MAX)?-1:dp[n][a])<<endl;

		
}