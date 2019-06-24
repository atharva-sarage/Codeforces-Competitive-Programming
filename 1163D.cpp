/******************************************
*    AUTHOR:         Atharva Sarage       *
*    INSTITUITION:   IIT HYDERABAD        *
******************************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define ll long long 
# define db double
# define inf 1e9
# define mx2 100005
# define mx 1005
ll n,s,t;
ll dp[mx][55][55],fail1[mx],fail2[mx];
ll transition[2][55][30];
string str1,str2,str3;
void pre()
{
	fail1[0]=0;
	ll len=0;
	ll i=1;
	while(i<s)
	{
		if(str2[i]==str2[len])
			{len++;fail1[i]=len;i++;}
		else
		{
			if(len!=0)
				len=fail1[len-1];
			else
				{fail1[i]=0;i++;}
		}
	}
	/***************/
	i=1;
	fail2[0]=0;
	len=0;
	while(i<t)
	{
		if(str3[i]==str3[len])
			{len++;fail2[i]=len;i++;}
		else
		{
			if(len!=0)
				len=fail2[len-1];
			else
				{fail2[i]=0;i++;}
		}
	}
}

ll calc1(ll p1,char a)
{
	while(1)
	{
		if(str2[p1]==a)
			{p1=p1+1;break;}
		else
		{
			if(p1!=0)
				p1=fail1[p1-1];
			else
				{p1=0;break;}
		}
	}
	return p1;
}
ll calc2(ll p1,char a)
{
	while(1)
	{
		if(str3[p1]==a)
			{p1=p1+1;break;}
		else
		{
			if(p1!=0)
				p1=fail2[p1-1];
			else
				{p1=0;break;}		
		}
	}
	return p1;
}
void pre2()
{
	for(ll i=0;i<s;i++)
		for(ll k=0;k<26;k++)
			transition[0][i][k]=calc1(i,k+'a');
	for(ll i=0;i<t;i++)
		for(ll k=0;k<26;k++)
			transition[1][i][k]=calc2(i,k+'a');					
}
ll solve(ll i,ll p1,ll p2)
{
	if(i>=n)
		return 0;
	ll &w=dp[i][p1][p2];
	if(w!=INT_MIN)
		return w;
	w=INT_MIN;
	if(str1[i]=='*')
	{
		for(ll j=0;j<26;j++)
		{
			ll p11,p22;
			p11=transition[0][p1][j];
			p22=transition[1][p2][j];
			ll ans=0;
			if(p11==s)
				{p11=fail1[s-1];ans++;}
			if(p22==t)
				{p22=fail2[t-1];ans--;}
			w=max(w,ans+solve(i+1,p11,p22));
		}
	}
	else
	{
		ll p11=(transition[0][p1][str1[i]-'a']);
		ll p22=(transition[1][p2][str1[i]-'a']);
		ll ans=0;
		if(p11==s)
			{p11=fail1[s-1];ans++;}
		if(p22==t)
			{p22=fail2[t-1];ans--;}
		w=ans+solve(i+1,p11,p22);
	}
	return w;
}
void init()
{
	for(int i=0;i<mx;i++)
		for(int j=0;j<55;j++)
			for(int k=0;k<55;k++)
				dp[i][j][k]=INT_MIN;

}
int main()
{
	//IOS;
	init();
	cin>>str1>>str2>>str3;
	n=str1.length();
	s=str2.length();
	t=str3.length();
	pre();pre2();
	cout<<solve(0,0,0)<<"\n";	
}
