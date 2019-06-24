#include<bits/stdc++.h>
using namespace std;
# define pb push_back
# define ff first
# define ss second
bool isprime[100005]; 
bool mark[100005];
vector <pair<int,int> > final;
void sieve(int n) 
{ 
    memset(isprime, true, sizeof(isprime));   
    for (int p=2; p*p<=n; p++) 
    { 
        if (isprime[p] == true) 
        { 
            for (int i=p*2; i<=n; i += p) 
                isprime[i] = false; 
        } 
    }    
} 
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	sieve(100000);
	int n;cin>>n;
	vector<int> vec;
	for(int i=3;i<=n/2;i++)
	{
		if(isprime[i])
			vec.pb(i);
	}
	unordered_set<int> kata;
	unordered_set<int> :: iterator itr,itr1;
	for(auto k:vec)
	{
		unordered_set <int> temp;
		for(int i=k;i<=n;i+=k)
		{
			if(!mark[i])
			{
				temp.insert(i);
				mark[i]=true;
			}
		}
		if(temp.size()%2==1)
		{
			kata.insert(2*k);
			temp.erase(2*k);
		}
		if(temp.empty())
			continue;
		for(itr=temp.begin();itr!=temp.end();)
		{
			itr1=itr;itr1++;
			final.pb({*itr,*itr1});
			itr=itr1;itr++;
		}
		temp.clear();
	}
	for(int i=2;i<=n;i+=2)
	{
		if(!mark[i])
			kata.insert(i);
	}
	for(itr=kata.begin();itr!=kata.end();)
		{
			itr1=itr;itr1++;
			if(itr1==kata.end())
				break;
			final.pb({*itr,*itr1});
			itr=itr1;itr++;
		}
	cout<<final.size()<<endl;
	for(auto k:final)
		cout<<k.ff<<" "<<k.ss<<endl;
}