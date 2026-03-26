#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n;
LL a[N];

int main(int argc, char const *argv[])
{
cin>>n;
for(int i = 1; i <= n; i++) cin >> a[i];
sort(a + 1, a + 1 + n);

LL ret=0;
for(int i=1;i<=n/2;i++)
{
ret+=a[n+1-i]-a[i];
}
cout<<ret<<endl;
return 0;
}