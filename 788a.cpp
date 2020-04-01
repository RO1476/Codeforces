#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i < n; i++) cin>>a[i];
	int dp[n-1][2];//0=>max 1=>min
	dp[n-2][0] = abs(a[n-2]-a[n-1]);
	dp[n-2][1] = 0ll;
	for(int i = n-3; i >= 0; i--){
		dp[i][0] = abs(a[i] - a[i+1]) + max(-1*dp[i+1][1],0ll);
		dp[i][1] = abs(a[i] - a[i+1]) + min(-1*dp[i+1][0],0ll);
	}
	int ans = dp[0][0];
	for(int i = 0; i < n-1; i++){
		for(int j = 0;j < 2; j++) ans = max(ans,dp[i][j]);
	}
	cout<<ans<<endl;
}

















