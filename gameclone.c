#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ticTacToePvP();
void ticTacToePvC();
void rockPaperScissors();

int main() {
    int choice, choice1;

    do {
        printf("\n====== Game Hub ======\n");
        printf("1. Tic Tac Toe\n");
        printf("2. Rock Paper Scissors\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\n1. Player vs Player\n");
                printf("2. Player vs Computer\n");
                printf("Enter your choice: ");
                scanf("%d", &choice1);

                if (choice1 == 1)
                    ticTacToePvP();
                else if (choice1 == 2)
                    ticTacToePvC();
                else
                    printf("Invalid choice!\n");
                break;

            case 2:
                rockPaperScissors();
                break;

            case 3:
                printf("Thanks for playing!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 3);

    return 0;
}

/*-----------------------------------*/
/* PLAYER vs PLAYER TIC TAC TOE      */
/*-----------------------------------*/
void ticTacToePvP() {
    char board[3][3];
    int row, col, player = 1, gameOver = 0;
    char mark;

    // Initialize board
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            board[i][j] = ' ';

    printf("\nTIC TAC TOE (Player vs Player)\n");
    printf("Player 1 -> X\nPlayer 2 -> O\n");

    while (!gameOver) {
        printf("\n");
        for (int i=0;i<3;i++) {
            printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
            if (i<2) printf("\n---|---|---\n");
        }
        printf("\n");

        mark = (player == 1) ? 'X' : 'O';
        printf("Player %d (%c), enter row and column (1-3 1-3): ", player, mark);
        scanf("%d %d", &row, &col);
        row--; col--;

        if (row<0 || row>2 || col<0 || col>2 || board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = mark;

        // Check win
        for (int i=0;i<3;i++) {
            if ((board[i][0]==mark && board[i][1]==mark && board[i][2]==mark) ||
                (board[0][i]==mark && board[1][i]==mark && board[2][i]==mark)) {
                printf("Player %d (%c) wins!\n", player, mark);
                gameOver = 1;
            }
        }
        if ((board[0][0]==mark && board[1][1]==mark && board[2][2]==mark) ||
            (board[0][2]==mark && board[1][1]==mark && board[2][0]==mark)) {
            printf("Player %d (%c) wins!\n", player, mark);
            gameOver = 1;
        }

        if (!gameOver) {
            int draw = 1;
            for (int i=0;i<3;i++)
                for (int j=0;j<3;j++)
                    if (board[i][j]==' ') draw = 0;
            if (draw) {
                printf("It's a draw!\n");
                gameOver = 1;
            }
        }

        player = (player == 1) ? 2 : 1;
    }
}

/*-----------------------------------*/
/* PLAYER vs COMPUTER TIC TAC TOE    */
/*-----------------------------------*/
void ticTacToePvC() {
    char b[3][3];
    int i, j, r, c, move = 0;
    char win = ' ';
    srand(time(0));

    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            b[i][j]=' ';

    printf("\nTIC TAC TOE (You = X, Computer = O)\n");

    while(1) {
        // Print board
        printf("\n");
        for(i=0;i<3;i++) {
            printf(" %c | %c | %c ", b[i][0], b[i][1], b[i][2]);
            if(i<2) printf("\n---|---|---\n");
        }
        printf("\n");

        // Player move
        printf("Enter row and column (1-3 1-3): ");
        scanf("%d%d", &r, &c);
        r--; c--;
        if(r<0 || r>2 || c<0 || c>2 || b[r][c]!=' ') {
            printf("Invalid move!\n");
            continue;
        }
        b[r][c] = 'X';
        move++;

        // Check if player won
        for(i=0;i<3;i++) {
            if(b[i][0]=='X'&&b[i][1]=='X'&&b[i][2]=='X') win='X';
            if(b[0][i]=='X'&&b[1][i]=='X'&&b[2][i]=='X') win='X';
        }
        if(b[0][0]=='X'&&b[1][1]=='X'&&b[2][2]=='X') win='X';
        if(b[0][2]=='X'&&b[1][1]=='X'&&b[2][0]=='X') win='X';
        if(win=='X'){ printf("You win!\n"); break; }

        if(move==9){ printf("It's a draw!\n"); break; }

        // Computer move
        while(1){
            r = rand()%3;
            c = rand()%3;
            if(b[r][c]==' ') { b[r][c]='O'; break; }
        }
        printf("Computer played at: %d %d\n", r+1, c+1);
        move++;

        // Check if computer won
        for(i=0;i<3;i++) {
            if(b[i][0]=='O'&&b[i][1]=='O'&&b[i][2]=='O') win='O';
            if(b[0][i]=='O'&&b[1][i]=='O'&&b[2][i]=='O') win='O';
        }
        if(b[0][0]=='O'&&b[1][1]=='O'&&b[2][2]=='O') win='O';
        if(b[0][2]=='O'&&b[1][1]=='O'&&b[2][0]=='O') win='O';
        if(win=='O'){ printf("Computer wins!\n"); break; }

        if(move==9){ printf("It's a draw!\n"); break; }
    }

    // Final board
    printf("\nFinal Board:\n");
    for(i=0;i<3;i++) {
        printf(" %c | %c | %c ", b[i][0], b[i][1], b[i][2]);
        if(i<2) printf("\n---|---|---\n");
    }
    printf("\n");
}

/*-----------------------------------*/
/* ROCK PAPER SCISSORS GAME          */
/*-----------------------------------*/
void rockPaperScissors() {
    int user, comp;
    srand(time(0));

    printf("\nRock Paper Scissors Game\n");
    printf("1. Rock\n2. Paper\n3. Scissors\n");
    printf("Enter your choice: ");
    scanf("%d", &user);

    comp = rand() % 3 + 1; // computer choice

    printf("You chose: %d\n", user);
    printf("Computer chose: %d\n", comp);

    if (user == comp)
        printf("It's a tie!\n");
    else if ((user == 1 && comp == 3) || (user == 2 && comp == 1) || (user == 3 && comp == 2))
        printf("You win!\n");
    else
        printf("Computer wins!\n");
}