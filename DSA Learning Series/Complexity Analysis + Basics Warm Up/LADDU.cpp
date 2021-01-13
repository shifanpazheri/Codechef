#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int act;
		string country;
		cin>>act>>country;
		
		int ans=0;
		string temp;
		int val;
		
		for(int i=0;i<act;i++)
		{
			cin>>temp;
			if(temp=="TOP_CONTRIBUTOR")
				ans+=300;
			else if(temp=="CONTEST_WON")
			{
				cin>>val;
				if(val<20)
					ans+=20-val+300;
				else ans+=300;
			}
			else if(temp=="BUG_FOUND")
			{
				cin>>val;
				ans+=val;
			}
			else if(temp=="CONTEST_HOSTED")
				ans+=50;
			else
			    assert(false);//Gives a run time error if it enters else statement
			    //Useful for debugging
		}
		if(country=="INDIAN")
			cout<<ans/200<<"\n";
		else
			cout<<ans/400<<"\n";// DONT FORGET THIS
	}
}
