#include<iostream>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int& x:a) cin >>x;
        sort(a.begin(),a.end());
        int ans=1;          
        for(int l=0;l<n;++l){
            for(int r=l;r<n;++r){
                if( (a[l]+a[r])%2==0 )
                   ans=max(ans,r-l+1);
            }
        }

        cout<<(n-ans)<<endl;
    }

}
