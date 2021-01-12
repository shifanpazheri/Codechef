#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int g;
		cin>>g;
		while(g--)
		{
			long long int i,n,q;
			cin>>i>>n>>q;
			if(n%2==1)
			{   
			    if(i==q) cout<<n/2<<"\n";
			    else cout<<((n/2)+1)<<"\n";
			}
			else
			{
			    cout<<n/2<<"\n";
			}
		}
	}
}
