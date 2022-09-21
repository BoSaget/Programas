//Manipular elementos HTML con JS

const heading = document.querySelector("#heading")

heading.textContent= "HEY"

console.log(heading.textContent)

//Query Selector obtiene la primer conincidencia con el Id, clase, etc
const inputNombre = document.querySelector("#nombre")
inputNombre.value = "Probandooo"
console.log(inputNombre)

//Query Selector All selecciona todas las etiquetas con de tipo <a>
const enlaces = document.querySelectorAll("a")

enlaces.forEach(enlace => enlace.textContent = "Hey enlace")