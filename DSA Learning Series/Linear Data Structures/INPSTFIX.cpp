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
		string str;
		cin>>str;
		
		stack <pair<int,int>> s;
		pair<char,int>a;
		
		for(int i=0;i<n;i++)
		{
			a.first=str[i];
			if(int(a.first)>=65&&int(a.first)<=90)
				cout<<a.first;
			else
			{
				switch(a.first)
				{
					case '+':a.second=1;break;
					case '-':a.second=1;break;
					case '*':a.second=2;break;
					case '/':a.second=2;break;
					case '^':a.second=3;break;
					default: a.second=0;break;
				}
				if(a.first!='('&&a.first!=')')
				{
					while(!s.empty()&&s.top().first!='('&&a.second<=s.top().second)//"<=" is really imp
					{
						cout<<char(s.top().first);
						s.pop();
					}
					s.push(a);
				}
				else if(a.first=='(')
				{
					s.push(a);
				}
				else
				{
					while(!s.empty()&&s.top().first!='(')
					{
						cout<<char(s.top().first);
						s.pop();
					}
					s.pop();
				}
				
			}
		}
		while(!s.empty())
		{
			cout<<char(s.top().first);
			s.pop();
		}
		cout<<"\n";
	}
	/*char x;
	cin>>x;
	cout<<int(x);*/
}
