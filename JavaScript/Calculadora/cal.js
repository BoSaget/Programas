const botonNumero = document.getElementsByName("numero")
console.log(botonNumero)

const botonOperador = document.getElementsByName("operador")
//console.log(botonOperador)

const botonClear = document.getElementsByName("clear")
//console.log(botonClear)

const botonResultado = document.getElementsByName("resultado")
//console.log(botonResultado)

let resultado = document.getElementById("resultado")

botonNumero.forEach(function(boton)
{
    boton.addEventListener('click', function()
    {
        agregarNumero(boton.innerText)
    })
})

botonOperador.forEach(function(boton)
{
    boton.addEventListener('click', function()
    {
        Operacion(boton.innerText)
    })
})

botonClear.addEventListener("click", function()
{
    Borrar()
    ActualizarDisplay()
})

botonResultado.addEventListener("click", function()
{
    Resultado()
    ActualizarDisplay()
})
