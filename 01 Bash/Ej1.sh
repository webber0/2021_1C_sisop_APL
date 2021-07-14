#!/bin/bash
funcA(){
	echo "Error. La sintaxis del script es la siguiente:"
	echo "./Ej1.sh ../../: $0 directorio 5" #Completar
	exit 1
}
funcB(){
	echo "Error. $1 No es un directorio valido." #Completar
	funcA
}
funcC(){
	if [[ ! -d $2 ]]; then
		funcB
	fi
}
funcC $# $1 $2 $3 $4 $5 #Valida los parametros

LIST=$(ls -d $1*/) #Obtiene los directorios que hay en un directorio pasado por parametro
ITEMS=() #Creo un array 

for d in $LIST; do #Por cada entrada de directorio encontrada 
	ITEM="`ls $d | wc -l` -$d" #Listar y contar la cantidad de directorios
	ITEMS+=($ITEM)
done

IFS=$'\n' sorted=($(sort -rV -t '-' -k 1 <<<${ITEMS[*]}))
CANDIDATES="${sorted[*]:0:$2}"
unset IFS
echo "Cantidad de Elementos" #Completar
printf "%s\n" "$(cut -d '-' -f 2 <<<${CANDIDATES[*]})"


# 1) El objetivo de este script es, contar la cantidad de elementos que
# se encuentran dentro de una carpeta. Notar que solo lee un subnivel.
# Recibe como paramentros, el directorio a analizar y la cantidad de lineas
# a imprimir por pantalla
# 
# 2) Luego de recibir 5 parámetros, el script valida que el primer parametro
# sea un directorio valido, este crea un array asociativo conteniendo a los subdirectorios
# existentes en el directorio elegido. Luego por cada elemento en el array,
# cuenta cuantos elementos tiene subdirectorio y lo almacena en formato clave/valor.
# Finalmente, el script muestra en patalla los resultados.
#
# 4) La función funcA debería llamarse "Ayuda", la funcion funcC debería
# llamarse "Ayuda" y funcB debería llamarse "MensajeError"
#
# 5) Como corrección, le sacaría $4 y $5 que no influyen en la ejecución
# del mismo. Agregaría como validacion que la cantidad de lineas 
#
# 6) La variable $# indica la cantidad de parámentros enviados al script.
# Otras variables similares son $@ o $* (Lista de todos los parámentros),
# $$ (PID del proceso actual), $! (PID del ultimo proceso hijo ejecutado
# en segundo plano, $? (Valor de ejecución del ultimo comando).
# $1, $2,..., ${10} son los parámentros que se le envian al script
#
