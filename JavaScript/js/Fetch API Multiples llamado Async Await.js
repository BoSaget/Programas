//Fetch API Multiples llamado Async Await.js

const url = "https://jsonplaceholder.typicode.com/comments"
const url2 = "https://jsonplaceholder.typicode.com/photos"

//PAra usar asyn await se necesita una función asincrona
const consultarAPI = async () => {

    const inicio = performance.now()
    //Await bloquea el codigo, previene que la siguiente linea se ejecute hasta tener una respuesta 
    const respuesta = await fetch(url)    
    const resultado = await respuesta.json()
    //console.log(resultado)

    //Ninguna consulta d eurl depende d la otra, por lo tnato no funciona de manera optima
    //console.log("iniciando segunda consulta")

    const respuesta2 = await fetch(url2)    
    const resultado2 = await respuesta2.json()
    //console.log(resultado2)

    const fin = performance.now()

    console.log(`Ejecucion primer async: ${fin - inicio}ms`)

}

consultarAPI()

const consultarAPI2 = async () => {

    const inicio = performance.now()
    //Promise.all arranca ambos al mismo tiempo
    const [respuesta, respuesta2] = await Promise.all([fetch(url), fetch(url2)])

    const resultado = await respuesta.json()
    const resultado2 = await respuesta2.json()

    //console,log(resultado)
    //console.log(resultado2)

    const fin = performance.now()

    console.log(`Ejecucion segundo async: ${fin - inicio}ms`)

}

consultarAPI2()
    