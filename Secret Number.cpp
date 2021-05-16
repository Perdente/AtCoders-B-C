//https://www.youtube.com/watch?v=FHkLhKQOwK4&ab_channel=VkyGamingStarjiVkyGamingStarjiVerified
//https://atcoder.jp/contests/abc201/tasks/abc201_c
#include<bits/stdc++.h>
using namespace std;
#define int long long int

void Malena(){
	string s;cin>>s;
	auto good=[&](int password)->bool{
		unordered_set<int>st;
		for(int i=0;i<4;++i){
			st.insert(password%10);
			password/=10;
		}
		for(int i=0;i<10;++i){
			if(s[i]=='x')
				if(st.count(i))return false;
			if(s[i]=='o')
				if(!st.count(i))return false;
		}
		return true;
	};
	int cnt=0;
	for(int password=0;password<10000;++password){
		if(good(password))cnt++;
	}
	cout<<cnt<<'\n';
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
