#include<iostream>

using namespace std;

int n,m;
const int N=1e6;
long long a[N],S[N];

int main()
{
	cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
for(int i=1;i<=n;i++) S[i]=S[i-1]+a[i];
while(m--)
{
	int l,r;cin>>l>>r;
	cout<<S[r]-S[l-1]<<endl;
}

	return 0;
}