#include <iostream>
#include <strstream>
#include <string.h>
#include "clas.h"

#define vos_ok 0
#define vos_false 1

using namespace std;

void test(const int* m_iA)
{

    cout << "testa : " << *m_iA << endl;
    int* x = new int;
    int* tmp;
    cout << m_iA << " " << x << endl;
    m_iA = x;
    cout << m_iA << " " << x << endl;
    *x = 999999;
    delete x;
    cout << m_iA << " " << x << endl;
    cout << "testa : " << *m_iA << "\t*x" << *x << endl;

}

int main()
{
    //Teacher t1();
    Teacher t2("wangliang");
    string tmpname = "xiaomin";
    t2.setname(tmpname);
    cout << "aft setname the name is : " << t2.getname() << endl;
    //t1.pubtest();
    t2.m_Stu.setname("llll");
    t2.m_Stu.display();
    return vos_ok;
}
