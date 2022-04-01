import pandas

documento = 'Excel.xlsx'
datos = pandas.read_excel(documento)
print(datos.head(5))
