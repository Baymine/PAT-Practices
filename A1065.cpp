/*
算法思想：主要的问题就是在与如何防止两个数相加之后越界。为了防止越界，将每一个数字都除以2，这样相加之后就不会越界了
但是这样产生了一个问题，一个数被除之后可能会出现小数，这个时候就需要浮点型，但是浮点型的范围又达不到要求
*/
/*
#include<cstdio>

int main(void){
    //传入数据
    int n;//Cases number
    long long a, b, c;//Input cases
    int caseSque = 1;
    scanf("%d",&n);
    
    while(n--){
        scanf("%lld%lld%lld",&a,&b,&c);
        a /= 2.0; b /= 2.0; c /= 2.0;
        
        printf("a=%lf b=%lf c=%lf\n",a,b,c);
        
        if(a+b > c) printf("Case #%d: true",caseSque);
        else printf("Case #%d: false",caseSque);
        if(n != 0)printf("\n");
        
        caseSque++;
    }
    //printf("\n%")
}
*/
/*
算法思想：当出现无非是上溢或者是下溢，又因为题目中已经给出了输入数据的范围，所以溢出的范围也就确定了
只需要列举出对应的情况所对应的结果。
可能出现的结果：
①上溢：A+B >= 2^63，实际结果位负数  ②下溢：A+B <= -2^63， 实际结果位正数 ③无溢出：正常比较

注意一点：scanf中""内的内容不是随意的！（深入了解一下）
*/

#include<cstdio>

int main(void) {
	int T;//Cases number
	int tcase = 1;//Test Sequence
	scanf("%d", &T);

	while (T--) {
		long long a, b, c;//Those input data
		scanf("%lld%lld%lld", &a, &b, &c);//Warning here

		long long res = a + b;
		bool flag;//The proposition is right or wrong
        //printf("result = %lld\n", res);

		if (a > 0 && b > 0 && res < 0)flag = true;
		else if (a < 0 && b < 0 && res >= 0)flag = false;
		else if (res > c)flag = true;
        else flag = false;
        
		if (flag == true) printf("Case #%d: true\n", tcase++);
		else printf("Case #%d: false\n", tcase++);
	}
	return 0;
}
