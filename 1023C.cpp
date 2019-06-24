#include<bits/stdc++.h>
using namespace std;
	int mark[200005]={0};
	int mark2[200005]={0};
	int col[200005];
	char str[200005];
int main()
{
	int n,k;
	cin>>n>>k;	
	cin>>str;
	stack <int> s;

	int c=1;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='(')
		{
			col[i]=c;
			
			s.push(c);
			c++;
		}
		if(str[i]==')')
		{
			col[i]=s.top();
			s.pop();
		}
	}

	int k1=k/2;
	for(int i=0;i<n;i++)
	{
		if(str[i]==')')
		{
			mark[i]=1;
			k1--;
		}
		if(k1==0)
			break;
	}
	for(int i=n-1;i>=0;i--)
	{
		if(mark[i]==1)
		{
			mark2[col[i]]=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(mark2[col[i]]==1)
			cout<<str[i];
	}

}