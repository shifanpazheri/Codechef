#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n,m,k;
		cin>>n>>m>>k;
		
		//long long a[n][m];
		map<pair<long long,long long>,long long> a;
		
	/*	for(long long i=0;i<n;i++)
		{
			for(long long j=0;j<m;j++)
			{
				a[make_pair(i,j)]=0;
			}
		}*/
		
		vector<pair<long long,long long>> temp(k);
		
		for(long long i=0;i<k;i++)
		{
			long long x,y;
			cin>>x>>y;
			a[make_pair(x-1,y-1)]=1;
			temp[i]=make_pair(x-1,y-1);
		}
		
		long long sum=0;
		
	    for(long long p=0;p<k;p++)
	    {
	        long long i=temp[p].first;
	        long long j=temp[p].second;
	        int count=0;
				if(i!=0)
					if(a[make_pair(i-1,j)]==1)
						count++;
				if(i!=n-1)
					if(a[make_pair(i+1,j)]==1)
						count++;
				if(j!=0)
					if(a[make_pair(i,j-1)]==1)
						count++;
				if(j!=m-1)
					if(a[make_pair(i,j+1)]==1)
						count++;
				count=4-count;
	
			sum+=count;
			//cout<<" i="<<i<<" j="<<j<<" count="<<count<<endl;
	    }
		
		cout<<sum<<"\n";
		
		/*for(long long i=0;i<n;i++)
		{
			for(long long j=0;j<m;j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
		
		cout<<"\n";*/
		
	}
}
