#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "main.h"
#include "utils.c"
#include "stage1.c"
#include "stage2.c"
#include "stage3.c"

int main(){
    char playerGrid[10][10];
    char computerGrid[10][10];
    struct initialShip arr[5];
    int i, j, total_players;

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            playerGrid[i][j] = '0';
            computerGrid[i][j] = '0';
        }
    }
    fillInitialShip(arr);

    printGrid(playerGrid);
    stage1(playerGrid, arr);

    printf("Wait for moment while Computer is placing its ships!!\n");
    stage2(computerGrid, arr);

    stage3(playerGrid, computerGrid);

}
