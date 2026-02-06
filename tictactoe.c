#include <stdio.h>

char board[3][3];
char currentPlayer = 'X';


void initializeBoard() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}


void displayBoard() {
    printf("\n");
    for(int i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if(i < 2)
            printf("\n---|---|---\n");
    }
    printf("\n\n");
}


void switchPlayer() {
    if(currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}


int checkWinner() {

    for(int i = 0; i < 3; i++) {
        if(board[i][0] == currentPlayer &&
           board[i][1] == currentPlayer &&
           board[i][2] == currentPlayer)
            return 1;

        if(board[0][i] == currentPlayer &&
           board[1][i] == currentPlayer &&
           board[2][i] == currentPlayer)
            return 1;
    }

    
    if(board[0][0] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][2] == currentPlayer)
        return 1;

    if(board[0][2] == currentPlayer &&
       board[1][1] == currentPlayer &&
       board[2][0] == currentPlayer)
        return 1;

    return 0;
}


int checkDraw() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

int main() {
    int row, col;

    initializeBoard();

    printf("===== TIC TAC TOE GAME =====\n");
    printf("Player 1: X\nPlayer 2: O\n");

    while(1) {
        displayBoard();

        printf("Player %c, enter row and column (0-2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if(row < 0 || row > 2 || col < 0 || col > 2 ||
           board[row][col] != ' ') {
            printf("Invalid move! Try again.\n");
            continue;
        }

        board[row][col] = currentPlayer;

        if(checkWinner()) {
            displayBoard();
            printf("🎉 Player %c Wins!\n", currentPlayer);
            break;
        }

        if(checkDraw()) {
            displayBoard();
            printf("🤝 It's a Draw!\n");
            break;
        }

        switchPlayer();
    }

    return 0;
}
