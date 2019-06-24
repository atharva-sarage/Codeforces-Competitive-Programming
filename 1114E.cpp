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
mt19937 rng64(chrono::steady_clock::now().time_since_epoch().count());
ll query1(ll x)
{
	cout<<">"<<" "<<x<<endl;
	ll ans;
	cin>>ans;
	return ans;
}
ll query2(ll x)
{
	cout<<"?"<<" "<<x<<endl;
	ll ans;
	cin>>ans;
	return ans;
}
int main()
{
	srand(rand());
	IOS;
	ll n;
	cin>>n;
	ll low=0;
	ll high=inf;
	ll mid;
	while(high>=low)
	{
		mid=low+(high-low)/2;
		if(query1(mid))
			low=mid+1;
		else
			high=mid-1;
	}
	ll maxi=low;
	set <ll> s;
	set <ll> :: iterator itr,itr1,itr2;
	s.insert(maxi);
	int RandomRange=n;
	for(ll i=0;i<30;i++)
	{
		int k = rng64() % RandomRange+1;
	    ll l=query2(k);
	    s.insert(l);
		if(s.size()==n)
			break;
	}
	ll g=0;
	itr2=s.end();
	itr2--;
	for(itr=s.begin();itr!=itr2;itr++)
	{
		itr1=itr;
		itr1++;
		g=__gcd(g,*itr1-*itr);

	}
	cout<<"! "<<maxi-(n-1)*g<<" "<<g<<endl;

    
}
