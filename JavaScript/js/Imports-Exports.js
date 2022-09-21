//Imports y Exports

//JS de manera nativa puede importar y exportar funciones
//Se importa la funciones previemnte exportada
//import hey from "./Funciones.js"

//PAra cuando se exporta una función de muchas funciones que contiene el arhicvo
//Se utilizará el nombre exacto porque no hay default
import { sumar as hey } from "./Funciones.js"
 
const resultado = hey(20)
console.log(resultado)