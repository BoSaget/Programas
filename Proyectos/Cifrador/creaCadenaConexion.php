<?php

$gs_cadena_1_94_base_array = array('_', '.', ':', 'x', 'y', 'z', '!', '#', '$', '{', '[', '^', '1', '2', '3', '(', ')', '=', 'D', 'E', 'F', '?', '\\', '¿', 'u', 'v', 'w', 'G', 'H', 'I', '%', '&', '/', '4', '5', '6', 'r', 's', 't', '}', ']', '-', 'J', 'K', 'L', ';', '<', 'o', 'p', 'q', '7', '8', '9', 'M', 'N', 'Ñ', '°', '¬', 'g', 'h', 'i', 'A', 'B', 'C', 'O', 'P', 'Q', '¡', '+', '*', 'd', 'e', 'f', 'R', 'S', 'T', 'm', 'n', 'ñ', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'j', 'k', 'l', '0', '>', ',');

$gs_cadena_data_base_array = array('F', '?', '\\', '¿', 'y', 'z', '!', '#', '1', '2', '3', '(', 'u', 'v', 'w', 'G', ')', '=', 'D', 'E', 'H', 'I', '%', '&', 'L', ';', '<', 'o', '/', '4', '5', '6', 'p', 'q', '7', '8', 'r', 's', 't', '}', '_', '.', ':', 'x', '9', 'M', 'N', 'Ñ', 'i', 'A', 'B', 'C', '+', '*', 'd', 'e', '$', '{', '[', '^', 'm', 'n', 'ñ', 'U', 'Z', 'a', 'b', 'c', 'j', 'k', 'l', '0', 'V', 'W', 'X', 'Y', 'f', 'R', 'S', 'T', 'O', 'P', 'Q', '¡', '°', '¬', 'g', 'h', ']', '-', 'J', 'K', '>', ',', ' ');

function f_get_letra_encriptada($arg_letra_s, $arg_cadena_seguridad, &$arg_chr_s, &$arg_msj_s)
{
	global $gs_cadena_data_base_array;
	$ll_ele_original = 0;
	$ll_ele_encontrado = 0;
	$ls_caracter_s = '';
	$ll_ele_original = 0;
	$ll_ele_encontrado = -1;
	$ls_caracter_s = '';

	foreach ($gs_cadena_data_base_array as $ls_caracter_s) {
		$ll_ele_original++;
		if ($arg_letra_s == $ls_caracter_s) {
			$ll_ele_encontrado = $ll_ele_original - 1;
			break;
		}
	}

	if ($ll_ele_encontrado == -1) {
		$arg_chr_s = $arg_letra_s;
	} else {
		$arg_chr_s = $arg_cadena_seguridad[$ll_ele_original];
	}
	return 1;
}

function f_crea_char_1al94($arg_numero_l, &$arg_caracter_s, &$arg_msj_s)
{

	global $gs_cadena_1_94_base_array;
	$ll_count = 0;
	$ls_cadena_base = array();

	$ll_count = 0;
	$ls_cadena_base = '';
	$ls_cadena_base = $gs_cadena_1_94_base_array;
	$ll_count = count($ls_cadena_base);

	if ($arg_numero_l <= 0 or $arg_numero_l > $ll_count) {
		$arg_caracter_s = '';
	} else {
		$arg_caracter_s = $ls_cadena_base[$arg_numero_l - 1];
	}
	$arg_msj_s = 'Caracter correcto';
	return 1;
}

