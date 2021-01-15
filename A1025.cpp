/*
#include <stdio.h>

struct Info{
    long long register_number;
    int final_rank, location_number, local_rank;
};

int main(void){
    int competitors;//参赛人数
    int location_number;//比赛考场
    
    scanf("%d%d",&location_number.&competitors);
    
}
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student{
    char id[15];
    int score,location_number,local_rank;
}stu[30010];//注意这里的最大数量在题目中是有体现的

bool cmp(Student a, Student b){
    if(a.score != b.score)return a.score > b.score;//分数按照从大到小排序
    else return strcmp(a.id,b.id) < 0;//字典序，大于->返回一个大于0的数；等于->返回0；小于->返回一个负数
    //这个是按照从小到大排序的^
}

int main (void){
    int n, k , num = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; ++i){
        scanf("%d",&k);
        
        //传入输入的数据，并存储到数组中
        for(int j = 0;j < k; ++j){
            scanf("%s%d",stu[num].id, &stu[num].score);
            stu[num].location_number = i;//第几考场
            num ++;//统计学生数量，确定每个考场的考生在数组中的位置
        }
        sort(stu + num - k, stu + num, cmp);//从大到小排序
        
        //对学生的排名进行赋值
        stu[num - k].local_rank = 1;
        for(int j = num - k + 1; j < num; j++){
            if(stu[j].score == stu[j-1].score){
                stu[j].local_rank = stu[j-1].local_rank;
            }
            else{
                stu[j].local_rank = j + 1 - (num - k);
            }
        }
    }
    printf("%d\n",num);
    sort(stu, stu+num, cmp);
    int r = 1;
    for(int i = 0; i < num; ++i){
        if(i > 0 && stu[i].score != stu [i - 1].score) r = i + 1;//这里时利用了数组下标和排名之间的关系
        printf("%s ",stu[i].id);
        printf("%d %d %d\n", r, stu[i].location_number,stu[i].local_rank);
    }
    /*
    while(num--){
        printf("score = %d;location_number = %d,local_rank = %d\n",stu[num].score,stu[num].location_number,stu[num].local_rank);
    }*/
    return 0;
}

/*
算法整体思想：先对数组的局部元素进行排序，得到在组内的排名，然后对整体元素进行排序，得到整体排名。对于局部数组，算法中的统计人数的变量num可以作为数组元素的位置指针
本次出现问题主要就是误解题目意思，导致一些信息没有得到充分利用
*/
