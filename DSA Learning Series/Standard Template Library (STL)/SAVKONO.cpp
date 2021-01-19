#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,z;
		cin>>n>>z;
		
		priority_queue<pair<int,bool>> pq;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			pq.push(make_pair(x,false));
		}
	
	int count=0;
	
	while(z>0)
	{
		int top=pq.top().first;
		count++;
		if(!top){
			count=-1;
			break;
		}
		
		pq.pop();
		z-=top;
		pq.push(make_pair(top/2,true));
		
	}
	
	if(count==-1) 
		printf("Evacuate\n");
	else
	{
		
		/*while(!pq.empty())
		{
			if(pq.top().second)
			{
				count++;
			}
			pq.pop();
		}*/
		cout<<count<<"\n";
	}
}
}
