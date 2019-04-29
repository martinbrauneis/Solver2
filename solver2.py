
import numpy as np
import random
import inspect
import time

def iniArray(x):
    for i in xrange(0, 11):
        for j in xrange(0, 11):
            for k in xrange(0, 11):
                x[i,j,k] = 1
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            for k in xrange(3, 8):
                x[i,j,k] = 0
    # print("iniArray")
    return x

def printArray(x):
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            for k in xrange(3, 8):
                if x[i,j,k] == 0: x[i,j,k] = 99
                
    print("----------")
    print("")
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            print("%d %d %d %d %d" % (x[i,j,3], x[i,j,4], x[i,j,5], x[i,j,6], x[i,j,7])) 
        print("")
    print("----------")

def findNextZero(x):
    erfolgreich = False
    i_i = 0
    j_j = 0
    k_k = 0
    i = random.randint(3, 8)
    j = random.randint(3, 8)
    k = random.randint(3, 8)
    while i_i < 5 and erfolgreich == False:
        while j_j < 5 and erfolgreich == False:
            while k_k < 5 and erfolgreich == False:
                if x[i][j][k] == 0:
                    erfolgreich = True
                    ri=i
                    rj=j
                    rk=k
                k = k + 1
                k_k = k_k + 1
                if k > 7: k = 3
            k_k = 0
            j = j + 1
            j_j = j_j + 1
            if j > 7: j = 3
        j_j = 0
        i = i + 1
        i_i = i_i + 1
        if i > 7: i = 3
    richtung_i = 0
    richtung_j = 0
    richtung_k = 0
    while richtung_i == 0: richtung_i = random.randint(-1, 1)
    while richtung_j == 0: richtung_j = random.randint(-1, 1)
    while richtung_k == 0: richtung_k = random.randint(-1, 1)
    while x[ri+richtung_i][rj][rk] == 0: ri = ri + richtung_i
    while x[ri][rj+richtung_j][rk] == 0: rj = rj + richtung_j
    while x[ri][rj][rk+richtung_k] == 0: rk = rk + richtung_k
    return ri, rj, rk;


def fehlendeSteine(x):
    n = 0
    for i in xrange(3, 8):
        for j in xrange(3, 8):
            for k in xrange(3, 8):
                if x[i,j,k] == 0: n += 1
    return n/5


def addBrick(x, n, i_start, j_start, k_start):
    a = random.randint(0, 5)
    i_a = 0
    erfolgreich = False
    while i_a < 6 and erfolgreich == False:
        if a == 0:
            i = -1
            j = 0
            k = 0
        elif a == 1:
            i = 1
            j = 0
            k = 0
        elif a == 2:
            i = 0
            j = -1
            k = 0
        elif a == 3:
            i = 0
            j = 1
            k = 0
        elif a == 4:
            i = 0
            j = 0
            k = -1
        elif a == 5:
            i = 0
            j = 0
            k = 1
        else:
             print(inspect.stack()[0][2])

        if ( x[i_start][j_start][k_start] == 0 and  
             x[i_start+1*i][j_start+1*j][k_start+1*k] == 0 and
             x[i_start+2*i][j_start+2*j][k_start+2*k] == 0 and
             x[i_start+3*i][j_start+3*j][k_start+3*k] == 0 ):
            b = random.randint(0, 7)
            i_b = 0
            while i_b < 8 and erfolgreich == False:
                if b < 4:
                    pos = 1
                else:
                    pos = 2

                if b == 0 or b == 4:
                    r1 = -1
                    r2 = 0
                elif b == 1 or b == 5:
                    r1 = 1
                    r2 = 0
                elif b == 2 or b == 6:
                    r1 = 0
                    r2 = -1
                elif b == 3 or b == 7:
                    r1 = 0
                    r2 = 1
                else:
                    print(inspect.stack()[0][2])
           
                if i != 0:
                    i_nip = pos * i
                    j_nip = r1
                    k_nip = r2
                elif j != 0:
                    j_nip = pos * j
                    k_nip = r1
                    i_nip = r2
                elif k != 0:
                    k_nip = pos * k
                    i_nip = r1
                    j_nip = r2
                else:
                    print(inspect.stack()[0][2])
                
                if x[i_start+i_nip][j_start+j_nip][k_start+k_nip] == 0:
                    x[i_start][j_start][k_start] = n 
                    x[i_start+1*i][j_start+1*j][k_start+1*k] = n
                    x[i_start+2*i][j_start+2*j][k_start+2*k] = n
                    x[i_start+3*i][j_start+3*j][k_start+3*k] = n
                    x[i_start+i_nip][j_start+j_nip][k_start+k_nip] = n
                    erfolgreich = True

                i_b = i_b + 1
                b = b + 1
                if b > 7: b = 0

        i_a = i_a + 1
        a = a + 1
        if a > 5: a = 0
    
    return erfolgreich, x


start_time = time.time()
x = np.zeros((11,11,11))
fehlende = 25
fehlendeMerker = 25
n = 10

x = iniArray(x)



while fehlende > 0:
    i, j, k = findNextZero(x)
    addDone, x = addBrick(x, n, i, j, k)
    if addDone == True:
        n = n + 1
        fehlende = fehlendeSteine(x)
        #print(fehlende)
        #raw_input()
    else:
        #print(i,j,k)
        #debugArray = x
        #debugArray[i, j, k] = 100
        #printArray(debugArray)
        #raw_input()
        if fehlende <= fehlendeMerker+3:
            if fehlende < fehlendeMerker: fehlendeMerker = fehlende
            print("aktull fehlende: ", fehlende)
            print("bestes Ergebnis: ", fehlendeMerker)
            printArray(x)
        x = iniArray(x)
        n = 11
printArray(x)
print("--- %s seconds ---" % (time.time() - start_time))

exit()
