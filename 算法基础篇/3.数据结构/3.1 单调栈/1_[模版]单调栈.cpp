#include<iostream>
#include<stack>
using namespace std;

const int N =3e6+10;
int n;
int a[N];
int ret[N];

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	stack<int> st;	
	for(int i=n;i>=1;i--)
	{
		while(st.size()&&a[st.top()]<=a[i]) st.pop();
			
		if(st.size()) ret[i]=st.top();

		st.push(i);
	}

	for(int i=1;i<=n;i++)
		cout<<ret[i]<<" ";
	cout<<endl;
	return 0;
}