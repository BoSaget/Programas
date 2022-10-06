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

          <form className="text-xl bg-gray-300 shadow-lg rounded-md mt-3 pt-2 pb-4">
            <div className="text-lg-center text-blue-400">
              <label class="block mt-1"htmlFor="mascota">Nombre Mascota</label>
              <input 
                id="mascota"
                type="text"
                placeholder="Nombre de la mascota" 
                className=" bg-gray-300 rounded-lg border-2 border-black outline-green-500 placeholder-blue-400 mt-2 p-2"
              />

              <label class="block mt-1"htmlFor="2">Buebos</label>
              <input 
                id="2"
                type="text"
                placeholder="Be" 
                className=" bg-gray-300 rounded-lg border-2 border-black outline-green-500 placeholder-blue-400 mt-2 p-2"
              />
            </div>
          </form>
        </p>
    </div>
  )
}

export default Formulario
