/**********************************************************
 ** Program: assignment5.cpp
 ** Author: Ragini Dindukurthi
 ** Date: 3/11/21
 ** Description: 1-2 player Connect Four game
 ** Input: number of players, rows, cols, selecting col
 ** Output: game board, game statements
*********************************************************/
#include <iostream> 
#include <cstring> 
#include <string> 
#include <cstdlib> 

using namespace std; 

int boolError(string);
/**********************************************************
 ** Function: boolErrorCheck
 ** Description: checks to see if input is equal to 1 or 0
 ** Parameters: mssg
 ** Pre-conditions: mssg must correspond to input  
 ** Post-conditions: a 0 or 1 is returned
 **********************************************************/

void printBoard(char**, int, int); 
/**********************************************************
 ** Function: printBoard
 ** Description: prints game board according to command
 ** line arguments (rows and columns)
 ** Parameters: board, rows, cols
 ** Pre-conditions: mssg must correspond to input  
 ** Post-conditions: game board is printed
 **********************************************************/

void printNum(int); 
/**********************************************************
 ** Function: printNum
 ** Description: prints column numbers
 ** Parameters: cols
 ** Pre-conditions: total cols must be known  
 ** Post-conditions: column numbers printed 
 ** (before game board is printed)
 **********************************************************/

void setUp(char**, int, int);
/**********************************************************
 ** Function: setUp
 ** Description: initializes board array
 ** Parameters: board, rows, cols
 ** Pre-conditions: rows and cols must be known, either 
 ** from command line arguments or runtime
 ** Post-conditions: board is ready to play
 **********************************************************/

void freeBoard(char**, int);
/**********************************************************
 ** Function: freeBoard
 ** Description: deallocates memory of board array
 ** Parameters: board, rows
 ** Pre-conditions: 1 game must be complete
 ** Post-conditions: memory is freed, 
 ** no memory leaks possible
 **********************************************************/

int turnError(int);
/**********************************************************
 ** Function: turnError
 ** Description: error handling for column selection
 ** Parameters: cols
 ** Pre-conditions: must be user's turn
 ** Post-conditions: valid col is returned
 **********************************************************/

void gameControl(char**, int, int, int);
/**********************************************************
 ** Function: gameControl
 ** Description: executes one player or two player mode
 ** Parameters: board, players, rows, cols
 ** Pre-conditions: rows, cols, num of players must be known, 
 ** either from command line arguments or runtime
 ** Post-conditions: one/two player mode begins
 **********************************************************/

int firstTurn();
/**********************************************************
 ** Function: firstTurn
 ** Description: asks user if they want to go 
 ** first in onePlayer mode
 ** Parameters: none
 ** Pre-conditions: one player mode executed
 ** Post-conditions: returns 1 or 0
 **********************************************************/

void compTurn(char**, int, int);
/**********************************************************
 ** Function: compTurn
 ** Description: executes computer's turn
 ** Parameters: board, rows, cols
 ** Pre-conditions: board must be checked for winner/tie
 ** Post-conditions: board is printed w computer's piece
 **********************************************************/

void playerTurn(char**, int, int, char);
/**********************************************************
 ** Function: playerTurn
 ** Description: player goes first in gameplay
 ** Parameters: board, rows, cols, playerChar
 ** Pre-conditions: board must be checked for winner/tie
 ** Post-conditions: board is printed w player's piece
 **********************************************************/

int checkBoard(char**, int, int, int, int); 
/**********************************************************
 ** Function: checkBoard
 ** Description: board is checked for winner/tie
 ** Parameters: board, rows, cols, gameOver, playerChar
 ** Pre-conditions: computer/player's turn is complete
 ** Post-conditions: returns gameOver
 **********************************************************/

int diagonalCheck(char**, int, int, int, int);
/**********************************************************
 ** Function: diagonalCheck
 ** Description: checks board for right/left diagonal win
 ** Parameters: board, rows, cols, gameOver, playerChar
 ** Pre-conditions: player/comp's turn completed
 ** Post-conditions: gameOver is returned
 **********************************************************/

