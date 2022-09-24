//el tempalte string es para concatenar variables con strings y finciones

const producto = "Table de 12 pulgadas"
const precio = 400
const marca = "Orange"

const textoDeFuncion = () => "Este texto proviene de la funcion: "

/*
console.log(producto + " $" + precio + "Dolares, Marca: " + marca)
console.log(producto , " $" , precio , "Dolares, Marca: " , marca)
*/
console.log(`${producto} $${precio}, Marca: ${marca} ${textoDeFuncion()}`)