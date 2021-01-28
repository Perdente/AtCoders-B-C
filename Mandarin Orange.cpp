//maximum area histogram

//https://www.youtube.com/watch?v=ZmnqCZp9bBs&ab_channel=TusharRoy-CodingMadeSimple
//https://www.codespeedy.com/largest-rectangular-area-in-a-histogram-in-cpp/
//https://atcoder.jp/contests/abc189/tasks/abc189_c
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N=1e5+6,mod=1e9+7;
signed main()
{
	int n;cin>>n;
	vector<int>hist(n);
	for(int &i:hist)cin>>i;
	stack<int>st;
	int area=0,max_area=0,top=0;
	int i=0;
	while(i<n){
	    if(st.empty() or hist[st.top()]<=hist[i])
	        st.push(i++);
	    else{
	        top=st.top();
	        st.pop();
	        area=hist[top]*(st.empty()?i:i-st.top()-1);
	        max_area=max(max_area,area);
	    }
	        
	}
	while(!st.empty()){
	    top=st.top();
        st.pop();
        area=hist[top]*(st.empty()?i:i-st.top()-1);
        max_area=max(max_area,area);
	}
	cout<<max_area<<"\n";
	return 0;
}

