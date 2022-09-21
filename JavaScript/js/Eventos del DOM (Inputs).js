//Eventos del DOM - Inputs

const inputNombre = document.querySelector(".nombre")

inputNombre.addEventListener("input", function(e){
    console.log("Escribiendo en el input")
    console.log(e.target.value)
})

const inputPassword = document.querySelector(".password")
inputPassword.addEventListener("input", functionPass)

function functionPass(e){
    inputPassword.type = "text"
    //setTimeout funciona en milisegundos
    setTimeout( () =>{
        inputPassword.type = "password"
    }, 100)
}