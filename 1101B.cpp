#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	int ans=str.length();
	int temp1,temp2,temp3,temp4;
	temp1=temp2=temp3=temp4=-1;
	int n=str.length();
	for(int i=0;i<n;i++)
	{
		if(str[i]=='[')
			{temp1=i;break;}
	}
	ans-=temp1;
	for(int i=n-1;i>=0;i--)
	{
		if(str[i]==']')
			{temp2=i;break;}
	}
	ans-=n-temp2-1;
	if(temp1==-1 || temp2==-1 || temp1>temp2)
		{cout<<-1<<endl;return 0;}
	for(int i=temp1+1;i<=temp2;i++)
	{
		if(str[i]==':')
			{temp3=i;break;}
	}
	ans-=(temp3-temp1-1);
	for(int i=temp2;i>=temp1;i--)
	{
		if(str[i]==':')
			{temp4=i;break;}
	}
	ans-=(temp2-temp4-1);
	if(temp3==-1 || temp3==temp4)
		{cout<<-1<<endl;return 0;}
	int c=0;
	for(int i=temp3+1;i<=temp4-1;i++)
	{
		if(str[i]=='|')
			c++;
	}
	ans-=temp4-temp3-1;
	ans+=c;
	cout<<ans<<endl;

}