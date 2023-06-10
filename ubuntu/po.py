x = 0
class car :
    def __init__(self) :
      self.price =  0
      self.model = "model"
      self.owner = "owner"
      self.mileage= 0
      self.number =  0

    def kitnapaisa(self):
        self.price =  int(input("enter the price of the thing"))
    def kaunsi(self) :
         self.model =  input("enter the model name ")
    def kiskihai(self):
        self.owner= input("enter yeh kiski gadi hai ?")
    def kitnachalegi(self):
        self.mileage = int(input("enter the mileage"))
    def counting(self):
        self.counting =  0
        self.counting+=1

while True:
    x = input("do you wanna make a thingy?")
    if x == "" or x.lower() == "no" or x.lower() == "n" :
       continue  ;
    else :

        gadi = car()
        gadi.kitnapaisa()
        gadi.kaunsi()
        gadi.kitnachalegi()
        gadi.counting()


        print(f"the price of the car is {gadi.price}")



