#include<bits/stdc++.h>
using namespace std;
# define mx 200005
# define mx1 100002
int main()
{
	int pre[mx]={0},visited[mx];
	memset(visited,-1,sizeof(visited));
	int n,ans=0;
	cin>>n;
	string str;
	cin>>str;
	pre[0]=mx1;
	visited[mx1]=0;
	for(int i=1;i<=n;i++)
	{
		if(str[i-1]=='1')
			pre[i]=pre[i-1]+1;
		else
			pre[i]=pre[i-1]-1;

		if(visited[pre[i]]!=-1)
			ans=max(ans,i-visited[pre[i]]);
		else
			visited[pre[i]]=i;
	}
	cout<<ans<<endl;
}