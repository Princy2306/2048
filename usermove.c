#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int count = 0;
void print_tile(int n, int board[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to generate a random number (2 or 4) in an empty tile
void random_number_generation(int board[4][4])
{
    int empty_tile[16][2];
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (board[i][j] == 0)
            {
                empty_tile[count][0] = i;
                empty_tile[count][1] = j;
                count++;
            }
        }
    }
    if (count > 0)
    {
        int random_no = rand() % count;
        int row = empty_tile[random_no][0];
        int col = empty_tile[random_no][1];
        board[row][col] = (rand() % 100 < 80) ? 2 : 4;
    }
}

// Function to move all tiles left & merge if needed
void move_left(int board[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        // Shift numbers to the left
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
            {
                for (int k = j + 1; k < 4; k++)
                {
                    if (board[i][k] != 0)
                    {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }

        // Merge identical numbers
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == board[i][j + 1] && board[i][j] != 0)
            {
                board[i][j] *= 2;
                board[i][j + 1] = 0;
            }
        }

        // Shift again after merging
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0)
            {
                for (int k = j + 1; k < 4; k++)
                {
                    if (board[i][k] != 0)
                    {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    count++;
}
void move_right(int board[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        // Shift numbers to the left
        for (int j = 3; j >0; j--)
        {
            if (board[i][j] == 0)
            {
                for (int k = j - 1; k >=0; k--)
                {
                    if (board[i][k] != 0)
                    {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }

        // Merge identical numbers
        for (int j = 3; j >0; j--)
        {
            if (board[i][j] == board[i][j - 1] && board[i][j] != 0)
            {
                board[i][j] *= 2;
                board[i][j - 1] = 0;
            }
        }

        // Shift again after merging
        for (int j = 3; j >0; j--)
        {
            if (board[i][j] == 0)
            {
                for (int k = j -1; k >=0; k--)
                {
                    if (board[i][k] != 0)
                    {
                        board[i][j] = board[i][k];
                        board[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    count++;
}

void move_down(int board[4][4])
{
    for (int j = 0; j < 4; j++)
    {
        // Shift numbers to the down
        for (int i = 3; i > 0; i--)
        {
            if (board[i][j] == 0)
            {
                for (int k = i - 1; k >= 0; k--)
                {
                    if (board[k][j] != 0)
                    {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
        }

        // Merge identical numbers
        for (int i = 3; i > 0; i--)
        {
            if (board[i][j] == board[i-1][j] && board[i][j] != 0)
            {
                board[i][j] *= 2;
                board[i-1][j] = 0;
            }
        }

        // Shift again after merging
        for (int i = 3; i > 0; i--)
        {
            if (board[i][j] == 0)
            {
                for (int k = i-1; k >=0; k--)
                {
                    if (board[k][j] != 0)
                    {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    count++;
}
void move_up(int board[4][4])
{
    for (int j = 0; j < 4; j++)
    {
        // Shift numbers to the left
        for (int i = 0; i < 3; i++)
        {
            if (board[i][j] == 0)
            {
                for (int k = i + 1; k < 4; k++)
                {
                    if (board[k][j] != 0)
                    {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
        }
        
        // Merge identical numbers
        for (int i = 0; i < 3; i++)
        {
            if (board[i][j] == board[i+1][j] && board[i][j] != 0)
            {
                board[i][j] *= 2;
                board[i+1][j] = 0;
            }
        }

        // Shift again after merging
        for (int i = 0; i < 3; i++)
        {
            if (board[i][j] == 0)
            {
                for (int k = i + 1; k < 4; k++)
                {
                    if (board[k][j] != 0)
                    {
                        board[i][j] = board[k][j];
                        board[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    
   count++;
        
}

int game_over(int board[4][4]){
            for(int i = 0 ; i < 4 ; i++){
                for(int j = 0 ; j < 4 ; j++){
                    if(board[i][j]==0){
                        return 0 ;
                    }
                }
            }
            for(int i = 0 ; i<4; i++){
                for(int j = 0 ; j < 3 ; j++){
                    // checking rows
                    if(board[i][j]==board[i][j+1])
                    return 0 ;
                    // checking columns
                    if(board[i][j]==board[i+1][j])
                    return 0;
                }
            }
            return 1;
        }
// Function to handle user input
void user_move(int board[4][4])
{
    char ch;
    printf("Use W/S/A/D to move:\n");
    scanf(" %c", &ch); // Space before %c avoids issues with newline

    switch (ch)
    {
    case 'W':
    case 'w':
       move_up(board);
        break;
    case 'S':
    case 's':
        move_down(board);
        break;
    case 'A':
    case 'a':
        move_left(board);
        break;
    case 'D':
    case 'd':
        move_right(board);
        break;
    default:
        printf("Invalid input! Use W, A, S, or D.\n");
    }

    // Generate a new number after a valid move
    random_number_generation(board);
}

int main()
{
    srand(time(NULL));
    int board[4][4] = {0};

    // Spawn initial numbers
    random_number_generation(board);
    random_number_generation(board);

    // Game loop (run until user quits)
    while (1)
    {
        print_tile(4, board);
        
         if(game_over(board)){
        printf("OOPSIEE GAME OVER\n");
        printf("%d",count*100);
        break;
    }
            user_move(board);

    }
    
   
   
    return 0;
}
