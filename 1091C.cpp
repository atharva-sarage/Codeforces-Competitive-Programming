#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <unordered_map>
#define lli long long int
using namespace std;
int main()
{
	lli i,n; vector<lli> fact; set<lli> ans;
	cin>>n;
	for(i=1;i<=sqrt(n)+5;++i)	if(n%i==0) { ans.insert((i*((n/i)*(n/i-1)/2))+(n/i)); ans.insert((n/i*(i*(i-1)/2))+i); }
	for(auto v:ans) cout<<v<<" ";
	cout<<endl;
}