//https://atcoder.jp/contests/abc191/tasks/abc191_c
//number of corners is number of edges
/* How to find corners-
1. ..........
            .
            .
            . grid[i][j]=1,grid[i+1][j]=0,grid[i][j+1]=0,grid[i+1][j+1]=0
2. .
   .
   .
   ......... grid[i][j]=1,grid[i+1][j]=1,grid[i][j+1]=1,grid[i+1][j+1]=0
   
   Loop through all the points and if 4 points are odd then it's corner(++ans)
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	int h,w;cin>>h>>w;
	vector<vector<bool>>grid(h,vector<bool>(w));
	for(int i=0;i<h;++i){
	    string s;cin>>s;
	    for(int j=0;j<w;++j){
	        grid[i][j]=s[j]=='#';
	    }
	}
	int ans=0;
	for(int i=0;i+1<h;++i){
	    for(int j=0;j+1<w;++j){
	        bool check=0;
	        check^=grid[i][j];
	        check^=grid[i+1][j];
	        check^=grid[i][j+1];
	        check^=grid[i+1][j+1];
	        ans+=check;
	    }
	}
	cout<<ans<<"\n";
	return 0;
}

