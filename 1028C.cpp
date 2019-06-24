#include<bits/stdc++.h>
using namespace std;
struct rect
{
	int a,b,c,d;
};
struct rect r[200005];
struct rect pre[200005];
struct rect suff[200005];
struct rect zero;
bool compare(struct rect p,struct rect q)
{
	if(p.a==q.a && p.b==q.b && p.c==q.c && p.d==q.d)
		return 1;
	return 0;
}
struct rect inter(struct rect p,struct rect q)
{
	if(compare(p,zero) || compare(q,zero))
		return zero;
	struct rect res;
	res.a=max(p.a,q.a);
	res.b=max(p.b,q.b);
	res.c=min(p.c,q.c);
	res.d=min(p.d,q.d);
	if(res.a>res.c || res.b>res.d)
		return zero;
	return res;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	zero.a=-1e9-1;
	zero.b=-1e9-1;
	zero.c=-1e9-1;
	zero.d=-1e9-1;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>r[i].a>>r[i].b>>r[i].c>>r[i].d;
	}
	pre[0]=r[0];
	suff[n-1]=r[n-1];
	for(int i=1;i<n;i++)
	{
		pre[i]=inter(pre[i-1],r[i]);
	}
	for(int i=n-2;i>=0;i--)
	{
		suff[i]=inter(suff[i+1],r[i]);
	}
	for(int i=1;i<n-1;i++)
	{
		if(!compare(inter(pre[i-1],suff[i+1]),zero)) // compare struct
		{ 
			struct rect ans=inter(pre[i-1],suff[i+1]);
			cout<<ans.a<<" "<<ans.b<<endl;
			return 0;
		}
	}
	if(!compare(suff[1],zero))
	{
		struct rect ans=suff[1];
		cout<<ans.a<<" "<<ans.b<<endl;
		return 0;
	}
	if(!compare(pre[n-2],zero))
	{
		struct rect ans=pre[n-2];
		cout<<ans.a<<" "<<ans.b<<endl;
		return 0;
	}


}
