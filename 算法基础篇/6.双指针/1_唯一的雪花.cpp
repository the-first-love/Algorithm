#include<iostream>
#include<unordered_map>

using namespace std;

const int N=1e6+10;
int a[N];


int main()
{
int T;cin>>T;
while(T--)
{
int n;cin>>n;
for(int i=1;i<=n;i++) cin>>a[i];
int left=1,right=1,ret=0;
//哈希表作为窗口，统计数据出现个数
unordered_map<int,int> mp;
while(right<=n)
{
//进窗口
mp[a[right]]++;
//判断条件
while(mp[a[right]]>1)
{
//出窗口
mp[a[left]]--;
left++;
}
//更新最长长度
ret=max(ret,right-left+1);
right++;
}

cout << ret << endl;
}

    return 0;
}