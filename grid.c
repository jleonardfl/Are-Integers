#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

//This program generates a grid of values for (x^y - x)/y with boundaries
//given as runtime arguments.  arvg should look like {grid, x, y}

int main(int argc, char** argv) {
    int x = 0;
    int y = 0;

    if(argc!=3){
        printf("Enter x dimension: ");
        scanf("%d", &x);
        printf("Enter y dimension: ");
        scanf("%d", &y);
    } else {
        x = atoi(argv[1]);
        y = atoi(argv[2]);
    }

    FILE *fp;
    fp = fopen("out.csv", "w");

    if(!fp){printf("Could not open file!\n");}
    else {printf("out.csv opened successfully.\n");}

    long double data[x][y];

    //_Bool are_integers[x][y];
    
    // Populate grids
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            float v = ((pow(i, j)-i)/j);
            data[i-1][j-1]=v;
            //are_integers[i-1][j-1]=(roundf(v)==v);
        }
    }

    /*
    // Print any non integer x y combinations
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(are_integers[i][j]==0){
                printf("Non-integer found!\t %.3Lg\n", data[i][j]);
            }
        }
    }
    printf("\n");
    */

    // Print grids
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            fprintf(fp, "%.3Lg,", data[i][j]);
        }
        fprintf(fp, "\n");
    }
    fprintf(fp, "\n");

    printf("\nSaved to out.csv.\n\n");

    /*
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d, ", are_integers[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    */

    return(0);
}

