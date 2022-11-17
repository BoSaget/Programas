// Inicia y presenta el mapa
function initMap() {
  //marcadores es una matriz de 2 dimensiones en donde se guardan las coordenadas y el estatus
  const marcadores = [
    [21.03832, -101.58679, "./Puntos/rojo.png"],
    [21.02754, -101.56811, "./Puntos/rojo.png"],
    [21.065568, -101.634039, "./Puntos/verde.png"]
  ]

  const centro = {lat: 23.00000, lng: -102.00000}
  // The map, centered at Uluru
  const map = new google.maps.Map(document.getElementById("map"), {
    zoom: 6,
    center: centro
  });

  // la constante marker se encarga de poner el marcador
  marcadores.forEach(marcador => {
    console.log(marcador)
    const coord = {lat: marcador[0], lng:marcador[1]}
    const marker = new google.maps.Marker({
      position: coord,
      map: map,
      icon: marcador[2]
    });
  });

}
window.initMap = initMap

$.ajax({
  url: 'index.php',
  success: function(data) {
    $('.result').html(data);
  }
});
//setInterval ejecuta el comando cada  espera 5 segundos
const intervalo = setInterval(initMap, 4000, window.initMap)
  