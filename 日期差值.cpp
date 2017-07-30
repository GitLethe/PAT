/*题目描述
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天。

输入
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD

输出
每组数据输出一行，即日期差值*/

/*日期、时间处理的重点在于进制问题，本问题提供了解决这类问题的思想*/

#include <stdio.h>
#include <math.h>

bool isLeap(int year);
int month[13][2] = { { 0,0 },{ 31,31 },{ 28,29 },{ 31,31 },{ 30,30 },{ 31,31 },{ 30,30 },{ 31,31 },{ 31,31 },{ 30,30 },{ 31,31 },{ 30,30 },{ 31,31 } };
//这样的数组处理闰年与平年的月份天数问题很方便，令数组1维为13个故意留出0号位，目的是让月份和数组下标对应
//0,1分别代表平年和闰年，与bool isLeap(int)函数返回值配合巧妙
int main()
{
	int time1, time2;
	int y1, y2, m1, m2, d1, d2;
	
	scanf("%d %d", &time1, &time2);
	
	if (time1>time2)
	{
		int temp = time1;
		time1 = time2;
		time2 = temp;
	}

	y1 = time1 / 10000;
	y2 = time2 / 10000;
	m1 = (time1 % 10000) / 100;
	m2 = (time2 % 10000) / 100;
	d1 = time1 % 100;
	d2 = time2 % 100;

	int ans = 1;
	while (!(y1==y2&&m1==m2&&d1==d2))
	{
		d1++;
		if (d1>month[m1][isLeap(y1)])       //处理时间、日期进制问题的关键步骤
		{
			m1++;
			d1 = 1;
		}
		if (m1>12)
		{
			y1++;
			m1 = 1;
		}
		ans++;
	}
	
	printf("%d\n", ans);
}

bool isLeap(int year)               //判断闰年的简单函数
{
	return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}
