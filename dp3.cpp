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
	vector<int>dp(a+1,0);
	dp[0]=1;
	for(int i=1;i<=a;i++){
		for(int j=0;j<n;j++){
			if(v[j]<=i){
				dp[i]=(dp[i]+dp[i-v[j]])%mod;
			}
		}
	}
	cout<<dp[a]<<endl;

}