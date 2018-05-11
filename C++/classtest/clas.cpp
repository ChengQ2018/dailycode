#include <iostream>
#include "clas.h"
#include <string.h>

using namespace std;

stu::stu(char* a)
{
    strcpy(name, a);
    sex = male;
    cout << "the another zang begin >>>" << endl;
}

//stu::stu():name(name),sex(sex),score(score)){cout << "the default excute: " << endl;}

void stu::setname(char *a)
{
    strcpy(name, a);
}

void stu::display()
{
    cout << "name is : " << name <<endl;
    cout << "sex is : " << sex <<endl;
    cout << "score is : " << score <<endl;
}

void stu::study(int n)
{
    if(n<10)
        score = 20;
    else if(n > 10 && n < 15)
        score = 0;
    else
        score = 90;
}


Teacher::Teacher(){cout << "Teacher() start" << endl;}

Teacher::Teacher(string _name, int _age)
{

    m_stName = _name;
    m_iAge = _age;
    cout << "Teacher( int _age) start" << endl;
}


void Teacher::setname(string _name)
{
    m_stName = _name;
}

string Teacher::getname()
{
    return m_stName;
}

void Teacher::setage(int _age)
{
    m_iAge = _age;
}

int Teacher::getage()
{
    return m_iAge;
}

void Teacher::pubtest()
{
    testprivate();
}


