const botonNumero = document.getElementsByName("numero")

const botonOperador = document.getElementsByName("operador")

const botonClear = document.getElementsByName("borrar")

const botonResultado = document.getElementsByName("igual")

let resultado = document.getElementById("resultado")

let operacionActual = ''
let operacionAnterior = ''
let operacion = undefined

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

botonClear[0].addEventListener('click', function()
{
    Borrar()
    ActualizarDisplay()
})

botonResultado[0].addEventListener('click', function()
{
    Calcular()
    ActualizarDisplay()
})

function Operacion(operador)
{
    if(operacionActual === '') return 
    if(operacionAnterior !== '')
    {
        Calcular()
    }
    operacion = operador.toString()
    operacionAnterior = operacionActual
    operacionActual = ""
}

function Calcular()
{
    let calculo
    const anterior = parseFloat(operacionAnterior)
    const actual = parseFloat(operacionActual)

    if(isNaN(anterior) || isNaN(actual)) return

    switch(operacion)
    {
        case '+':
            calculo = anterior + actual
            break
        
        case '-':
            calculo = anterior - actual
            break
            
        case 'X':
            calculo = anterior * actual
            break
                
        case '/':
            calculo = anterior / actual
            break
        default:
            return
    }
    operacionActual =  calculo
    operacion = undefined
    operacionAnterior = ""
}

function agregarNumero(numero)
{
    operacionActual = operacionActual.toString() + numero.toString()
    ActualizarDisplay()
}

function Borrar()
{
    operacionActual = ""
    operacionAnterior = ""
    operacion = undefined
}

function ActualizarDisplay()
{
    resultado.value = operacionActual
}
