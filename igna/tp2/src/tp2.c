/*
 ============================================================================
 Name        : tp.c
 Author      : santigo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define ESTRUCTURA 4
int menu(int *opcion);
int getInt(	int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);
int utn_esNumerica(char input[]);
//getStr(char *charStr, int lenght, char *pMensaje);


typedef struct
{
	int edad;
	int dni;
	char nombre[30];
	int isEmpty;

}datosPersonales;

//typedef struct datosPersonales personas;



int main(void) {

	int opcionElegida;
	datosPersonales personas[ESTRUCTURA];
	int seguir=0;

	for(int i=0;i<ESTRUCTURA;i++)
	{
		personas[i].isEmpty=0;
	}
	personas[1].dni=32424;
	personas[1].edad=54;
	personas[1].isEmpty=1;
	strcpy(personas[1].nombre,"Santiago");

	menu(&opcionElegida);

	switch (opcionElegida)
	{
		case 1:
			do
				{
					for(int i=0;i<ESTRUCTURA;i++)
					{

						if(personas[i].isEmpty==0)
							{

								getInt(&personas[i].dni,"ingrese dni","error en el ingreso",0,99999999,3);
								getInt(&personas[i].edad,"Ingrese edad","Error en el ingreso",0,100,3);
								personas[i].isEmpty=1;
								break;
							}
					}



				}while(seguir!=0);


			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;

	}


	for(int i=0;i<ESTRUCTURA;i++){

		printf("\n%d",personas[i].isEmpty);
		printf("\nCon DNI numero %d",personas[i].dni);
		printf("\ny %d Anios de edad",personas[i].edad);
	}



	return 0;
}



int fantasma_buscarEmpty(Fantasma array[], int size, int* posicion)                    //cambiar fantasma
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

int fantasma_alta(datosPersonales personas[], int size, int* contadorID)                          //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(fantasma_buscarEmpty(array,size,&posicion)==-1)                          //cambiar fantasma
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\ngetUnsignedInt: ","\nError",1,sizeof(int),1,1,1,&array[posicion].varInt);           //mensaje + cambiar campo varInt
            utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
            utn_getName("getName\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varString);                      //mensaje + cambiar campo varString
            utn_getTexto("getTexto\n: ","\nError",1,TEXT_SIZE,1,array[posicion].varLongString);                 //mensaje + cambiar campo varLongString
            printf("\n Posicion: %d\n ID: %d\n varInt: %d\n varFloat: %f\n varString: %s\n varLongString: %s",
                   posicion, array[posicion].idUnico,array[posicion].varInt,array[posicion].varFloat,array[posicion].varString,array[posicion].varLongString);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array fantasma Array de fantasma
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int fantasma_baja(datosPersona personas[], int sizeArray)                                      //cambiar fantasma
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(fantasma_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].varInt=0;                                                               //cambiar campo varInt
            array[posicion].varFloat=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].varString,"");                                                   //cambiar campo varString
            strcpy(array[posicion].varLongString,"");                                               //cambiar campo varLongString
            retorno=0;
        }
    }
    return retorno;
}






buscarLibre(array,size, &posicion)
{

	int retorno;
	int i;
	if(array!=NULL && sixe>=0 && posicion!= NULL)
	{
		for(i=0;i<size;i++)
		{

		}
	}

}


int buscarPrimerOcurrencia(datosPersonales personas[], int cantidadDeElementos, int valor){

	int i;
	int ret=-1;
	for(i=0; i<cantidadDeElementos;i++){
		if(arrayPersonas[i].isEmpty==valor){
			ret= i;
		}
	}
	return ret;
}



int getInt(	int *pResultado,
		char *pMensaje,
		char *pMensajeError,
		int minimo,
		int maximo,
		int reintentos)
{
	int retorno = 0;
	int i,j;
	char input[50];
	int buffer;
	int length;


	for(j=0;j<reintentos;j++)
	{
		printf("%s",pMensaje);
		fgets(input, sizeof(input), stdin);
		length = strlen (input);
		input[length-1]='\0'; // saco enter

		retorno = utn_esNumerica(input);

		buffer = atoi(input);

		if(retorno==0 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			break;
		}
		else
		{
			retorno=-1;
		}
	}
	return retorno;
}

int utn_esNumerica(char input[])
{
	int length = strlen(input);
	int i,retorno;

	retorno = 0;
	for(i=0;i<length;i++)
	{
		if(input[i] < '0' || input[i] > '9')
		{
			if(input[i]=='-' && i==0)
			{
				continue;
			}
			if(input[i]=='+' && i==0)
			{
				continue;
			}
			retorno = -1;
			break;
		}
	}
	return retorno;
}


getStr(char charStr[], int lenght, char *pMensaje){

	char buffer[59];
	printf(pMensaje);
	__fpurge(stdin);
	fgets(buffer, sizeof(buffer),stdin);
	strncpy(charStr, buffer, sizeof(buffer));


	return 0;
}



int menu(int *opcion){
	int numero;

	printf("---------------------------------");
	printf("\n--------ingrese la opcion-------");
	printf("\n--------------------------------");

	getInt(&numero,"\n\n1.Altas\n2.Bajas\n3.Modificaciones\n4.Listar\n5.Ordenar","Error",0,6,3);
	printf("\n%d",numero);
	*opcion=numero;
	return 0;
}














/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getInt(	int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos);

int main(void)
{
	int numero;
	if(getInt(&numero, "ingrese numero","numero invalido",0,100,2)==0)
	{
		printf("get int me devolvio:%d",numero);
	}

	// para probar
	if(utn_esNumerica("+9")==0)
		printf("ok");
	else
		printf("err");
	//____________




	return EXIT_SUCCESS;
}



int getInt(	int *pResultado,
		char *pMensaje,
		char *pMensajeError,
		int minimo,
		int maximo,
		int reintentos)
{
	int retorno = 0;
	int i,j;
	char input[50];
	int buffer;
	int length;


	for(j=0;j<reintentos;j++)
	{
		printf("%s",pMensaje);
		fgets(input, sizeof(input), stdin);
		length = strlen (input);
		input[length-1]='\0'; // saco enter

		retorno = utn_esNumerica(input);

		buffer = atoi(input);

		if(retorno==0 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			break;
		}
		else
		{
			retorno=-1;
		}
	}
	return retorno;
}

int utn_esNumerica(char input[])
{
	int length = strlen(input);
	int i,retorno;

	retorno = 0;
	for(i=0;i<length;i++)
	{
		if(input[i] < '0' || input[i] > '9')
		{
			if(input[i]=='-' && i==0)
			{
				continue;
			}
			if(input[i]=='+' && i==0)
			{
				continue;
			}
			retorno = -1;
			break;
		}
	}
	return retorno;
}



























Estructuras - Definicion y Declaracion

#include <stdio.h>
#include <stdlib.h>
//Definición de Estructura
//struct datosPersonales
typedef struct {
    char nombre[20];
    char apellido[20];
    char calle[20];
    int numero;
}datosPersonales;
//};
int main()
{   //Declaracion de variable agenda de tipo datosPersonales
    datosPersonales agenda;
//struct datosPersoanles agenda;

    return 0;
}

Estructuras - Operador Punto (acceso a los campos)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosPersonales{
    char nombre[20];
    char apellido[20];
    char calle [20];
    int numero;
};

int main()
{
 struct datosPersonales agenda;

        strcpy(agenda.nombre, "Yanina");
        strcpy(agenda.apellido, "Scudero");
        strcpy(agenda.calle ,"Avenida Mitre");
        agenda.numero = 750;

        printf("El nombre es: %s ", agenda.nombre);
        printf("\nEl apellido es: %s ", agenda.apellido);


    return 0;
}


Estructuras - Carga de Datos

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosPersonales{
    char nombre[20];
    char apellido[20];
    char calle [20];
    int numero;
};

int main()
{
 struct datosPersonales agenda;

        printf("Ingrese el Nombre ");
        gets(agenda.nombre);
        fflush(stdin);

        printf("\nIngrese el apellido ");
        gets(agenda.apellido);
        fflush(stdin);

        printf("\nIngrese calle ");
        gets(agenda.calle);
        fflush(stdin);

        printf("\nIngrese numero de calle ");
        scanf("%d",&agenda.numero);

        //Mostrar datos
        printf("\nDatos Personales");
        printf("\n%s", agenda.nombre);
        printf("\n%s", agenda.apellido);
        printf("\n%s", agenda.calle);
        printf("\n%d", agenda.numero);



    return 0;
}

Estructuras - Vector de tipo Estructura


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosPersonales{
    char nombre[20];
    char apellido[20];
    char calle [20];
    int numero;

};

int main()
{
    struct datosPersonales vecAgenda[3];
    int i;

    for(i=0;i<3;i++){
        printf("\nIngrese nombre ");
        gets(vecAgenda[i].nombre);
        printf("\nIngrese apellido ");
        gets(vecAgenda[i].apellido);
        printf("\nIngrese calle ");
        gets(vecAgenda[i].calle);
        printf("\nIngrese numero ");
        scanf("%d", &vecAgenda[i].numero);
        fflush(stdin);
    }
    //Mostrar elementos de la estructura
    for(i=0;i<3;i++){
        printf("\n Nombre: %s ", vecAgenda[i].nombre);
        printf("\nApellido: %s ", vecAgenda[i].apellido);
        printf("\nCalle: %s ", vecAgenda[i].calle);
        printf("\nNumero: %d ", vecAgenda[i].numero);
    }


}




Propiedades de las estructuras
ASIGNACION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct datosPersonales{
    char nombre[20];
    char apellido[20];
    char calle [20];
    int numero;

};

int main()
{
    struct datosPersonales vecAgenda[3], vecContactos[3], vecAmigos[3];
    int i;

    for(i=0;i<3;i++){
        printf("\nIngrese nombre ");
        gets(vecAgenda[i].nombre);
        printf("\nIngrese apellido ");
        gets(vecAgenda[i].apellido);
        printf("\nIngrese calle ");
        gets(vecAgenda[i].calle);
        printf("\nIngrese numero ");
        scanf("%d", &vecAgenda[i].numero);
        fflush(stdin);
    }
    //Mostrar elementos de la estructura
    for(i=0;i<3;i++){
        printf("\nNombre: %s ", vecAgenda[i].nombre);
        printf("\nApellido: %s ", vecAgenda[i].apellido);
        printf("\nCalle: %s ", vecAgenda[i].calle);
        printf("\nNumero: %d ", vecAgenda[i].numero);
    }

    //Asignar una estructura a otra y mostrar
        for(i=0;i<3;i++){
        strcpy(vecContactos[i].nombre,vecAgenda[i].nombre);
        strcpy(vecContactos[i].apellido,vecAgenda[i].apellido);
        strcpy(vecContactos[i].calle,vecAgenda[i].calle);
        vecContactos[i].numero=vecAgenda[i].numero;
        printf("\n Nombre %d Copiado %s ",i, vecContactos[i].nombre);
        printf("\n Apellido %d Copiado %s ",i, vecContactos[i].apellido);
        printf("\n Calle %d Copiado %s ",i, vecContactos[i].calle);
        printf("\n Numero %d Copiado %d ",i, vecContactos[i].numero);
        }


    //Si tienen el mismo formato ahorro codigo
        for(i=0;i<3;i++){
        vecAmigos[i]=vecContactos[i];//Asignacion
        printf("\n Amigos/Nombre %d Amigos Copiado %s ",i, vecAmigos[i].nombre);
        printf("\n Amigos/Apellido %d Amigos Copiado %s ",i, vecAmigos[i].apellido);
        printf("\n Amigos/Calle %d Amigos Copiado %s ",i, vecAmigos[i].calle);
        printf("\n Amigos/Numero %d Amigos Copiado %d ",i, vecAmigos[i].numero);
        }



}


Estructuras - Estructuras Anidadas

uso de la Propiedad ASIGNACION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct direccion{
    char calle[20];
    int numero;
};

struct datosPersonales{
    char nombre[20];
    char apellido[20];
    struct direccion domicilio;

};

int main()
{
    struct datosPersonales vecAgenda[3];
    //struct direccion vecDir[3];
    int i;

   ///*
   for(i=0;i<3;i++){
        printf("\nIngrese nombre ");
        gets(vecAgenda[i].nombre);
        printf("\nIngrese apellido ");
        gets(vecAgenda[i].apellido);
        printf("\nIngrese calle ");
        gets(vecAgenda[i].domicilio.calle);
        printf("\nIngrese numero ");
        scanf("%d", &vecAgenda[i].domicilio.numero);
        fflush(stdin);
    }
    //Mostrar elementos de la estructura
    for(i=0;i<3;i++){
        printf("\n Nombre: %s ", vecAgenda[i].nombre);
        printf("\nApellido: %s ", vecAgenda[i].apellido);
        printf("\nCalle: %s ", vecAgenda[i].domicilio.calle);
        printf("\nNumero: %d ", vecAgenda[i].domicilio.numero);
    }



    //Cargando datos con la propiedad ASIGNACION
    for(i=0;i<3;i++){
        printf("\nIngrese nombre ");
        gets(vecAgenda[i].nombre);
        printf("\nIngrese apellido ");
        gets(vecAgenda[i].apellido);

        printf("\nIngrese calle ");
        gets(vecDir[i].calle);
        printf("\nIngrese numero ");
        scanf("%d", &vecDir[i].numero);
        fflush(stdin);
    }
    //Mostrar elementos de la ambas estructuras
    printf("\n Muestro ambas estructuras");
    for(i=0;i<3;i++){
        printf("\n Nombre: %s ", vecAgenda[i].nombre);
        printf("\nApellido: %s ", vecAgenda[i].apellido);
        printf("\nCalle: %s ", vecDir[i].calle);
        printf("\nNumero: %d ", vecDir[i].numero);
    }
    //Asignar los valores de la estructura vecDir a vecAgenda
    for(i=0;i<3;i++){
        vecAgenda[i].domicilio = vecDir[i];
    }
    //Mostrar elementos de la estructura Agenda
    printf("\n Muestro la estructuras Agenda con Domicilio asignado");
    for(i=0;i<3;i++){
        printf("\n Nombre: %s ", vecAgenda[i].nombre);
        printf("\nApellido: %s ", vecAgenda[i].apellido);
        printf("\nCalle: %s ", vecAgenda[i].domicilio.calle);
        printf("\nNumero: %d ", vecAgenda[i].domicilio.numero);
    }

}



    Estructuras - Comparacion
    Ordenar alfabeticamente la estructura por los nombres

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    struct datosPersonales{
        char nombre[20];
        char apellido[20];
        char calle [20];
        int numero;

    };

    int main()
    {
        struct datosPersonales vecAgenda[3], aux;
        int i,j;

        for(i=0;i<3;i++){
            printf("\nIngrese nombre ");
            gets(vecAgenda[i].nombre);
            printf("\nIngrese apellido ");
            gets(vecAgenda[i].apellido);
            printf("\nIngrese calle ");
            gets(vecAgenda[i].calle);
            printf("\nIngrese numero ");
            scanf("%d", &vecAgenda[i].numero);
            fflush(stdin);
        }
        //Mostrar elementos de la estructura
        for(i=0;i<3;i++){
            printf("\n Nombre: %s ", vecAgenda[i].nombre);
            printf("\nApellido: %s ", vecAgenda[i].apellido);
            printf("\nCalle: %s ", vecAgenda[i].calle);
            printf("\nNumero: %d ", vecAgenda[i].numero);
        }

        //Ordenar
        for(i=0;i<3-1;i++)
        {
                for(j=i+1;j<3;j++)
                {
                //strcmp
                //menor a cero = izquierda es menor derecha
                //cero         = izquierda es igual que derecha
                //mayor a cero = izquierda es mayor derecha
                    if((strcmp(vecAgenda[i].nombre,vecAgenda[j].nombre))>0)
                    {
                    aux=vecAgenda[i];
                    vecAgenda[i]=vecAgenda[j];
                    vecAgenda[j]=aux;
                    }
                }

        }
        //Mostrar la estructura ORDENADA
            printf("\nESTRUCTURA ORDENANDA \n");
        for(i=0;i<3;i++){
            printf("\n Nombre: %s ", vecAgenda[i].nombre);
            printf("\nApellido: %s ", vecAgenda[i].apellido);
            printf("\nCalle: %s ", vecAgenda[i].calle);
            printf("\nNumero: %d ", vecAgenda[i].numero);
        }
    }


*/

