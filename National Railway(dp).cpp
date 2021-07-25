//dp
//https://atcoder.jp/contests/abc210/tasks/abc210_d
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	int h,w,cost;cin>>h>>w>>cost;
	vector<vector<int>>dp(h,vector<int>(w)),a(h,vector<int>(w));
	for(int i=0;i<h;++i){
		for(int j=0;j<w;++j){
			cin>>a[i][j];
		}
	}
	int rep=2;
	int mi=1LL<<60;
	while(rep--){
		for(int i=0;i<h;++i){
			for(int j=0;j<w;++j){
				int up=(i-1>=0?dp[i-1][j]:1LL<<60);
				int left=(j-1>=0?dp[i][j-1]:1LL<<60);
				dp[i][j]=min(a[i][j],min(up,left)+cost);
				mi=min(mi,min(up,left)+cost+a[i][j]);
			}
		}
		reverse(a.begin(), a.end());
		// for(int i=0;i<h;++i){
		// 	for(int j=0;j<w;++j){
		// 		cout<<a[i][j]<<" ";
		// 	}cout<<endl;
		// }
		// cout<<endl;
	}
	cout<<mi<<endl;
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
