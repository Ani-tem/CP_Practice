#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n,a;cin>>n>>a;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int mod=1e9+7;
	vector<vector<int>>dp(n+1,vector<int>(a+1,0));
	for(int i=0;i<n+1;i++){
		dp[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a;j++){
			if(v[i-1]<=j){
				dp[i][j]=(dp[i-1][j]+dp[i][j-v[i-1]])%mod;
			}
			else dp[i][j]=dp[i-1][j];
		
		}
	}
	cout<<dp[n][a];
}