void compFirst(char**, int, int);
/**********************************************************
 ** Function: compFirst
 ** Description: computer goes first in gameplay
 ** Parameters: board, rows cols
 ** Pre-conditions: user says no to going first
 ** Post-conditions: computer and player play until winner/tie
 **********************************************************/

int tieCheck(char**, int, int, int);
/**********************************************************
 ** Function: tieCheck
 ** Description: checks board for tie
 ** Parameters: board, rows, cols, gameOver
 ** Pre-conditions: check for wins is complete
 ** Post-conditions: gameOver is returned
 **********************************************************/

void printEnd(int, string);
/**********************************************************
 ** Function: printEnd
 ** Description: prints winner/tie
 ** Parameters: gameOver, mssg
 ** Pre-conditions: 1 game is complete
 ** Post-conditions: winner/tie is printed on screen 
 **********************************************************/

void playerFirst(char**, int, int);
/**********************************************************
 ** Function: playerFirst
 ** Description: player goes first in gameplay
 ** Parameters: board, rows, cols
 ** Pre-conditions: user says 1 for first turn
 ** Post-conditions: player/comp play until winner/tie
 **********************************************************/

void twoPlay(char**, int, int);
/**********************************************************
 ** Function: twoPlay
 ** Description: two player mode, executes both player's turn
 ** Parameters: board, rows, cols
 ** Pre-conditions: user enter 2 for num players in 
 ** command line/runtime
 ** Post-conditions: game continues until winner/tie
 **********************************************************/

void commandError(int, char**, int&, int&, int&);
/**********************************************************
 ** Function: commandError
 ** Description: error checks command line arguments
 ** Parameters: arg, argv, rows, cols, players
 ** Pre-conditions: program is executed 
 ** Post-conditions: valid input for rows, players, 
 ** cols is updated
 **********************************************************/

void rowsError(char**, int&);
/**********************************************************
 ** Function: rowsError
 ** Description: rows are error checked and valid rows 
 ** are returned
 ** Parameters: argv, rows
 ** Pre-conditions: program is executed
 ** Post-conditions: valid rows are updated
 **********************************************************/

void colsError(char**, int&);
/**********************************************************
 ** Function: colsError
 ** Description: cols are error checked and valid cols 
 ** are returned
 ** Parameters: argv, cols
 ** Pre-conditions: program is executed
 ** Post-conditions: valid cols are updated
 **********************************************************/

void playersError(char**, int&);
/**********************************************************
 ** Function: playersError
 ** Description: players are error checked and valid players 
 ** are returned
 ** Parameters: argv, players
 ** Pre-conditions: program is executed
 ** Post-conditions: valid players are updated
 **********************************************************/

void playersReprompt(int&);
/**********************************************************
 ** Function: playersReprompt
 ** Description: user is reprompted for num of players
 ** Parameters: players
 ** Pre-conditions: players must be checked if valid or not
 ** Post-conditions: valid players are updated
 **********************************************************/

void rowsReprompt(int&);
/**********************************************************
 ** Function: rowsReprompt
 ** Description: user is reprompted for rows
 ** Parameters: rows
 ** Pre-conditions: program is executed
 ** Post-conditions: valid rows are updated
 **********************************************************/

void colsReprompt(int&);
/**********************************************************
 ** Function: colsReprompt
 ** Description: user is reprompted for cols
 ** Parameters: cols
 ** Pre-conditions: program is executed
 ** Post-conditions: valid cols are updated
 **********************************************************/

int main(int argc, char* argv[]){
    int play = 1; 
    int rows = 0; 
    int cols = 0;
    int players = 0;

    cout << "Welcome to Connect Four!" << endl;
    commandError(argc, argv, rows, cols, players);
     

    do{
        char **board = new char*[rows];
        for(int i = 0; i < rows; i++){
            board[i] = new char[cols]; 
        }
        setUp(board, rows, cols); 
        gameControl(board, players, rows, cols); 


        freeBoard(board, rows);
        board = NULL; 
        play = boolError("Do you want to play again? (1, 0)"); 
    }while(play == 1);

    cout << "Goodbye!" << endl; 

    return 0; 
}

