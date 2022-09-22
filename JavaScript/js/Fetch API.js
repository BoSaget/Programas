//Fetch API (El nuevo ajax)

const url = "https://jsonplaceholder.typicode.com/comments"

const consultarAPI = () => {
    //Promises, un valor que va a estar disponible ahora o en un futuro
    fetch(url)
        .then( respuesta => respuesta.json())
        .then( (resultado) => {
            resultado.forEach(elemento => {
                console.log(elemento)
            });
        })
}
consultarAPI()
    