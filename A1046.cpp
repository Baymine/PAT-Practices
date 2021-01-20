

//遇到的问题：不知道应该用什么方式存储输入的数据
/*！！！！部分正确没有找出出错的案例：因为输入的时候可能是序号大的在前面，这样向前的时候就要经过N到1节点的路径，这个
原先预想的不一致，导致最终结果不一致（这个时候向后的路径就加上了多余的距离）
出现问题的原因：自己的想法是依托于一定条件之上的，但是自己没有意识到这个条件，导致写出来的程序是依托在这个条件之上的，缺少了普适性。

*/
//算法思想：向后的思想


#include <cstdio>
#include<math.h>
#include<algorithm>
using namespace std;

int main(void){
    //输入数据
    //合适的存储方式：方便后续的取用
    int N;
    scanf("%d",&N);
    
    int dis[N + 1];
    for(int i = 0;i<=N + 1;++i){
        dis[i] = 0;
    }
    

    
    for(int i = 2, j; i <= N; ++i){
        scanf("%d",&j);
        dis[i] = dis [i-1] + j;
        //printf("%d\t",dis[i]);
    }
    scanf("%d",&dis[0]);

    int testNumber;
    scanf("%d",&testNumber);
    
    int totalDisF,totalDisB;
    int targetA,targetB;
    while(testNumber--){
        scanf("%d %d",&targetA,&targetB);
        //往前到达目标的距离：将对应节点的的累计距离加起来放在数组中，做减法
        
        if(targetA > targetB)swap(targetA, targetB);
        totalDisF = abs(dis[targetA] - dis[targetB]);
        //往后达到目标的距离
        totalDisB = dis[targetA] + dis[0] + abs(dis[N] - dis[targetB]);
        //获取较小者
        int min = totalDisF < totalDisB ? totalDisF : totalDisB;
        //输出
        printf("%d",min);
        if(testNumber != 0)printf("\n");
    }

}

//算法思想：比较顺时针和逆时针的距离。顺时针可以用从第一个节点到第i个节点的距离作为数组值，然后用相应的
//下标访问相减即可。逆时针应该将这个路径看成一个圆，总距离减去顺时针的距离即可

/*
#include <cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100005;
int dis[MAXN];//The distance between fist knot and i th knot
int A[MAXN];//The distance between i and i+1

int main(void){
	int sum = 0;//The total distance of whole circle
	int query;
	int n; 
	int left, right;

	//统计总权值并完成相应的dis数组
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &A[i]);//Note this ,it uses '&'
		sum += A[i];
		dis[i] = sum;
	}

	scanf("%d", &query);//How many cases
	for (int i = 0; i < query; ++i) {
		scanf("%d%d", &left, &right);
		if (left > right)swap(left, right);
		int temp = dis[right - 1] - dis[left - 1];
		printf("%d\n", min(temp, sum - temp));
	}
	return 0;
}
*/
