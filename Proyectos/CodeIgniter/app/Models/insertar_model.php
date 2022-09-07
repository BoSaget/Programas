<?php
    //extendemos CI_Model
    class usuarios_model extends CI_Model{
        public function __construct() {
            //llamamos al constructor de la clase padre
            parent::__construct();
            
            //cargamos la base de datos
            $this->load->database();
        }
        
        public function ver(){
            //Hacemos una consulta
            $consulta=$this->db->query("SELECT * FROM alumnos;");
            
            //Devolvemos el resultado de la consulta
            return $consulta->result();
        }
        
        public function add($nombre, $apellido, $numero, $boleta){
            $consulta=$this->db->query("SELECT Boleta FROM alumnos WHERE Boleta LIKE '$boleta'");
            if($consulta->num_rows()==0){
                $consulta=$this->db->query("INSERT INTO alumnos (Nombre, Apellido, Numero, Boleta) VALUES('$nombre','$apellido','$numero','$boleta');");
                if($consulta==true){
                return true;
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        
        public function mod($id_usuario,$modificar="NULL",$email="NULL",$password="NULL",$nombre="NULL",$apellido="NULL"){
            if($modificar=="NULL"){
                $consulta=$this->db->query("SELECT * FROM usuarios WHERE id_usuario=$id_usuario");
                return $consulta->result();
            }else{
            $consulta=$this->db->query("
                UPDATE usuarios SET email='$email', password='$password',
                nombre='$nombre', apellido='$apellido' WHERE id_usuario=$id_usuario;
                    ");
            if($consulta==true){
                return true;
            }else{
                return false;
            }
            }
        }
        
        public function eliminar($id_usuario){
        $consulta=$this->db->query("DELETE FROM usuarios WHERE id_usuario=$id_usuario");
        if($consulta==true){
            return true;
        }else{
            return false;
        }
        }
    }
?>
