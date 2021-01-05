#include<stdio.h>
#include<math.h>

int main(void){
    int h,m;//定义时间
    int s;
    int pre,aft;
    double interval;
    
    if(scanf("%d%d",&aft,&pre) == 0)return -1;
    interval = (pre - aft)/100.00;//如何保证运算之后的精度？有没有办法直接移动小数点
    
    h = interval /(3600);
    m = (interval - (3600 * h))/60;
    s = round(interval - 3600*h - 60*m);
    
    //printf("%d,interval = %lf\n",(interval - 3600*h - 60*m),interval);
    printf("%02d:%02d:%02d",h,m,s);//注意这里的输出格式（时间的输出格式）
    
    return 0;
    
}

//Better way
//之前的计算方式过于原始，同时定义的变量过多，内存消耗会大一点
#include<cstdio>

int main(void) {
	int c1, c2;
	scanf("%d%d", &c1, &c2);
	int ans = c2 - c1;

  //四舍五入的操作。其实想清楚四舍五入的原因是什么即可。最后的倒数第二个数是不是大于5，，所以这里是需要一个去头的操作
  //注意到这里是提前将其转化成了整型，这样避免了浮点运算
	if (ans % 100 >= 50) ans = ans / 100 + 1;
	else ans = ans / 100;

	printf("%02d:%02d:%02d\n", ans / 3600, ans % 3600 / 60, ans % 60);
	return 0;
}

/*
*总结：1)对于数据去头和去尾的两种的操作：去头用%得到的余数就是数据的尾部；用/整除，得到的就是数据的头部
*2)对于时间的格式的输出方式   3）分析问题的本源（那个四舍五入的例子）  4）在计算过程中尽量避免浮点运算
*
* 
*遗留问题：假设要将一个数除以10^n，但是又不能损失精度，应该怎么办？
*
*/

