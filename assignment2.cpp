/**********************************************************
 ** Program: assignment2.cpp
 ** Author: Ragini Dindukurthi
 ** Date: 1/26/21
 ** Description: A Blackjack/TwentyOne with 1-4 Players
 ** Input: number of players, bank amount, bets
 ** Output: dealer/game statements
*********************************************************/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

int turns(int, int);
/**********************************************************
 ** Function: turns
 ** Description: executes each player's turn, including
 ** bets and drawing more cards. 
 ** Parameters: playerCount, bankn
 ** Pre-conditions: game set up must be complete
 ** with bank account information and player count
 ** Post-conditions: player and dealer's turns complete,
 ** bank amount updated based on outcome of game
**********************************************************/

int dealerTurn(int, int, int);
/**********************************************************
 ** Function: dealerTurn
 ** Description: executes dealer's turn 
 ** Parameters: playerTotal, bank, bet
 ** Pre-conditions: player's turn must be complete,
 ** needs player's running total and bet 
 ** Post-conditions: player's and dealer's turn is complete, 
 ** ready to move to next player's turn
*********************************************************/

int main(){

	cout << "Welcome to TwentyOne!" << endl;
	cout << "1 means yes, 0 means no." << endl;

	int bank1 = 0; //each bank number corresponds with player number
	int bank2 = 0;
	int bank3 = 0;
	int bank4 = 0;

	int playerCount; //stores number of players
	int endGame;	 //controls playing game again
	
	cout << "How many players? (1-4): ";
	cin >> playerCount;

	while (playerCount != 1 && playerCount != 2 && playerCount != 3 && playerCount != 4){
		cout << "Error! Please enter a number between 1-4: ";
		cin >> playerCount;
	}

	for (int x = 1; x <= playerCount; x++){ // each iteration corresponds with player's bank
		int tempBank; // temp variable to hold bank amount of each player
		cout << "Player " << x << "'s Bank: ";
		cin >> tempBank;

		while (tempBank <= 0){
			cout << "Error! Please enter a number greater than 0: ";
			cin >> tempBank;
		}

		if (x == 1){
			bank1 = tempBank;
		}
		else if (x == 2){
			bank2 = tempBank;
		}
		else if (x == 3){
			bank3 = tempBank;
		}
		else if (x == 4){
			bank4 = tempBank;
		}
	}

	do { // bank values will be preserved if game is played again

		if (bank1 == 0 && bank2 == 0 && bank3 == 0 && bank4 == 0){
			cout << "All players have 0 in bank accounts! Game over!" << endl;
			break;
		}
		for (int x = 1; x <= playerCount; x++){ // each iteration coordinates with player's turn
			cout << "Player " << x << "'s Turn" << endl;

			if (x == 1){
				cout << "You have " << bank1 << " in your account." << endl;
				bank1 = turns(playerCount, bank1);
			}
			else if (x == 2){
				cout << "You have " << bank2 << " in your account." << endl;
				bank2 = turns(playerCount, bank2);
			}
			else if (x == 3){
				cout << "You have " << bank3 << " in your account." << endl;
				bank3 = turns(playerCount, bank3);
			}
			else if (x == 4){
				cout << "You have " << bank4 << " in your account." << endl;
				bank4 = turns(playerCount, bank4);
			}
		}

		cout << "Do you want to play again? (1, 0): ";
		cin >> endGame;

		while (endGame != 1 && endGame != 0){
			cout << "Error! Enter 1 or 0: ";
			cin >> endGame;
		}

	} while (endGame == true);

	cout << "Goodbye!" << endl;
	return 0;
}

int turns(int pC, int bank){

	int playerTotal = 0; //player's running total
	int draw; // controls drawing another card
	int newCard; // generates new card with rand
	int bet = 0; // stores player's bet amount 

	if (bank == 0){
		cout << "You have no money, turn skipped!" << endl;
		return 0;
	}
	else{
		cout << "Bet Amount: ";
		cin >> bet;

		while (bet <= 0 || bet > bank){
			if (bet <= 0){
				cout << "Error! Please enter a value greater than zero: ";
				cin >> bet;
			}
			else if (bet > bank){
				cout << "Your bank account has: " << bank << endl;
				cout << "Error! Please enter a value less than or equal to " << bank << ": ";
				cin >> bet;
			}
		}

		do{
			draw = -1;
			srand(time(NULL));
			newCard = rand() % 11 + 1;
			playerTotal = playerTotal + newCard;
			cout << "You drew a(n) " << newCard << "." << endl;
			cout << "Your running total is " << playerTotal << "." << endl;

			if (playerTotal > 21){// automatic game endings 
				cout << "Bust! You lose!" << endl;
				bank = bank - bet;
				cout << "Your bank amount is " << bank << "." << endl;
				break;
			}
			else if (playerTotal == 21){
				cout << "You win!" << endl;
				bank = bank + bet;
				cout << "Your bank amount is " << bank << "." << endl;
				break;
			}
			else{
				cout << "Would you like to draw again? (1 , 0): "; 
				cin >> draw;

				while (draw != 1 && draw != 0){
					cout << "Error! Please enter 1 or 0: ";
					cin >> draw;
				}
			}
		} while (draw == 1);
	}

	bank = dealerTurn(playerTotal, bank, bet); //executes dealer's turn
	return bank;
}

int dealerTurn(int playerTotal, int bank, int bet){

	int dealerTotal = 0; // dealer's running total
	int dealerCard = 0; // generates new card for dealer
	
	if (playerTotal > 21 || playerTotal == 21){ // allows dealer's turn to be skipped under these conditions
		return bank;
	}

	cout << "Dealer's Turn" << endl;
	
	while (true){

		srand(time(NULL));
		dealerCard = rand() % 11 + 1;
		dealerTotal = dealerCard + dealerTotal;
		cout << "Dealer drew a(n) " << dealerCard << "." << endl;
		cout << "Their running total is " << dealerTotal << "." << endl;

		if (dealerTotal == 21 || dealerTotal > playerTotal){// automatic game endings
			cout << "Dealer wins!" << endl;
			bank = bank - bet;
			cout << "Your bank amount is " << bank << "." << endl;
			break;
		}
		else if (dealerTotal > 21 || dealerTotal < playerTotal){
			cout << "Player wins!" << endl;
			bank = bank + bet;
			cout << "Your bank amount is " << bank << "." << endl;
			break;
		}
		else if (dealerTotal == playerTotal){
			cout << "Tie!" << endl;
			break;
		}
	}

	return bank;
}
