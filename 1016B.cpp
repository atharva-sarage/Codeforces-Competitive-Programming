// silly question
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int q;
	cin>>q;
	char str[1003];
	char str2[1003];
	cin>>str>>str2;
	int end[1103]={0};
	for(int i=0;i<n;i++)
	{
		int j=0;
		int i1=i;
		while(str[i]==str2[j] && j<m && i<n)
		{
			i++;
			j++;
		}
		if(j==m)
			{
				end[i-1]++;
			}
		i=i1;
	}
	for(int j=0;j<n;j++)
	{
		if(j!=0)
		end[j]=end[j]+end[j-1];
	}
/*for(int j=0;j<n;j++)
	{
		cout<<end[j]<<" ";
	}
	printf("\n");*/
	for(int i=0;i<q;i++)
	{
		
		int u,v;
		cin>>u>>v;
		u--;v--;
		if(u+m-2>v)
			cout<<0<<endl;
		else
		cout<<end[v]-end[u+m-2]<<endl;

	}
}