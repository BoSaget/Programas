import openpyxl

def nuevo_peso(pesos, error, x0, x1, x2):
    taza= 0.4
    

def activacion(y):
    if y < 0:
        return -1
    else:
        return 1

path_file = "Perceptron_DataSet.xlsx"
data = openpyxl.load_workbook(path_file)
sheet = data.get_sheet_by_name('Sheet1')
#IMprimiendo el nombre de las columnas
print(sheet['A1'].value)

#Filtrar datos
x1 = []

pesos = [0.65, 0.38, 0.33]




