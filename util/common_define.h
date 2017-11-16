/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   common_define.h
 @author     root
 @version
 @date       2019/09/29 01:31
 @brief
 @details    2019/09/29 root create
*/
/*************************************************************************
    > File Name: common_define.h
    > Author: hulkcao
    > Mail: 546314485@qq.com
    > Created Time: Sat 03 Aug 2019 03:26:23 AM UTC
 ************************************************************************/

#ifndef _COMMON_DEFINE_H
#define _COMMON_DEFINE_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <random>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <gtest/gtest.h>
using namespace std;

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {
    }
};

#define LOG(...)do { \
        printf("%s line %d:\t", __func__, __LINE__); \
        printf(__VA_ARGS__); \
        printf("\n"); \
    }while(0)

namespace comm
{
int *bubbleSort(int *A, int n);
TreeNode *createTree(vector<int> &arr);

//执行脚本命令，获取返回值
//int commondExecute();
}

class RandomUtils
{
public:
    static int getInt(int start=10,int end=1000);
    static double getDouble(double start=10,double end=1000);
};
namespace
{

template <typename T>
void printItemList(T &itemlist)
{
    for (auto &v : itemlist)
    {
        cout << v << " ";
    }

    cout << endl;
}

}

//gtest custom printf
namespace testing
{
 namespace internal
 {
  extern void ColoredPrintf(GTestColor color, const char* fmt, ...);
 }
}

#define PRINTF(...)  do { testing::internal::ColoredPrintf(testing::internal::COLOR_YELLOW, __VA_ARGS__); } while(0)

// C++ stream interface
class TestCout : public std::stringstream
{
public:
    ~TestCout()
    {
        PRINTF("%s",str().c_str());
    }
};

#define TEST_COUT  TestCout()

#endif
