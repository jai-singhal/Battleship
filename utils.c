
void printGrid(char grid[][10]){
    int i, j;
    printf("\n");
    for(i = 0; i < 10; i++){
        printf("\t\t\t");
        for(j = 0; j < 10; j++){
            if(grid[i][j] == '0')
                printf("%3c", '_');
            else
                printf("%3c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void printBothGridTogether(char grid1[][10], char grid2[][10], int is_human, int is_comp){
    int i, j;
    printf("\n");
    printf("\t\t PLayer Grid \t\t\t\t Computer Grid\t\n\n");
    for(i = 0; i < 10; i++){
        printf("\t");
        for(j = 0; j < 10; j++){
            if(is_human){
              if(grid1[i][j] != '0')
                  printf("%3c", grid1[i][j]);
              else
                  printf("%3c", '_');
            }
            else{
                printf("%3c", '_');
            }
        }
        printf("\t\t");
        for(j = 0; j < 10; j++){
            if(is_comp)
                if(grid2[i][j] != '0')
                    printf("%3c", grid2[i][j]);
                else
                    printf("%3c", '_');
            else
                printf("%3c", '_');
        }
        printf("\n");
    }
    printf("\n");
}

void fillInitialShip(struct initialShip arr[]){
    strcpy(arr[0].shipName, "Cruiser");
    strcpy(arr[1].shipName, "Submarine");
    strcpy(arr[2].shipName, "DEstroyer");
    strcpy(arr[3].shipName, "BattleShip");
    strcpy(arr[4].shipName, "Aircraft Carrier");

    arr[0].holes = 2;
    arr[1].holes = 3;
    arr[2].holes = 3;
    arr[3].holes = 4;
    arr[4].holes = 5;

    arr[0].symbol = 'C';
    arr[1].symbol = 'S';
    arr[2].symbol = 'D';
    arr[3].symbol = 'B';
    arr[4].symbol = 'A';
}
