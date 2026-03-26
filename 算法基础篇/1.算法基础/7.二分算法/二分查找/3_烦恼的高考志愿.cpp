#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+10;
typedef long long LL;
LL m,n,a[N];

int main(int argc, char const *argv[])
{
	cin>>m>>n;
	for(int i=1;i<=m;i++) cin>>a[i];
	sort(a+1,a+1+m);

    //左右护法，保证a[0]不影响结果
    a[0]=-1e6;

	LL ret=0;
	for(int i=1;i<=n;i++) 
	{
	LL b;cin>>b;
    int left=1,right=m;
    while(left<right)
    {
    	int mid=(left+right)/2;
    	if(a[mid]>=b) right=mid;
    	else left=mid+1;
    }
    int pos=left;
    ret+=min(abs(a[pos]-b),abs(a[pos-1]-b));
	}
	cout<<ret<<endl;
	return 0;
}