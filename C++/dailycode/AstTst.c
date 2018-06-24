#if 1
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
/******
在一个二维数组中，每一行都按照从左到右递增的顺序排序，
每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
1.遍历
2.左下角出发，上移减，右移加
******/

#define random(x) rand()%x
#define true 1
#define false 0

int JudgeIfExist(int *ast, int m, int n, int num)
{
    printf("*************getin\n");
    int i, j;
    int *cur = NULL;
    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            //printf("a[%d][%d] = %d, ad = %d\n", i, j, *(ast+i*n+j), ast+i*n+j);
            cur = ast+i*n+j;
            if( *cur == num)
            {
                //printf("ast[%d][%d] is the num\n", m+1, n+1);
                printf("a[%d][%d] = %d\n", i+1, j+1, *(ast+i*n+j));
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int loop1, loop2;
    int rdast[10][10];
    for(loop1=0; loop1<10; loop1++)
    {
        for(loop2=0; loop2<10; loop2++)
        {
            rdast[loop1][loop2] = random(200);
        }
    }
    for(loop1=0; loop1<10; loop1++)
    {
        for(loop2=0; loop2<10; loop2++)
        {
            printf("%-5d  ", rdast[loop1][loop2]);
        }
        printf("\n");
    }
    int iget;
    printf("input a num : \n");
    if(scanf("%d", &iget)!=0)
    {
        int flag = false;
        flag = JudgeIfExist((int*)rdast, 10, 10, iget);
        if(flag == true)
        {
            printf("thaku! ...\n");
        }
        else printf("sor! ...\n");
    }
}
#endif
