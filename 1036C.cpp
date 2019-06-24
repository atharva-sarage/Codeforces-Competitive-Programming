/*
    Author-Atharva Sarage
    IIT HYDERABAD
*/

#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
ll dp[4][20];
void build()
{

	dp[0][0]=1;
	dp[1][0]=dp[2][0]=dp[3][0]=1;
	
	for(ll i=1;i<=18;i++)
		{
			dp[0][i]=1;
			dp[3][i]=9*9*9*((i-1)*(i-2))/2+9*9*(i-1)+9;
			dp[2][i]=9*9*(i-1)+9;
			dp[1][i]=9;
		}
	for(ll i=1;i<=18;i++)
	{
		dp[1][i]+=dp[1][i-1];
		dp[2][i]+=dp[2][i-1];
		dp[3][i]+=dp[3][i-1];
	}
	
}
ll classy(ll n)
{
	if(n==0)
		return 0;
	vector <ll> vec;
	while(n>=1)
	{
		vec.push_back(n%10);
		n/=10;
	}
	reverse(vec.begin(),vec.end());
	ll final=dp[3][vec.size()-1]+(vec[0]-1)*dp[2][vec.size()-1];
	ll l=2;
	for(ll i=1;i<vec.size();i++)
	{
		if(vec[i]!=0)
			{
				final+=dp[l][vec.size()-i-1]+(vec[i]-1)*dp[l-1][vec.size()-i-1];
				l--;
			}
		if(l==0)
			break;
	}
	vec.clear();
	return final;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	build();
	/*for(ll i=1;i<=18;i++)
	{
		cout<<dp[1][i]<<" "<<dp[2][i]<<" "<<dp[3][i]<<endl;
	}*/
	ll t;
	cin>>t;
	//cout<<classy(t)<<endl;
	while(t--)
	{
		ll l,r;
		cin>>l>>r;
		cout<<classy(r)-classy(l-1)<<endl;
	}
}