function f_crea_cadena_seguridad($arg_posicion_l, &$arg_valida_s, &$arg_cadena_seguridad, &$arg_msj_s)
{

	global $gs_cadena_data_base_array;
	$arg_valida_s = 'false';
	$ls_cadena_base = array();
	$ls_cadena_nueva = array();
	$ll_incia_en = 0;
	$ll_ele_arr = 0;
	$ll_ele = 0;
	$ll_long_cadena_base = 0;
	$ls_cadena_base = $gs_cadena_data_base_array;
	$ll_long_cadena_base = count($ls_cadena_base);
	$ll_incia_en = $arg_posicion_l;
	$ll_ele_arr = 0;
	$ll_ele = 0;

	for ($ll_ele = $ll_incia_en; $ll_ele < $ll_long_cadena_base; $ll_ele++) {
		$ll_ele_arr++;

		if ($ll_ele_arr > $ll_long_cadena_base) {
			$arg_valida_s = 'false';
			$arg_msj_s = 'Error al crear la cadena de seguridad';
			return -1;
		}

		if ($ls_cadena_base[$ll_ele] == 'NULL' or is_null($ls_cadena_base[$ll_ele])) {
			$ls_cadena_nueva[$ll_ele_arr] = ' ';
		} else {
			$ls_cadena_nueva[$ll_ele_arr] = $ls_cadena_base[$ll_ele];
		}
	}

	for ($ll_ele = 0; $ll_ele < $ll_incia_en; $ll_ele++) {
		$ll_ele_arr++;

		if ($ls_cadena_base[$ll_ele] == 'NULL' or is_null($ls_cadena_base[$ll_ele])) {
			$ls_cadena_nueva[$ll_ele_arr] = ' ';
		} else {
			$ls_cadena_nueva[$ll_ele_arr] = $ls_cadena_base[$ll_ele];
		}
	}

	if (count($ls_cadena_nueva) != $ll_long_cadena_base) {
		$ls_cadena_nueva = '';
		$arg_valida_s = 'false';
		$arg_msj_s = 'Error al al crear la cadena de seguridad';
		return -1;
	} else {
		$arg_cadena_seguridad = $ls_cadena_nueva;
		$arg_valida_s = 'true';
		$arg_msj_s = 'Cadena de seguridad correcta';
		return 1;
	}
}

function f_get_letra_descifra($arg_caracter_s, $arg_cadena_seguridad_array, $arg_condicion_s, &$arg_caracter_des_s, &$arg_msj_s)
{

	global $gs_cadena_data_base_array;
	$ll_count = 0;
	$ll_ele_encontrado = 0;
	$ll_ini = 0;
	$ll_count = 0;
	$ll_ele_encontrado = 1000;
	$ll_ini = 0;

	if ($arg_condicion_s == '' or is_null($arg_condicion_s)) {
		$arg_condicion_s = 'CONTRHOL';
	}

	foreach ($arg_cadena_seguridad_array as $caracter) {
		$ll_count++;
		if ($arg_caracter_s == $caracter) {
			$ll_ele_encontrado = $ll_count;
			break;
		}
	}

	if ($ll_ele_encontrado <> 1000) {
		$arg_caracter_des_s = $gs_cadena_data_base_array[$ll_ele_encontrado - 1];
	} else {
		$arg_caracter_des_s = $arg_caracter_s;
	}

	$arg_msj_s = 'Caracter correcto [letra_descifra]';
	return 1;
}

function f_obten_valor_char_1al20($arg_chr_s, &$arg_index_l, &$arg_msj_s)
{

	global $gs_cadena_1_94_base_array;
	$ll_val_chr = 0;

	$ll_val_chr = 0;

	foreach ($gs_cadena_1_94_base_array as $caracter) {
		$ll_val_chr++;
		if ($arg_chr_s == $caracter) {
			if ($arg_chr_s == '#' or $arg_chr_s == 'x' or $arg_chr_s == '¿') {
				$arg_index_l = $ll_val_chr;
			} else {
				$arg_index_l = $ll_val_chr - 1;
			}
			break;
		}
	}
	$arg_msj_s = 'correcto 1-120';
	return 1;
}

