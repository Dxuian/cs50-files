# TODO

n  = (input("Number: "))
x = len(n)
ev = 0 
for i in range(x-2,-1,-2):
    if (int(n[i]))*2<9:
        ev+=(int(n[i])*2)
    else:
        ns = int(n[i])*2
        ev+= (ns%10)+(((ns-(ns%10))%100/10))

for j in range(x-1,-1,-2):
    ev+=2*(int(n[j]))
if ev%10==0:
    if x==15:
        print("AMEX\n")
    elif (x==13 or x==16) and int(n[0])==4 :
        print("VISA\n")    
    elif x==16:
        print("MASTERCARD\n")
else:
    print("INVALID\n")
