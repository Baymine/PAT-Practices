#include <stdio.h>

struct Num{
    int count = 0;
    int A = 0;
}Num[5];


int main(void){
    int input_num;double sum = 0;
    int total = 0;
    scanf("%d",&total);
    
    while(total--){
        //注意在case之后是常数表达式
        scanf("%d",&input_num);
        switch(input_num % 5){
            case 0:
                if(input_num % 2 == 0){
                    Num[0].A +=input_num;
                    Num[0].count ++;
                }
                break;
            case 1:
                Num[1].count++;
                if(Num[1].count % 2 == 1){
                     Num[1].A += input_num;
                 }
                 else Num[1].A -= input_num;
                 break;
                
            case 2:
                Num[2].count++;Num[2].A++;
                break;
            case 3:
                sum += input_num;
                Num[3].count ++;
                break;
            default:
                if(Num[4].A < input_num) Num[4].A = input_num;
                Num[4].count++;       
        }
    }

    for(int i = 0; i <= 4;++i){
        if(Num[i].count == 0 && i != 4) printf("N ");
        else if(Num[i].count == 0 && i == 4)printf("N");
        else if(i == 3)printf("%.1lf ",sum/Num[3].count);
        else if(i == 4)printf("%d",Num[4].A);
        else printf("%d ",Num[i].A);
    }
    //printf("\n%d %d",Num[0].A,Num[0].count);
}

/*还是审题，这是一个很严重的问题！在处理这些题目的一些bug的时候的采用了外部工具，想想是否能够不借用外部工具就可以找出这些bug
其实还有相当一部分的bug是因为自己审题不够细致导致的，其实题目的每一个字都是值得斟酌的！！！
本题中写了一个死循环，导致运行时间出现错误，还有就是在结束处的判断不够明确导致时间超时。所以，现在应该总结一下一些错误出现的原因，
这样以后出现相同的提示就可以更加有针对性的去解决。

*bug：运行超时——1.出现死循环  2.与1类似，结束条件判断有问题

*/
