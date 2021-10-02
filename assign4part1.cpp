/**********************************************************
 ** Program: assignment4part2.cpp
 ** Author: Ragini Dindukurthi
 ** Date: 2/23/21
 ** Description: text surgeon with three operations
 ** Input: user strings and operation related user information
 ** Output: modified strings 
*********************************************************/
#include <iostream>  
#include <cstring> 
#include <cstdlib>
#include <string> 

using namespace std; 

//LS: Letter Swap 
//FS: Flip String 
//WF: Word Frequency 

int select();
/**********************************************************
 ** Function: select
 ** Description: prints available operations   
 ** Parameters: none 
 ** Pre-conditions: a string/paragraph must be entered
 ** Post-conditions: must return user's choice
 **********************************************************/
int selectError();
/**********************************************************
 ** Function: selectError
 ** Description: error handling for operation selection   
 ** Parameters: none 
 ** Pre-conditions: user must know available operations
 ** Post-conditions: an error checked input is returned
 **********************************************************/
void control(int, char*);
/**********************************************************
 ** Function: control
 ** Description: executes user's selected operation 
 ** Parameters: choice, oString 
 ** Pre-conditions: user's choice is known
 ** Post-conditions: users selected operation will execute
 **********************************************************/
void getLS(char*);
/**********************************************************
 ** Function: getLS
 ** Description: gets info needed for letter swap, creates
 ** modified string    
 ** Parameters: oString
 ** Pre-conditions: need user's string/paragraph
 ** Post-conditions: letter to swap and replacement letter is known
 **********************************************************/
void LS(char, char, char*);
/**********************************************************
 ** Function: LS
 ** Description: swaps letter in user's string   
 ** Parameters: swapLetter, replaceLetter, oString
 ** Pre-conditions: need to know replacement letter and
 ** letter to be swapped
 ** Post-conditions: modified string is printed
 **********************************************************/
void FS(char*, char*&);
/**********************************************************
 ** Function: FS
 ** Description: flips user's string 
 ** Parameters: oString, flipString
 ** Pre-conditions: need a cstring pointer
 ** Post-conditions: flipped string is printed 
 **********************************************************/
void getWF(char*); 
/**********************************************************
 ** Function: getWF
 ** Description: asks user for n words 
 ** Parameters: oString
 ** Pre-conditions: selected word frequency option
 ** Post-conditions: cleaned words are put into c++ string
 ** array
 **********************************************************/
int WFgetError();
/**********************************************************
 ** Function: WFgetError
 ** Description: error handling + asks user how many words
 ** they want to search for
 ** Parameters: none
 ** Pre-conditions: selected word frequency option
 ** Post-conditions: return valid n 
 **********************************************************/
string cleanString(string);
/**********************************************************
 ** Function: cleanString
 ** Description: purges string of special characters
 ** Parameters: temp
 ** Pre-conditions: user enters word 
 ** Post-conditions: returns purged words 
 **********************************************************/
bool WFerrorCheck(string);
/**********************************************************
 ** Function: WFerrorCheck
 ** Description: error handling part 2
 ** Parameters: input
 ** Pre-conditions: user enters amount of words they want 
 ** to search for
 ** Post-conditions: returns valid n
 **********************************************************/ 
void runWF(int, string*, char*);
/**********************************************************
 ** Function: runWF
 ** Description: loops calcWF function n times (for each word)
 ** Parameters: n, words (array), oString
 ** Pre-conditions: purged words must be in dynamic c++ string array 
 ** Post-conditions: word frequency of each word printed 
 **********************************************************/
int calcWF(string, char*);
/**********************************************************
 ** Function: calcWF
 ** Description: compares and check for equivalence of words
 ** Parameters: words element, oString
 ** Pre-conditions: each word must be in c++ string array
 ** Post-conditions: word frequency is printed
 **********************************************************/
int end(int); 
/**********************************************************
 ** Function: end
 ** Description: controls do/while loop that allows user to play again
 ** Parameters: again
 ** Pre-conditions: user must have selected and executed operation
 ** Post-conditions: plays again or quits program 
 **********************************************************/
int getWordLength(string);
/**********************************************************
 ** Function: getWordLength
 ** Description: gets the length of each word
 ** Parameters: input 
 ** Pre-conditions: input must be cleaned
 ** Post-conditions: returns length of word 
 **********************************************************/
