import csv
import sys
import os
from copy import deepcopy
import cs50
da = sys.argv[1]
ba = sys.argv[2]
databa = da
bases = ba
p = []

with open(databa, "r") as data:
    it = csv.reader(data, delimiter=',')

    for x in it:
        p.insert(it.line_num-1, x)
with open(bases, "r") as ab:

    mem = csv.reader(ab)
    a = ""
    for x in mem:
        a = x

    arr = deepcopy(p)
    del arr[2:len(arr)]
    for j in range(1, len(arr), 1):
        for i in range(1, len(arr[0]), 1):
            arr[j][i] = 0
    arr[1][0] = 'count'

    # for j in range(1,len(arr[0]),1):
    #     if p[0][j] in str(a) :
    #         arr[1][j]+=str(a).count(p[0][j])
    # for i in range(len(a)):
    #     if p[0][j] in str(a) :
    #         x = a.find(p[0][j])
    #         arr[1][j]+=1
    # for j in range(1,len(arr[0]),1):
    #         x = 0
    #         for i in range(x,len(str(a)),1):
    #             x  = (str(a)).find(p[0][j],x)
    #             if ((str(a)).find(p[0][j],x) != -1 and (str(a)).find(p[0][j],x)==x+len(p[0][j])     ):
    #                 x  = (str(a)).find(p[0][j],x)
    #                 arr[1][i]+=1
    # at = []

    # j  = 1
    # while j<len(arr[0]) :
    #     if p[0][j] in str(a):
    #          x  = (str(a)).find(p[0][j],x)

    # for j in range(1, len(arr[0]), 1):

    #   x = 0
    #   co = 0
    #   cohigh=  0
    #   while x < len(str(a)) and (str(a)).find(p[0][j], x+len(p[0][j])) != -1:
    #         x = (str(a)).find(p[0][j], x+len(p[0][j]))
    #         if x != -1:
    #             if co == 0:
    #                 co = 1
    #             while (str(a)).find(p[0][j], x+len(p[0][j])) == x+len(p[0][j]):
    #                 co += 1
    #                 x = (str(a)).find(p[0][j], x+len(p[0][j]))
    #             if co>cohigh:
    #                 cohigh = co

    #   arr[1][j] = cohigh

    for j in range(1,  len(arr[0]), 1):
        maxc = x = 0
        count = 1
        while x < len(str(a)):
            x = (str(a)).find(p[0][j], x+len(str(arr[0][j])))
            if x == -1:
                break
            if x+len(str(arr[0][j])) == (str(a)).find(p[0][j], x+len(str(arr[0][j]))):
                while x+len(str(arr[0][j])) == (str(a)).find(p[0][j], x+len(str(arr[0][j]))):
                    count += 1
                    x = (str(a)).find(p[0][j], x+len(str(arr[0][j])))
            if maxc < count:
                maxc = count
        arr[1][j] = maxc

    # for j in range(1, len(p), 1):
    #     for i in range(1, len(p[1]), 1):
    #         if arr[1][i] == int(p[j][i]) and i != len(p[1])-1:
    #             xyz = 123
    #         elif arr[1][i] == int(p[j][i]) and i == len(p[1])-1:
    #             print(p[j][0])
    #             exit()
    #         elif (j == len(p)-1):
    #             asas = 12
    #         else:
    #             break
    # if asas == 12:
    #     print("No match")
    ar = [0 for i in range(len(p))]
    ar[0] = "mcount"
    for j in range(1, len(p), 1):
        for i in range(1, len(arr[0]), 1):
            if int(p[j][i]) == int(arr[1][i]):
                ar[j] += 1
            else:
                pass
    counter = 0
    pos = 0
    for i in range(1, len(ar), 1):
        if counter < ar[i]:
            counter = ar[i]
            pos = i
    if counter <= ((len(arr[0]) - 1)/4)*3:
        print("No match")
    else:
        print(p[pos][0])
    akjdfakj = 12312
    sdfsj12 = 1213


# # q.append(p[0])
# # q.insert(0,p[][])
# # # for i in range()
# # print(q)
