#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
float opcionFacturacionMensual(char *path, char *mes);
int calcularMes(char *mes);
float calcularFacturacion(char *direccion_completa);
float opcionFacturacionAnual(char *path);
float opcionPromedioDeFacturacion(char *path);

float opcionPromedioDeFacturacion(char *path){
   float facturacion=0;
   int cantMeses=0;
    char pathEnero[1024],
        pathFebrero[1024],
        pathMarzo[1024],
        pathAbril[1024],
        pathMayo[1024],
        pathJunio[1024],
        pathJulio[1024],
        pathAgosto[1024],
        pathSeptiembre[1024],
        pathOctubre[1024],
        pathNoviembre[1024],
        pathDiciembre[1024];
    /*Concadeno el path a los path de cada mes*/
    strcpy(pathEnero,path);
    strcpy(pathFebrero,path);
    strcpy(pathMarzo,path);
    strcpy(pathAbril,path);
    strcpy(pathMayo,path);
    strcpy(pathJunio,path);
    strcpy(pathJulio,path);
    strcpy(pathAgosto,path);
    strcpy(pathSeptiembre,path);
    strcpy(pathOctubre,path);
    strcpy(pathNoviembre,path);
    strcpy(pathDiciembre,path);
    /*Genero la ruta absoluta para las funciones*/
    strcat(pathEnero,"enero.txt");
    strcat(pathFebrero,"febrero.txt");
    strcat(pathMarzo,"marzo.txt");
    strcat(pathAbril,"abril.txt");
    strcat(pathMayo,"mayo.txt");
    strcat(pathJunio,"junio.txt");
    strcat(pathJulio,"julio.txt");
    strcat(pathAgosto,"agosto.txt");
    strcat(pathSeptiembre,"septiembre.txt");
    strcat(pathOctubre,"octubre.txt");
    strcat(pathNoviembre,"noviembre.txt");
    strcat(pathDiciembre,"diciembre.txt");

    /*Calculo de la facturacion*/
    facturacion+=calcularFacturacion(pathEnero);
    if(calcularFacturacion(pathEnero) != 0) cantMeses++;
    facturacion+=calcularFacturacion(pathFebrero);
    if(calcularFacturacion(pathFebrero) != 0) cantMeses++;
    facturacion+=calcularFacturacion(pathMarzo);
    if(calcularFacturacion(pathMarzo) != 0) cantMeses++;
    facturacion+=calcularFacturacion(pathAbril);
    if(calcularFacturacion(pathAbril) != 0) cantMeses++;
    facturacion+=calcularFacturacion(pathMayo);
    if(calcularFacturacion(pathMayo) !=0) cantMeses++;
    facturacion+=calcularFacturacion(pathJunio);
    if(calcularFacturacion(pathJunio) != 0) cantMeses++;
    facturacion+=calcularFacturacion(pathJulio);
    if(calcularFacturacion(pathJulio) != 0) cantMeses++;
    facturacion+=calcularFacturacion(pathAgosto);
    if(calcularFacturacion(pathAgosto) != 0) cantMeses++;
    facturacion+=calcularFacturacion(pathSeptiembre);
    if(calcularFacturacion(pathSeptiembre) != 0) cantMeses++;
    facturacion+=calcularFacturacion(pathOctubre);
    if(calcularFacturacion(pathOctubre) != 0) cantMeses++;
    facturacion+=calcularFacturacion(pathNoviembre);
    if(calcularFacturacion(pathNoviembre) != 0) cantMeses++;
    facturacion+=calcularFacturacion(pathDiciembre);
    if(calcularFacturacion(pathDiciembre) != 0) cantMeses++;

    if(facturacion == 0) return facturacion; //para que no divida por cero
    return facturacion/cantMeses; 
}
float opcionFacturacionAnual(char *path){
   float facturacion=0;;
    char pathEnero[1024],
        pathFebrero[1024],
        pathMarzo[1024],
        pathAbril[1024],
        pathMayo[1024],
        pathJunio[1024],
        pathJulio[1024],
        pathAgosto[1024],
        pathSeptiembre[1024],
        pathOctubre[1024],
        pathNoviembre[1024],
        pathDiciembre[1024];
    /*Concadeno el path a los path de cada mes*/
    strcpy(pathEnero,path);
    strcpy(pathFebrero,path);
    strcpy(pathMarzo,path);
    strcpy(pathAbril,path);
    strcpy(pathMayo,path);
    strcpy(pathJunio,path);
    strcpy(pathJulio,path);
    strcpy(pathAgosto,path);
    strcpy(pathSeptiembre,path);
    strcpy(pathOctubre,path);
    strcpy(pathNoviembre,path);
    strcpy(pathDiciembre,path);
    /*Genero la ruta absoluta para las funciones*/
    strcat(pathEnero,"enero.txt");
    strcat(pathFebrero,"febrero.txt");
    strcat(pathMarzo,"marzo.txt");
    strcat(pathAbril,"abril.txt");
    strcat(pathMayo,"mayo.txt");
    strcat(pathJunio,"junio.txt");
    strcat(pathJulio,"julio.txt");
    strcat(pathAgosto,"agosto.txt");
    strcat(pathSeptiembre,"septiembre.txt");
    strcat(pathOctubre,"octubre.txt");
    strcat(pathNoviembre,"noviembre.txt");
    strcat(pathDiciembre,"diciembre.txt");

    /*Calculo de la facturacion*/
    facturacion+=calcularFacturacion(pathEnero);
    facturacion+=calcularFacturacion(pathFebrero);
    facturacion+=calcularFacturacion(pathMarzo);
    facturacion+=calcularFacturacion(pathAbril);
    facturacion+=calcularFacturacion(pathMayo);
    facturacion+=calcularFacturacion(pathJunio);
    facturacion+=calcularFacturacion(pathJulio);
    facturacion+=calcularFacturacion(pathAgosto);
    facturacion+=calcularFacturacion(pathSeptiembre);
    facturacion+=calcularFacturacion(pathOctubre);
    facturacion+=calcularFacturacion(pathNoviembre);
    facturacion+=calcularFacturacion(pathDiciembre);

    return facturacion;
}
float calcularFacturacion(char *direccion_completa){
    FILE *fmes;
    float total=0;
    float valor=0;
    fmes = fopen(direccion_completa,"r");
    if(fmes == NULL){
        fprintf(stderr,"El archivo no existe o no es accesible.\n");
        exit(EXIT_FAILURE);
        }
    while(!feof(fmes)){
       fscanf(fmes, "%f\n", &valor);
       total+=valor;
    }
    fclose(fmes);
    return total;
}
int calcularMes(char *mes){
    if( strcmp(mes,"01") == 0 || strcmp(mes,"1") == 0 || strcasecmp(mes,"enero") == 0 ) return 1;
    if( strcmp(mes,"02") == 0 || strcmp(mes,"2") == 0 || strcasecmp(mes,"febrero") ==0 ) return 2;
    if( strcmp(mes,"03") == 0 || strcmp(mes,"3") == 0 || strcasecmp(mes,"marzo") ==0 ) return 3;
    if( strcmp(mes,"04") == 0 || strcmp(mes,"4") == 0 || strcasecmp(mes,"abril") ==0 ) return 4;
    if( strcmp(mes,"05") == 0 || strcmp(mes,"5") == 0 || strcasecmp(mes,"mayo") ==0 ) return 5;
    if( strcmp(mes,"06") == 0 || strcmp(mes,"6") == 0 || strcasecmp(mes,"junio") ==0 ) return 6;
    if( strcmp(mes,"07") == 0 || strcmp(mes,"7") == 0 || strcasecmp(mes,"julio") ==0 ) return 7;
    if( strcmp(mes,"08") == 0 || strcmp(mes,"8") == 0 || strcasecmp(mes,"agosto") ==0 ) return 8;
    if( strcmp(mes,"09") == 0 || strcmp(mes,"9") == 0 || strcasecmp(mes,"septiembre") ==0 ) return 9;
    if( strcmp(mes,"10") == 0 || strcasecmp(mes,"octubre") ==0 ) return 10;
    if( strcmp(mes,"11") == 0 || strcasecmp(mes,"noviembre") ==0 ) return 11;
    if( strcmp(mes,"12") == 0 || strcasecmp(mes,"diciembre") ==0 ) return 12;
    return -1;
}

