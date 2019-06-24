#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin>>n;
	vector <pair<int,int> > ycor;
	vector <pair<int,int> > ycor1;
	vector <pair<int,int> > xcor;

	for(int i=0;i<n;i++)
	{
		int x1,y1;
		cin>>x1>>y1;
		xcor.push_back(make_pair(x1,i));
		ycor.push_back(make_pair(y1,i));
		ycor1.push_back(make_pair(y1,i));
	}
	sort(xcor.begin(),xcor.end());
	sort(ycor.begin(),ycor.end());
	int final=0;
	for(int i=0;i<n-1;i++)
	{
		int ans=xcor[n-1].first;
		if(ycor1[xcor[i].second].first==ycor[0].first)
		{
			//cout<<i<<endl;
			final=max(final,ycor[1].first-ans);
		}
	}
	if(ycor1[xcor[n-1].second].first==ycor[0].first)
	{
		//printf("***\n");
		final=max(final,ycor[1].first-xcor[n-2].first);
	}
	else
		final=max(final,ycor[0].first-xcor[n-2].first);

	cout<<final<<endl;
}