int getNumeroProfe(int *pNumero, int rangoMax, int rangoMin, int reintentos)
{
int numero, i;
int retorno= -1; //cargo retorno con error
		//pedido
		printf("Ingrese un numero:");
		scanf("%d", &numero);
		for(i=0;i<reintentos; i++)
		{
			if(numero>=rangoMin && numero<=rangoMax)
			{
				*pNumero = numero;
				retorno=0;
				break;
			}
			else
				printf("naah esta mal");
		}
		return retorno;
}


int getNumero(int *pnumeroIngresado, int max, int min, int reintentos)
{
	int retorno = -1;
	int numeroIngresado;
	int intentoSuperado=0;
	printf("\ningrese un numero: ");
	scanf("%d", &numeroIngresado);

	while (numeroIngresado<min || numeroIngresado>max)
	{
		printf("\nnumero fuera de rango, ingrese numero: ");
		scanf("%d", &numeroIngresado);
	reintentos--;
		if(reintentos ==0)
		{
			intentoSuperado=1;
			break;
		}
	}
	if(intentoSuperado==1)
		{
		*pnumeroIngresado=0;
		return retorno;
		}
	*pnumeroIngresado=numeroIngresado;
	retorno=0;
	return retorno;
}



int getStr(char charStr[], int length, char *pMensaje)
{

char buffer[100];
printf("%s", pMensaje);
__fpurge(stdin);
fgets(buffer, sizeof(buffer),stdin);

strncpy(charStr,buffer,sizeof(buffer));
	return 0;
}



