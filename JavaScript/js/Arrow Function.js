//Funciones - Arrow Function

const sumar = (numero1, numero2 = 1) => {
    return numero1 + numero2
}

const resultado = sumar(30)
console.log(resultado)

const arrow = numero1 => numero1 + 2

const resultado2 = arrow(20)
console.log(resultado2)