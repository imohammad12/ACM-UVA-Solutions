import sys
import math
import re

while True:
    maxx = -1000000
    try:
        aa = [int(x) for x in input().split()]
        aa = aa[:-1]
        for i in range(len(aa)):
            for j in range(i, len(aa)):
                summ = 1
                for k in range(i, j+1):
                    if i == j:
                        summ = aa[i]
                    else:
                        summ *= aa[k]
                if maxx < summ :
                    maxx = summ
        if maxx != -1000000:
            print(maxx)
    except EOFError:
        break

