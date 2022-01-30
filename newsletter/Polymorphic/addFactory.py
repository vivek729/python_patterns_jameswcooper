#base adder class
class Summer:
    def __init__(self, x, y):
        self.sum = 0
        self.x = x
        self.y = y
    def add(self):
        pass

"""Adds two numbers (int or float)"""
class SummerNum(Summer):
    def __init__(self, x, y):
        super().__init__(x, y)

    def add(self):
        self.sum = self.x + self.y
        return self.sum
"""Adds any values it can convert to floats"""
class SummerMix(Summer)   :
    def __init__(self, x, y):
        super().__init__(x, y)

    def add(self):
        self.sum = float(self.x) + float(self.y)
        return self.sum

"""Decides which addition class to return"""
class WhichSum:
    def __init__(self,x,y):
        self.x = x
        self.y = y

    # if it is an integer or float result will be true
    def isNumber(self, z):
        return (str(z).isnumeric())

    # return the numeric addition class if both are numbers
    # otherwise return the mixed type addition class
    def getSummer(self)->Summer:
        if self.isNumber(self.x) \
                and self.isNumber((self.y)):
            return SummerNum(self.x, self.y)
        else:
            return SummerMix(self.x, self.y)

sf = WhichSum(12.2, '13.4')
adder = sf.getSummer()  # get the class
print(adder.add())

sf = WhichSum(123, 45.6)
print(sf.getSummer().add()) # use the class directly
