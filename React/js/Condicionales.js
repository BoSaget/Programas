//Condicionales

const disponible = 4000
const retirar = 2000

if (disponible > retirar)
{
    //Se cumple la condición
    console.log("Si puedes retirar")
}
else
{
    //No se cumple la condicion
    console.log("No puedes retirar perro")
}

/**
 * < 
 * >
 * <=
 * >=
 * ==
 * !=
 * 
 */

//Comparación == y ===
const numero = 20
const numero2 = "20"

/**
 * == comparación peor on es estricto
 * === comparación estricta
 */

if(String(numero) === numero2)
{
    console.log("Son iguales")
}

else
{
    console.log("No son iguales")
}
