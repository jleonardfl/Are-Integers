#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

//This program generates a grid of values for (x^y - x)/y with boundaries
//given as runtime arguments.  arvg should look like {grid, x, y}

int main(int argc, char** argv) {
    assert(argc==3);

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);
    long double data[x][y];

    _Bool are_integers[x][y];
    
    // Populate grids
    for(int i = 1; i <= x; i++){
        for(int j = 1; j <= y; j++){
            float v = pow(i, j);
            data[i-1][j-1]=v;
            are_integers[i-1][j-1]=(roundf(v)==v);
        }
    }

    // Print any non integer x y combinations
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            if(are_integers[i][j]==0){
                printf("Non-integer found!\t %.3Lg\n", data[i][j]);
            }
        }
    }
    printf("\n");

    // Print grids
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%.3Lg \t", data[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            printf("%d \t", are_integers[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    return(0);
}

