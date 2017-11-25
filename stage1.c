
void stage1(char playerGrid[][10], struct initialShip arr[]){
    int total_players, row, col, i, j, k, temp;
    char direction, ship;
    int flag[5], flag1;

    for(i = 0; i < 5; i++)
        flag[i] = 0;

    printf("Player Chance\n");

    while(1){
        printf("Ships Left: ");
        for(i = 0; i < 5; i++){
          if(flag[i] == 0){  //terminating case for while(1)
              printf("%c ", arr[i].symbol);
          }
        }
        printf("\n");

        do{
          printf("\nEnter your move: ");
          scanf("%d %d %c %c", &row, &col, &direction, &ship);
          fflush(stdin);
        }
        while((row > 9 || col > 9 || row < 0 || col < 0) && ( direction != 'H' || direction != 'V') && printf("Wrong Move. Try Again\n"));


        for(j = 0; j < 5; j++){
            if(arr[j].symbol == ship)    break;  // J IS THE SHIP FOUND IN THE STRUCTURE
        }
        if(j == 5){
            printf("No ship found!! Try AGain\n");
            continue;
        }
        if (flag[j] == 1){
            printf("You have already used this Ship.. Try Again \n");
            continue;
        }


        k = 0;
        flag1 = 0;

        if(direction == 'H'){
            if(col + arr[j].holes > 10){
                printf("Error!! Ship cannot be placed outside!! Try Again \n");
                printf("After next move, the player grid becomes: \n");
                fflush(stdin);
                printGrid(playerGrid);
                continue;
            }

            while(k < arr[j].holes){
                if(playerGrid[row][col + k] != '0'){
                    flag1 = 1;
                }
                k++;
            }
            k = 0;
            if(!flag1){
                while(k < arr[j].holes){
                    playerGrid[row][col + k] = ship;
                    k++;
                }
                flag[j] = 1;
            }
            else{
                printf("Error!! Overlapping of ship is not allowed!! Try Again \n");
            }
        }

        else if(direction == 'V'){
            if(row + arr[j].holes > 10){
                printf("\n\nError!! Ship cannot be placed outside!! Try Again \n");
                printf("After above move, the player grid becomes: \n");
                fflush(stdin);
                printGrid(playerGrid);
                continue;
            }

            while(k < arr[j].holes){
                if(playerGrid[row + k][col] != '0'){
                    flag1 = 1;
                }
                k++;
            }
            k = 0;
            if(!flag1){
                while(k < arr[j].holes){
                  playerGrid[row + k][col] = ship;
                  k++;
                }
                flag[j] = 1;
            }
            else{
                printf("Error!! Overlapping of ship is not allowed!! Try Again \n");
            }
        }

        else{
            printf("Wrong Input\n");
            continue;
        }

        printf("After above move, the player grid becomes: \n");
        printGrid(playerGrid);
        fflush(stdin);

        flag1 = 0;
        for(i = 0; i < 5; i++){
          if(flag[i] == 0){  //terminating case for while(1)
              flag1 = 1;
          }
        }
        if(!flag1){
          printf("ThankYou!! You have placed all your ship \n" );
          break;
        }
    }
}
