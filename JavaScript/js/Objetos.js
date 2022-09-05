// Objetos

const producto = {
    nombre: "Tablet",
    precio: 300,
    disponible: true
}

console.log(producto)
console.table(producto)

console.log(producto.nombre)

//Destructuring
const {precio, nombre} = producto

console.log(precio)
console.log(nombre)

//Object Literal Enhacement
const autenticado = true
const usuario = "Juan"

const nuevoObjeto = {
    autenticado: autenticado,
    usuario: usuario
}

console.table(nuevoObjeto)