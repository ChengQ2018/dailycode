#include <iostream>
#include <string>
#include <string.h>

#define vos_error -1
#define vos_ok 0


using namespace std;

typedef struct uniontest{
    char tlvtype[10];
    union{
        int iA;
        double dB;
        char cC[20];
    }tlvdata;
}uniontest_s;

int main()
{
    uniontest_s g_test[1000];
    int n, m, loop;
    char tmp[10] = {0};
    cout << "typein n & m: " << endl;
    if(scanf("%d%d", &n, &m)!=2)
    {
        cout << "please input two INT num" << endl;
        return vos_error;
    }
    else
    {
        for(loop=0; loop<n; loop++)
        {
            scanf("%s", tmp);
            strcpy(g_test[loop].tlvtype, tmp);
            if(strcmp(g_test[loop].tlvtype, "INT")==0)
            {
                scanf("%d", &g_test[loop].tlvdata.iA);
            }
            if(strcmp(g_test[loop].tlvtype, "DOUBLE")==0)
            {
                scanf("%f", &g_test[loop].tlvdata.dB);
            }
            if(strcmp(g_test[loop].tlvtype, "STRING")==0)
            {
                scanf("%s", g_test[loop].tlvdata.cC);
            }
            //else cout << " input corecct type" << endl;
        }

        int *pCout = new int [m];
        for(loop=0; loop<m; loop++)
        {
            cout << "choose one : " << endl;
            if(scanf("%d", &pCout[loop])!=1)
                return vos_error;
        }

        for(loop=0; loop<m; loop++)
        {
            if(strcmp(g_test[pCout[loop]].tlvtype, "INT") == 0)
                cout << g_test[pCout[loop]].tlvdata.iA << endl;
            if(strcmp(g_test[pCout[loop]].tlvtype, "DOUBLE") == 0)
                cout << g_test[pCout[loop]].tlvdata.dB << endl;
            if(strcmp(g_test[pCout[loop]].tlvtype, "STRING") == 0)
                cout << g_test[pCout[loop]].tlvdata.cC << endl;
        }
        delete []pCout;

    }
}
