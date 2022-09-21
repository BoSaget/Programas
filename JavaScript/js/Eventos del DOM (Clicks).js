//Eventos del DOM - Clicks

const clickHeading = () =>
{
    console.log("Mi crazy, acabas de dar click en el heading que dice: " + heading.innerHTML)
}

const heading = document.querySelector('.heading')

heading.addEventListener("click", () => {
    console.log("Mi crazy, acabas de dar click en el heading que dice: " + heading.innerHTML)
    heading.textContent = "Nuevo Heading"
})


//Si llega a tener parentesis mandará a llamar la función automaticamente
//heading.addEventListener("click", clickHeading)

const enlaces = document.querySelectorAll("a")
//NO se puede usar un add event listener cuando se tiene un arreglo, para eso se recorre el arreglo
enlaces.forEach(enlace => {
    enlace.addEventListener("click", () => {
        console.log("Mi crazy, acaba de clickear un enlace: " + enlace.textContent)
    })
})
