// NOMBRE Y APELLIDOS: MART�N SENDE POMBO
// CURSO: 2019/20   ESTUDIOS: GRADO DE BIOTECNOLOG�A

#include <stdio.h>
#include <locale.h>

int sumatorio (int min1, int max1);
int promedio (int min2, int max2);
int producto (int min3, int max3);

void main()
{
    // Permite emplear los carateres propios del espa�ol incluidos en el alfabeto ASCII extendido
    setlocale(LC_ALL, "spanish");

    /* Imprime en pantalla el nombre de la pr�ctica y inicializa la varible cuyo valor condiciona la ejecuci�n del bucle
    "do ... while" que aparece a continuaci�n */
    printf("\n\n PR�CTICA n� 4");
    char caracter;

    // Permite visualizar y emplear el men� de este programa
    do {
        // Presenta en pantalla el t�tulo y opciones del men�
        printf("\n\n ------------------------------- MEN� -------------------------------------------------------");
        printf("\n\n 1: Suma de n�s comprendidos entre un valor m�nimo y otro m�ximo, ambos incluidos");
        printf("\n 2: Media de los n�s impares comprendidos entre un valor m�nimo y otro m�ximo, incluido el 1�, excluido el 2�");
        printf("\n 3: Producto de los n�s pares comprendidos entre un valor m�nimo y otro m�ximo, ambos excluidos");
        printf("\n\n Introduzca una opci�n entre 1 y 3: ");

        // Estas 2 instrucciones permiten elegir una de las 3 opciones disponibles
        int eleccion;
        scanf("%d", &eleccion);

        // Esta sentencia de selecci�n "switch" ejecuta la opci�n elegida
        switch (eleccion){
            /* Permite definir el valor m�nimo y el m�ximo entre los que se realizar� la operaci�n indicada en la primera
            opci�n del men� y, devuelve el correspondiente resultado */
            case 1:{
                int min1, max1;
                printf("\nIntroduzca el menor n�mero entero del intervalo cerrado al que se aplicar� el sumatorio: ");
                scanf("%d", &min1);
                printf("\nIntroduzca el mayor n�mero entero del intervalo cerrado al que se aplicar� el sumatorio: ");
                scanf("%d", &max1);

                printf("\n El resultado de la suma es: %d", sumatorio(min1, max1));
                printf("\n");
                break;
            }
            /* Permite introducir los valore m�nimo y m�ximo entre los que se llevar� a cabo la operaci�n indicada en la 2�
            opci�n del men� y, devuelve su correspondiente resultado */
            case 2:{
                int min2, max2;
                printf("\nIntroduzca el menor n�mero entero del intervalo semiabierto a la derecha al que se aplicar� el promedio: ");
                scanf("%d", &min2);
                printf("\nIntroduzca el mayor n�mero entero del intervalo semiabierto a la derecha al que se aplicar� el promedio: ");
                scanf("%d", &max2);

                float resultado2 = promedio(min2, max2);
                printf("\n El resultado de la media es: %.3f", resultado2);
                printf("\n");
                break;
            }
            /* Permite definir el valor m�nimo y el m�ximo entre los que se ejecutar� la operaci�n referida en la tercera
            opci�n del men� e, imprime en pantalla su correspondiente resultado */
            case 3:{
                int min3, max3;
                printf("\nIntroduzca el menor n�mero entero del intervalo abierto al que se aplicar� el producto: ");
                scanf("%d", &min3);
                printf("\nIntroduzca el mayor n�mero entero del intervalo abierto al que se aplicar� el producto: ");
                scanf("%d", &max3);

                printf("\n El resultado del producto es: %d", producto(min3, max3));
                printf("\n");
                break;
            }
            /* Avisa al usuario de que, en lugar de introducir en el b�fer el n�mero correspondiente a alguna de las 3 opciones,
            ha escrito otro distinto o uno de los car�cteres 'n' y 'N' */
            default:{
                printf("Opci�n no v�lida");
            }
        }

        // Pregunta al usuario si quiere finalizar la ejecuci�n del programa y recoge su respuesta escrita en el "buffer"
        printf("\n �Desea finalizar la ejecuci�n del programa? En caso negativo, introduzca n o N: ");
        scanf(" %c", &caracter);
    } while ((caracter == 78) || (caracter == 110));

}

// Realiza la suma de todos los n�meros pertenecientes al intervalo cerrado cuyos extremos fueron introducidos en "case 1"
int sumatorio(int min1, int max1)
{
    int resultado1 = 0, sumando = 0;
    for(resultado1 = min1, sumando = (min1 + 1); sumando <= max1; sumando++){
        resultado1 = resultado1 + sumando;
    }
    return resultado1;
}

/* Calcula la media aritm�tica de todos los n�meros impares pertenecientes al intervalo semiabierto a la derecha cuyos
extremos han sido introducidos en el "case 2" de la bifurcaci�n "switch" */
int promedio (int min2, int max2)
{
    float resultado2 = 0; int numero = 0;
    if(min2 % 2 == 0){
        for(numero = (min2 + 1); numero < max2; numero = numero + 2){
            resultado2 = resultado2 + numero;
        }
        resultado2 = resultado2 / ((max2 - 1) / 2);
        return resultado2;
    }
    else{
        for(numero = min2; numero < max2; numero = numero + 2){
            resultado2 = resultado2 + numero;
        }
        resultado2 = resultado2 / ((max2 - 1) / 2);
        return resultado2;
    }


}

/* Lleva a cabo el producto de todos los n�meros pares pertenecientes al intervalo abierto cuyos extremos fueron definidos
en el "case 3" de la sentencia de selecci�n "switch" */
int producto (int min3, int max3)
{
    int resultado3 = 1; int factor = 1;
    if(min3 % 2 == 0){
        for(factor = (min3 + 2); factor < max3; factor = (factor + 2)){
             resultado3 = (resultado3 * (factor));
        }
        return resultado3;
    }
    else{
        for(factor = (min3 + 1); factor < max3; factor = (factor + 2)){
            resultado3 = (resultado3 * (factor));
        }
        return resultado3;
    }
}
