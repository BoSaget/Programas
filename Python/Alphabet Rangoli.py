def print_rangoli(size):
    a = 96 + size
    
    for i in range(0, (size*2)-1):
        for j in range(0, (4*n)-3):
            if(i  < size):
                print(chr(a - i), end = "")
                
            else:
                print(chr(a), end = "")            
        
        print("")
        

n = int(input())
print_rangoli(n)