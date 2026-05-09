#include<iostream>
#include<deque>
using namespace std;
typedef long long LL;

const int N =1e6+10;
int n,k;
LL a[N];

int main()
{
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	cin>>a[i];

		deque<int> q;
		// 窗口内最小值- 单调递增的队列- 存下标
		for(int i=1;i<=n;i++)
		{
			while(q.size()&&a[q.back()]>=a[i]) q.pop_back();

			q.push_back(i);
			
			// 判断队列里面元素是否在合法窗口内
			if(q.back()-q.front()+1>k) q.pop_front();

			if(i>=k) cout<<a[q.front()]<<" ";
			
		}
		cout<<endl;

		q.clear();
		// 窗口内最大值- 单调递减的队列- 存下标
		for(int i=1;i<=n;i++)
		{
			while(q.size()&&a[q.back()]<=a[i]) q.pop_back();
			q.push_back(i);
			if(q.back()-q.front()+1>k) q.pop_front();
			if(i>=k) cout<<a[q.front()]<<" ";
		}
		cout<<endl;
return 0;
}