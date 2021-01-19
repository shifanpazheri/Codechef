#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	
	map <string,string> mp1;
	map <string,int> mp2;
	map <string,int> mp3;
	
	for(int i=0;i<n;i++)
	{
		string name,country;
		cin>>name>>country;
		mp1[name]=country;
		mp2[name]=0;
		mp3[country]=0;
	}
	
	for(int i=0;i<m;i++)
	{
		string name;
		cin>>name;
		mp2[name]++;
		mp3[mp1[name]]++;
	}
	
	/*cout<<"\n\n\n";
	
	for(auto it:mp1)
	{
		cout<<it.first<<" "<<it.second<<"\n";
	}
	
	cout<<"\n\n\n";
	
	for(auto it:mp2)
	{
		cout<<it.first<<" "<<it.second<<"\n";
	}
	
	cout<<"\n\n\n";
	
	for(auto it:mp3)
	{
		cout<<it.first<<" "<<it.second<<"\n";
	}*/
	
	int s=-1,c=-1;
	string sci,con;
	
	for(auto it:mp2)
	{
		//cout<<it.first<<" "<<it.second<<"\n";
		if(it.second>s)
		{
			s=it.second;
			sci=it.first;
		}
	}
	
	for(auto it:mp3)
	{
		//cout<<it.first<<" "<<it.second<<"\n";
		if(it.second>c)
		{
			c=it.second;
			con=it.first;
		}
	}
	
	cout<<con<<"\n"<<sci<<"\n";

}
