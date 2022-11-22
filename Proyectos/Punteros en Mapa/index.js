let marcadores
let mapa = 0
let cambioDeEstatus = false

// Inicia y presenta el mapa
function initMap() 
{  
  if(cambioDeEstatus == false)
  {
    //Se define el punto desde el que se apreciará el mapa por default y la coordenada para centrar
    const centro = {lat: 23.00000, lng: -102.00000}
    mapa = new google.maps.Map(document.getElementById("mapa"), {
      zoom: 6,
      center: centro
    });

    //Cambia el estatus, para que no se actualiza todo el mapa
    cambioDeEstatus = true
    console.log("entró if " + cambioDeEstatus)
  }

  else
  {
    console.log("entró else")
    mapa.setZoom(mapa.getZoom());
  }

  console.log(marcadores)
  //La variable global marcadores entra en un ciclo para extrar cada elemento del arrelgo
  marcadores.forEach(marcador => {
    
    //Se separa la cadena de valores   
    marcador= marcador.split('_')
    console.log(marcador)

    //Guarda el valor de la coordenada en una constante
    const coord = {lat: parseFloat(marcador[0]), lng: parseFloat(marcador[1])}

    let color = "http://maps.google.com/mapfiles/ms/icons/green-dot.png"

    //Checa el estatus para definir el color del puntero
    if(marcador[2] == '1')
    {
      color = "http://maps.google.com/mapfiles/ms/icons/red-dot.png"
    }

    //Crea el mapa con el color del estatus y la coordenada pasadas
    const marker = new google.maps.Marker({
      position: coord,
      map: mapa,
      icon: color
    });

  });
}

function actualizarEstatus()
{
  $.ajax({
    url: 'actualizar.php',
    success: function(data) {
  
      //Respuesta extrae el valor de la base de datos y lo pasa a la variable global marcadores como arrelgo
      const respuesta = JSON.parse(data)
      marcadores = respuesta.punto

      if(marcadores.length != 0)
      {
        console.log(cambioDeEstatus)
        
        window.initMap = initMap
        window.location.replace(window.location) 
      }
    }
  })
}

if (mapa == 0)
{
  $.ajax({
    url: 'index.php',
    success: function(data) {
  
      //Respuesta extrae el valor de la base de datos y lo pasa a la variable global marcadores como arrelgo
      const respuesta = JSON.parse(data)
      marcadores = respuesta.punto
  
      //Manda a llamar a la funcion para mostrar el mapa
      window.initMap = initMap
      
    }
  })
}

//Funcion para actualizar los punteros
setInterval(
  actualizarEstatus,
  3000
)