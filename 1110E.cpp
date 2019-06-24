/**************************
*	Author-Atharva Sarage *
*		IIT HYDERABAD     *
**************************/
#include<bits/stdc++.h>
#warning Check Max_Limit,Overflows
using namespace std;
# define ff first
# define ss second
# define pb push_back
# define mod 1000000007
# define mx 100005
# define ll long long 
# define db double
# define inf 1e9
# define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll s[mx],t[mx];
vector<ll>s1,s2;
int main()
{
	IOS;
	ll n;
	cin>>n;
	for(ll i = 0; i < n; ++i)
		{cin>>s[i]; if(i!=0)s1.push_back(s[i]-s[i-1]);}
	for(ll i = 0; i < n; ++i)
		{cin>>t[i]; if(i!=0)s2.push_back(t[i]-t[i-1]);}
	sort(s1.begin(),s1.end());
	sort(s2.begin(),s2.end());
	ll flag=0;
	if(s[0]!=t[0] || s[n-1]!=t[n-1])
		flag=1;
	for(ll i=0;i<n-1;i++)
	{
		if(s2[i]!=s1[i])
			{flag=1;break;}
	}
	if(flag==1)
		cout<<"No"<<endl;
	else
		cout<<"Yes"<<endl;

	
}
