#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,many,flag2=0;
	cin>>n;
	int freq[200]={0};
	vector <int> adj[200];
	vector <int> one;
	int mark[200]={0};
	string final;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		freq[x]++;
		adj[x].push_back(i);
	}	
	for(int i=0;i<101;i++)
	{
		if(freq[i]==1)
			{
			one.push_back(i);
			}

		if(freq[i]>2 )
			{
			many=i;
			flag2=1;
			}
	}

	if(one.size()%2==0)
	{

		cout<<"YES"<<endl;
		for(int i=0;i<one.size();i++)
		{
			if(i%2==0)
			{
			final[adj[one[i]][0]]='A';
			mark[adj[one[i]][0]]=1;
			}
			else
			{
			mark[adj[one[i]][0]]=1;
			final[adj[one[i]][0]]='B';
			}
		}
		for(int i=0;i<n;i++)
		{
			if(mark[i]==0)
				final[i]='A';
		}
		for(int i=0;i<n;i++)
		{
			cout<<final[i];
		}
		cout<<endl;
		
	}
	else if(one.size()%2==1 && flag2==1) 
	{
		cout<<"YES"<<endl;
		for(int i=0;i<one.size();i++)
		{
			mark[adj[one[i]][0]]=1;
			if(i%2==0)
			final[adj[one[i]][0]]='A';
			else
			final[adj[one[i]][0]]='B';
		}
		final[adj[many][0]]='B';
		mark[adj[many][0]]=1;
		for(int i=1;i<adj[many].size();i++)
			{
			mark[adj[many][i]]=1;
			final[adj[many][i]]='A';
			}
		for(int i=0;i<n;i++)
		{
			if(mark[i]==0)
				final[i]='A';
		}
		for(int i=0;i<n;i++)
		{
			cout<<final[i];
		}
		cout<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}