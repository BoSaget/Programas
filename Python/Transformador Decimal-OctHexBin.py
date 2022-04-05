number = int(input(""))

bin_n = list(bin(number))
bin_n.remove("0")
bin_n.remove("b")
bin_n = "".join(bin_n)
        
oct_n = list(oct(number))
oct_n.remove("0")
oct_n.remove("o")
oct_n = "".join(oct_n)
        
hex_n = list(hex(number))
hex_n.remove("0")
hex_n.remove("x")
hex_n = "".join(hex_n)
        
print("Decimal: " + str(number))
print("Octal: " + oct_n)
print("Hexadecimal: " + hex_n)
print("Binario: " + bin_n)