#include "quick.h"

int quick_sort(int ary[], int ary_size)
{
    if (ary_size <= 1) {return 0;}

    int l = 0, r = ary_size - 1;
    int hole = 0;
    int tmp = ary[0]; //ary[0]作为基准值

    /*
    * 右先挖个坑 ！
    * 两种情况：
    * 1. l = r 跳出：右找到左（右挖出的坑左侧的值比基准值大，即属于基准值的位置的土著比基准值大，右邻居比基准值小）
    * 2. r < l 跳出：左找到右（左侧已全都小于基准值）
    */
    for ( ; r > l; r--)
    {
        if (ary[r] < tmp)
        {
            ary[hole] = ary[r];
            hole = r; // 右坑位记录

            for ( ; l < r; l++) // 右侧挖出坑（右遍历查找到小于基准值得元素）后，左遍历
            {
                if (ary[l] > tmp)
                {
                    ary[hole] = ary[l];
                    hole = l; // 左坑位记录
                    break;
                }
            }

            //防止r递减1
            //if (r == l)
                //break;
        }
    }

    if (l != r)
    {
        printf("error : l != r , l = %d, r = %d \n", l, r);
        //return -1;
    }

    // 找到基准值的位置
    ary[l] = tmp;
    printf("l = %d, r = %d \n", l, r);

    quick_sort(&ary[l + 1], ary_size - (l + 1));
    quick_sort(&ary[0], l);

    return 0;
}

int i = 0 ;
int tmp;
void ExChange(int* a, int* b)
{
    tmp = *a;
    //printf("tmp :%d", *tmp);
    *a = *b;
    *b =    tmp;
}

void Choose(int sortlst[], int n)
{
     for(; i<n-1; i++)
    {
        for(int k=i+1; k<n; k++)
            if(sortlst[i]>sortlst[k])
                (ExChange(&sortlst[i], &sortlst[k])) ;
    }
}

void Insertlst(int sortlst[], int n)
{
    for(i=1; i<n; i++)
    {
        tmp = sortlst[i];
        for(int k=i-1; k>=0; k--)
           if(tmp<sortlst[k])
            {
                sortlst[k+1] = sortlst[k];
                sortlst[k] = tmp;
            }
    }
}

void bubblesort(int sor[], int n)
{
    int i, j;
    for(i=0; i<n-1; i++)
    {
        for(j=n-2; j>=i; j--)
        {
            (sor[j]>sor[j+1]) ? (ExChange(&sor[j], &sor[j+1])) : 0;
        }
    }
}

void bubblesorts(int sor[],int n)
{
    int i,j;
    for(i = n-1;i>0;i--)
    {
        for(j=1;j<=i;j++)
        {
            (sor[j-1]>sor[j])?(ExChange(&sor[j-1],&sor[j])): 0;
        }
    }
}

