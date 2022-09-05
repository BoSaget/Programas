const tecnologias = ["HTML", "CSS", "JavaScript", "React", "NOde.js"]
const numeros = [10, 20, 30]

let nuevoArray;

//Filter
nuevoArray = tecnologias.filter(tech => tech !== "React")

//Includes
//Comprobar si existe un elemento en el array
//const resultado = tecnologias.includes("GraphQL")

//Some
//Comprobar si alguno cumple con la condición
//const resultado = numeros.some(numero => numero > 50)

//Find
//Retorna el primer numero que cumpla con la condición
//const resultado = numeros.find(numero => numero > 5)

//Every
//Indica si todos los datos del arreglo cumplen la condición
//const resultado = numeros.every(numero => numero < 50 )

//Reduce
//const resultado = numeros.reduce( (total, numeroActual) => numeroActual + total, 0)

//Filter crea un nuevo array con base a los resultados
//const resultado =  tecnologias.filter(tech => tech === "NOde.js")
//const resultado =  numeros.filter(numero => numero < 30)

//console.log(resultado)

//Iteraciones
//foreach Accede a cada elemento del array
tecnologias.forEach((elemento, indice) => console.log(indice))

//map Crea un nuevo arreglo
const arrayMap = tecnologias.map(elemento => elemento)

console.log(arrayMap)

