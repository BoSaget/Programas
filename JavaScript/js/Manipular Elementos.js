//Manipular elementos HTML con JS

const heading = document.querySelector("#heading")

heading.textContent= "HEy"

console.log(heading.textContent)

const inputNombre = document.querySelector("#nombre")
inputNombre.value = "Probandooo"
console.log(inputNombre)

const enlaces = document.querySelectorAll("a")

enlaces.forEach(enlace => enlace.textContent = "Hey enlace")