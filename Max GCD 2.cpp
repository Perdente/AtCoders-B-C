//https://atcoder.jp/contests/jsc2021/tasks/jsc2021_c
/*
we need to check the if the no of multiples of i betn 1<=i<=m is at least 2?
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long int

signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n,m;cin>>n>>m;
	for(int i=m;i>=1;--i){
		if((m/i)-((n-1)/i)>=2){
			return cout<<i<<endl,0;
		}
	}
	
	return 0;
}
