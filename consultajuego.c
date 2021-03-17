#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	MYSQL *conn;
	int err;
	// Estructura especial para almacenar resultados de consultas 
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int edad;
	char nombre[20];
	char consulta [80];
	//Creamos una conexion al servidor MYSQL 
	conn = mysql_init(NULL);
	if (conn==NULL) {
		printf ("Error al crear la conexiￃﾳn: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	conn = mysql_real_connect (conn, "localhost","root", "mysql", "juego", 0, NULL, 0);
	if (conn==NULL) {
		printf ("Error al inicializar la conexiￃﾳn: %u %s\n", 
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}



	printf("Dime el nick del jugador que quieras saber su puntuacion:");
	scanf("%s", nombre);
	sprintf(consulta," SELECT PUNTUACIONES.PUNTOS FROM (PUNTUACIONES) WHERE PUNTUACIONES.PLAYER = '%s'", nombre);	

	// consulta SQL para obtener una tabla con todos los datos

	err=mysql_query (conn, consulta);
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}




	//recogemos el resultado de la consulta. El resultado de la

	resultado = mysql_store_result (conn);
	row = mysql_fetch_row (resultado);

	if (row == NULL)
		printf ("No se han obtenido datos en la consulta\n");
	else
		while (row !=NULL) {
			printf ("El jugador %s tiene %s puntos", nombre, row[0]);
			row = mysql_fetch_row (resultado);
	}

	// Ahora vamos a buscar el nombre de la persona cuyo DNI es uno
	// dado por el usuario
/*	printf ("Dame el DNI de la persona que quieres buscar\n"); */
/*	scanf ("%s", dni);*/
	// construimos la consulta SQL
/*	strcpy (consulta,"SELECT nombre FROM personas WHERE dni = '"); */
/*	strcat (consulta, dni);*/
/*	strcat (consulta,"'");*/
	// hacemos la consulta 
/*	err=mysql_query (conn, consulta); */
/*	if (err!=0) {*/
/*		printf ("Error al consultar datos de la base %u %s\n",*/
/*				mysql_errno(conn), mysql_error(conn));*/
/*		exit (1);*/
/*	}*/
	//recogemos el resultado de la consulta 
/*	resultado = mysql_store_result (conn); */
/*	row = mysql_fetch_row (resultado);*/
/*	if (row == NULL)*/
/*		printf ("No se han obtenido datos en la consulta\n");*/
/*	else*/
		// El resultado debe ser una matriz con una sola fila
		// y una columna que contiene el nombre
/*		printf ("Nombre de la persona: %s\n", row[0] );*/
	// cerrar la conexion con el servidor MYSQL 
/*	mysql_close (conn);*/
/*	exit(0);*/
}


































