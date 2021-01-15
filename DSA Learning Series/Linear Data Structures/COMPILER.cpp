#include <bits/stdc++.h>
using namespace std;


// handling this tescase is important "<<>"
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		
		stack<char>s;
		int len=str.length();
		int count=0;
		int ans=0;
		
		for(int i=0;i<len;i++)
		{
			int stacklen=s.size();
			
			if(str[i]=='<')
			{
				s.push(str[i]);
				//count++;
			}
			else if(str[i]=='>'&&stacklen>0)
			{
				s.pop();
				count+=2;
			}
			else
			{
				break;
			}
			if(s.size()==0)
			    ans=count;
		}
		cout<<ans<<"\n";
	}
}
