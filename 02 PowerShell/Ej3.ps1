<#
    .Synopsis
    La funcion del script es para detectar archivos iguales en su contenido
    .Description
    La funcion del script es para detectar archivos iguales en su contenido
    El script se invoca de la siguiente mantera:
    [Path del script]/Ej3.ps1 -DirectorioEntrada [Carpeta a analizar] -DirectorioLog [Carpeta de destino del log] -Umbral [Umbral en KB]
    .Parameter DirectorioEntrada
    Es el directorio a revisar
    .Parameter DirectorioLog
    Es el directorio donde se va a almacenar el log
    .Parameter Umbral
    Es el umbral en KB a partir de que mira los archivos
    .Example
    /media/sf_vmSharedFolder/Ps/Ej3/Ej3.ps1 -DirectorioEntrada /media/sf_vmSharedFolder/Ps/Ej3/IN/ -DirectorioLog /home/defox/Escritorio/ -Umbral 0.5
    .Example
    ./Ej3.ps1 -DirectorioEntrada /media/sf_vmSharedFolder/Ps/Ej3/IN/ -DirectorioLog /home/defox/Escritorio/ -Umbral 0.5
    
#>

#Validaciones principales
[CmdletBinding()]
Param( 
    [Parameter(Position=1,Mandatory=$true)]
    [ValidateScript({Test-Path -PathType Container $_})]
    [String]$DirectorioEntrada,
    [Parameter(Position=2,Mandatory=$true)]
    [ValidateScript({Test-Path -PathType Container $_})]
    [String]$DirectorioLog,
    [Parameter(Position=3,Mandatory=$true)]
    [ValidateRange("Positive")]
    [float] $Umbral)
#Verifico que las carpetas no sean iguales
    if($DirectorioEntrada -eq $DirectorioLog){
        Write-Error "Las carpetas son iguales " -Category InvalidArgument
}
$fecha = Get-Date -Format "yyyyMMddHHmm" # Formato para el log
$Array = @() #Creo un array
(Get-ChildItem -Path $DirectorioEntrada -Recurse | Where-Object {$_.Length -ge ($Umbral *1000)}).FullName | foreach { $Array += $_ }
For($i=0; $i -lt $Array.Length; $i++){
    For($j=$i+1; $j -lt $Array.Length; $j++){
        if((Get-FileHash $Array[$i]).Hash -eq (Get-FileHash $Array[$j]).Hash){
            Write-Output $Array[$j] >> $DirectorioLog/Log_$fecha.out
        }
    }
}