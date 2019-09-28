#include<bits/stdc++.h>
#define int long long
int a[300001],b[300001];
int dp[300001][3];
using namespace std;

int32_t main(){
int q;//int n;
//cin>>q;
scanf("%lld",&q);
while(q--){
    //cin>>n;
    int n;scanf("%lld",&n);
    for(int pos = 0; pos < n; pos++){ scanf("%lld",a + pos);scanf("%lld",b + pos);}//cin>>a[pos]>>b[pos];
    /*if(n==1){
        cout<<0<<endl;
        continue;
    }*/
    //memset(dp,INT_MAX,sizeof(dp));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) dp[i][j] = 1000000000000000001;
    }
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) cout<<dp[i][j]<<" \n"[j==2];
    }*/
    for(int x = 0; x < 3; x++) dp[0][x] = x*b[0];
    for(int pos = 1; pos < n; pos++){
        for(int add = 0; add < 3; add++){
            for(int x = 0; x < 3; x++){
                 if(a[pos] + add != a[pos-1] + x) dp[pos][add] = min(dp[pos][add],add*b[pos] + dp[pos-1][x]);
            }
        }
    }
    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++) cout<<dp[i][j]<<" \n"[j==2];
    }*/
    cout<<min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2])<<endl;
    //printf("%lld\n",min(min(dp[n-1][0],dp[n-1][1]),dp[n-1][2]));
}
}
/*
1
3
2 4
2 1
3 5
*/
