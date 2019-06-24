#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,flag=0,index1;
	cin>>n>>m;
	string str;
	string str2;
	cin>>str>>str2;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='*')
			{
				index1=i;
				flag=1;
			}
	}
	int flag4=0,flag3=0,flag2=0;
	if(flag==0)
	{
		if(n!=m)
			cout<<"NO"<<endl;
		else
		{
			for(int i=0;i<n;i++)
				if(str[i]!=str2[i])
				{
					flag4=1;
					break;
				}
		
		if(flag4==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
		}
	}
	else
	{
		for(int i=0;i<index1;i++)
		{
			if(str[i]!=str2[i])
				flag2=1;
		}
		int i=0;
		
		while(str[n-1-i]!='*' && i>=0 )
		{
			if(m-i-1<index1)
			{
				flag3=1;
				break;
			}
			if(str[n-i-1]!=str2[m-1-i])
			{
				flag3=1;
				break;
			}
			i++;
			
		}	
		if(flag2 || flag3)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}

}