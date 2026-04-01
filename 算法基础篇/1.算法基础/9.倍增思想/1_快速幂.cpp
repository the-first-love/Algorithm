#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
LL a,b,p;

LL quickpow(LL a,LL b,LL p)
{
LL ret=1;
while(b)
{
if(b&1) ret= ret * a % p;
b>>=1;
a=a*a%p;
}
return ret;
}

int main(int argc, char const *argv[])
{
scanf("%lld%lld%lld", &a, &b, &p);
printf("%lld^%lld mod %lld=%lld\n",a,b,p,quickpow(a,b,p));
return 0;
}