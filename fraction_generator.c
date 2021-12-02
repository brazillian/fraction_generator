
/* **************************************************************************************** */
/*  Program name: Fractions generator.                                                      */
/*  Created by: Luiz Guilherme C. Silva.                                                    */
/*  Date: 02/12/2021.                                                                       */
/*  Objective: Random generate exercises to practice fractions.                             */
/*  *************************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int select_type();
void generate_numbers(int);
int correct_answear();

typedef struct {
    int fraction_one[2];
    int fraction_two[2];
}fractions;

fractions variables;


int main() {
    srand(time(0));
    system("clear");
    
    int player_answear;
    
    printf("NOTA: Este programa foi criado para pessoas que querem treinar suas habilidades\nem reconhecimento de frações. Sempre que voce acertar o programa voltara para a tela inicial\nonde será selecionado o tipo de fração desejada.\nNo mais, é apenas isso, obrigado!");
    getchar();
    
    do{
        system("clear");
        generate_numbers(select_type());
        printf("\nX = %d\n    --\n    %d\t\tY = %d\n\t\t    --\n\t\t    %d\n\n[1] X\n[2] Y\n[0] Iguais\n\nQual fração é maior? --> ", variables.fraction_one[0], variables.fraction_one[1], variables.fraction_two[0], variables.fraction_two[1]);
        scanf("%d", &player_answear);
    }while(player_answear == correct_answear());
    
    printf("Que pena, você errou...");
    getchar();

    return 0;
}

int select_type() {
    int type;
    do {
        printf("[1] Numeradores iguais\n[2] Denominadores iguais\n[0] Nada igual\n\nSelecione o tipo --> ");
        scanf("%d", &type);
        system("clear");
    }while(type != 1 && type != 2 && type != 0);
    
    return type;
    
}

void generate_numbers(int type) {
    switch(type) {
        case 1:
        for (int i = 0; i < 2; i++) {
            if (i == 0) {
                variables.fraction_one[0] = rand () % 100;
                variables.fraction_two[0] = variables.fraction_one[0];
            }
            else {
                do {
                    variables.fraction_one[i] = rand() % 100;
                    variables.fraction_two[i] = rand() % 100; 
                }while(variables.fraction_one[i] == variables.fraction_two[i]);
                

            }
        }
        break;
        case 2:
        for (int i = 0; i < 2; i++) {
            if (i == 1) {
                variables.fraction_one[1] = rand() % 100;
                variables.fraction_two[1] = variables.fraction_one[1];
            }
            else {
                do {
                    variables.fraction_one[i] = rand() % 100;
                    variables.fraction_two[i] = rand() % 100;
                }while (variables.fraction_one[i] == variables.fraction_two[i]);
            }
        }
        break;
        case 0:
        for (int i = 0; i < 2; i++) {
            do {
                variables.fraction_one[i] = rand() % 100;
                variables.fraction_two[i] = rand() % 100;
            }while(variables.fraction_one[i] == variables.fraction_two[i]);
        }
        break;
    }
    
}

int correct_answear() {
    double fraction_one_calc, fraction_two_calc;
    int correct_answear;
    
    fraction_one_calc = (float)variables.fraction_one[0] / (float)variables.fraction_one[1];
    fraction_two_calc = (float)variables.fraction_two[0] / (float)variables.fraction_two[1];

    
    if (fraction_one_calc > fraction_two_calc) {
        correct_answear = 1;
    }
    else if(fraction_one_calc < fraction_two_calc){
        correct_answear = 2;
    }
    else {
        correct_answear = 0;
    }
    
    return correct_answear;
}
