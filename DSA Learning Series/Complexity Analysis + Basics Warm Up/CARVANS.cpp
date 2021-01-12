#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector <int> max;
		max.resize(n);
		
		vector <int> a;
		a.resize(n);
		
		for(int i=0;i<n;i++)
		{
			cin>>max[i];
			a[i]=max[i];
		}
		
		for(int i=1;i<n;i++)
		{
			a[i]=min(a[i],a[i-1]);
		}
		
		int count=0;
		
		for(int i=0;i<n;i++)
		{
			if(a[i]==max[i]) count++;
		}
		cout<<count<<"\n";
	}
	
}