void commandError(int arg, char** argv, int& rows, int& cols, int& players){

    if(arg != 4){
        cout << "Error! Invalid number of arguments or missing arguments." <<endl; 
        playersReprompt(players); 
        rowsReprompt(rows); 
        colsReprompt(cols); 
    }
    
    else{
        playersError(argv, players); 
        rowsError(argv, rows);
        colsError(argv, cols); 
    }

}

void playersError(char** argv, int& players){

    if(atoi(argv[1]) == 1 || atoi(argv[1]) == 2){
        players = atoi(argv[1]); 
    }

    else{
        playersReprompt(players); 
    }
}

void rowsError(char** argv, int& rows){

    if(atoi(argv[2]) >= 4 && atoi(argv[2]) <= 20){
        rows = atoi(argv[2]); 
    }
    else{
        rowsReprompt(rows); 
    }

}

void colsError(char** argv, int& cols){

    if(atoi(argv[3]) >= 4 && atoi(argv[3]) <= 20){
        cols = atoi(argv[3]); 
    }
    else{
        colsReprompt(cols); 
    }
}

void playersReprompt(int& players){

    bool valid = false;
    string input;

    cout << "Error! Invalid input. Enter 1 or 2 for number of players." << endl;
    do{
        cout << "Enter number of players: "; 
        getline(cin, input); 

        if(input.length() > 1){ //the valid input should be 1 character
            cout << "Error! Input is too large. Please enter 1 or 2." << endl;
            valid = false;
        }
        else if(!(input[0] == '1' || input[0] == '2')){
            cout << "Error! Invalid input. Please enter 1 or 2." << endl;
            valid = false;
        }
        else{
            valid = true;
        }
    }while(valid == false);
    players = atoi(input.c_str());

}

void rowsReprompt(int& rows){

    bool valid = false;
    string input;

     cout << "Error! Invalid input. Enter a positive integer between 4 and 20 for rows." << endl;
    do{
        cout << "Enter number of rows: "; 
        getline(cin, input); 

        if(atoi(input.c_str()) < 0){ //the valid input should be positive
            cout << "Error! Please enter a positive integer." << endl;
            valid = false;
        }
        else if(!(atoi(input.c_str()) >= 4 && atoi(input.c_str()) <= 20)){
            cout << "Error! Invalid characters. Please enter an integer between 4 and 20 for rows." << endl;
            valid = false;
        }
        else{
            valid = true;
        }
    }while(valid == false);
    rows = atoi(input.c_str());

}

void colsReprompt(int& cols){

    bool valid = false;
    string input;

    cout << "Error! Invalid input. Enter a positive integer between 4 and 20 for columns." << endl;
    do{
        cout << "Enter number of columns: "; 
        getline(cin, input); 

        if(atoi(input.c_str()) < 0){ //the valid input should be positive
            cout << "Error! Please enter a positive integer." << endl;
            valid = false;
        }
        else if(!(atoi(input.c_str()) >= 4 && atoi(input.c_str()) <= 20)){
            cout << "Error! Invalid characters. Please enter a positive integer between 4 and 20 for columns." << endl;
            valid = false;
        }
        else{
            valid = true;
        }
    }while(valid == false);
    cols = atoi(input.c_str());

}

int boolError(string mssg){
    bool valid = false;
    string input;

    do{
        cout << mssg << ": "; 
        getline(cin, input); 

        if(input.length() > 1){ //the valid input should be 1 character
            cout << "Error! Please enter 1 or 0." <<endl;
            valid = false;
        }
        else if(!(input[0] == '1' || input[0] == '0')){
            cout << "Error! Invalid characters. Please enter 1 or 0." <<endl;
            valid = false;
        }
        else{
            valid = true;
        }
    }while(valid == false);
    return atoi(input.c_str());
}

