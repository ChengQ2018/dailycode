#coding=utf-8

import os,re

'''
公司最近在开展代码监视的活动，单独组建了一个群组，用于反馈组员每日代码检视的成果。
代码检视的输出为华为内源网站上的issue地址，现在要统计每个人每日的issue条数。
这个脚本用来提取群消息中的成员姓名+对应的issue地址。
需要提取的消息格式如下：
cwx6364632 12:33 
http:www.xxxx.xxxx.xxx
需要分析的情况：一人发多条同样的issue；一人同时发多条不同issue
'''

fillenamea = r'E:\test_2018\a.text'
fillenameb = 'E:\\test_2018\\b.text'

nampttern = re.compile('cxw469300', re.I)
isuepattern = re.compile('http:\w*.com', re.I)
namlst = []
isulst = []
relst = []

def GetSimpLst(filelst):
    simplst = []
    for item in filelst:
        if simplst.count(item) == 0:
            simplst.append(item)
    return simplst

def GetNameAndIssueLst(simplst):
    num = 0
    for lcon in simplst:
        num += 1
        if num <= len(simplst):
            ret1 = isuepattern.match(lcon)
            if ret1 != None:
                #print(ret1)
                isulst.append(ret1.string)
                relst = simplst[:num][::-1]
                for relcon in relst:
                    ret2 = nampttern.match(relcon)
                    if ret2 != None:
                        print(ret2)
                        namlst.append(ret2.string)
                        break
    return namlst, isulst

def WriteLstToFile(namlst, isulst):
    tarfile = open(fillenameb, 'w')
    if len(namlst) == len(isulst):
        for i in range(len(namlst)):
            tarfile.write(namlst[i] + '\n' + isulst[i] + '\n')
    tarfile.close()

print(os.path.exists(fillenamea))
if(os.path.exists(fillenamea)):
    sorcfile = open(fillenamea, 'r')
    content = sorcfile.readlines()
    sorcfile.close()
    simplst = GetSimpLst(content)
    print(simplst)
    nlst, islst = GetNameAndIssueLst(simplst)
    WriteLstToFile(nlst, islst)

