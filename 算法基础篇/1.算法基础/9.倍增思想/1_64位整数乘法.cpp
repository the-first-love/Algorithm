#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL a,b,p;

LL quickmul(LL a,LL b,LL p)
{
LL ret=0;
while(b)
{
if(b&1) ret= (ret+a) % p;
b>>=1;
a=(a+a)%p;
}
return ret;
}

int main(int argc, char const *argv[])
{
scanf("%lld%lld%lld", &a, &b, &p);
printf("%lld\n",quickmul(a,b,p));
return 0;
}