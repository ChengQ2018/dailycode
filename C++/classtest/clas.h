#include <iostream>

#define male 0
#define female 1


using namespace std;


class stu
{
public:
    stu():name("wangkiang"),sex(0),score(100){cout << "the default excute: " << endl;}
    //stu(string name = "wangliang", int sex = 0, int score = 100);
    stu(char *a);
    void setname(char *a);
    void display();
    void study(int n);
private:
    char name[20];
    bool sex;
    int score;

};

class Teacher{
public:
    stu m_Stu;
    Teacher();
    Teacher(string _name = "hello", int _age = 20);
    void setname(string _name);
    string getname();
    void setage(int _age);
    int getage();
    void pubtest();

private:
    string m_stName;
    int m_iAge;
    void testprivate(){cout << "success assingment" << endl;}
};





