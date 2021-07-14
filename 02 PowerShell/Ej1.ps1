
[CmdletBinding()]
Param( 
    [Parameter(Position=1,Mandatory=$false)]
    [ValidateScript({Test-Path -PathType Container $_})]
    [String]$directorio,
    [int]$cantidad_lineas=100)
    $directorio = '/media/sf_vmSharedFolder/Bash'
$LIST = Get-ChildItem -Path $directorio -Directory
$ITEMS = ForEach($ITEM in $LIST){
    $COUNT=(Get-ChildItem -Path $ITEM).Length
    $indice=@{
        name = $ITEM
        count = $COUNT }
    New-Object psobject -Property $indice}
    $CANDIDATES= $ITEMS |Sort-Object -Property Count -Descending | Select-Object -First $cantidad_lineas | Select-Object -Property name
    Write-Output "Directorios"
    Write-Output $CANDIDATES| Format-Table -HideTableHeaders

# 1) El objetivo de este script es, contar la cantidad de elementos que
# se encuentran dentro de una carpeta. Notar que solo lee un subnivel.
# Recibe como paramentros, el directorio a analizar y la cantidad de lineas
# a imprimir por pantalla
#
# 2) Luego de recibir el directorio (no obligatorio), el script valida que 
# sea un directorio valido, este crea un array asociativo conteniendo a los subdirectorios
# existentes en el directorio elegido. Luego por cada elemento en el array,
# cuenta cuantos elementos tiene subdirectorio y lo almacena en formato clave/valor.
# Finalmente, el script muestra en patalla los resultados.
#
# 4) El script necesita recibir la cantidad de lineas a imprimir (parametro seteado). En el caso de
# la cantidad de lineas, la validación tiene que validar que el valor sea mayor a cero.
#
# 5) CmdletBinding() es un cmdlet que, me añade funcionalidades avanzadas para usar
# en el script, desde la configuración de los parametros, hasta la posiblidad de 
# utilizar el parametro -Debug de Write-Debug sin declararlo previamente (pues 
# CmdletBinding lo declara)
#
# 6) Existen 3 tipos de comillas en PowerShell (PS): comillas simples, comillas dobles y 
# acento grave.
# - Comillas simples: Son comillas del estilo '' y PS va a interpretar literalmente
# el contenido, sin expansión ni sustitución.
#
# - Comillas dobles: Son comillas del estilo "" y PS va a interpretar el contenido
# pero, si hay una variable, entonces, la variable se va a reemplazar por el contenido
# de la misma
#
# - Acento Grave: Es una comilla ` y para PS va a representar un literal (sin reemplazo por el
# contenido de la variable)
# Util para cuando uno realiza un Write-Host `$variable = $variable
#
# 7) Si al script no se le pasa parametros, la misma toma el PWD como directorio
#

