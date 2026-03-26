#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
    int n=nums.size(),retleft,retright;
    //处理空数组
    if(!n) return {-1,-1};

    //查找起始位置
    int left=0,right=n-1;
    while(left<right)
    {
    int mid=(left+right)/2;
    if(nums[mid]>=target) right=mid;
    else left=mid+1;
    }
    if(nums[left]!=target) return {-1,-1};
    else retleft=left;

    //查找结束位置
    left=0,right=n-1;
    while(left<right)
    {
    int mid=(left+right+1)/2;
    if(nums[mid]<=target) left=mid;
    else right=mid-1;
    }
    if(nums[left]!=target) return {-1,-1};
    else retright=right;

    return {retleft,retright};
    }

   
};