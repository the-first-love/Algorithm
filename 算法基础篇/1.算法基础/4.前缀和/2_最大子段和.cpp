#include<iostream>

using namespace std;
typedef long long ll;
int n;
const int N=1e6;
ll a[N],S[N];

int main()
{
	cin>>n;
for(int i=1;i<=n;i++) cin>>a[i];
	
	ll ret=-1e20;
    ll prevmin=0;
for(int i=1;i<=n;i++)
{
	S[i]=S[i-1]+a[i];
    ret=max(ret,S[i]-prevmin);
    prevmin=min(S[i],prevmin);
}
cout<<ret<<endl;

return 0;
}
