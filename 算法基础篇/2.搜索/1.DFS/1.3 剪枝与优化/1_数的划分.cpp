#include <iostream>
#include<algorithm>
using namespace std;

int n,k;
int ret,sum;

void dfs(int begin,int cnt)
{
if(cnt==k)
{
	if(n==sum) ++ret;
	return;
}

for(int i=begin;i<n;i++)
{

//可行性剪枝：进入递归前就剪枝
if(sum+i*(k-cnt)>n) return;

sum+=i;
dfs(i,cnt+1);
sum-=i;
}

}

int main(int argc, char const *argv[])
{
	cin>>n>>k;
	dfs(1,0);
	cout<<ret<<endl;

	return 0;
}