//graph-coloring
#include<bits/stdc++.h>
using namespace std;
#define int long long int
 
vector<bool>visited;
vector<vector<int>>graph;
vector<int>colors,level;
int dfs(int u){
	int cnt=1;
	visited[u]=true;
	for(auto v:graph[u]){
		if(level[v]!=0 and level[v]!=level[u]+1){
			if(colors[v]==colors[u])cnt=0;
			continue;
		}
		level[v]=level[u]+1;
		int temp=0;
		for(int i=1;i<=3;++i){
			if(i==colors[u])continue;
			colors[v]=i;
			temp+=dfs(v);
			colors[v]=0;
		}
		cnt*=temp;
	}
	return cnt;
}
 
signed main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n>>m;
	graph.resize(n+1);
	visited.resize(n+1);
	colors.resize(n+1);
	level.resize(n+1);
	for(int i=0;i<m;++i){
		int x,y;cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	int ans=1;
	for(int i=1;i<=n;++i){
		if(!visited[i]){
			colors[i]=1;
			level[i]=1;
			ans*=3*dfs(i);
		}
	}
	cout<<ans<<'\n';	
	return 0;
}
