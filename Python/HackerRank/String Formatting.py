def print_formatted(number):
    
    largo = list(bin(number))
    largo.remove("0")
    largo.remove("b")
    largo = "".join(largo)
    largo = len(largo)
    
    for i in range (1, number + 1):
        
        oct_i = list(oct(i))
        oct_i.remove("0")
        oct_i.remove("o")
        oct_i = "".join(oct_i)
        
        hex_i = list(hex(i))
        hex_i.remove("0")
        hex_i.remove("x")
        hex_i = "".join(hex_i)
        hex_i = hex_i.swapcase()
        
        bin_i = list(bin(i))
        bin_i.remove("0")
        bin_i.remove("b")
        bin_i = "".join(bin_i)
        
        print((str(i)).rjust(largo), end=" ")
        print((oct_i).rjust(largo), end=" ")
        print((hex_i).rjust(largo), end=" ")
        print((bin_i).rjust(largo))

number = int(input(""))
print_formatted(number)