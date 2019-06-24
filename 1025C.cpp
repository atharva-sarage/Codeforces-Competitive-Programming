#include<bits/stdc++.h>
using namespace std;
int main()
{
	char str[100005];
	cin>>str;
	int n=strlen(str),final=0;
	int pre[100005];
	int suff[100005];
	pre[0]=1;
	suff[n-1]=1;
	for(int i=1;i<n;i++)
	{
		if(str[i-1]==str[i])
			pre[i]=1;
		else
			pre[i]=1+pre[i-1];
	}
	for(int i=n-2;i>=0;i--)
	{
		if(str[i+1]==str[i])
			suff[i]=1;
		else
			suff[i]=1+suff[i+1];
	}
	for(int i=0;i<n;i++)
			final=max(final,pre[i]);

	if(str[0]!=str[n-1])
	{
		//printf("***\n");
		final=max(suff[0]+pre[n-1],final);
	}
	cout<<min(final,n)<<endl;
}