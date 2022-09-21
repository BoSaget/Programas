//Código html con JavaScript
const formulario = document.querySelector("#formulario")
formulario.addEventListener("submit", e => {

    //Previene el comportamiento normal del formulario
    e.preventDefault()
    
    const nombre = document.querySelector(".nombre").value
    console.log(nombre)

    const password = document.querySelector(".password").value
    console.log(password)

    const alertaPrevia = document.querySelector(".alerta")
    if(alertaPrevia)
    {
        //Quieta el codigo del html
        alertaPrevia.remove()
    }

    const alerta = document.createElement('DIV')

    //console.log(alerta)
    alerta.classList.add("alerta")

    if(nombre === '' || password === '')
    {
        alerta.textContent = "Todos los campos son obligatorios"
        alerta.classList.add("error")
    }
    else
    {
        alerta.textContent = "Todo va de peli pelin peludo"
        //Agrega el código al html
        alerta.classList.add("exito")
    }

    formulario.appendChild(alerta)
})