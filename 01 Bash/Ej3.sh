#!/bin/bash
#Funciones
Ayuda(){
	echo "Bienvenido a la ayuda"
	echo "La funcion del script es para detectar archivos iguales en su contenido"
	echo "El script se invoca de la siguiente mantera:"
	echo "[Path del script]/Ej3.sh [Carpeta a analizar] [Carpeta de destino del log] [Umbral en KB]"
	echo ""
	echo "Ejemplo de ejecucion: ./Ej3.sh ./IN ./OUT 2"
	echo ""
	echo "Para directorios con espacios, ingresarlo de la siguiente manera:"
	echo "Ejemplo de ejecucion: ./Ej3.sh \"./Nombre de Directorio de origen\" \"./Nombre de Directorio de destino\" 2"
	exit 0
}
ErrorCantidadParametros(){
	echo "La cantidad de parametros ingresada no es suficiente"
	echo "Ejecute el parametro -? para obtener la ayuda."
	exit 1;
}

ErrorNoSonCarpetas(){
	echo "Los directorios ingresados no son validos"
	echo "Vuelva a intentarlo por favor."
	exit 1;
}

ErrorCarpetasIguales(){
	echo "Los directorios ingresados son iguales"
	echo "Por favor, elija otro directorio para guardar el log."
	exit 1;
}

ErrorValorNegativo(){
	echo "El umbral solicitado es menor a 0"
	echo "El umbral minimo es 0. Por favor, vuelva a intentarlo."
	exit 1
}

Core(){
	#Obtengo la fecha
	fecha=$(date +%Y%m%d%H%M)
	salida=$(echo "$2"/log_$fecha.out)
	IFS=$'\n' 
	read -r -d '' -a top < <( find "$1" -type f -size +$(($3))k && printf '\0' )
	for ((n=0; n < ${#top[*]} ; n++ )) do
		for((s=n+1; s < ${#top[*]} ; s++ )) do
			if(cmp -s "${top[n]}" "${top[s]}"); then
				echo "${top[s]}" >> "$salida" #Aca lo reemplazaria con la generación de log
			fi
		done
	done
	unset top
	unset IFS
}
#RunProgram $1 0
#Fin de funciones

#Acceso a la ayuda
if [[ $# -eq 1 && ($1 = '-h' || $1 = '-help' || $1 = '-?') ]]; then
	Ayuda
	exit 0
fi

#Validacion de funciones
if [[ $# -eq 3 && ( -d "$1" ) && ( -d "$2" ) && ( "$1" != "$2" ) && ($3 -ge 0) ]]; then
	Core "$1" "$2" $3
	elif [[ ($# -ne 3) && ($# -ne 1) ]]; then ErrorCantidadParametros
	elif [[ ( ! -d "$1" ) || ( ! -d "$2" ) ]]; then ErrorNoSonCarpetas
	elif [[ ( "$1" == "$2" ) ]]; then ErrorCarpetasIguales
	else ErrorValorNegativo
fi
