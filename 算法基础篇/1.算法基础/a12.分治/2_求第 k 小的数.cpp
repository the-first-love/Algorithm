#include <iostream>
#include <algorithm>
#include<ctime>

typedef long long LL;
using namespace std;

const int N=5e6+10;

LL a[N];
int n,k;

LL get_random(int l,int r)
{
	return a[rand()%(r-l+1)+l];
}

LL quick_select(int left,int right,int k)
{
if(left==right) return a[left];
//随机取数组中的值来划分
LL p=get_random(left,right);
//[left,l],[l+1,r-1],[r,right]
int l=left-1,r=right+1,i=left;
while(i<r)
{
if(a[i]==p) i++;
else if(a[i]<p) swap(a[i++],a[++l]);
else swap(a[i],a[--r]);
}
//计算区间长度
int l1=l-left+1,l2=r-l-1,l3=right-r+1;
if(k<=l1) return quick_select(left,l,k);
else if(k>l1&&k<=l1+l2) return p;
else return quick_select(r,right,k-l1-l2);
}

int main(int argc, char const *argv[])
{
scanf("%d %d",&n,&k);
k++;
for(int i=1;i<=n;i++) scanf("%lld",&a[i]);;
srand(time(0));

printf("%lld\n",quick_select(1,n,k));
return 0;
}