<?php
	$servidor = "localhost";
	$usuario = "root";
	$password = "root123";
	$database = "arduino";

	$conexion = new mysqli($servidor, $usuario, $password, $database);

	if ($conexion->connect_error)
	{
		die('Error en la conexion'.$conexion->connect_error);
	}

	printf("Informacion del servidor: %s", $conexion->server_info);
?>