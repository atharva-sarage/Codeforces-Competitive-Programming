#include<bits/stdc++.h>
using namespace std;
typedef int long long ll;
ll spf[15000007];
ll a[300005],count1=0;
ll freq[15000007];
ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
}
void sieve() 
{ 
    spf[1] = 1; 
    for (ll i=2; i<15000004; i++) 
  
    spf[i] = i; 
  
    for (ll i=4; i<15000004; i+=2) 
        spf[i] = 2; 
  
    for (ll i=3; i*i<15000004; i++) 
    { 
        if (spf[i] == i) 
        { 
            for (ll j=i*i; j<15000004; j+=i) 
  
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
} 
 
void divi(ll x,ll ind) 
{ 

    while (x != 1) 
    { 
    	ll y=spf[x];
    	freq[y]++;
        while(x%y==0)
        	x/=y;
    }
} 

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    //prllf("*****\n");
    ll n,max1=0,gcd_1;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        a[i]=x;
        if(i!=0)
        gcd_1=gcd(gcd_1,x);
        else
        gcd_1=x;
    }
   
    for(ll i=0;i<n;i++)
    {
        a[i]/=gcd_1;
    }
    for(ll i=0;i<n;i++)
    {
        divi(a[i],i);
    }
   
     for(ll i=2;i<=15000006;i++)
    {
        max1=max(max1,freq[i]);
    }
    if(max1==0)
        cout<<-1<<endl;
    else
        cout<<n-max1<<endl;
}