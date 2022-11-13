// Initialize and add the map
function initMap() {
    // The location of Uluru
    const marcador = { lat: 21.03832, lng:  -101.58679};
    // The map, centered at Uluru
    const map = new google.maps.Map(document.getElementById("map"), {
      zoom: 8,
      center: marcador,
    });

    const verde = "./Puntos/rojo.png"

    // The marker, positioned at Uluru
    const marker = new google.maps.Marker({
      position: marcador,
      map: map,
      icon: verde     
    });
  }
  
  window.initMap = initMap;