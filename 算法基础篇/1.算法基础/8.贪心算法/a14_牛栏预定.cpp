#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 5e4 + 10;

int n;
int ret[N];//储存最终结果
struct node //同时用于储存牛和牛棚数据
{
    int x; // 开始时间 / 结束时间
    int y; // 结束时间 / 牛棚编号
    int i; //排序前编号

bool operator<(const node& a) const //默认是大堆，仿函数使用less
{
return x>a.x;
}

}a[N];

bool cmp(node& a,node& b)
{
    return a.x<b.x;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++) 
    {
        cin >> a[i].x >> a[i].y;
        a[i].i = i;
    }

sort(a+1,a+1+n,cmp);
priority_queue<node> heap;//用小根堆存放牛棚
int cnt=1;ret[a[1].i]=1;

heap.push({a[1].y,1});

for(int i=2;i<=n;i++)
{
int l=a[i].x,r=a[i].y;node t=heap.top();
if(l>t.x)
{
    heap.pop();ret[a[i].i]=t.y;
    heap.push({r,t.y});
}
else ret[a[i].i]=++cnt,heap.push({r,cnt});
}

cout<<cnt<<endl;
for(int i=1;i<=n;i++)
{
    cout<<ret[i]<<endl;
}

return 0;
}