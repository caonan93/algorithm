/*************************************************************************
	> File Name: 56.MergeIntervals.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月07日 星期二 23时50分07秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//https://leetcode.com/problems/merge-intervals/
class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        for(auto& arr:intervals){
			if(arr[0]>arr[1]) std::swap(arr[0],arr[1]);
		}
		std::sort(intervals.begin(),intervals.end(),[](vector<int> a,vector<int> b){return a[0]<b[0];});
		for(auto& arr:intervals){
			printf("[%d,%d] ",arr[0],arr[1]);
		}
		cout<<endl;
		return vector<vector<int>>();
    }
};


int main()
{
	Solution s;
	vector<vector<int>> init_arr{{1,3},{2,6},{8,10},{3,9}};
	s.merge(init_arr);
    return 0;
}

