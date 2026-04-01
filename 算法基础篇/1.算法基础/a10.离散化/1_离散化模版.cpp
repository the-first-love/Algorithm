#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int N = 1e5 + 10;
int n;
int a[N]; // 原始数据
int pos; // 记录离散化数组中元素的个数
int disc[N]; // 离散化需要的数组

//模版一：排序+去重+二分查找

int find(int x)
{
	int l=1,r=pos;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(disc[mid]>=x) r=mid;
		else l=mid+1;
	}
	return l;
}

void func1()
{
pos=0;
for(int i=1;i<=n;i++)
{
int x;cin>>x;
a[i]=x;
disc[++pos]=x;
}
sort(disc+1,disc+1+pos);
pos=unique(disc+1,disc+1+pos)-(disc+1);

for(int i=1;i<=n;i++)
{
int x = a[i];
cout << x << "离散化后是：" << find(x) << endl;
}
}


//模版二：排序+STL
unordered_map<int,int> id;
void func2()
{
pos=0;
for(int i=1;i<=n;i++)
{
int x;cin>>x;
a[i]=x;
disc[++pos]=x;
}
sort(disc+1,disc+1+pos);
int cnt=0;
for(int i=1;i<=pos;i++)
{
	if(id.count(disc[i])) continue;
	else id[disc[i]]=++cnt;
}
for(int i = 1; i <= n; i++)
{
int x = a[i];
cout << x << "离散化后是："<< id[a[i]] << endl; 
}
}


int main()
{
cin >> n;
func2();

return 0;
}