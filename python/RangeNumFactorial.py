# -*- coding:utf-8 -*-

lst = []
#str1 = ''
LINELENGTH = 40
lst2 =[]

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










