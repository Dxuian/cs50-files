import sys
class unnat:
    name = "helllo"
    def __init__(self,name,age,place):
        self.name =  "dannasama" 
        self.age  =  age 
        self.place = place 
    def change_the_value(self):
        self.name =  str(input("enter the new name of the the variable name:   "))
        print(self.name , self.age, self.place)
    
x  = input("helli what would you like to enter: ") 
inst  =  unnat(x,123,"hello")
inst.change_the_value()
print(inst.name)
print(unnat)
    
