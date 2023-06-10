# cook your dish here
a = int(input())
for i in range(a):
    b =  int(input())
    i = 0 
    while i<=b:
        if(i%2)!=0  and b>1:
            print("10",end="")
            b-=2
            i+=1
        elif(i%2)==0 and b>1:
            print("01",end="")    
            b-=2
            i+=1
        else  :
            if i%2==0:
                print("1")
                b-=1
                i+=1
            else:
                print("0")
                b-=1
                i+=1
    print("\n")        