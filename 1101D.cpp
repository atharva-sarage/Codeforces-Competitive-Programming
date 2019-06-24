#include<bits/stdc++.h>
using namespace std;
#define pb push_back
int spf[200010],a[200010];
vector<int>adj[200010];
vector <int>vec[200010];
map <int,int> s[200010];
int ans=1;
void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<200005; i++) 
  
    spf[i] = i; 
  
    for (int i=4; i<200005; i+=2) 
        spf[i] = 2; 
  
    for (int i=3; i*i<200005; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<200005; j+=i) 
  
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
 
void divi(int x,int ind) 
{ 
    while (x != 1) 
    { 
        int y=spf[x];
        vec[ind].pb(y);
        while(x%y==0)
            x/=y;
    }
} 
int dfs(int u,int par,int x) // max length down the tree with gcd x
{
	if(s[u][x])
		return s[u][x];
	int max3=0;
	if(x==0)
	{
		for(auto k:adj[u])
		{
			if(k==par)continue;
			dfs(k,u,0);
		}		
		for(auto l:vec[u]) // x==0
		{
			int max1=0,max2=0;
			for(auto k:adj[u])
			{
				if(k==par)continue;
				if(a[k]%l==0)
				{
					int temp=dfs(k,u,l);
					if(temp>=max1)
						{max2=max1;max1=temp;}
					else if(temp>=max2)
						{max2=temp;}
				}
			}
			ans=max(ans,1+max1+max2);
			max3=max(max3,max1);
		}
	}
	else
	{
		int max1=0,max2=0;
			for(auto k:adj[u])
			{
				if(k==par)continue;
				if(a[k]%x==0)
				{
					int temp=dfs(k,u,x);
					if(temp>=max1)
						{max2=max1;max1=temp;}
					else if(temp>=max2)
						{max2=temp;}
				}
			}
			ans=max(ans,1+max1+max2);
			max3=max(max3,max1);
	}
	s[u][x]=max3+1;
	return max3+1;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	sieve();
	int n,flag=0;
	cin>>n;
	
	for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			divi(a[i],i);
			if(a[i]!=1)flag=1;
		}


	for(int i=0;i<n-1;i++)
	{
		int x,y;
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	if(flag==0)
		{cout<<0<<endl;return 0;}
	dfs(1,-1,0);
	cout<<ans<<endl;


}
