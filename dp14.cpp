#include<iostream>
#include<vector>
using namespace std;
int f(vector<int>&v,int index,int prev,vector<vector<int>>&dp){
	if(index==v.size())return 0;
	if(dp[index][prev+1]!=-1)return dp[index][prev+1];
	if(prev==-1||v[index]<v[prev])return dp[index][prev+1]=max(1+f(v,index+1,index,dp),f(v,index+1,prev,dp));
	else return  dp[index][prev+1]=f(v,index+1,prev,dp);
}
int main(){
	int n;cin>>n;
	vector<int> v(n);
	for(int it=0;it<n;it++){
		cin>>v[it];
	}
	vector<vector<int>>dp(n,vector<int>(n+1,-1));
	int ans=f(v,0,-1,dp);
	cout<<ans<<endl;

}