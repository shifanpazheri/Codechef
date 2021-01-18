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
	int n;
	cin>>n;
	vector<pair<int,int>>a(n+10001);
	
	for(int i=0;i<=10000;i++)
	{
		a[i]=make_pair(i,500);
	}

	
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x;
		cin>>y;
		a[i+10001]=make_pair(x,y);
	}
	
	sort(a.begin(),a.end());
	
	stack<pair<int,int>> s;
	vector<int> right(n+10001);
	vector<int> left(n+10001);
	
	
	for(int i=0;i<10001+n;i++)
	{
		while(!s.empty()&&a[i].second<s.top().second)
		{
			right[s.top().first]=a[i].first;
			s.pop();
		}
		s.push(make_pair(i,a[i].second));
	}
	
	while(!s.empty())
	{
		right[s.top().first]=10000;
		s.pop();
	}
	
	for(int i=10000+n;i>=0;i--)
	{
		while(!s.empty()&&a[i].second<s.top().second)
		{
			left[s.top().first]=a[i].first;
			s.pop();
		}
		s.push(make_pair(i,a[i].second));
	}
	
	while(!s.empty())
	{
		left[s.top().first]=0;
		s.pop();
	}
	
	int ans=0;
	for(int i=0;i<10001+n;i++)
	{
		ans=max(ans,a[i].second*(right[i]-left[i]));
	}
	
	cout<<ans;
}
