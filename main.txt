// NOMBRE Y APELLIDOS: MARTÍN SENDE POMBO
// CURSO: 2019/20   ESTUDIOS: GRADO DE BIOTECNOLOGÍA

#include <stdio.h>
#include <locale.h>

int sumatorio (int min1, int max1);
int promedio (int min2, int max2);
int producto (int min3, int max3);

void main()
{
    // Permite emplear los carateres propios del español incluidos en el alfabeto ASCII extendido
    setlocale(LC_ALL, "spanish");

    /* Imprime en pantalla el nombre de la práctica y inicializa la varible cuyo valor condiciona la ejecución del bucle
    "do ... while" que aparece a continuación */
    printf("\n\n PRÁCTICA nº 4");
    char caracter;

    // Permite visualizar y emplear el menú de este programa
    do {
        // Presenta en pantalla el título y opciones del menú
        printf("\n\n ------------------------------- MENÚ -------------------------------------------------------");
        printf("\n\n 1: Suma de nºs comprendidos entre un valor mínimo y otro máximo, ambos incluidos");
        printf("\n 2: Media de los nºs impares comprendidos entre un valor mínimo y otro máximo, incluido el 1º, excluido el 2º");
        printf("\n 3: Producto de los nºs pares comprendidos entre un valor mínimo y otro máximo, ambos excluidos");
        printf("\n\n Introduzca una opción entre 1 y 3: ");

        // Estas 2 instrucciones permiten elegir una de las 3 opciones disponibles
        int eleccion;
        scanf("%d", &eleccion);

        // Esta sentencia de selección "switch" ejecuta la opción elegida
        switch (eleccion){
            /* Permite definir el valor mínimo y el máximo entre los que se realizará la operación indicada en la primera
            opción del menú y, devuelve el correspondiente resultado */
            case 1:{
                int min1, max1;
                printf("\nIntroduzca el menor número entero del intervalo cerrado al que se aplicará el sumatorio: ");
                scanf("%d", &min1);
                printf("\nIntroduzca el mayor número entero del intervalo cerrado al que se aplicará el sumatorio: ");
                scanf("%d", &max1);

                printf("\n El resultado de la suma es: %d", sumatorio(min1, max1));
                printf("\n");
                break;
            }
            /* Permite introducir los valore mínimo y máximo entre los que se llevará a cabo la operación indicada en la 2ª
            opción del menú y, devuelve su correspondiente resultado */
            case 2:{
                int min2, max2;
                printf("\nIntroduzca el menor número entero del intervalo semiabierto a la derecha al que se aplicará el promedio: ");
                scanf("%d", &min2);
                printf("\nIntroduzca el mayor número entero del intervalo semiabierto a la derecha al que se aplicará el promedio: ");
                scanf("%d", &max2);

                float resultado2 = promedio(min2, max2);
                printf("\n El resultado de la media es: %.3f", resultado2);
                printf("\n");
                break;
            }
            /* Permite definir el valor mínimo y el máximo entre los que se ejecutará la operación referida en la tercera
            opción del menú e, imprime en pantalla su correspondiente resultado */
            case 3:{
                int min3, max3;
                printf("\nIntroduzca el menor número entero del intervalo abierto al que se aplicará el producto: ");
                scanf("%d", &min3);
                printf("\nIntroduzca el mayor número entero del intervalo abierto al que se aplicará el producto: ");
                scanf("%d", &max3);

                printf("\n El resultado del producto es: %d", producto(min3, max3));
                printf("\n");
                break;
            }
            /* Avisa al usuario de que, en lugar de introducir en el búfer el número correspondiente a alguna de las 3 opciones,
            ha escrito otro distinto o uno de los carácteres 'n' y 'N' */
            default:{
                printf("Opción no válida");
            }
        }

        // Pregunta al usuario si quiere finalizar la ejecución del programa y recoge su respuesta escrita en el "buffer"
        printf("\n ¿Desea finalizar la ejecución del programa? En caso negativo, introduzca n o N: ");
        scanf(" %c", &caracter);
    } while ((caracter == 78) || (caracter == 110));

}

// Realiza la suma de todos los números pertenecientes al intervalo cerrado cuyos extremos fueron introducidos en "case 1"
int sumatorio(int min1, int max1)
{
    int resultado1 = 0, sumando = 0;
    for(resultado1 = min1, sumando = (min1 + 1); sumando <= max1; sumando++){
        resultado1 = resultado1 + sumando;
    }
    return resultado1;
}

/* Calcula la media aritmética de todos los números impares pertenecientes al intervalo semiabierto a la derecha cuyos
extremos han sido introducidos en el "case 2" de la bifurcación "switch" */
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

/* Lleva a cabo el producto de todos los números pares pertenecientes al intervalo abierto cuyos extremos fueron definidos
en el "case 3" de la sentencia de selección "switch" */
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
