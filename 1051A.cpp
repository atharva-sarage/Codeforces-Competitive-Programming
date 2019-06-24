#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin>>s;
	int flag1=0,flag2=0,flag3=0,pos1,pos2,pos3;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='a' && s[i]<='z')
			{
			flag1+=1;
			pos1=i;
			}
		if(s[i]>='A' && s[i]<='Z')
			{
			flag2+=1;
			pos2=i;
			}
		if(s[i]>='0' && s[i]<='9')
			{
			flag3+=1;
			pos3=i;
			}
	}
	
	if(flag1==0 && flag2==0)
	{
		s[0]='a';
		s[1]='A';
	}
	else if(flag1==0 && flag3==0)
	{
		s[0]='a';
		s[1]='1';
	}
	else if(flag3==0 && flag2==0)
	{
		s[0]='1';
		s[1]='A';
	}
	else if(flag1==0 )
	{
			if(flag2>flag3)
				s[pos2]='a';
			else
				s[pos3]='a';
	}
	else if(flag2==0 )
	{
			if(flag1>flag3)
				s[pos1]='A';
			else
				s[pos3]='A';
	}
	else if(flag3==0 )
	{
			if(flag1>flag2)
				s[pos1]='1';
			else
				s[pos2]='1';
	}
	cout<<s<<endl;


	}
}