class Fraction:
    def __init__(self, n=0, d=1):
        if d == 0:
            raise ValueError("Denominator cannot be zero.")
        self.num = n
        self.deno = d
    
    def set_num(self, n):
        self.num = n
    
    def set_deno(self, d):
        if d == 0:
            raise ValueError("Denominator cannot be zero.")
        self.deno = d
    
    def get_num(self):
        return self.num
    
    def get_deno(self):
        return self.deno
    
    def show(self):
        print(f"{self.num}/{self.deno}")

f1 = Fraction(3, 4)
f2 = Fraction(5, 6)
    
print("Fractions:")
f1.show()
f2.show()
    
# Setting new values
f1.set_num(7)
f1.set_deno(8)
print("Updated Fraction 1:")
f1.show()
    
print("Fraction 2:", f2.get_num(),f2.get_deno())
