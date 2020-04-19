/*************************************************************************
	> File Name: CHowManyNines.cpp
	> Author: hulkcao
	> Mail: caonann@qq.com
	> Created Time: 2020年04月17日 星期五 13时02分56秒
 ************************************************************************/

#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;
//超时了
bool judgeLeapYear(int year)
{
	if(year%400 == 0 || year%4==0 && year%100 != 0) return true;
	return false;
}

int getMonthDay(int year,int month)
{
	std::vector<int> months_day{31,28,31,30,31,30,31,31,30,31,30,31};
	if(judgeLeapYear(year)) months_day[1]=29;
	return months_day[month-1];
}

int getNineCountDigt(int n)
{
	int sum=0;
	do
	{
		int mod = n % 10;
		if(mod==9) sum ++;
		n/=10;
	}while(n!=0);
	return sum;
}

int getEageDayLCount(int d)
{
	int tmpday=0;
	if(d>=9) tmpday++;
	if(d>=19) tmpday++;
	if(d>=29) tmpday++;
	return tmpday;
}

int getEageDayRCount(int d)
{
	int tmpday=3;
	if(d>9) tmpday--;
	if(d>19) tmpday--;
	if(d>29) tmpday--;
	return tmpday;
}

int getNineCount(int y1,int m1,int d1,int y2,int m2,int d2)
{
	int diffYear = y2-y1;
	int sum = 0;
	if(diffYear)
	{
		int eageday = getEageDayRCount(d1);
		sum = (12-m1)*3+eageday;
		if(!judgeLeapYear(y1) && m1 <=2 ) sum--;
		if(m1 <9) sum+=30;
		if(m1 == 9) sum+=(getMonthDay(y1,m1)-d1+1);

		eageday = getEageDayLCount(d2);
		sum += (m2-1)*3+eageday;
		if(!judgeLeapYear(y2) && m2 >=2 ) sum--;
		if(m2 >9) sum+=30;
		if(m2 ==9) sum+=d2;

		sum+= (diffYear-1)*(12*3+30);
		int leapYearCount=0;
		for(int y=y1+1;y<y2;y++) if(!judgeLeapYear(y)) leapYearCount++;
		sum-=leapYearCount;

		int totalday = getMonthDay(y1,m1)-d1+1;
		for(int i=m1+1;i<=12;i++) totalday+=getMonthDay(y1,i);
		sum+=getNineCountDigt(y1)*totalday;

		totalday= d2;
		for(int i=m2-1;i>=1;i--) totalday+=getMonthDay(y2,i);
		sum+=getNineCountDigt(y2)*totalday;

		for(int y=y1+1;y<y2;y++) {
			totalday = judgeLeapYear(y) ?totalday= 366:totalday=365;
			sum+=getNineCountDigt(y)*totalday;
		}
	}
	else{
		int diffmonth=m2-m1;
		if(diffmonth)
		{
			int eageday = getEageDayRCount(d1);
			sum+=eageday;
			eageday = getEageDayLCount(d2);
			sum+=eageday;
			sum+=(diffmonth-1)*3;
			if(m1<9 && m2>9) sum+=30;
			if(m1 == 9) sum+=getMonthDay(y1,m1)-d1+1;
			if(m2 == 9) sum+=d2;
			if(!judgeLeapYear(y1) && m1<=2 && m2 >=2) sum--;
			int totalday = getMonthDay(y1,m1)-d1+1;
			for(int i=m1+1;i<m2;i++) totalday+=getMonthDay(y1,i);
			totalday+= d2;
			sum+=getNineCountDigt(y1)*totalday;
		}
		else{
			for(int i=d1;i<=d2;i++)
			{
				if(getNineCountDigt(i)) sum++;
				sum+=getNineCountDigt(y1);
				if(m1 == 9) sum++;
			}
			return sum;
		}
	}
	return sum;
}

void test()
{
	assert(judgeLeapYear(2012));
	assert(judgeLeapYear(2020));
	//assert(judgeLeapYear(2100));
	assert(!judgeLeapYear(1993));
	cout<<"getNineCountDigt "<<getNineCountDigt(9399)<<endl;
	cout<<"getNineCountDigt "<<getNineCountDigt(2399)<<endl;
	cout<<"getNineCountDigt "<<getNineCountDigt(2389)<<endl;
	cout<<"getNineCountDigt "<<getNineCountDigt(2387)<<endl;
	cout<<getNineCount(2017 ,4 ,9, 2017 ,5 ,9)<<endl; //4
	cout<<getNineCount(2100 ,2 ,1 ,2100 ,3 ,1)<<endl; //2
	cout<<getNineCount(2100 ,5 ,1 ,2100 ,6 ,1)<<endl; //3
	cout<<getNineCount(2100 ,5 ,1 ,2100 ,8 ,9)<<endl; //10
	cout<<getNineCount(2100 ,5 ,1 ,2100 ,8 ,19)<<endl; //11
	cout<<getNineCount(2100 ,5 ,1 ,2101 ,5 ,1)<<endl; //35

	cout<<getNineCount(2100 ,5 ,1 ,2102 ,5 ,1)<<endl; //70
	cout<<getNineCount(2100 ,5 ,1 ,2103 ,5 ,1)<<endl; //105

	cout<<getNineCount(9996 ,2 ,1 ,9996 ,3 ,1)<<endl; //93
	cout<<getNineCount(2100 ,2 ,1 ,2100 ,2 ,9)<<endl; //1
	cout<<getNineCount(2100 ,2 ,1 ,2100 ,2 ,8)<<endl; //0
	cout<<getNineCount(2100 ,2 ,1 ,2100 ,2 ,28)<<endl; //2
	cout<<getNineCount(9999 ,1 ,1 ,9999 ,12 ,31)<<endl; //1495
	cout<<getNineCount(2000 ,1 ,1 ,9999 ,12 ,31)<<endl; //1763534
	cout<<getNineCount(2100 ,9 ,1 ,2100 ,9 ,28)<<endl; //30
}


int main()
{
	int T;
	scanf("%d\n",&T);
	for(int i=0;i<T;i++)
	{
		int y1,m1,d1,y2,m2,d2;
		cin >> y1 >> m1>>d1>>y2>>m2>>d2;
		int ret = getNineCount(y1,m1,d1,y2,m2,d2);
		cout<<ret<<endl;
	}
    return 0;
}

