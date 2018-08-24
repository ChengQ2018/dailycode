#include <stdio.h>
#include <stdlib.h>


int ReOrderArray(int ast[], int num)
{
    int loop = 0, num_a = 0, num_b = 0, j = 0;
    int *ary_a = (int*)malloc(num);
    int *ary_b = (int*)malloc(num);

    for( ; loop<num; loop++)
    {
        if(ast[loop]%2)
        {
            *(ary_a+num_a) = ast[loop];
            num_a++;
        }
        else
        {
            *(ary_b+num_b) = ast[loop];
            //printf("***%d\n", *(ary_b+num_b));
            num_b++;
        }
    }

    if((num_a+num_b) != num)
    {
        printf("num dont right!\n");
        return -1;
    }

    for(loop=0; loop<num; loop++)
    {
        if(loop<num_a)
            ast[loop] = *(ary_a+loop);
        else
        {
            ast[loop] = *(ary_b+j);
            j++;
        }
    }

    free(ary_a);
    free(ary_b);

    return 0;
}

int main()
{
    int arytest[10] = {0,1,2,3,4,5,6,7,8,9};
    int ret;

    ret = ReOrderArray(arytest, 10);
    if(ret != 0)
    {
        printf("error\n");
        return 0;
    }

    int i = 0;
    for(; i<10; i++)
        printf("after changed no.%d is %d\n", i, arytest[i]);

    return 0;
}
