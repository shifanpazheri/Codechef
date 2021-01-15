#include <bits/stdc++.h>
using namespace std;

// GIVEN THAT corresponding expression is guaranteed to be well-bracketed

int main()
{
	long long int n;
	cin>>n;
	stack <long long int> s;
	
	long long int depth=0;
	long long int first_depth=0;
	long long int max_seq=0;
	long long int first_pos=0;
	long long int start=-1,end=0;
	
	long long int ans=0;
	
	vector <long long int> a(n);
	
	for(long long int i=0;i<n;i++)
		cin>>a[i];
	
	for(long long int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			s.push(a[i]);
			if((long long int)depth<(long long int)s.size())
			{
				depth=s.size();
				first_depth=i+1;
			}
		}
		else
			s.pop();
		
	}
	ans=0;
	for(long long int i=0;i<n;i++)
	{
		if(a[i]==1)
		{
			s.push(a[i]);
			if((long long int)ans<(long long int)s.size())
			{
				ans=s.size();
			}
		}
		else
			s.pop();
		
		if(s.size()==0)
		{	
			//cout<<"i="<<i<<" end ="<<end<<" start="<<start<<" ans="<<ans<<" max_seq="<<max_seq<<endl;
			end=i;
			//max_seq=max(max_seq,end-start+1);
			//cout<<"sub= "<<end-start<<" max_seq="<<max_seq<<"\n";
			if(max_seq<(end-start)&&ans==depth)
			{
				max_seq=end-start;
				first_pos=start+2;
				ans=0;
			}
			//cout<<"i="<<i<<" end ="<<end<<" start="<<start<<" ans="<<ans<<" max_seq="<<max_seq<<endl;
			start=i;
		}
		
	}
	
	cout<<depth<<" "<<first_depth<<" "<<max_seq<<" "<<first_pos;
}
