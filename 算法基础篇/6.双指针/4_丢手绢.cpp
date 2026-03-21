#include <iostream>
using namespace std;

typedef long long LL;
const int N = 1e5 + 10;
int n;
LL a[N];

int main(int argc, char const *argv[])
{
cin >> n;
LL sum = 0;
for(int i = 1; i <= n; i++)
{
cin >> a[i];
sum += a[i];
}
int left = 1, right = 1;
LL k = 0;
LL ret = 0;
while(right<=n)
{
k+=a[right];
while(k>=sum/2)
{
ret=max(ret,sum-k);
k-=a[left];
}
ret=max(ret,k);
right++;
}

cout<<ret;
	return 0;
}