#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5; //constant for global variable declarations

int32_t main() {
    //Fast IO
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  	int n,k;
	cin>>n>>k;
	
	pair<int,int> temp;
	stack<pair<int ,int>> s;
	
	int f=1;
	
	for(int i=0;i<n;i++)
	{
		cin>>temp.first;
		temp.second=i;
		while(!s.empty()&&s.top().first>temp.first)
		{
		//	cout<<" temp.first is:"<<temp.first<<" temp.second is:"<<temp.second<<" s.top().first is:"<<s.top().first<<" s.top().second is:"<<s.top().second+1<<" value is: "<<temp.second-s.top().second<<endl;
			f*=(temp.second-s.top().second+1);
			f=f%(1000000007);
			s.pop();
		}
		s.push(temp);
	}
	
	cout<<f<<endl;
	
}
