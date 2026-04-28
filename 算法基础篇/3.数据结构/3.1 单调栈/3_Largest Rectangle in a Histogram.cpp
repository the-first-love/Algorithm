#include<iostream>
#include<stack>
using namespace std;
typedef long long LL;

const int N =1e5+10;
int n;
LL h[N];
LL r[N],l[N];

int main()
{
	while(cin>>n,n)
	{
		for(int i=1;i<=n;i++)
		cin>>h[i];

		stack<int> st;
		for(int i=1;i<=n;i++)
		{
			while(st.size()&&h[st.top()]>=h[i]) st.pop();

			if(st.size()) l[i]=st.top();
			else l[i]=0;
			
			st.push(i);
		}
		//清空
		while(st.size()) st.pop();

		for(int i=n;i>=1;i--)
		{
			while(st.size()&&h[st.top()]>=h[i]) st.pop();

			if(st.size()) r[i]=st.top();
			else r[i]=n+1;

			st.push(i);
		}

		LL ret=0;
		for(int i=1;i<=n;i++)
		{
			ret=max(ret,h[i]*(r[i]-l[i]-1));
		}
		cout<<ret<<endl;
	}
	return 0;
}