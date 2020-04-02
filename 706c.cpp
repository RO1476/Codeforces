#include<bits/stdc++.h>
#define N 100002
#define int long long
using namespace std;
string s[N];
int a[N];

#define inf 1000000000000000

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin>>n;
	for(int i = 0;i < n; i++) cin>>a[i];
	for(int i = 0;i < n; i++) cin>>s[i];
	int ans = -1;
	int dp[n][2];//dpij=>min amt of energy for 1st i strings j=0=>ith same j=1=>ith reversed
	for(int i = 0;i < n; i++) dp[i][0] = dp[i][1] = inf;
	dp[0][0] = 0;
	dp[0][1] = a[0];
	for(int i = 1;i < n; i++){
		string curr = s[i],prev = s[i-1];
		string rcurr = curr;reverse(rcurr.begin(),rcurr.end());
		string rprev = prev;reverse(rprev.begin(),rprev.end());
		if(curr >= prev) dp[i][0] = dp[i-1][0];
		if(curr >= rprev) dp[i][0] = min(dp[i][0],dp[i-1][1]);
		if(rcurr >= prev) dp[i][1] = a[i]+dp[i-1][0];
		if(rcurr >= rprev) dp[i][1] = min(dp[i][1],a[i]+dp[i-1][1]);
	}
	ans = min(dp[n-1][0],dp[n-1][1]);
	if(ans==inf) ans = -1;
	cout<<ans<<endl;
}














