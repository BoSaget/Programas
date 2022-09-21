//Funciones - Function Declaration

//Las function declaration se pueden delcarar en cualquier parte por que JS primero compila todas las funciones
//Si no se le pasa un valor a dato2, su parametro por default sera el numero 0
function sumar(dato1, dato2 = 0) {
    console.log(dato1 + dato2)
}

sumar(10, 20)
sumar(5, 3)
sumar(100)