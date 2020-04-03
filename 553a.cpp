#include<bits/stdc++.h>
#define int long long
#define modulo 1000000007
using namespace std;

int nCrModp(int n, int r, int p = modulo) 
{ 
    // The array C is going to store last row of 
    // pascal triangle at the end. And last entry 
    // of last row is nCr 
    int C[r+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; // Top row of Pascal Triangle 
  
    // One by constructs remaining rows of Pascal 
    // Triangle from top to bottom 
    for (int i = 1; i <= n; i++) 
    { 
        // Fill entries of current row using previous 
        // row values 
        for (int j = min(i, r); j > 0; j--) 
  
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 	

int32_t main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int a[n],pref[n];
	cin>>a[0];pref[0] = a[0];
	for(int i = 1;i < n; i++){
		cin>>a[i];
		pref[i] = pref[i-1] + a[i];
	}
	int dp[n];
	dp[0] = 1;
	for(int i = 1;i < n; i++){
		int r = pref[i-1] + 1;
		int n = a[i]-1;
		int factor = nCrModp(n+r-1,r-1);//C(n+r-1,r-1);
		dp[i] = dp[i-1]*factor;
		dp[i] %= modulo;
	}
	cout<<dp[n-1]<<endl;
}
