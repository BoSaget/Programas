//Operaciones Arreglos

const tecnologias = ["HTML", "CSS", "JavaScript", "React", "NOde.js"]

//Añadir elementos al array
//tecnologias.push("GraphQL") Añade al final del array
//tecnologias.unshift("Mongo")  Añade al inicio

//const nuevoArreglo = [...tecnologias, "GraphQL"]
const nuevoArreglo = ["GraphQL", ...tecnologias]


//Eliminar elementos del array
//tecnologias.pop() //Elimina del Final
//tecnologias.shift() //Elimina al inicio
//tecnologias.splice(2, 1) //Elimina de una posición espesifica

const nuevoArray = tecnologias.filter(function(tech) {
    return tech === "React"
})
//Reemplazar elementos del array
//tecnologias[0] = "GraphQL"

const newArray = tecnologias.map(function(tech){
    if(tech === "HTML")
    {
        return "GraphQL"
    }
    else
    {
        return tech
    }
}) 

console.table(tecnologias)
//console.table(nuevoArreglo)
console.table(newArray)