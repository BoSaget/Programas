//Unir 2 Objetos o mas
const producto = {
    nombre: "Tablet",
    precio: 300,
    disponible: true
}

const cliente = {
    nombre: "Leon",
    premium: true
}

// const nuevoObjeto = Object.assign(producto, cliente) No
const nuevoObjeto2 = {
    producto: {...producto},
    clinte: {...cliente}}

console.log(nuevoObjeto2)