function f_strlen($arg_cadena_s, &$arg_longitud_l)
{

	$ll_index = 0;
	$ll_count = 0;
	$ll_count = 0;

	for ($ll_index = 0; $ll_index <= strlen($arg_cadena_s); $ll_index++) {
		$ls_caracter = mb_substr($arg_cadena_s, $ll_index, 1, 'UTF-8');

		if ($ls_caracter == 'á' or $ls_caracter == 'é' or $ls_caracter == 'í' or $ls_caracter == 'ó' or $ls_caracter == 'ú' or $ls_caracter == 'Á' or $ls_caracter == 'É' or $ls_caracter == 'Í' or $ls_caracter == 'Ó' or $ls_caracter == 'Ú' or $ls_caracter == 'ñ' or $ls_caracter == 'Ñ') {
			$ll_count++;
		}
	}

	if ($ll_count > 0) {
		$arg_longitud_l = strlen($arg_cadena_s) - $ll_count;
		return 1;
	} else {
		$arg_longitud_l = strlen($arg_cadena_s);
		return 1;
	}
}

function f_valida_caracteres($arg_cadena_s, &$arg_indica_l)
{

	$arg_indica_l = 0;
	$ll_index = 0;
	$ll_strlen = 0;
	$ls_caracter = '';
	$arg_indica_l = 0;
	$ls_caracter = '';
	$ls_combinacion = '';

	f_strlen($arg_cadena_s, $ll_strlen);

	for ($ll_index = 0; $ll_index <= $ll_strlen; $ll_index++) {
		$ls_caracter = mb_substr($arg_cadena_s, $ll_index, 1, 'UTF-8');
		$ls_combinacion .= $ls_caracter;

		if ($ll_index == 1) {
			if ($ls_combinacion == 'x:') {
				$arg_indica_l = 1;
				break;
			} else if (mb_substr($ls_combinacion, 0, 1, 'UTF-8') == ' q') {
				$arg_indica_l = 1;
				break;
			}
		}

		if ($ls_caracter == '<' or $ls_caracter == '>' or $ls_caracter == '&') {
			$arg_indica_l = 1;
			break;
		}
	}
	return 1;
}


function cadenaConexion($arg_data_s, $arg_max_l, &$arg_data_encriptado_s, &$arg_msj_s)
{

	$ll_count_caracter = 0;
	$ll_longitud = 0;
	$ll_long_data = 0;
	$ls_car_long = '';
	$ll_random = 0;
	$ls_car_semilla = 0;
	$lb_aviso = '';
	$arg_data_encriptado_s = '';
	$ll_letra = 0;
	$ls_chr_data = '';
	$ls_chr_encriptado = '';
	$ls_car_semilla = '';
	$arg_msj_s = '';
	$arg_cadena_seguridad = array();
	$ll_count_caracter = 0;

	f_strlen($arg_data_s, $ll_long_data);

	$ll_letra = 0;

	if ($arg_data_s == '' or is_null($arg_data_s)) {
		$arg_msj_s = 'El dato a encriptar es nulo, favor de verificar';
		return -1;
	}

	if ($ll_long_data <= 0) {
		$arg_msj_s = 'El número de caracteres es diferente a los programados, favor de verificar';
		return -1;
	}

	f_crea_char_1al94($ll_long_data, $ls_car_long, $arg_msj_s);

	$ll_random = round((date('s') + 1) / 2);

	f_crea_char_1al94($ll_random + 1, $ls_car_semilla, $arg_msj_s);

	if (f_crea_cadena_seguridad($ll_random, $lb_aviso, $arg_cadena_seguridad, $arg_msj_s) < 0) {
		return -1;
	}

	if ($lb_aviso == 'false') {
		return -1;
	}

	$arg_data_encriptado_s = $ls_car_semilla . $ls_car_long;

	for ($ll_letra = 1; $ll_letra <= $ll_long_data; $ll_letra++) {
		$ls_chr_data = mb_substr($arg_data_s, $ll_letra - 1, 1, 'UTF-8');
		f_get_letra_encriptada($ls_chr_data, $arg_cadena_seguridad, $ls_chr_encriptado, $arg_msj_s);
		$arg_data_encriptado_s .= $ls_chr_encriptado;
	}

	f_strlen($arg_data_encriptado_s, $ll_longitud);

	if ($ll_longitud < $arg_max_l) {
		for ($ll_letra = $ll_longitud + 1; $ll_letra <= $arg_max_l; $ll_letra++) {

			if (f_crea_char_1al94(rand(0, 20), $ls_chr_encriptado, $arg_msj_s) < 0) {
				return -1;
			} else {
				$arg_data_encriptado_s .= $ls_chr_encriptado;
			}
		}
	}

	f_valida_caracteres($arg_data_encriptado_s, $ll_count_caracter);

	if ($ll_count_caracter == 1) {
		cadenaConexion($arg_data_s, $arg_max_l, $arg_data_encriptado_s, $arg_msj_s);
	} else {
		$arg_msj_s = 'Se encripto correctamente';
		return 1;
	}
}


