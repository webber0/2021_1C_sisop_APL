#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int seleccionar_opcion();
int calcularMes(char *mes);
void ayuda();
void mensaje_por_mes(int mes, float resultado);

/*
    ####################   ENCABEZADO    ##########################
    #							                                  #
    #	Nombre de los archivos: CLI.c y CORE.c	                  #
    #	Numero de APL : 3				                          #
    #	Numero de Ejercicio: 3		                 		      #
    #							                                  #
    #  INTEGRANTES:						                          #
    #	Leandro Bellana	32419830		                	      #
    #	Gonzalo Messina 38130447			                      #
    #	Nicolás Pompeo	37276705		                          #
    #							                                  #
    ###############################################################
*/
void mensaje_por_mes(int mes, float resultado){
    switch (mes)
    {
    case 1:
        printf("El total facturado en el mes de Enero fue: $%.2f\n",resultado);
        break;
    case 2:
        printf("El total facturado en el mes de Febrero fue: $%.2f\n",resultado);
        break;
    case 3:
        printf("El total facturado en el mes de Marzo fue: $%.2f\n",resultado);
        break;
    case 4:
        printf("El total facturado en el mes de Abril fue: $%.2f\n",resultado);
        break;
    case 5:
        printf("El total facturado en el mes de Mayo fue: $%.2f\n",resultado);
        break;
    case 6:
        printf("El total facturado en el mes de Junio fue: $%.2f\n",resultado);
        break;
    case 7:
        printf("El total facturado en el mes de Julio fue: $%.2f\n",resultado);
        break;
    case 8:
        printf("El total facturado en el mes de Agosto fue: $%.2f\n",resultado);
        break;
    case 9:
        printf("El total facturado en el mes de Septiembre fue: $%.2f\n",resultado);
        break;
    case 10:
        printf("El total facturado en el mes de Octubre fue: $%.2f\n",resultado);
        break;
    case 11:
        printf("El total facturado en el mes de Noviembre fue: $%.2f\n",resultado);
        break;
    case 12:
        printf("El total facturado en el mes de Diciembre fue: $%.2f\n",resultado);
        break;
    default:
        break;
    }
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
void ayuda(){
    printf("Bienvenido a la ayuda\n");
    printf("Este programa consiste de 2 partes: el (CLI)ente y el que procesa la informacion(CORE)\n");
    printf("Las tareas del cliente son: recibir el año, el tipo de operacion y el mes (si fuera necesario)\n");
    printf("y se lo envia a CORE mediante un pipe nombrado. Recibe de CORE el resultado.\n");
    printf("\n");
    printf("Las tareas de CORE son: recibir por parametro un directorio donde se ubican\n");
    printf("los archivos a procesar (separados por año) y el mes (si fuera necesario), procesar dichos archivos segun lo solicitado por el usuairo\n");
    printf("y el resultado enviarlo al cliente \n");
    printf("\n");
    printf("Limitaciones:\n- El directorio debe poseer los 12 meses creados. No es necesario que tengan contenido.\n- El path al directorio SIEMPRE DEBE terminar en /\n");
    printf("\n");
    printf("Ejemplo de ejecucion:\n");
    printf("En una terminal: $ ./CLI\n");
    printf("En otra terminal: $ ./CORE /home/defox/facturacion/\n");
    exit(EXIT_SUCCESS);
}
int seleccionar_opcion(){
    printf("1- Facturacion Mensual\n2- Facturacion Anual\n3- Facturacion Promedio\n4- Salir\n");
    int opcion_elegida;
    printf("Elija una opcion: \n");
    scanf("%d",&opcion_elegida);
    return opcion_elegida;
}
int main(int argc, char *argv[]){
    //Ingreso a la ayuda
    if (argc == 2 && (strcmp(argv[1],"-?") == 0 || strcmp(argv[1],"--help") == 0)){
        ayuda();
    }
    int opcion_menu,
        fd_a_core,
        fd_de_core,
        mes;
    char /*path[1024],*/
        year[5],
        month[15];
    float resultado;
    mkfifo("/tmp/A_CORE",0666); //Esto lo hago solo una vez
    printf("Bienvenido al sistema de Gestion!\n");
    do{
        //Esto es independiente de la opcion
        resultado=0;
        printf("Seleccione una opcion:\n");
        opcion_menu = seleccionar_opcion();
        switch (opcion_menu)
        {
        case 1:
            printf("Ingrese el a%co:\n",165);
            scanf("%s",year);
            printf("\nIngrese el mes:\n");
            scanf("%s",month);
            break;
        case 2:
        case 3:
            printf("Ingrese el a%co:\n",165);
            scanf("%s",year);
            break;
        }
        //Aca le envio a core todo los datos, incluso si esta tiene "basura"
        fd_a_core=open("/tmp/A_CORE",O_WRONLY);
        if(fd_a_core == -1){
            fprintf(stderr,"La tuberia no pudo abrirse con exito\n");
            exit(EXIT_FAILURE);
        }
        write(fd_a_core,year,sizeof(year));
        write(fd_a_core,&opcion_menu,sizeof(opcion_menu));
        write(fd_a_core,month,sizeof(month));
        close(fd_a_core);
        //Leo la opcion que envia CORE
        fd_de_core = open("/tmp/DE_CORE",O_RDONLY);
        if(fd_de_core == -1){
            fprintf(stderr,"La tuberia no pudo abrirse con exito\n");
            exit(EXIT_FAILURE);
        }
        read(fd_de_core,&resultado,sizeof(resultado));
        close(fd_de_core);
        switch (opcion_menu){
        case 1:
            mes = calcularMes(month);
            mensaje_por_mes(mes,resultado);
            break;
        case 2:
            printf("La facturacion del a%co %s fue $ %.2f\n",165,year,resultado);
            break;
        case 3:
            printf("La facturacion promedio del a%co %s fue $ %.2f\n",165,year,resultado);
        default:
            break;
        }
    }while(opcion_menu!=4);
    //Una vez que ya no voy a seguir operando, le devulevo la postestad al SO
    //para eliminarlos
    unlink("/tmp/A_CORE");
    unlink("/tmp/DE_CORE");
    return EXIT_SUCCESS;
}