void printBoard(char** board, int rows, int cols){

    printNum(cols); 
    
    cout << endl; 
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (i % 2 == 0 && j % 2 == 0){
                cout << "|\033[30;47m " << board[i][j] << " ";
            }
            else if (i % 2 == 1 && j % 2 == 1){
                cout << "|\033[30;47m " << board[i][j] << " "; 
            }
             else{
                cout << "|\033[0m " << board[i][j] << " ";
                cout << "\033[0m";
            }
            cout << "\033[0m"; 
        }
        cout << "|"; 
        cout << endl;
    }
}

void printNum(int cols){
    for(int x = 0; x < cols; x++){

        if(x == 0){
            cout << "  " <<  (x+1) << "   "; 
        }
        else if(x == 8){
            cout << (x+1) << "  "; 
        }
        else if(x == 9){
            cout <<  (x+1);  
        }
        else if(x > 9){
            cout << "  " << (x+1); 
        }
        else{
            cout <<  (x+1) << "   ";
        }
    }
}

void setUp(char** board, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            board[i][j] = 32; 
        }
    }
    printBoard(board, rows, cols);
}

void freeBoard(char** board, int rows){
    for(int i = 0; i < rows; i++){
        delete [] board[i];
        board[i] = NULL; 
    }
    delete [] board; 
}

int turnError(int cols){
    bool valid = false;
    string input;
    char last = '0' + cols; 

    do{
        cout << "Select a column: "; 
        getline(cin, input); 

        if(input.length() > 1){ //the valid input should be 1 character
            cout << "Error! Please enter a column between 1 and " << cols << "." <<endl;
            valid = false;
        }
        else if(!(input[0] >= 49 && input[0] <= last)){ /// use a to i function to do this 
            cout << "Error! Please enter a column between 1 and " << cols << "." <<endl;
            valid = false; 
        }
        else{
            valid = true;
        }
    }while(valid == false);
    return atoi(input.c_str());
}



void gameControl(char** board, int players, int rows, int cols){
    if(players == 1){
        int first = firstTurn();
        if(first == 0){
            compFirst(board, rows, cols);
        }
        else if(first == 1){
            playerFirst(board, rows, cols);
        }
    }
    else if(players == 2){
        twoPlay(board, rows, cols); 
    }
}

int firstTurn(){
    cout << "Welcome to One Player Mode!" << endl; 
    cout << "You are playing against a semi-intelligent computer!" <<endl;
    cout << "Computer: X, Player 1: O" << endl; 
    return boolError("Do you want to go first? (1, 0)"); 
    
}

void compFirst(char** board, int rows, int cols){
    int gameOver = 0; 
    int playerChar = 0; 

    do{
        compTurn(board, rows, cols);
        gameOver = checkBoard(board, rows, cols, gameOver, 88); 
        if(gameOver == 1 || gameOver == 2){
            printEnd(gameOver, "Computer wins! Game Over."); 
            break; 
        }
        playerTurn(board, rows, cols, 79);
        gameOver = checkBoard(board, rows, cols, gameOver, 79);
        printEnd(gameOver, "Player wins! Game Over."); 
    }while(gameOver == 0);

    

}

void playerFirst(char** board, int rows, int cols){
    int gameOver = 0; 
    int playerChar = 0; 

    do{
        playerTurn(board, rows, cols, 79);
        gameOver = checkBoard(board, rows, cols, gameOver, 79); 
        if(gameOver == 1 || gameOver == 2){
            printEnd(gameOver, "Player wins! Game Over."); 
            break; 
        }
        compTurn(board, rows, cols);
        gameOver = checkBoard(board, rows, cols, gameOver, 88);
        printEnd(gameOver, "Computer wins! Game Over."); 
    }while(gameOver == 0);

}

