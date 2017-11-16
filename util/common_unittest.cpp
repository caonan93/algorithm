#include "common_define.h"

TEST(CommonUtilTtest,RandomTest)
{
    for(int i=0;i<100;i++)
    {
        TEST_COUT<<RandomUtils::getInt()<<" ";
    }
    TEST_COUT<<endl;
    for(int i=0;i<100;i++)
    {
        TEST_COUT<<RandomUtils::getDouble()<<" ";
    }
    TEST_COUT<<endl;
}