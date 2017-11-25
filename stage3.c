
void stage3(char playerGrid[][10], char computerGrid[][10]){
    int x, y, i, j, total_hits_player = 0, total_hits_comp = 0;
    char computerGridNew[10][10], playerGridOld[10][10];
    time_t t;
    int temp_x, temp_y;
    char temp;
    int total_chances = 0;

    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            computerGridNew[i][j] = '0';
            playerGridOld[i][j] = playerGrid[i][j];
        }
    }

    printBothGridTogether(playerGrid, computerGridNew, 1, 1);
    while(total_hits_player < 5 && total_hits_comp < 5){
        total_chances++;
        if(total_hits_player < 5){
            // printBothGridTogether(playerGrid, computerGridNew, 1, 1);
            do{
                printf("Enter the cordinate (x,y) where you want to attack: ");
                scanf("%d%d", &x, &y);
            }
            while((x > 9 || y > 9 || x < 0 || y < 0) && printf("Wrong Move. Try Again\n"));
                // printf("%d %d\n", x, y);
            if(computerGrid[x][y] != '0'){
              temp = computerGrid[x][y];
              computerGridNew[x][y] = computerGrid[x][y];
              temp_x = x;
              temp_y = y;
              while(computerGrid[++temp_x][temp_y] == temp){
                  computerGridNew[temp_x][temp_y] = computerGrid[x][y];
              }
              temp_x = x;
              while(computerGrid[temp_x][++temp_y] == temp){
                  computerGridNew[temp_x][temp_y] = computerGrid[x][y];
              }
              temp_y = y;
              while(computerGrid[--temp_x][temp_y] == temp){
                  computerGridNew[temp_x][temp_y] =  computerGrid[x][y];
              }
              temp_x = x;
              while(computerGrid[temp_x][--temp_y] == temp){
                  computerGridNew[temp_x][temp_y] = computerGrid[x][y];
              }
              total_hits_player++;
            }
            else{
                computerGridNew[x][y] = 'M';
            }
        }

        if(total_hits_player == 5){
            printf("\n\n----------------------Player WINS----------------------\n\n");
            break;
        }

        if(total_hits_comp < 5){
            // printBothGridTogether(playerGrid, computerGridNew, 1, 1);
            do{
                srand((unsigned) time(&t));
                x = rand()%10;
                y = rand()%10;
            }
            while(playerGrid[x][y] == 'M' && playerGrid[x][y] == 'X');
            // printf("%d %d\n", x, y);
            if(playerGrid[x][y] != '0' && playerGrid[x][y] != 'X' && playerGrid[x][y] != 'M'){
                temp = playerGrid[x][y];
                playerGrid[x][y] = 'X';
                temp_x = x;
                temp_y = y;
                while(playerGrid[++temp_x][temp_y] == temp){
                    playerGrid[temp_x][temp_y] = 'X';
                }
                temp_x = x;
                while(playerGrid[temp_x][++temp_y] == temp){
                    playerGrid[temp_x][temp_y] = 'X';
                }
                temp_y = y;
                while(playerGrid[--temp_x][temp_y] == temp){
                    playerGrid[temp_x][temp_y] = 'X';
                }
                temp_x = x;
                while(playerGrid[temp_x][--temp_y] == temp){
                    playerGrid[temp_x][temp_y] = 'X';
                }
                total_hits_comp++;
            }
            else{
                playerGrid[x][y] = 'M';
            }
        }

        if(total_hits_comp  == 5){
            printf("\n\n---------------------------Computer WINS!!-------------------------\n\n");
            break;
        }

       printBothGridTogether(playerGrid, computerGridNew, 1, 1);

    }
    printf("Total Chances: %d\n", total_chances);
    printf("Total Misses by player: %d\n", total_chances - total_hits_player);
    printf("Total Misses by Computer: %d\n", total_chances - total_hits_comp);
    printf("Actual placing of ships of both the players\n");
    printBothGridTogether(playerGridOld, computerGrid, 1, 1);
}