int getInt(	int *pResultado,char *pMensaje,char *pMensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int buffer;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}
int printArrayInt(int *pArray , int limite)
{
	int retorno = -1;
	int i;
	printf("\nDEBUG\n");
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			printf("\n\t%i",pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}


int getArrayInt(	int *pArray,
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int retorno = -1;
	int buffer;
	int i=0;
	char respuesta;
	printf("\nDEBUG\n");
	if(pArray != NULL && limite > 0)
	{
		do
		{

			if(	getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)
			{
				pArray[i] = buffer;
				i++;
				if(i == limite)
				{
					break;
				}
			}

			printf("Continuar (s/n)? \n");
			__fpurge(stdin); // fflush(stdin)
			scanf("%c",&respuesta);
		}while(respuesta != 'n');
		retorno = i;
	}
	return retorno;
}
int getMaxArray(int *pArray, int limite, int *maximo, int *iMaximo)
{
	int i;
	int aiMaximo;
	int retorno =-1;
	int aMaximo;

	if(pArray != NULL && limite > 0)
	{
		for(i=0; i<limite;i++)
		{
			if(i==0)
			{
		 aMaximo =pArray[i];
		 aiMaximo = i;
		// printf("entro");

			}
			if(pArray[i]>aMaximo)
			{
			 aMaximo =pArray[i];
			 aiMaximo=i;
			}
		}
	}
	*maximo=aMaximo;
	*iMaximo = aiMaximo;

	retorno =0;
	return retorno;
}

int getMinArray(int *pArray, int limite, int *minimo, int *iMinimo)
{
	int i;
	int aiMinimo;
	int retorno =-1;
	int aMinimo;

	if(pArray != NULL && limite > 0)
	{
		for(i=0; i<limite;i++)
		{
			if(i==0)
			{
		 aMinimo =pArray[i];
		 aiMinimo = i;
		// printf("entro");

			}
			if(pArray[i]>aMinimo)
			{
			 aMinimo =pArray[i];
			 aiMinimo=i;
			}
		}
	}
	*minimo=aMinimo;
	*iMinimo = aiMinimo;

	retorno =0;
	return retorno;
}
int getIntFromString(char Array[], int length, int *respuesta)
{
int retorno = -1;
	printf("ingrese un numero: ");
	fgets(Array,length, stdin);
	length =strlen(Array);
	if(isArrayOfNumbers(Array, length)==-1)
	{
		printf("Ingreso algo que no es un numero");
		return retorno;
	}else
	{
	*respuesta=atoi(Array);
	}
	return 0;
}
int isArrayOfNumbers(char Array[], int length)
{
	int retorno = 0;
	int i;

	for(i=0;i<length-1;i++)
	{
		if(Array[i]<'0' || Array[i]>'9')
		{
			if(i==0 && Array[i]=='+')
			{
				continue;
			}

			retorno =-1;
			break;
		}
		retorno=0;
		break;
	}

	return retorno;
}

int getIntNegFromString(char Array[], int length, int *respuesta)
{
int retorno = -1;
	printf("ingrese un numero: ");
	fgets(Array,length, stdin);
	length =strlen(Array);
	if(isArrayOfNumbersNeg(Array, length)==-1)
	{
		printf("Ingreso algo que no es un numero");
		return retorno;
	}else
	{
	*respuesta=atoi(Array);
	}
	return 0;
}
int isArrayOfNumbersNeg(char Array[], int length)
{
	int retorno = 0;
	int i;

	for(i=0;i<length-1;i++)
	{
		if(Array[i]<'0' || Array[i]>'9')
		{
			if(i==0 && Array[i]=='-')
			{
				continue;
			}
		}
		retorno=0;
		break;
	}

	return retorno;
}

