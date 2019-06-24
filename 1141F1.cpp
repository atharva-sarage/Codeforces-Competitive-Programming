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
# define mx2 300005
# define mx 600
int dp[mx],a[mx],pre[mx],n;
pair <int,int> update[mx];
vector <pair<int,int> > vec[mx2];
int solve(int i,int sum)
{
	if(i>n)
		return 0;
	int &w=dp[i];
	if(w!=-1)
		return w;
	int j=i;
	int temp=0;
	while(j<=n)
		{
			temp+=a[j];j++;
			if(temp==sum)
				break;
		}
	if(j==n+1 && temp!=sum)
	{
		w=solve(i+1,sum);
		update[i]={i+1,0};
	}
	else
	{
		int temp1=solve(i+1,sum);
		int temp2=1+solve(j,sum);
		w=max(temp1,temp2);
		if(temp1>temp2)
			update[i]={i+1,0};
		else
			update[i]={j,1};
	}

	return w;
}
int main()
{
	IOS;
	int final=0;
	cin>>n;
	pre[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	if(n==1)
	{
		cout<<1<<endl;
		cout<<1<<" "<<1<<endl;
		return 0;
	}
	int c=0,fully_final;
	for(int i=1;i<n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			int sum1=pre[j]-pre[i-1];
			memset(dp,-1,sizeof(dp));
			solve(j+1,sum1);
			vec[c].pb({i,j});
			int k=j+1;
			while(k<=n)
				{
					if(update[k].ss==0)
						k++;
					else
						{
							vec[c].pb({k,update[k].ff-1});
							k=update[k].ff;
						}
				}
				if(final<vec[c].size())
					{fully_final=c;final=vec[c].size();}

				c++;
		}
	}
	cout<<vec[fully_final].size()<<endl;
	int c1=pre[vec[fully_final][0].ss]-pre[vec[fully_final][0].ff-1];
	for(auto k:vec[fully_final])
	{
		cout<<k.ff<<" "<<k.ss<<" "<<endl;
		//cout<<pre[k.ss]-pre[k.ff-1]<<endl;
		assert(pre[k.ss]-pre[k.ff-1]==c1);
	}

}
