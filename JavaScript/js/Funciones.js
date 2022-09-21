function sumar (n1, n2 = 0)
{
    return n1 + n2
}

function restar (n1, n2 = 0)
{
    return n1 - n2
}


//Solamente se puede utilizar un export por documento

//el default permite llamar a la funcion importada como sea y exporta la 
//exporta para que pueda ser importada en otros archivos
//export default sumar

//Para exportar mas de una función se deberá tratar como objeto
export{
    sumar,
    restar
}