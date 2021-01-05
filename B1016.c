//B1016

#include <stdio.h>
#include <string.h>
#include<math.h>

int Get(char A[], char D) {
    int n = 0;//统计D出现的次数
    int result = 0;//最终结果 
    for (unsigned int i = 0; i <= strlen(A); ++i) {
        if (A[i] == D) n++;
    }
    //printf("n = %d\n", n);
    while (n--) {//弄清楚这个过程逻辑
        result += ((int)(D - '0') * pow(10, n));
        //printf("(D-'0') = %d,n = %d;result = %d\n",D - '0',n, result);
    }
    return result;
}

int main(void) {
    char A[11], D;//输入值
    int tag1, tag2;//两个输入的D值的结果

    if (scanf("%s", &A) == 0)return -1;
    getchar();
    if (scanf("%c", &D) == 0)return -1;
    tag1 = Get(A, D);
    //printf("A = %s;B = %c,tag1 = %d\n",A,D,tag1);

    getchar();
    if (scanf("%s", &A) == 0)return -1;
    getchar();
    if (scanf("%c", &D) == 0)return -1;
    tag2 = Get(A, D);
    //printf("A = %s;B = %c,tag1 = %d\n",A,D,tag2);

    printf("%d", tag1 + tag2);


    //更好的方法
    //想想如何更快地找到bug出现的原因：一定要尽快找到出现异常的变量，所以优先检查变量是不是全部都正确，先不要分析出错的原因
    //先找到导致这一切的根源的变量
    long long a, b, da, db;//这种变量命名方式也可以借鉴一下
    scanf("%lld%lld%lld%lld", &a, &da, &b, &db);
    long long pa = 0, pb = 0;
    while (a != 0) {//当时没有想到这种遍历方法
        if (a % 10 == da) pa = pa * 10 + da;
        a /= 10;
    }
    while (b != 0) {
        if (b % 10 == db)pb = pb * 10 + db;
        b /= 10;
    }
    printf("%lld\n", pa + pb);


    return 0;
}
/*1.代码测试：目的就是为了找出哪里出现了错误，这个时候应该用输出函数将所有的变量逐个输出，然后分析出现异常的地方
* 2.类型转换时，char -> int 是将char对应的ASCII码，例如在这里就是将'6'转化成了54
* 3.算法思路：设置一个函数，
*/
