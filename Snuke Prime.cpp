//https://atcoder.jp/contests/abc188/tasks/abc188_d
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 2e5+5;
int n,k;
int a[N],b[N],c[N];
map<int,int>mp;
signed main()
{
	cin>>n>>k;
	for(int i=1;i<=n;++i){
	    cin>>a[i]>>b[i]>>c[i];
	    mp[a[i]]+=c[i];
	    mp[b[i]+1]-=c[i];
	}
	int ans=0,cur=0,prev=0;
	for(auto &it:mp)
	{
	    ans+=min(k,cur)*(it.first-prev);
	    cur+=it.second;
	    prev=it.first;
	}
	cout<<ans<<endl;
	
	
	return 0;
}
