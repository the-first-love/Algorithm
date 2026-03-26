#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
const int N = 5e4 + 10;
int n;
struct node
{
// 存每⼀头⽜的信息：开始时间，结束时间，排序之前的位置，分配的⽜棚号
int x, y, pos, num;
}a[N];
int cnt;
int ret[N];
multimap<int, int> st;
bool cmp(node& x, node& y)
{
return x.x < y.x;
}
int main()
{
cin >> n;
for(int i = 1; i <= n; i++)
{
cin >> a[i].x >> a[i].y;
a[i].pos = i;
}
sort(a + 1, a + 1 + n, cmp);
for(int i = 1; i <= n; i++)
{
int l = a[i].x, r = a[i].y;
auto it = st.upper_bound(l);
// 不能接在任何⼀个区间后⾯，那就新开⼀个区间
if(it == st.end())
{
st.insert({r, ++cnt});
a[i].num = cnt;
}
else // 能接在某个区间后⾯，那就接上去
{
int p = it->second;
st.erase(it); // 把之前⽜删掉
st.insert({r, p}); // 新来的⽜放进去
a[i].num = p;
}
}
cout << cnt << endl;
for(int i = 1; i <= n; i++)
{
ret[a[i].pos] = a[i].num;
}
for(int i = 1; i <= n; i++) cout << ret[i] << endl;
return 0;
}



