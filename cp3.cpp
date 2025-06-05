#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> d(n+1),l(n+1),r(n+1),a(n+1),b(n+1),h(n+1);
        for (int i=1;i<=n;i++)cin>>d[i];
        for (int i=1;i<=n;i++)cin>>l[i]>>r[i];
        a[0]=b[0]=0;
        bool flag=true;
        for (int i=1;i<= n;i++) {
            int x=a[i-1],y=b[i-1];
            if (d[i] == -1) {
                x+=0;
                y+=1;
            } else {
                x+=d[i];
                y+=d[i];
            }
            x=max(x,l[i]);
            y=min(y,r[i]);
            if (x>y) {
                flag=false;
                break;
            }
            a[i]=x;
            b[i]=y;
        }
        if (!flag) {
            cout <<-1<<endl;
            continue;
        }
        h[n]=a[n];
        for (int i=n;i>=1;i--) {
            if (d[i]!=-1) {
                h[i-1]=h[i]-d[i];
            } else {
                if (h[i]>=a[i-1]&&h[i]<=b[i-1]) {
                    d[i]=0;
                    h[i-1]=h[i];
                } else {
                    d[i]=1;
                    h[i-1]=h[i]-1;
                }
            }
        }
        for (int i=1;i<=n;i++){
            if(i==n)cout<<d[i]<<endl;
            else cout<<d[i]<<" ";
        }
    }
}
