//Mistake！！
/*
#include <stdio.h>

struct Situation{
    static char a;
    int count = 0;
};

int N = 10;//比赛轮数
int A_lost = 0, A_win = 0 , draw = 0 ;//甲输、赢的次数
int B_lost = 0, B_win = 0;//乙输、赢的次数
// A[2],B[2];//存储甲乙双方出拳情况,0、1、2分别代表剪刀石头布
char a,b;//甲乙当前出拳情况
char A_max,B_max;//胜率最大的情况
Situation A[2],B[2];

int Judge(char a, char b);
void Print(char a[], char b[]);
int main(void){
    
    
    //BCJ
    A[0].a = 'B';A[1].a = 'C';A[2].a = 'J';
    B[0].a = 'B';B[1].a = 'C';B[2].a = 'J';
    
    //Print(A,B);
    
     
    //printf("%c && %c\n", A[0].a,B[0].a);
    //printf("Before:%c && %c\n", A[0].a,B[0].a);
    if(scanf("%d",&N) == -1)return -1;
    
    
    while(N--){
        getchar();
        scanf("%c",&a);
        getchar();
        scanf("%c",&b);//注意在输入char的时候空格也会被当成一个字符
        //getchar();
        //getchar();
        //printf("%c && %c\n",a,b);
        
        
        
        Judge(a,b);
       
        //printf("A[%d] = %c B[%d] = %c\n",N,A[N].a,N,B[N].a);
    }
    
    for(int i = 0; i <= 2; ++i){
        printf("A[%d] = %c B[%d] = %c\n",i,A[i].a,i,B[i].a);
    }
    
    
    printf("%d %d %d\n",A_win,draw,A_lost);
    printf("%d %d %d\n",B_win,draw,B_lost);
    
    int A_max_num = A[0].count;
    int B_max_num = B[0].count;
    for(int i = 0; i <= 2; ++i){
        if(A_max_num < A[i].count){
            A_max = A[i].a;
            A_max_num = A[i].count;
        }
        if(B_max_num < B[i].count){
            B_max = B[i].a;
            B_max_num = B[i].count;
        }
        printf("A[%d] = %c B[%d] = %c\n",i,A[i].a,i,B[i].a);
    }
    
    printf("%c %c",A_max,B_max);
}
//判断这一局的结果，负数代表乙赢，正数代表甲赢，0代表平局,并统计双方出拳情况BCJ
int Judge(char a, char b){
    switch (a){
        case 'J':
            if(b == 'C'){
                B[1].count++;
                return -1;
            }
            else if(b == 'J'){
                draw++;
                return 0;
            }
            else if(b == 'B'){
                A[2].count++;
                return 1;
            } 
            break;
        case 'C':
            if(b == 'B'){
                B[0].count++;
                return -1;
            }
            else if(b == 'C'){
                draw++;
                return 0;
            }
            else if(b == 'J'){
                A[1].count++;
                return 1;
            } 
            break;
        case 'B':
            if(b == 'J'){
                B[2].count++;
                return -1;
            }
            else if(b == 'B'){
                draw++;
                return 0;
            }
            else if(b == 'C'){
                A[0].count++;
                return 1;
            }
            break;
        
    }
}
void Print(Situation a[],Situation b[]){
    for(int i = 0; i <= 2; ++i){
        printf("A[%d] = %c B[%d] = %c\n",i,a[i].a,i,b[i].a);
    }
}
//遇到的问题：想要将结构体中的
*/
/*算法思想：将判断胜负的方式转换成数学关系，其他的就运用数组统计相关信息
*需要注意的地方：scanf在传入字符的时候会将空格和换行也当成一个字符，在输入的两个变量之间的空格必不可少，加上空格
*之后就可以忽略输入过程中的空格,可能时传入的变量值与“”中的字符个数是相等的
*/



#include <cstdio>

//将字母转换成相应的数字
int change(char c) {
	if (c == 'B') return 0;
	if (c == 'C') return 1;
	if (c == 'J') return 2;
}

int main(void) {
	char mp[3] = { 'B','C','J' };
	int n;
	scanf("%d", &n);
	int times_A[3] = { 0 }, times_B[3] = { 0 };//记录胜、平、负的次数
	int hand_A[3] = { 0 }, hand_B[3] = { 0 };//获胜时的手势
	char c1, c2;//甲乙的当局的手势
	int k1, k2;//当局手势所对应的数字

	for (int i = 0; i < n; ++i) {
		getchar();//注意scanf中输入char的时候，读入空格和换行
		scanf("%c %c", &c1, &c2);//注意两个%c之间加了空格，因为输入的格式中有空格，所以这个空格是必须的，否则会将空格作为字符读入
		
		//转换成相应的整型数字
		k1 = change(c1);
		k2 = change(c2);

		//判断胜负
		if ((k1 + 1) % 3 == k2) {
			times_A[0]++;
			times_B[2]++;
			hand_A[k1]++;
		}else if(k1 == k2){
			times_A[1]++;
			times_B[1]++;
		}
		else {
			times_A[2]++;
			times_B[0]++;
			hand_B[k2]++;
		}
	}

	printf("%d %d %d\n", times_A[0], times_A[1], times_A[2]);
	printf("%d %d %d\n", times_B[0], times_B[1], times_B[2]);
	int id1 = 0, id2 = 0;

	//找出获胜次数最多的手势
	for (int i = 0; i < 3; ++i) {
		if (hand_A[i] > hand_A[id1])id1 = i;
		if (hand_B[i] > hand_B[id2])id2 = i;
	}
	printf("%c %c\n", mp[id1], mp[id2]);
	return 0;
}
