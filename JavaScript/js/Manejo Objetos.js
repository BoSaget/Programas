// Objetos Manipulación

const producto = {
    nombre: "Tablet",
    precio: 300,
    disponible: true
}

//Object.freeze(producto) -- No deja modificarlo para nada
//Object.seal(producto) -- Solamente permita modificar propiedades existentes

//Reescribir un valor
producto.nombre = "Monitor Curvo"

producto.imagen = "Imagen.png"

delete producto.disponible

console.table(producto)