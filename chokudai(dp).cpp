//https://atcoder.jp/contests/abc211/tasks/abc211_c
//https://atcoder.jp/contests/abc211/editorial/2327
//find the number of subsequences of T from string S
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int mod=1e9+7;

void Malena(){
	string s;cin>>s;
	string t="chokudai";
	int n=s.size(),m=8;
	int dp[n+1][m+1];
	// dp[i][j]= num of combination of j char from i of string s 
	//			 that combines first j chars of "chokudai"

	for(int i=0;i<=n;++i)
		dp[i][0]=1;//when no characters is underlined
	for(int j=1;j<=m;++j)
		dp[0][j]=0;//no combination of characters is chosen
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(s[i-1]!=t[j-1]){
				dp[i][j]=dp[i-1][j];
			}else{
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
			}
			dp[i][j]%=mod;
		}
	}
	cout<<dp[n][m]<<'\n';
}

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	t=1;
	//cin>>t;
	while(t--){
		Malena();
	}
	return 0;
}