function cadenaConexionRetorna($arg_data_s, &$arg_data_des_s, &$arg_msj_s)
{

	$ll_max_caracteres = 0;
	$ll_index = 0;
	$ll_letra = 0;
	$ll_len_data = 0;
	$ll_max = 0;
	$ls_chr_seg = '';
	$ls_che_len_data = '';
	$arg_data_des_s = '';
	$ls_chr_data = '';
	$ls_caracter_des = '';
	$ls_valida_s = '';

	if ($arg_data_s == '' or is_null($arg_data_s)) {
		$arg_msj_s = 'El dato a descifrar es nulo, favor de verificar';
		return -1;
	}

	$ls_chr_seg = mb_substr($arg_data_s, 0, 1, 'UTF-8');

	if ($ls_chr_seg == '' or is_null($ls_chr_seg)) {
		$arg_msj_s = 'Error al obtener la semilla, favor de verificar';
		return -1;
	}
	/*
	if (($ls_chr_seg == '#') || ($$ls_chr_seg == 'x') || ($$ls_chr_seg == '¿')){
		$ll_max = 4;
	}else{
			$ll_max = 4;
	}	*/

	if (f_obten_valor_char_1al20($ls_chr_seg, $ll_index, $arg_msj_s) < 0) {
		return -1;
	}

	if (($ls_chr_seg == '#') || ($ls_chr_seg == '¿')) {
		//No incrementa
	} else {
		$ll_index++;
	}

	if (f_crea_cadena_seguridad($ll_index - 1, $ls_valida_s, $ls_cadena_seguridad, $arg_msj_s) < 0) {
		return -1;
	}

	if ($ls_valida_s == 'false') {
		return -1;
	}

	$ls_che_len_data = mb_substr($arg_data_s, 1, 1, 'UTF-8');

	if ($ls_che_len_data == '' or is_null($ls_che_len_data)) {
		$arg_msj_s = 'Error al obtener la longitud, favor de verificar';
		return -1;
	}

	if (f_obten_valor_char_1al20($ls_che_len_data, $ll_len_data, $arg_msj_s) < 0) {
		return -1;
	}

	if (($ll_len_data == 4) || ($ll_len_data == 8)) {
		$ll_max_caracteres = 3;
	} else {
		$ll_max_caracteres = 4;
	}

	if ($ls_che_len_data == 'y' or $ls_che_len_data == '$') {
		$ll_len_data = $ll_len_data + 1;
	}

	$arg_data_des_s = '';

	for ($ll_letra = 4; $ll_letra <= $ll_len_data + $ll_max_caracteres; $ll_letra++) {
		$ls_chr_data = mb_substr($arg_data_s, $ll_letra - 2, 1, 'UTF-8');
		f_get_letra_descifra($ls_chr_data, $ls_cadena_seguridad, $ls_chr_seg, $ls_caracter_des, $arg_msj_s);
		$arg_data_des_s .= $ls_caracter_des;
	}

	$arg_msj_s = 'Descifrado';
	return 1;
}
