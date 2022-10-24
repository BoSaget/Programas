function Formulario() {
  return (
    <div className="lg:w-2/5 md:w-1/2">
        <h2 className="font-black text-center text-3xl text-blue-600">
          Seguimiento pacientes Formulario
        </h2>

        <p className="font-bold text-2xl text-center mt-4">
          Añadir Pacientes{" "}
          <span className="text-blue-600">
            Administrar
          </span>
        </p>
        <div className="font-bold text-xl text-center mt-3 pt-2 pb-4">
          <form className=" bg-gray-300 shadow-lg rounded-md pt-1">
            <div className="text-lg text-blue-400">
              <label class="block mt-1"htmlFor="mascota">Nombre Mascota</label>
              <input 
                id="mascota"
                type="text"
                placeholder="Nombre de la mascota" 
                className=" bg-gray-300 rounded-lg border-2 border-black outline-blue-400 placeholder-blue-400 my-2 p-2 w-80"
              />

              <label class="block mt-1"htmlFor="propietario">Propietario</label>
              <input 
                id="propietario"
                type="text"
                placeholder="Propietario" 
                className=" bg-gray-300 rounded-lg border-2 border-black outline-blue-400 placeholder-blue-400 my-2 p-2 w-80"
              />

              <label class="block mt-1"htmlFor="email">Email</label>
              <input 
                id="email"
                type="email"
                placeholder="Email de contacto" 
                className=" bg-gray-300 rounded-lg border-2 border-black outline-blue-400 placeholder-blue-400 my-2 p-2 w-80"
              />

              <label class="block mt-1"htmlFor="alta">Fecha de alta</label>
              <input 
                id="alta"
                type="date"
                className=" bg-gray-300 rounded-lg border-2 border-black outline-blue-400 placeholder-blue-400 my-2 p-2 w-80"
              />

              <label class="block mt-1"htmlFor="alta">Fecha de alta</label>
              <textarea
                id="sintomas"
                className=" bg-gray-300 rounded-lg border-2 border-black outline-blue-400 placeholder-blue-400 my-2 p-2 w-80"
                placeholder="Describe los sintomas"
              />
            </div>
            <input
              type="submit"
              className="font-bold uppercase  bg-gray-500 rounded-lg  w-80 p-3 mb-2 hover:bg-green-600"
              value="Agregar Paciente"
            />
          </form>
        </div>
    </div>
  )
}

export default Formulario
