//Eventos del DOM - Submit

const formulario = document.querySelector("#formulario")
formulario.addEventListener("submit", e => {

    //Previene el comportamiento normal del formulario
    e.preventDefault()
    
    const nombre = document.querySelector(".nombre").value
    console.log(nombre)

    const password = document.querySelector(".password").value
    console.log(password)

    if(nombre === '' || password === '')
    {
        console.log("Todos los campos son olbigatorios")
    }
    else
    {
        console.log("Todo va de peli pelin peludo")
    }
})