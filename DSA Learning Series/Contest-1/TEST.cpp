#include <bits/stdc++.h>
using namespace std;

int main() {

	vector<int>a;
	a.resize(10000000);
	for(long long int i=0;i<10000000;i++)
	{
	    cin>>a[i];
	    if(a[i]==42) break;
	}
	for(long long int i=0;a[i]!=42;i++)
	{
	    cout<<a[i]<<"\n";
	}
	
	return 0;
}