int calcSingle(string, char*);
/**********************************************************
 ** Function: calcSingle
 ** Description: searches for single letter words
 ** Parameters: word, oString 
 ** Pre-conditions: wordLength should be 1
 ** Post-conditions: returns frequency of single letter word
 **********************************************************/
int boolErrorCheck();
/**********************************************************
 ** Function: boolErrorCheck
 ** Description: error checks end function input
 ** Parameters: word, oString 
 ** Pre-conditions: should have executed one operation
 ** Post-conditions: returns valid input
 **********************************************************/
int compareChar(string word, int wPosition, char* oString, int oPosition);
/**********************************************************
 ** Function: compareChar
 ** Description: compares each character of oString with word character
 ** Parameters: word, wPosition, oString, oPosition
 ** Pre-conditions: words should all be greater than 1
 ** Post-conditions: equivalence should be returned
 **********************************************************/

int main(){
    int again = 1; 
    cout << "Welcome to Text Surgeon!" <<endl; 
    char oString[1024]; 
    cout << "Enter a string/paragraph: "; 
    cin.getline(oString, 1023, '\n');
    
    if (cin.fail()) {
        cin.ignore(1023,'\n'); 
        cin.clear(); 
    }

    do{
        int choice = select(); 
        control(choice, oString); 
        again = end(again);

    }while(again == 1);
    cout << "Goodbye!" <<endl; 

    return 0;
}

int select(){ 
    cout << "Select an operation from the list below. " <<endl; 
    cout << "1: Letter Swap"<< endl; 
    cout << "2: Flip the String" <<endl; 
    cout << "3: Word Frequency" <<endl;
    int choice = selectError();
    return choice;
}

int selectError(){
    bool valid = false;
    string input;

    do{
        cout << "Enter your selection number: ";;
        getline(cin, input); 
        if(input.length() > 1){ //the valid input should be 1 character
            valid = false;
        }
        else if(!(input[0] == '1' || input[0] == '2' || input[0] == '3')){  
            valid = false;
        }
        else{
            valid = true;
        }
        
    }while(valid == false);
    return atoi(input.c_str());
}

void control(int choice, char* oString){
    if(choice == 1){
        getLS(oString);
    }
    else if(choice == 2){
        char* flipString; 
        FS(oString, flipString);
    }
    else if(choice == 3){
       getWF(oString); 
    }
    cin.clear(); 
}

void getLS(char* oString){
    char swapLetter = 0; 
    char replaceLetter = 0; 
    cout << "This is your string: " << oString <<endl; 
    char modString[1024];
    modString[1023] = '\0'; 
    strcpy(modString, oString); 
    cout << "Enter the letter you want to swap: "; 
    cin >> swapLetter;
    cin.ignore(256, '\n');  
    cout << "Enter the replacement letter: "; 
    cin >> replaceLetter; 
    cin.ignore(256, '\n');
    LS(swapLetter, replaceLetter, modString);
}

void LS(char swapLetter, char replaceLetter, char* modString){
    char capreplaceLetter = replaceLetter - 32; //getting capital  of the replacement letter
    char capswapLetter = swapLetter - 32; //getting capital of swap letter

    for(int i = 0; i < strlen(modString); i++){
        if (modString[i] == swapLetter){
            modString[i] = replaceLetter; //swaps lowercase swapLetter
        }
        else if(modString[i] == capswapLetter){
            modString[i] = capreplaceLetter; //swaps uppercase swapLetter
        }
    }
    cout << "Here is your new string: " <<endl; 
    cout << modString <<endl; 
}

void FS(char* oString, char* &flipString){
    int size = strlen(oString);  
    flipString = new char[size + 1]; //creating a cstring on the heap 
    
    int x = 0;
    for(int i = size - 1; i >= 0; i--){
        flipString[x] = oString[i]; //assigning the last character of user's string as the first character of the flip string 
        x++;
    }

    flipString[size] = '\0';
    cout << "Here is your flipped string: " <<endl; 
    cout << flipString <<endl; 

    delete [] flipString; 
    flipString = NULL; 
}

int WFgetError(){
    bool valid = false;
    string input;

    do{//error checking and getting n (amount of words user wants to search for)
        cout << "Enter the amount of words you want to search for: "; 
        cin.clear(); 
        getline(cin, input); 
        valid = WFerrorCheck(input);
    }while(valid == false);
    return atoi(input.c_str());
}

bool WFerrorCheck(string input){
    int counter = 0;
    for(int x = 0; x < input.length(); x++){//error checking n

        if(!(input[x] >= 48 && input[x] <= 57)){
            return false;
        }
    }
    return true;
}

