#include<bits/stdc++.h>
using namespace std;
# define mx 100005
vector<int> vec2[mx];
int a[mx];
typedef int long long ll;
int main()
{
	int n,max1=0,flag=0,freq=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		if(x==1)
			freq++;
		a[i]=x;
		vec2[x].push_back(i);
		max1=max(x,max1);
	}
	for(int i=1;i<=max1;i++)
	{
		if(vec2[i].size()<vec2[i+1].size())
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		{
			cout<<-1<<endl;
			return 0;
		}
	for(int i=1;i<=max1;i++)
	{
		for(int j=0;j<vec2[i].size();j++)
			a[vec2[i][j]]=j+1;
	}
	cout<<freq<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	printf("\n");



}