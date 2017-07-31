/*#1 非十进制转换为十进制*/
/*
  二进制转换十进制 10110
  0*2^0 + 1*2^1 + 1*2^2 + 0*2^3 + 1*2^4 = 0+2+4+16 = 22 
 */


  int x, p;
	scanf("%d %d", &x,&p);

	int y = 0,power=1;
	while (x!=0)
	{
		int k = x % 10;       //取最后一位
		y += k*power;
		power *= p;           //增指数
		x /= 10;              //去最后一位
	}
	printf("%d\n", y);
  
  
  /*#2 十进制转换非十进制*/
  /*
    除基留余法
    十进制 197 转换为 八进制
    
    197 / 8(基) =  24 + 5     ↑
    24  / 8     =  3  + 0     ↑ 倒序
    3   / 8     =  0  + 3     ↑
                   ↑商为0，算法结束
                   
    八进制   305
  */
  
  
	int ans[50], x, power;          //ans[50]用来存结果，由于算法的思想，结果是倒序存在数组中的
	int num = 0;

	scanf("%d %d", &x, &power);
	do                              //用do-while循环先运行一次是因为，若十进制数为0，也运行一次，使ans[0]=0
	{

		ans[num++] = x%power;
		x /= power;
	} while (x != 0);

	for (int i = num-1; i >= 0; i--)
	{
		printf("%d", ans[i]);
	}
	printf("\n");
