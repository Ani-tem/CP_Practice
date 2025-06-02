#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n;cin>>n;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	vector<int> tem;
	for(auto it:v){
		if(tem.empty()||tem.back()<it){
			tem.push_back(it);
		}
		else{
			auto i=lower_bound(tem.begin(),tem.end(),it)-tem.begin();
			tem[i]=it;
		}
	}
	cout<<tem.size()<<endl;
}