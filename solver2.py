import numpy as np
import random
import inspect
import time


x = np.zeros((11, 11, 11, 5), np.int32)


def iniArray():
    for i in xrange(0, 11):
        for j in xrange(0, 11):
            for k in xrange(0, 11):
                x[i,j,k,0] = 1
                x[i,j,k,1] = 0
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            for k in xrange(3, 8):
                x[i,j,k,0] = 0

def subBrick(n):
    stopp = False
    l = 0
    i = 3
    m = 0
    ii = 0
    jj = 0
    kk = 0
    while i < 8 and stopp == False:
        j = 3
        while j < 8 and stopp == False:
            k = 3
            while k < 8 and stopp == False:
                if x[i,j,k,0] == n:
                    if l == 0:
                        m = x[i,j,k,1]
                        ii = x[i,j,k,2]
                        jj = x[i,j,k,3]
                        kk = x[i,j,k,4]
                    x[i,j,k,0] = 0
                    x[i,j,k,1] = 0
                    x[i,j,k,2] = 0
                    x[i,j,k,3] = 0
                    x[i,j,k,4] = 0
                    l += 1
                    if l >= 5: stopp = True
                k += 1
            j += 1
        i += 1
    return m, ii, jj, kk;

def addBrick(i, j, k, n, m):
    status = False
    if m < 48:
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
            x[i,j,k,2] = i
            x[i+ri*1,j+rj*1,k+rk*1,2] = i
            x[i+ri*2,j+rj*2,k+rk*2,2] = i
            x[i+ri*3,j+rj*3,k+rk*3,2] = i
            x[i+ni+ri*pos,j+nj+rj*pos,k+nk+rk*pos,2] = i
            x[i,j,k,3] = j
            x[i+ri*1,j+rj*1,k+rk*1,3] = j
            x[i+ri*2,j+rj*2,k+rk*2,3] = j
            x[i+ri*3,j+rj*3,k+rk*3,3] = j
            x[i+ni+ri*pos,j+nj+rj*pos,k+nk+rk*pos,3] = j
            x[i,j,k,4] = k
            x[i+ri*1,j+rj*1,k+rk*1,4] = k
            x[i+ri*2,j+rj*2,k+rk*2,4] = k
            x[i+ri*3,j+rj*3,k+rk*3,4] = k
            x[i+ni+ri*pos,j+nj+rj*pos,k+nk+rk*pos,4] = k
            status = True
    return status

def printArray():
    y = np.zeros((5,5,5,2))
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            for k in xrange(3, 8):
                y[i-3,j-3,k-3,0] = x[i,j,k,0] + 10
                y[i-3,j-3,k-3,1] = x[i,j,k,1] + 10
    print("----------")
    print("")
    for i in xrange(0, 5):
        for j in xrange(0, 5):
            print("%d %d %d %d %d || %d %d %d %d %d" % (y[i,j,0,0], y[i,j,1,0], y[i,j,2,0], y[i,j,3,0], y[i,j,4,0], y[i,j,0,1], y[i,j,1,1], y[i,j,2,1], y[i,j,3,1], y[i,j,3,1])) 
        print("")
    print("----------")

def fehlende():
    n = 0
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            for k in xrange(3, 8):
                if x[i,j,k,0] == 0: n += 1
    return n/5

def lastAdd():
    n = 0
    m = 0
    ii = 0
    jj = 0
    kk = 0
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            for k in xrange(3, 8):
                if x[i,j,k,0] > n:
                    n = x[i,j,k,0]
                    m = x[i,j,k,1]
                    ii = x[i,j,k,2]
                    jj = x[i,j,k,3]
                    kk = x[i,j,k,4]
    return n, m, ii, jj, kk;

def nextFree():
    stopp = False
    i = 3
    while(i < 8 and stopp == False):
        j = 3
        while(j < 8 and stopp == False):
            k = 3
            while(k < 8 and stopp == False):
                if x[i][j][k][0] == 0: stopp = True
                k += 1
            j += 1
        i += 1
    return i-1, j-1, k-1;

def status():
    n = 0
    m = 0
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            for k in xrange(3, 8):
                n = n + x[i,j,k,1] * (i+1) * (j+1) * (k+1)
                m = m + 48 * (i+1) * (j+1) * (k+1)
    return 100*n/m


start_time = time.time()

#[][][][0]: Brick Number
#[][][][1]: varianz der orientierung (0...47)
#[][][][2]: i base of varianz
#[][][][3]: j base of varianz
#[][][][4]: k base of varianz

iniArray()
n = 0
m = 0
i, j, k = nextFree()
best = 0

while True: 
    while addBrick(i, j, k, n, m) == False and m < 48:
        m += 1
    if m != 48:
        n += 1
        m = 0
        i, j, k = nextFree()
        if n >= best:
            print(fehlende())
            print("%f" % status())
            printArray()
            if n > best: best = n
    else:
        #print(fehlende())
        #print(n,m,i,j,k)
        while(m >= 47):
            n, m, i, j, k = lastAdd()
            m, j, j, k = subBrick(n)
        m += 1
        #print(fehlende())
        #print(n,m,i,j,k)
        #printArray()

printArray()
print(fehlende())
print("--- %s seconds ---" % (time.time() - start_time))

exit()
