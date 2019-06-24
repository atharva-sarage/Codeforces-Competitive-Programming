#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x1,y1,x2,y2;
	cin>>x1>>y1>>x2>>y2;
	
	int t1=2*abs(x1-x2)+4+abs(y2-y1-1)+abs(y2-y1+1);
	int t2=2*abs(y1-y2)+4+abs(x2-x1-1)+abs(x2-x1+1);

	cout<<max(t1,t2)<<endl;

}