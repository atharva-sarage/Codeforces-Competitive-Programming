#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#define lli long long int
using namespace std;
int main()
{
	int i,y,b,r,out;
	cin>>y>>b>>r;
	out=min({y,b-1,r-2});
	cout<<(out+1)*3<<endl;

}