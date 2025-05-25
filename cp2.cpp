#include<iostream>
#include<vector>
using namespace std;
bool is(const string &t) {
    int bal=0;
    if (t.size()%2) return false;   
    for (char c:t) {
        bal+=(c=='('?+1:-1);
        if (bal<0) return false;     
    }
    return bal==0;                   
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--) {
        string s;
        cin >> s;
        if(s.size()>=2){
        string mid=s.substr(1,s.size()-2);
        cout<<(is(mid)?"NO":"YES")<<endl;
   		}
    }
}