void getWF(char* oString){
    int n = WFgetError(); 
    string *words = new string[n+1]; //creating dynamic c++ string array to store words
    cin.clear(); 
    
    cout << "Enter the words you want to search for." <<endl; 
   
    string temp; 
    for(int i = 0; i < n; i++){ //loops n times to get all the words user wants to search for
        cout << "Word " << i + 1 << ": " ; 
        getline(cin, temp); 
        words[i] = cleanString(temp); //calling cleanString function 
	}

    runWF(n, words, oString);
    delete [] words; 
    words = NULL;  
}

string cleanString(string input){
    int i = 0; 
    int len = input.length();
    int position = 0;
    int x = 0;

    while(i < len){
        
        if((input[i] >= 32 && input[i] <= 64) || (input[i] >= 91 && input[i] <= 96) || (input[i] >= 123 && input[i] <= 126)){
            position = len - i; 
            x = i;  
            for(int j = 0; j < position; j++){
                input[x] = input[x+1]; 
                x++;
            }
            len = input.length(); 
        }
        else if(input[i] >= 65 && input[i] <= 90){
            input[i] = input[i] + 32; //turns any uppercase letters in the word to lowercase (case insensitive)
            i++; 
        }
        else{
            i++; 
        }
    }
    return input; 
}

void runWF(int n, string* words, char* oString){
    int freq = 0; 

    for(int i = 0; i < n; i++){//iterates based on n amount of words
        freq = calcWF(words[i], oString);
        cout << words[i] << ": " << freq <<endl;
    }
}

int getWordLength(string input){
    int count = 0; 
    for(int i = 0; i < input.length(); i++){
        if(input[i] >= 97 && input[i] <= 122){ //counts amount of letters in the word
            count++;
        }
    }
    return count; 
}

int calcWF(string word, char* oString){
    int position = 0;
    int counter = 0; 
    int found = 0; 
    int wordLen = getWordLength(word);
    char temp;

    if(wordLen == 1){
        return calcSingle(word, oString); //executes only if the word the user is searching for is one letter, like a or i
    }

    for(int i = 0; i < strlen(oString); i++){
        if(oString[i] >= 65 && oString[i] <= 90){
            temp = oString[i] + 32; //changing to lowercase 
        }
        else {
            temp = oString[i];
        }
        if(word[0] == temp){
            position = i;  
            found = 1; 
            for(int j = 0; j < wordLen; j++){
                found = compareChar(word, j, oString, position); //changing to lowercase
                if (found == 1){
                    position++;
                }
                else{
                    break;
                }
            }
            if(found == 1){
                counter++; 
            }
        }
    }
    return counter; 
}

int compareChar(string word, int wPosition, char* oString, int oPosition){
    char temp;

    if(oString[oPosition] >= 65 && oString[oPosition] <= 90){ // compares to lower case
        temp = oString[oPosition] + 32;
        if(word[wPosition] == temp){
            return 1;
        }
    }
    else{           
        if(word[wPosition] == oString[oPosition]){
            return 1;
        }
    }
    return 0;
}

int calcSingle(string word, char* oString){
    int position = strlen(oString);
    int counter = 0;
    char temp;     

    for(int i = 0; i < position; i++){
        if(oString[i] >= 65 && oString[i] <= 90){
            temp = oString[i] + 32; //changing to lowercase 
        }
        else {
            temp = oString[i];
        }
        if(word[0] == temp){
            if((oString[i+1] == ' ') && (i == 0)){//beginning
                counter++;
            }
            else if((oString[i-1] == ' ') && (oString[i+1] == ' ')){//middle
                counter++;
            }
            else if((oString[i-1] == ' ') && (i == position - 1)){ //last
                counter++;
            }
        }
    }
    return counter; 
}

int end(int again){
    
    again = boolErrorCheck();
    
    if(again == 1){
        return 1; 
    } 
    else if(again == 0){
        return 0; 
    }
}

int boolErrorCheck(){
    bool valid = false;
    string input;

    do{
        cout << "Play Again? (1, 0): ";
        getline(cin, input);

        if(input.length() > 1){ //the valid input should be 1 character
            valid = false;
        }
        else if(!(input[0] == '0' || input[0] == '1')){  
            valid = false;
        }
        else{
            valid = true;
        }
        
    }while(valid == false);
    return atoi(input.c_str());
}