float opcionFacturacionMensual(char *path, char *mes){
    int nro_mes;
    float facturacion = 0;
    char pathEnero[1024],
        pathFebrero[1024],
        pathMarzo[1024],
        pathAbril[1024],
        pathMayo[1024],
        pathJunio[1024],
        pathJulio[1024],
        pathAgosto[1024],
        pathSeptiembre[1024],
        pathOctubre[1024],
        pathNoviembre[1024],
        pathDiciembre[1024];
    /*Concadeno el path a los path de cada mes*/
    strcpy(pathEnero,path);
    strcpy(pathFebrero,path);
    strcpy(pathMarzo,path);
    strcpy(pathAbril,path);
    strcpy(pathMayo,path);
    strcpy(pathJunio,path);
    strcpy(pathJulio,path);
    strcpy(pathAgosto,path);
    strcpy(pathSeptiembre,path);
    strcpy(pathOctubre,path);
    strcpy(pathNoviembre,path);
    strcpy(pathDiciembre,path);
    /*Genero la ruta absoluta para las funciones*/
    strcat(pathEnero,"enero.txt");
    strcat(pathFebrero,"febrero.txt");
    strcat(pathMarzo,"marzo.txt");
    strcat(pathAbril,"abril.txt");
    strcat(pathMayo,"mayo.txt");
    strcat(pathJunio,"junio.txt");
    strcat(pathJulio,"julio.txt");
    strcat(pathAgosto,"agosto.txt");
    strcat(pathSeptiembre,"septiembre.txt");
    strcat(pathOctubre,"octubre.txt");
    strcat(pathNoviembre,"noviembre.txt");
    strcat(pathDiciembre,"diciembre.txt");
    nro_mes = calcularMes(mes);
    
    switch (nro_mes)
    {
    case 1:
        facturacion = calcularFacturacion(pathEnero);
        break;
    case 2:
        facturacion = calcularFacturacion(pathFebrero);
        break;
    case 3:
        facturacion = calcularFacturacion(pathMarzo);
        break;
    case 4:
        facturacion = calcularFacturacion(pathAbril);
        break;
    case 5:
        facturacion = calcularFacturacion(pathMayo);
        break;
    case 6:
        facturacion = calcularFacturacion(pathJunio);
        break;
    case 7:
        facturacion = calcularFacturacion(pathJulio);
        break;
    case 8:
        facturacion = calcularFacturacion(pathAgosto);
        break;
    case 9:
        facturacion = calcularFacturacion(pathSeptiembre);
        break;
    case 10:
        facturacion = calcularFacturacion(pathOctubre);
        break;    
    case 11:
        facturacion = calcularFacturacion(pathNoviembre);
        break;
    case 12:
        facturacion = calcularFacturacion(pathDiciembre);
        break;
    default:
        break;
    }
    return facturacion;
}
int main(int argc, char *argv[]){
    /*Variables obligatorias*/
    int opcion_elegida,
        fd_a_core,
        fd_de_core;
    char path_tmp[1024],
        path[1024],
        year_tmp[5],
        year[5],
        month_tmp[15],
        month[15];
    float resultado;
    strcpy(path_tmp,argv[1]); //Esto es para hacerlo 1 vez, y lo tengo ya seteado
    mkfifo("/tmp/DE_CORE",0666); //Esto lo hago solo una vez
    do{
        fd_a_core=open("/tmp/A_CORE",O_RDONLY); //Leo desde el cliente
        if(fd_a_core == -1){
            fprintf(stderr,"La tuberia no pudo abrirse con exito\n");
            exit(EXIT_FAILURE);
        }
        //read(fd_a_core,path_tmp,sizeof(path_tmp));
        read(fd_a_core,year_tmp,sizeof(year_tmp));
        read(fd_a_core,&opcion_elegida,sizeof(opcion_elegida));
        read(fd_a_core,month_tmp,sizeof(month_tmp));
        close(fd_a_core);
        //Limpieza de variables
        strcpy(path,path_tmp);
        strcpy(year,year_tmp);
        strcpy(month,month_tmp);
        //Concadeno todo el año
        strcat(path,year);
        strcat(path,"/");
        //printf("%s\n%s\n%d\n",path,year,opcion_elegida); //Sacarlo cuando todo este OK
        resultado = 0;
        switch (opcion_elegida){
        case 1:
            resultado = opcionFacturacionMensual(path,month);
            break;
        case 2:
            resultado = opcionFacturacionAnual(path);
            break;
        case 3:
            resultado = opcionPromedioDeFacturacion(path);
        default:
            break;
        }
        /*Para terminar*/
        //printf("Desea contunuar? Ingrese 4 para finalizar, otro numero para seguir\n");
        //scanf("%d",&opcion_elegida);

        //Aca le devuelvo al cliente el resultado
        fd_de_core = open("/tmp/DE_CORE",O_WRONLY);
        if(fd_de_core == -1){
            fprintf(stderr,"La tuberia no pudo abrirse con exito\n");
            exit(EXIT_FAILURE);
        }
        write(fd_de_core,&resultado,sizeof(resultado));
        close(fd_de_core);
    }while(opcion_elegida != 4);
    //Una vez que termino, despejo los recursos.
    unlink("/tmp/A_CORE");
    unlink("/tmp/DE_CORE");
    return EXIT_SUCCESS;
}