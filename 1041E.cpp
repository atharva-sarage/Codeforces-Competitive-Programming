#include<bits/stdc++.h>
# define mx 1000
using namespace std;
int pos[mx];
int final[mx];
int deg[mx];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		deg[x]++;
		deg[y]++;		
	}
	
	final[0]=n;
	pos[n]=0;
	int last=0;
	stack <int> s;
	for(int i=n-1;i>=1;i--)
	{
		int v=deg[i];
		if(v!=0)	
		{
		pos[i]=last+v;
		for(int j=last+1;j<pos[i];j++)
			s.push(j);
			last=pos[i];
		}
		else
		{
			if(s.empty())
			{
				printf("NO\n");
				return 0;
			}
			pos[i]=s.top();
			s.pop();
		}
		final[pos[i]]=i;
	}
	for(int i=0;i<n;i++)
	{
		if(final[i]==0)
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<n;i++)
		cout<<final[i]<<" "<<final[i-1]<<endl;




}