#include "quick.h"

int main()
{
    int test_ary[] = {3, 1, 2, 7, 15, 9, 11, 6, 4, 5};
    //int test_ary[] = {1, 2, 3, 4, 5};

    int ret = 0;
    ret = quick_sort(test_ary, sizeof(test_ary)/sizeof(int));

    //if (ret != 0)
        //printf("fail\n");
    //else

    for (int i = 0; i < sizeof(test_ary)/sizeof(int); i++)
    {
        printf("ary[%d] = %d \n", i, test_ary[i]);
    }



    return 0;
}
