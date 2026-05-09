#include<iostream>
#include<deque>
using namespace std;
typedef long long LL;

const int N =1e6+10;
int n,m;
LL a[N];

int main(int argc, char const *argv[])
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];

	deque<int> q;
	for(int i=1;i<=n;i++)
	{
		while(q.size()&&a[q.back()]>=a[i]) q.pop_back();

		q.push_back(i);

		if(q.back()-q.front()+1>m) q.pop_front();

		if(i>=m) cout<<a[q.front()]<<endl;
	}

	return 0;
}