
import numpy as np
import random
import inspect
import time

def iniArray(x):
    for i in xrange(0, 11):
        for j in xrange(0, 11):
            for k in xrange(0, 11):
                x[i,j,k,0] = 1
                x[i,j,k,1] = 0
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            for k in xrange(3, 8):
                x[i,j,k,0] = 0
    return x

def subBrick(x, n):
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            for k in xrange(3, 8):
                if x[i,j,k,0] == n: 
                    x[i,j,k,0] = 0
                    x[i,j,k,1] = 0
    return x

def addBrick(x, i, j, k, n, m):
    status = False
    if m < 16:
        if m < 8: ri = -1
        else: ri = 1
        rj = 0
        rk = 0
    elif m < 32:
        if m < 24: rj = -1
        else: rj = 1
        ri = 0
        rk = 0
    else:
        if m < 40: rk = -1
        else: rk = 1
        ri = 0
        rj = 0
    if m < 4 or 7 < m < 12 or 15 < m < 20 or 23 < m < 28 or 31 < m < 36 or 39 < m < 44: pos = 1
    else: pos = 2
    if m==16 or m==20 or m==24 or m==28 or m==32 or m==36 or m==40 or m==44:
        ni = -1
        nj = 0
        nk = 0
    elif m==17 or m==21 or m==25 or m==29 or m==33 or m==37 or m==41 or m==45:
        ni = 1
        nj = 0
        nk = 0
    elif m==0 or m==4 or m==8 or m==12 or m==34 or m==38 or m==42 or m==46:
        ni = 0
        nj = -1
        nk = 0
    elif m==1 or m==5 or m==9 or m==13 or m==35 or m==39 or m==43 or m==47:
        ni = 0
        nj = 1
        nk = 0
    elif m==2 or m==6 or m==10 or m==14 or m==18 or m==22 or m==26 or m==30:
        ni = 0
        nj = 0
        nk = -1
    elif m==3 or m==7 or m==11 or m==15 or m==19 or m==23 or m==27 or m==31:
        ni = 0
        nj = 0
        nk = 1
    else: 
        print("error")
    if (x[i,j,k,0] == 0 and
    x[i+ri*1,j+rj*1,k+rk*1,0] == 0 and
    x[i+ri*2,j+rj*2,k+rk*2,0] == 0 and
    x[i+ri*3,j+rj*3,k+rk*3,0] == 0 and
    x[i+ni+ri*pos,j+nj+rj*pos,k+nk+rk*pos,0] == 0):
        x[i,j,k,0] = n
        x[i+ri*1,j+rj*1,k+rk*1,0] = n
        x[i+ri*2,j+rj*2,k+rk*2,0] = n
        x[i+ri*3,j+rj*3,k+rk*3,0] = n
        x[i+ni+ri*pos,j+nj+rj*pos,k+nk+rk*pos,0] = n
        x[i,j,k,1] = m
        x[i+ri*1,j+rj*1,k+rk*1,1] = m
        x[i+ri*2,j+rj*2,k+rk*2,1] = m
        x[i+ri*3,j+rj*3,k+rk*3,1] = m
        x[i+ni+ri*pos,j+nj+rj*pos,k+nk+rk*pos,1] = m
        status = True
    return status, x;



def printArray(x):
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            for k in xrange(3, 8):
                if x[i,j,k,0] == 0: x[i,j,k,0] = 99
                x[i,j,k,1] += 10
    print("----------")
    print("")
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            print("%d %d %d %d %d || %d %d %d %d %d" % (x[i,j,3,0], x[i,j,4,0], x[i,j,5,0], x[i,j,6,0], x[i,j,7,0], x[i,j,3,1], x[i,j,4,1], x[i,j,5,1], x[i,j,6,1], x[i,j,7,1])) 
        print("")
    print("----------")






start_time = time.time()
x = np.zeros((11,11,11,2))

x = iniArray(x)

x = subBrick(x, 5)
for i in xrange(0, 48):
    addState, x = addBrick(x,4,4,4,11,i)
    if addState == False: print("No add possible", i)
    else:
        printArray(x)
        x = iniArray(x)

printArray(x)
print("--- %s seconds ---" % (time.time() - start_time))

exit()
