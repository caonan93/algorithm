/*************************************************************************
	> File Name: 5381.querys_key.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月12日 星期日 11时39分20秒
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;
//https://leetcode-cn.com/contest/weekly-contest-184/problems/queries-on-a-permutation-with-key/

class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
		vector<int> p;
		for(int i=1;i<=m;i++) p.push_back(i);
		vector<int> ret;
		for(int i=0;i<queries.size();i++)
		{
			int queries_i = queries[i];
			int p_val = get_and_op_index(queries_i,p);
			ret.push_back(p_val);
		}
		return ret;
    }
private:
	int get_and_op_index(int val,vector<int>& p)
	{
		int ret = 0;
		for(int i=0;i<p.size();i++)
		{
			if(val == p[i])
			{
				ret = i;
				break;
			}
		}
		for(int end=ret;end>=1;end--)
		{
			p[end] = p[end-1];
		}
		p[0] = val;
		return ret;
	}
};

void test(vector<int> queries, int m)
{
	Solution s;
	auto arr = s.processQueries(queries,m);
	for(auto& v:arr){
		printf("%d ",v);
	}
	printf("\n");
}
int main()
{
	test({4,1,2,2},4);
	test({7,5,5,8,3},8);
	test({0,0,1},1);
    return 0;
}

