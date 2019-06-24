#include<bits/stdc++.h>
using namespace std;
struct queen 
{
	int r,c,index1;
};
struct queen q[100005];
int freq[100005];
int a[10];
bool compare1(queen q1,queen q2)
{
	if(q1.r+q1.c==q2.r+q2.c)
		return q1.c<q2.c;
	return q1.r+q1.c<q2.r+q2.c;
}
bool compare2(queen q1,queen q2)
{
	if(q1.c-q1.r==q2.c-q2.r)
		return q1.r<q2.r;
	return q1.c-q1.r<q2.c-q2.r;
}
bool compare3(queen q1,queen q2)
{
	if(q1.c==q2.c)
		return q1.r<q2.r;
	return q1.c<q2.c;
}
bool compare4(queen q1,queen q2)
{
	if(q1.r==q2.r)
		return q1.c<q2.c;
	return q1.r<q2.r;
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		q[i].r=x;
		q[i].c=y;
		q[i].index1=i;
	}
	sort(q,q+m,compare1);
	for(int i=0;i<m;i++) // positive slope diagonal
	{
		int ind=q[i].index1;
		if(i!=m-1 && q[i].c+q[i].r==q[i+1].c+q[i+1].r)
			freq[ind]++;
		if(i!=0 && q[i].c+q[i].r==q[i-1].c+q[i-1].r)
			freq[ind]++;
	}
	sort(q,q+m,compare2);
	for(int i=0;i<m;i++) // negative slope diagonal
	{
		int ind=q[i].index1;
		if(i!=m-1 && q[i].c-q[i].r==q[i+1].c-q[i+1].r)
			freq[ind]++;
		if(i!=0 && q[i].c-q[i].r==q[i-1].c-q[i-1].r)
			freq[ind]++;
	}
	sort(q,q+m,compare3);
	for(int i=0;i<m;i++)
	{
		int ind=q[i].index1;
		if(i!=m-1 && q[i].c==q[i+1].c)
			freq[ind]++;
		if(i!=0 && q[i].c==q[i-1].c)
			freq[ind]++;
	}
	sort(q,q+m,compare4);
	for(int i=0;i<m;i++)
	{
		int ind=q[i].index1;
		if(i!=m-1 && q[i].r==q[i+1].r)
			freq[ind]++;
		if(i!=0 && q[i].r==q[i-1].r)
			freq[ind]++;
	}
	for(int i=0;i<m;i++)
	{
		a[freq[i]]++;
	}
	for(int i=0;i<=8;i++)
		cout<<a[i]<<" ";
	cout<<endl;

}