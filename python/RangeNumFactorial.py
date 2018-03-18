# -*- coding:utf-8 -*-

lst = []
#str1 = ''
LINELENGTH = 40
lst2 =[]

'''
题目：我们知道1的阶乘是1，2的阶乘是2，3的阶乘是6，4的阶乘是24，将前4个数字的阶乘排在一起是12624，
现在要求将1~50的阶乘排在一起打印出来，要求，每40个数字1行，当本行超过40个时换行到下一行，另外在每行的开头打印行号。
代码写的有点问题，需要完善：
1,36行调用一个返回固定字符串函数，发现其长度会发生改变。
2,对于字符串切片不太了解，39行需要再review
3,列表使用前需要初始化，可以定义为全局变量。字符串只能定义为局部变量？
'''

def SelfChange(n):
    if(n > 1):
        n = n*SelfChange(n - 1)
    return n

def GetNumIntoStringLst():
    for i in range(0,50):
        str1 = str(SelfChange(i))
        lst.append(str1)
    return lst

def MkLstIntoString():
    str2 = ''
    slst = GetNumIntoStringLst()
    for i in range(0, len(slst)):
        str2 += slst[i]
    return str2

def NumLstToLine():
    nstr = MkLstIntoString()
    a = int(len(nstr)/LINELENGTH) + 1
    for i in range(a):
        lst2.append(nstr[i*LINELENGTH:(i+1)*LINELENGTH])
    return lst2

#print(NumLstToLine())
file = open('a.text','a')
for l in NumLstToLine():
    file.write('\n' + str(l))
file.close()










