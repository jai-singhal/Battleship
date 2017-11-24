
void stage2(char computerGrid[][10],  struct initialShip arr[]){
    int total_players, row, col, i, j, k, temp, x;
    char direction, ship;
    int flag[5] = {0}, flag1;
    time_t t;

    while(1){
        fflush(stdin);
        sleep(0.1);
        srand((unsigned) time(&t));
        row = rand()%10;
        col = rand()%10;
        srand((unsigned) time(&t));
        x = rand();
        if(x % 2 )  direction = 'H';
        else    direction = 'V';
        x = rand() % 5;
        ship = arr[x].symbol;

        for(j = 0; j < 5; j++){
            if(arr[j].symbol == ship)    break;  // J IS THE SHIP FOUND IN THE STRUCTURE
        }
        if (flag[j] == 1){
            continue;
        }

        k = 0;
        flag1 = 0;
        if(direction == 'H'){
            if(col + arr[j].holes > 10){
                continue;
            }

            while(k < arr[j].holes){
                if(computerGrid[row][col + k] != '0'){
                    flag1 = 1;
                }
                k++;
            }
            k = 0;
            if(!flag1){
                while(k < arr[j].holes){
                    computerGrid[row][col + k] = ship;
                    k++;
                }
                flag[j] = 1;
            }
        }

        else if(direction == 'V'){
            if(row + arr[j].holes > 10){
                continue;
            }

            while(k < arr[j].holes){
                if(computerGrid[row + k][col] != '0'){
                    flag1 = 1;
                }
                k++;
            }
            k = 0;
            if(!flag1){
                while(k < arr[j].holes){
                  computerGrid[row + k][col] = ship;
                  k++;
                }
                flag[j] = 1;
            }
        }

        // printf("After next move, the Computer grid becomes: \n");
        // fflush(stdin);
        // printGrid(computerGrid);
        flag1 = 0;
        // printf("Ships Left: ");
        for(i = 0; i < 5; i++){
          if(flag[i] == 0){  //terminating case for while(1)
              flag1 = 1;
              // printf("%c ", arr[i].symbol);
          }
        }

        if(!flag1){
          // printf("No ship Left!!\n\n");
          printf("Computer have placed all his ships \n\n" );
          break;
        }
        // else{
        //   printf("\n\n");
        // }
    }
}
