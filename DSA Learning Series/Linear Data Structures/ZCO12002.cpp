#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5; //constant for global variable declarations

//templete from contest2 part1 video

int32_t main() {
    //Fast IO
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,x,y;
    cin>>n>>x>>y;
    
    vector<pair<int,int>> a(n);
    
    for(int i=0;i<n;i++)
	{
		cin>>a[i].first;
		cin>>a[i].second;
	}
    
   vector<int> start(x+1);
    start[0]=INT_MIN;
    for(int i=1;i<=x;i++)
		cin>>start[i];
		
	vector<int> finish(y+1);
	finish[y]=INT_MAX;
	for(int i=0;i<y;i++)
		cin>>finish[i];
		
	sort(a.begin(),a.end());//as default sort by first element
	sort(start.begin(),start.end());
	sort(finish.begin(),finish.end());
	
/*	for(int i=0;i<n;i++)
	{
		cout<<"("<<a[i].first<<","<<a[i].second<<")"<<"\n";
	}

	for(int i=0;i<x;i++)
		cout<<start[i]<<" ";
		
	cout<<"\n";
	
	for(int i=0;i<y;i++)
		cout<<finish[i]<<" ";
	
	cout<<"\n";
*/
	
/*	int ans=INT_MAX;
	for(int i=0;i<x;i++)
	{
		int count=0;
		for(int j=0;j<n;j++)
		{
			if(start[i]<=a[j].first)
			{
				for(int k=0;k<y;k++)
				{
					if(a[j].second<=finish[k])
					{
						count=finish[k]-start[i]+1;
						ans=min(ans,count);
						break;
					}
				}
				break;	
			}
		}
	}
*/
	vector<pair<int,int>>sol(n,make_pair(0,INT_MAX));
	int ans=INT_MAX;
	for(int i=0;i<n;i++)
	{
	    int index1=lower_bound(start.begin(), start.end(), a[i].first)-start.begin();
	    if(a[i].first==start[index1])
	        sol[i].first=start[index1];
	    else
	        sol[i].first=start[index1-1];
		/*for(int j=x-1;j>=0;j--)
		{
			if(a[i].first>=start[j])
			{
				sol[i].first=start[j];
				break;
			}
		}*/
		
		int index2=upper_bound(finish.begin(), finish.end(), a[i].second)-finish.begin();
		if(a[i].second==finish[index2-1])
		    sol[i].second=finish[index2-1];
		else
		    sol[i].second=finish[index2];
		/*for(int j=0;j<y;j++)
		{
			if(a[i].second<=finish[j]&&finish[j]>=a[i].first)
			{
				//cout<<"finish="<<finish[j]<<endl;
				sol[i].second=finish[j];
				break;
			}
		}*/
	}
	
	for(int i=0;i<n;i++)
	{
	    //cout<<" i="<<i<<" start="<<sol[i].first<<" end="<<sol[i].second;
		ans=min(ans,sol[i].second-sol[i].first+1);
	   	//cout<<" ans="<<ans<<endl;
	}
	
	cout<<ans<<"\n";
}
