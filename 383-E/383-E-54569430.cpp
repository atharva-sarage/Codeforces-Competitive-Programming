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
# define mx2 24
# define mx (1<<24)
ll f[mx];
int main()
{
	IOS;
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++)	
	{
		string x;
		cin>>x;
		vector <ll>s;
		vector <ll>::iterator ip;
		for(ll j=0;j<3;j++)
			s.push_back((1<<(x[j]-'a')));
		sort(s.begin(),s.end());
		ip = unique(s.begin(),s.end()); 
    	s.resize(distance(s.begin(), ip)); 
    	if(s.size()==1)
			f[s[0]]++;
		else if(s.size()==2 && s[0]!=s[1])
			{f[s[0]]++;f[s[1]]++;f[(s[0])|(s[1])]--;}
		else if(s.size()==2 && s[0]!=s[2])
			{f[s[0]]++;f[s[2]]++;f[(s[0])|(s[2])]--;}
		else
			{
				f[s[0]]++;f[s[1]]++;f[s[2]]++;
				f[(s[0])|(s[1])]--;f[(s[0])|(s[2])]--;f[(s[2])|(s[1])]--;
				f[(s[0])|(s[1])|(s[2])]++;
			}
		s.clear();
	}
	// rest all subsets values is 0 sum of subsets modification
	ll ans=0;
	for(ll i=0;i<mx2;i++)
	{
		for(ll mask=0;mask<mx;mask++)
		{
			if(mask&(1<<i))continue;
			f[(mask|(1<<i))]+=f[mask];			
		}
	}
	for(ll i=0;i<mx;i++)
		{ans=(ans^(f[i]*f[i]));}

	cout<<ans<<endl;
}