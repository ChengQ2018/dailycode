# -*- conding:utf-8 -*-

import ftplib


filelist = ftplib.FTP('192.168.0.5').nlst()
print(filelist)
