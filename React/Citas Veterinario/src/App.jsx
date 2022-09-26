import Header from "./components/Header"
import Formulario from "./components/Formulario"
import Listado_Pacientes from "./components/Listado_Pacientes"

function App() {
  
  //Antes del Return es bueno para crear una funcion o una validacion

  //Dentro del return no puesdes escribir funcioes debido a que estas seran imprasas como tal
  //Dentro del return solo serian metodos
  return (
    //Fragment
    <>
       <Header />
       <Formulario />
       <Listado_Pacientes />
    </>
  )
}

export default App
