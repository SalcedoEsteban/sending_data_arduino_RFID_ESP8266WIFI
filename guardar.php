<?php
	require 'conexion.php';

	//$codigotarjeta = $_POST['codigotarjeta'];
	//$chipid = $_POST['chipid'];

	$codigotarjeta = $_GET['codigotarjeta'];
	$chipid = $_GET['chipid'];	

	$nuevo_registro = "INSERT INTO tarjeta(tar_chi_id, tar_cod, tar_fec) VALUES ('$chipid', '$codigotarjeta', CURRENT_TIMESTAMP)";

	$resultado = $conexion->query($nuevo_registro);

	if ($resultado)
	{
		echo "<h1>los datos se han guardado correctamenre</h1>";
	}
	else
	{
		echo "<h2>error al guardar los datos</h2>";
	}

	//$conexion->close();

	echo "Pagina para subir los datos<br />";
 	echo "<br />Chip ID = $chipid <br />";
 	echo "<br />Codigo Tarjeta = $codigotarjeta <br />";
?>