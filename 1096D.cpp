#include<bits/stdc++.h>
using namespace std;
# define pb push_back
# define ll long long
ll a[100005],b[100005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n;
	ll ans1=0,ans2=0,ans3=0,ans4=0,flag1=0,flag2=0,flag3=0,flag4=0;
	cin>>n;
	string str,str2;
	vector <ll> vec;
	cin>>str;
	for(ll i=0;i<n;i++)
		cin>>b[i];
	ll t=0;
	for(ll i=0;i<str.length();i++)
	{
		if(str[i]=='h' || str[i]=='a' || str[i]=='r' || str[i]=='d')
			{str2+=str[i];a[t]=b[i];t++;}
	}
	for(ll i=0;i<str2.length();i++)
	{
		if(str2[i]=='h' && flag1==0)
			{flag1=1;vec.pb(i);}
		if(str2[i]=='a' && flag1==1 && flag2==0)
			{flag2=1;vec.pb(i);}
		if(str2[i]=='r' && flag2==1 && flag3==0)
			{flag3=1;vec.pb(i);}
		if(str2[i]=='d' && flag3==1 && flag4==0)
			{flag4=1;vec.pb(i);}
	}
	if(vec.size()<4)
	{
		cout<<0<<endl;return 0;
	}
	flag1=flag2=flag3=flag4=0;
	for(ll i=str2.length()-1;i>=0;i--)
	{
		if(str2[i]=='d' && flag1==0)
			{flag1=1;vec.pb(i);}
		if(str2[i]=='r' && flag1==1 && flag2==0)
			{flag2=1;vec.pb(i);}
		if(str2[i]=='a' && flag2==1 && flag3==0)
			{flag3=1;vec.pb(i);}
		if(str2[i]=='h' && flag3==1 && flag4==0)
			{flag4=1;vec.pb(i);}
	}
	for(ll i=0;i<str2.length();i++)
	{
		if(str2[i]=='h')
		{
			if(i>=vec[0] && i<=vec[7])
				ans1+=a[i];
		}
		if(str2[i]=='a')
		{
			if(i>=vec[1] && i<=vec[6])
				{ans2+=a[i];ans2=min(ans2,ans1);}
		}
		if(str2[i]=='r')
		{
			if(i>=vec[2] && i<=vec[5])
				ans3+=a[i];ans3=min({ans1,ans2,ans3});
		}
		if(str2[i]=='d')
		{
			if(i>=vec[3] && i<=vec[4])
				ans4+=a[i];ans4=min({ans1,ans2,ans3,ans4});
		}
	}
	cout<<ans4<<endl;

}
