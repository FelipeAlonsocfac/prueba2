#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ME     20        // Cantidad m�xima de estudiantes
#define CRC    4         // Cantidad de rangos de calificaci�n
#define MLR    12        // M�xima longitud de un rango
#define CC     4         // Cantidad de calificaciones, incluida la definitiva
#define LN     20        // Longitud del nombre, incluido el fin de cadena.
#define LC     5         // Longitud del carn�, incluido el fin de cadena.

/* Escuela Colombiana de Ingenier�a
   Algoritmos y programaci�n de computadores (AYPC-1)
   Profesora: ingeniera Patricia Salazar Perdomo
   Estudiante: Nombre Apellidos
   Ejercicios No. 19. Nuevos tipos de datos
   15 de noviembre de 2017

   Implementar las opciones:
   1. Agregar un estudiante
   2. Calcular la definitiva. Los pesos de los tercios son 30%, 30% y 40%, respectivamente.
   3. Contar los estudiantes por rango de la definitiva y escribir el resultado. Los rangos ya est�n definidos.

   Si�ntanse en libertad de agregar campos a los tipos de datos ya definidos, de acuerdo con lo que se pide obtener. Les sugiero consultarme.

*/

struct datos_e
{
       char nombre[LN];
       char carne[LC];          // Cadena de caracteres num�ricos
       float calif[CC];         // Para las calificaciones de cada tercio y la definitiva. 30%, 30% y 40%.
};

struct rango                    // Agreguen los campos que consideren necesarios para obtener los resultados solicitados
{
       float lim_inf;
       float lim_sup;
};

void titulo(const char [ ]);


int main(void)
{
      int opcion;
      char rangosxcalif[CRC][MLR]={"[0.0, 2.0)", "[2.0, 3.0)", "[3.0, 4.0)", "[4.0, 5.0]"};
      struct rango r_calif[]={{0.0, 2.0},{2.0, 3.0},{3.0, 4.0}, {4.0, 5.1}};
      struct datos_e de[ME]={{"E1","0011",{3.2,4.1,5.0,-1.0}},{"E2","1722",{1.5,1.6,2.0,-1.0}},{"E3","1314",{5.0,4.7,5.0,-1.0}},{"E4","1317",{4.3,4.0,2.0,-1.0}},{"E5","8121",{3.7,2.3,1.3,-1.0}},{"E6","3312",{3.6,4.9,4.7,-1.0}},{"E7","5542",{3.4,4.5,5.0,-1.0}},{"E8","7131",{3.3,1.4,1.5,-1.0}},{"E9","0014",{1.3,3.4,3.5,-1.0}},{"E10","6532",{3.1,4.1,4.6,-1.0}}};
	  int ce=10;
	  int tip[CRC];
      void muestra_dat(struct datos_e [ME], int);
      void agregar_un_e(struct datos_e [ME],int *);
      void cal_def(struct datos_e [ME], int);
      void por_rango_cal(struct datos_e [ME], int [CRC], int );
      void resul_por_rango_cal(int [CRC], int );
      opcion=0;
      do{
               system("cls");
               printf("\n\n\t\t\tD A T O S   E S T U D I A N T E S\n\n");
               printf("\t\t\t0. Ver datos de los estudiantes\n");
               printf("\t\t\t1. Agregar un estudiante (uno a la vez)\n"); //
               printf("\t\t\t2. Calcular la definitiva\n");
               printf("\t\t\t3. Por rango de la definitiva\n");
               printf("\t\t\t4. S A L I R\n");
               printf("\n\t\t\tQu%c desea hacer ",130);
               scanf ("%d",&opcion);
               switch (opcion)
               {
                case 0: muestra_dat(de, ce);
                        break;
                case 1: agregar_un_e(de, &ce);
                        break;
                case 2: cal_def(de, ce);
                        break;
                case 3: por_rango_cal(de , tip, ce);
                        resul_por_rango_cal(tip, ce);
                        break;
                }
                system("pause");
      }
      while (opcion != 4);
}




void muestra_dat(struct datos_e de[ME], int ce)
{
int pe;
titulo("D A T O S  de los E S T U D I A N T E S");
printf("\n%-3s %-10s  %-6s %-4s %-4s %-4s %-10s\n\n","No.","Estudiante","Carne","T1","T2","T3","Definitiva" );
for (pe=0; pe < ce; pe++)
{
    printf("%-3d. %-10s %-6s %-.1f  %-.1f  %-.1f  %-.1f\n",pe+1,de[pe].nombre,de[pe].carne,de[pe].calif[0],de[pe].calif[1],de[pe].calif[2],de[pe].calif[3]);
}
printf("\n\n");
}





void agregar_un_e(struct datos_e de[ME],int *ce)
{
void mod_dat(struct datos_e *);

titulo("A G R E G A  UN  E S T U D I A N T E");
mod_dat(&de[*ce]);
*ce=*ce+1;
}

void mod_dat(struct datos_e *de)
{
int cont;

printf("\n\nDe nombre de estudiante nuevo >> ");
scanf("%s",(*de).nombre);
printf("\n\nDe Carnet >> ");
scanf("%s",(*de).carne);
cont=0;
while (cont<3)
	{
	 printf("\n\nDe nota #%d >> ",cont+1);
	 scanf("%f",&(*de).calif[cont]);
	 cont ++;
	}
}





void cal_def(struct datos_e de[ME],int ce) // 30%, 30% y 40%
{
int cont;

cont=0;
while (cont<ce)
	{
	 (de[cont]).calif[3]= ((de[cont]).calif[0])*0.3 + ((de[cont]).calif[1])*0.3 + ((de[cont]).calif[2])*0.4;
	 cont ++;
	}

}



void por_rango_cal(struct datos_e de[ME], int tip[CRC], int ce )
{
titulo("C U E N T A ESTUDIANTES por rango de calificaci�n definitiva");

void cal_def(struct datos_e [ME],int );
int cont1,cont2;
float linf,lsup;
cal_def(de, ce);
linf=0;
lsup=2;
for (cont1=0;cont1<CRC;cont1++)
	{
	 tip[cont1]=0;
	}
for (cont1=0;cont1<CRC;cont1++)
	{
	 for (cont2=0;cont2<ce;cont2++)
	 	{
		 if ( de[cont2].calif[3] >= linf && (de[cont2]).calif[3] < lsup) tip[cont1] ++;
		}
	 linf=lsup;
	 lsup++;
	}

}









void resul_por_rango_cal(int tip[CRC], int ce)
{
titulo("M U E S T R A cantidad de estudiantes por rango de definitiva");

int cont1,cont2;
float linf,lsup;

linf=0;
lsup=2;
for (cont1=0;cont1<CRC;cont1++)
	{
	  printf("\n\nEl numero de estudiantes con calificacion final entre %f y %f es: \n\n%d",linf,lsup,tip[cont1]);
	 linf=lsup;
	 lsup=lsup+1;
	}
printf("\n\n F I N");
}




void titulo(const char titulo[ ])
{
system("cls");
printf("\n\n\t%s\n\n",titulo);
}
