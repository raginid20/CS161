/******************************************************
 * Program: assignment1.cpp
 * Author: Ragini Dindukurthi
 * Date: 01/14/2021
 * Description: A text adventure game
 * Input: User selects inputs from options given
 * Output: Story statements to guide the user, decisions
 *****************************************************/

#include <iostream>
#include <cstdlib> // rand() 
#include <ctime> // for srand()

using namespace std; 

int main(){

	cout << "All options are listed in order." << endl;	
	cout << "A DMV Adventure!" << endl; // opening messages
	cout << "Welcome! Your mission should you choose to accept it, is to renew your license." << endl; 
	cout << "But this task is not as easy as it seems, there are many obstacles in your way!" << endl; 
	cout << "The bureaucratic delays at the DMV will frustrate you and may even break you." << endl; 
	cout << "Good luck!" << endl; 
	cout << endl;	

	cout << "You arrive at the DMV to renew your license on a sunny afternoon."<<endl;
	cout << "Unfortunately, this is rush hour and the building is packed." << endl;
	cout << "You take a number from the dispenser." << endl; 
	cout << "You are the 79th customer." << endl; 
	cout << endl;	
	
	char q1; 
	cout << "You are faced with an important decision already!" << endl; 
	cout << "Do you want to fill out forms or take a seat? (f,s): "; // input 1
	cout << endl;
	cin >> q1; 
	
	if (q1 == 'f'){ // path 1
	
		char q1_1;		
		cout << "When you're filling out forms, you spot an annoying colleague from work!" << endl;
		cout << "Will you disguise yourself with a fake mustache or approach him? (d , a): "; // input 2 
		cin >> q1_1;
		
		if (q1_1 == 'a'){
	
			cout << "Your colleague traps you in conversation and you fail to escape :(" << endl;
			cout << "The DMV closes in the meantime, and you fail to get your license renewed." << endl; 
			cout << "You go home and cry." << endl;
			cout << "Game over." << endl;
	
		}		

		else if (q1_1 == 'd'){			
	
			int  q1_2;
			cout << endl;
			cout << "Good choice! Your colleague doesn't recognize you and leaves." << endl; 
			cout << endl;
			cout << "But just when you thought you could rest easy, a mysterious man appears!"<< endl;
			cout << "'You must tell me your favorite number or you shall not pass!' he proclaims." << endl; 
			cout << "You are weirded out by the situation but you comply." << endl;
			cout << "Tell him your favorite number (1-10): "; // input 3 
			cin >> q1_2; 	
			q1_2 = q1_2 + 3; // adds 3 to favorite number 
	
			if (q1_2 >= 10){
	
				cout << "'You cannot pass!' the mysterious man shouts." << endl; 
				cout << "A clerk tells you to leave for causing a commotion." << endl; 
				cout << "You go home with your expired license :(" << endl;
				cout << "Game over." << endl;
	
			}
	
			else if (q1_2 <= 10){	
	
				bool  q1_3;
				cout << "'Your intelligence is ... adequate.' the man says." << endl; 
				cout << "You feel oddly insulted, but he lets you pass." << endl;
				cout << endl; 
				cout << "Your number is called! You've finally made it to the clerk." << endl; 
				cout << "But the clerk won't help you unless you pass this pop quiz!" << endl;
				cout << "The pop quiz asks you one question on basic chemistry." << endl; 
				cout << "Water has a pH of about 7. True or False? (1, 0): "; // input 4 
				cin >> q1_3;	
			
				if (q1_3 == false){
					
					cout << "You fail the quiz." << endl;
					cout << "The clerk is disappointed in your knowledge of middle school chemistry." << endl;
					cout << "Embarrassed, you go home." << endl; 
					cout << "Game over!" << endl;
			
				}				

				else if (q1_3 == true){

					cout << "You pass the quiz!" << endl; 
					cout << "The clerk renews your license!" << endl;
					cout << "Mission Success!" << endl; 

				} // end of path 1		
			}
		}						
	}	

	else if (q1 == 's'){ // path 2
		
		char q2; 
		cout << "You take a seat just as a salesman plops down next to you." << endl;
		cout << "He asks if you're satisfied with your current refrigerator." << endl; 
		cout << "What will you say?" << endl; 
		cout << "Tell him your father is the owner of a famous refrigerator company." << endl; 
		cout << "Give him your wallet and personal information." << endl; 
		cout << "(f, w): "; // input 5
		cin >> q2; 
		
		if (q2 == 'w'){

			cout << "Without your wallet or personal information, you can't renew your license!" << endl; 
			cout << "You regret your actions and go home for the day." << endl; 
			cout << "Mission fail :(" << endl; 
			cout << "Game over!" << endl; 

		}

		else if (q2 == 'f'){
			
			cout << "Dejected, the salesman moves to sit elsewhere." << endl; 
			cout << "Suddenly, a famous fortune teller appears!" << endl; 
			cout << "She asks you to flip a coin. Intrigued, you flip it." << endl;  	
			srand(time(NULL));	
			int coinflip = rand() % 2; // element of chance! 			

			if (coinflip == 1){

				cout << "She nods and says, 'Your fortune fares well today,'" << endl; 
				cout << "You will set out to accomplish a great feat today." << endl; 
				cout << "When it's your turn, cheers erupt." << endl; 
				cout << "Apparently you are the DMV's 1000th customer!" << endl; 
				cout << "You are given a fast pass for your next DMV visit." << endl; 
				cout << "Mission success! :)" << endl; 

			}

			else if(coinflip == 0){
				
				char q2_1; 
				cout << "'Today you will receive the gift of canine and a feathered foe.'" << endl; 
				cout << "'An assault from the sky and an assault from the ground.' she says ominously." << endl; 
				cout << "You are confused." << endl; 
				cout << "Will you go home or tempt your fate? (g, t): "; // input 6
				cin >> q2_1; 

				if(q2_1 == 'g'){

					cout << "You go home in fear and fail to renew your license." << endl; 
					cout << "Mission fail! :(" << endl; 
					cout << "Game over." << endl;

				}

				if (q2_1 == 't'){
				
					cout << "You get your license renewed." << endl; 
					cout << "But soon as you go outside you step in dog poop and a bird poops on you!" << endl; 
					cout << "Game over!" << endl; 
					
				} // end of path 2	
			}
		}
	}
}
