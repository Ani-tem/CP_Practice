#include<iostream>
#include<vector>
using namespace std;
int mod=1e9+7;
// int f(int n,int count,vector<int>&dp){
// 	if(count==n){
//        return 1;
// 	}
// 	if(dp[count]!=-1)return dp[count];
// 	int sub=0;
// 	for(int i=1;i<=6;i++){
// 		if(count+i<=n){
// 			sub=(sub+f(n,count+i,dp))%mod;
// 		}
// 	}
// 	return dp[count]=sub;
// }
int main(){
	int n;cin>>n;
	
	vector<int> dp(n+1,0);
	dp[n]=1;
	for(int i=n-1;i>=0;i--){
		int sub=0;
		for(int j=1;j<=6;j++){
		if(i+j<=n){
			sub=(sub+dp[i+j])%mod;
		}
	    }
	    dp[i]=sub;
	}

	

	cout<<dp[0];

}