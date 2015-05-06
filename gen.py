#!/usr/bin/python
#-*- coding:utf-8 -*-
import sys
import random

a = ['A','G','T','C']
dim = 4
for i in xrange(100):
    s = ""
    for j in xrange(dim):
        s += a[random.randrange(0,4)]
    print s
