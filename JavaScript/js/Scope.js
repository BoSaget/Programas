//Scope alcance de variable

const precio = 300

function hola ()
{
    const precio = 600
    console.log(precio)
}

console.log(precio)

hola()