void compTurn(char** board, int rows, int cols){
    bool done = false; 
    int currentCol = 0;  

    cout << "Computer's Turn" << endl; 

    for(int i = rows - 1; i >= 0; i--){
        for(int j = 0; j < cols; j++){
            if(board[i][j] == ' '){
                board[i][j] = 88;
                printBoard(board, rows, cols);
                return;   
            }
        }
    }

}

void playerTurn(char** board, int rows, int cols, char playerChar){
    bool done = false; 
    int currentCol = 0;

    if(playerChar == 79){
        cout << "Player 1's Turn" << endl; 
    }
    else if(playerChar == 88){
        cout << "Player 2's Turn" << endl; 
    }

    do{
        currentCol = turnError(cols); 
        for(int i = rows - 1; i >= 0; i--){ 
            if(board[i][currentCol - 1] == ' '){
                board[i][currentCol - 1] = playerChar; 
                done = true; 
                break; 
            }
        }
        printBoard(board, rows, cols);
        if(done == false){
            cout << "That column is full, please select another one!" <<endl;
        }
    }while(done == false); 

}

int checkBoard(char** board, int rows, int cols, int gameOver, int playerChar){
    int maxCols = cols; 
    int maxRows = rows; 
    //horizontal 
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(board[i][j] == playerChar &&  j + 3 < maxCols){
                if(board[i][j + 1] == playerChar && board[i][j + 2] == playerChar && board[i][j + 3] == playerChar){
                    gameOver = 1; //1 = win 
                    return gameOver; 
                }
            }
        }
    }
    //vertical 
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(board[i][j] == playerChar &&  i + 3 < maxRows){
                if(board[i + 1][j] == playerChar && board[i + 2][j] == playerChar && board[i + 3][j] == playerChar){
                    gameOver = 1; //1 = win 
                    return gameOver; 
                }
            }
        }
    }

    gameOver = diagonalCheck(board, rows, cols, gameOver, playerChar);
    gameOver = tieCheck(board, rows, cols, gameOver);

    return gameOver; 

}

int diagonalCheck(char** board, int rows, int cols, int gameOver, int playerChar){
    int maxCols = cols;
    int maxRows = rows;  
    //right diagonal 
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(board[i][j] == playerChar && i - 3 >= 0 && j + 3 < maxCols){
                if(board[i - 1][j + 1] == playerChar && board[i - 2][j + 2] == playerChar && board[i - 3][j + 3] == playerChar){
                    gameOver = 1; //1 = win 
                    return gameOver; 
                }
            }
        }
    }
    //left diagonal
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(board[i][j] == playerChar && i + 3 < maxRows && j + 3 < maxCols){
                if(board[i + 1][j + 1] == playerChar && board[i + 2][j + 2] == playerChar && board[i + 3][j + 3] == playerChar){
                    gameOver = 1; //1 = win 
                    return gameOver; 
                }
            }
        }
    }
    return gameOver; 
}

int tieCheck(char** board, int rows, int cols, int gameOver){
    int done = 0; 
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if(board[i][j] == 32){
                return gameOver;   
            }
        }
    }

    gameOver = 2; 
    return gameOver; 
   
}

void printEnd(int gameOver, string mssg){
    if(gameOver == 1){
       cout << mssg <<endl; 
    }
    else if(gameOver == 2){
        cout << "Tie! Game Over." <<endl; 
    }
}

void twoPlay(char** board, int rows, int cols){
    cout << "Welcome to Two Player Mode." << endl; 
    cout << "Player 1: O, Player 2: X" <<endl; 

    int gameOver = 0; 
    int playerChar = 0; 

    do{
        playerTurn(board, rows, cols, 79);
        gameOver = checkBoard(board, rows, cols, gameOver, 79); 
        if(gameOver == 1 || gameOver == 2){
            printEnd(gameOver, "Player 1 wins! Game Over."); 
            break; 
        }
        playerTurn(board, rows, cols, 88); 
        gameOver = checkBoard(board, rows, cols, gameOver, 88);
        printEnd(gameOver, "Player 2 wins! Game Over."); 
    }while(gameOver == 0);

}
 