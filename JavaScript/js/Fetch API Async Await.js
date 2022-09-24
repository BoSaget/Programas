//Fetch API con Async Await

const url = "https://jsonplaceholder.typicode.com/comments"

//PAra usar asyn await se necesita una función asincrona
const consultarAPI = async () => {

    //Await bloquea el codigo, previene que la siguiente linea se ejecute hasta tener una respuesta 
    const respuesta = await fetch(url)    
    const resultado = await respuesta.json()
}

consultarAPI()
    