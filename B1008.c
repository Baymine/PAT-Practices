//数组元素循环右移问题

//Mine
#include <stdio.h>

void Reverse(int a[],int n,int m){//从n开始，到m结束,为数组的序号
    int temp;
    for(int i = n, j = m; i < j ;++i,--j){
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main(void){
    int n,m;//数组大小，向右移动的位数
    
    if(scanf("%d%d",&n,&m) == 0)return -1;
    m = m % n;
        
    int g[n] = {0};
    for(int i = 0; i < n; ++i){
        scanf("%d", &g[i]);
    }
    if(m>n){
        Reverse(g,0,n-1);
        for(int i = 0; i < n;++i){
        printf("%d",g[i]);
        if(i != n - 1)printf(" ");
    }
    }
    
    Reverse(g,0,n-1);
    Reverse(g,0,m-1);
    Reverse(g,m,n-1);
    for(int i = 0; i < n;++i){
        printf("%d",g[i]);
        if(i != n - 1)printf(" ");
    }
    
}




//Solution

#include<cstdio>

int main() {
	int a[110];
	int n, m, count = 0;

	//输入两个数组的参数
	scanf("%d%d", &n, &m);
	m = m % n;//修正

	//输入数组的内容
	for (int i = 0; i < n; ++i)  scanf("%d", &a[i]);

	//从不同的地方开始输出数组
	//注意这里是用了额外的数组！
	for (int i = n - m; i < n; ++i) {
		printf("%d", a[i]);
		count++;
		if (count < n) printf(" ");
	}
	for (int i = 0; i < n - m; i++) {
		printf("%d", a[i]);
		count++;
		if (count < n)printf(" ");
	}
	return 0;
}


/*
* 主要遇到的问题就是边界审查的问题，因为数组有两个定位方式，在自己写的过程中，因为没有统一这种定位方式
* 导致自己在确定边界的时候产生混乱。还有想要确定边界的一个好办法就是运用共性特性统一的原理，想想一些特例
*/
