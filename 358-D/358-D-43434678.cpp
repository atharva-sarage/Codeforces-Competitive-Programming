#include<bits/stdc++.h>
using namespace std;
# define mx 3005
struct hare {int x,y,z;};
struct hare h[mx];
int dp1[mx][2];
int n;
int solve(int pos,int state)
{
	
	if(pos==n){
		if(state==0)
			return h[pos].x;
		else return h[pos].y;
	}
	int &res=dp1[pos][state];
	if(res!=-1)
		return res;
	res=0;
	
	if(state==0){
		res=max(solve(pos+1,1)+h[pos].x,solve(pos+1,0)+h[pos].y);
	}
	else{
		res=max(solve(pos+1,1)+h[pos].y,solve(pos+1,0)+h[pos].z);
	}
	return res;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(dp1,-1,sizeof(dp1));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i].x;
	for(int i=1;i<=n;i++)
		cin>>h[i].y;
	for(int i=1;i<=n;i++)
		cin>>h[i].z;
	int ans=0;
	ans=solve(1,0);
	cout<<ans<<endl;


}