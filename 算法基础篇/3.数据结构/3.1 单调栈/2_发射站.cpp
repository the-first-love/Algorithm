#include<iostream>
#include<stack>
using namespace std;
typedef long long LL;
const int N =1e6+10;
int n;
LL h[N];
int v[N];
int dist[N];

int main()
{
	cin>>n;

	for(int i=1;i<=n;i++)
		cin>>h[i]>>v[i];

	stack<int> st;
	for(int i=1;i<=n;i++)
	{
		while(st.size()&&h[st.top()]<=h[i]) st.pop();

		if(st.size()) dist[st.top()]+=v[i];

		st.push(i);
	}
	while(st.size()) st.pop();

	for(int i=n;i>=1;i--)
	{
		while(st.size()&&h[st.top()]<=h[i]) st.pop();

		if(st.size()) dist[st.top()]+=v[i];

		st.push(i);
	}

	int ret=0;
	for(int i=1;i<=n;i++)
		ret=max(ret,dist[i]);

	cout<<ret<<endl;
	return 0;
}