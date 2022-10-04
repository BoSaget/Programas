function Formulario() {
  return (
    <div className="lg:w-2/5 md:w-1/2">
        <h2 className="font-black text-center text-3xl text-blue-600">
          Seguimiento pacientes Formulario
        </h2>

        <p className="font-bold text-2xl text-center mt-5">
          Añadir Pacientes{" "}
          <span className="text-blue-600">
            Administrar
          </span>

          <form className="text-xl bg-gray-300 shadow-lg mt-5 rounded-md w-96 py-3">
            <div className="text-lg-center text-blue-400 block">
              <label htmlFor="mascota">Nombre Mascota</label>
              <input 
                id="mascota"
                type="text"
                placeholder="Nombre de la mascota" 
                className=" bg-gray-300 rounded-lg border-2 border-black mt-2 placeholder-blue-400"
              />
            </div>
          </form>
        </p>
    </div>
  )
}

export default Formulario
