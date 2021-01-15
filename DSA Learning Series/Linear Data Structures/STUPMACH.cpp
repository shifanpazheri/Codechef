#include <bits/stdc++.h>
using namespace std;

long long int ans=0;

void machine(vector <long long int> v1,long long int p,long long int q)
{
//	cout<<"In Machine:"<<ans<<"\n";
	if(p>=q)
	{
		ans+=v1[p];
		return;
	}
	
	long long int minm= INT_MAX;
	long long int index=0;
	
	for(long long int i=p;i<=q;i++)
	{
		if(minm>v1[i])
		{
			minm=v1[i];
			index=i;
		}
	}
	
	ans+=(q-p+1)*minm;
	
//	cout<<"print value :";
	for(long long int i=p;i<=index;i++)
	{
		v1[i]-=minm;
//		cout<<v1[i]<<" ";
	}
//	cout<<"\n";
	
	machine(v1,0,index-1);
	
}

int main()
{
	long long int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		vector <long long int> v1;
		v1.resize(n);
		
		for(long long int i=0;i<n;i++)
		{
			cin>>v1[i];
		}
		
		machine(v1,0,n-1);
		
		cout<<ans<<"\n";
		ans=0;
	}
}
