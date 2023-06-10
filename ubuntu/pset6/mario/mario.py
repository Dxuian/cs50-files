import cs50
import pdb
h = cs50.get_int("Height: ")
i = h
while (i<=0 or i>=9):
  h = cs50.get_int("Height: ")
  i=h
for j in range(h):
    for sp in range(h-j-1):
        print(" ",end="")
    for ha in range(j+1):
        print("#",end="")
    print("  ", end="")

    for ha in range(j+1):
        print("#",end="")
    print("")