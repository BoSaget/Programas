cadena = input("")

#Alfanumerico
#validation_a = cadena.isalnum()
#print(validation_a)

validation_a = False
validation_b = False
validation_c = False
validation_d = False
validation_e = False

for i in range (0, len(cadena)):

    aux = cadena[i]

    if aux.isalpha() == True:
        #Alfabetico
        validation_a = True
        validation_b = True

    if aux.isdigit() == True:
        #Digitos
        validation_c = True
        validation_a = True

    if aux.islower() == True:
        #Minusculas
        validation_d = True

    if aux.isupper() == True:
        #Mayusculas
        validation_e = True


print(validation_a)
print(validation_b)
print(validation_c)
print(validation_d)
print(validation_e)