#include <iostream>
#include <algorithm>
#include<cstring>
typedef long long LL;
using namespace std;

const int N=5e5+10;

LL a[N],t[N];
int n;

LL merge(int left,int right)
{
if(left>=right) return 0;

LL ret=0;
int mid=(left+right)/2;
//左右分别计算出逆序数，并完成区间排序
ret+=merge(left,mid);
ret+=merge(mid+1,right);

int l=left,r=mid+1,pos=left;

while(l<=mid&&r<=right)
{
if(a[l]>a[r]) ret+=mid-l+1,t[pos++]=a[r++];
else t[pos++]=a[l++];
}
while(l<=mid) t[pos++]=a[l++];
while(r<=right) t[pos++]=a[r++];
memmove(a+left,t+left, sizeof(LL)*(right-left+1));
return ret;
}


int main(int argc, char const *argv[])
{
cin>>n;
for(int i=1;i<=n;i++) cin>>a[i];

cout<<merge(1,n)<<endl;

return 0;
}