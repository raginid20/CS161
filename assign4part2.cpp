/**********************************************************
 ** Program: assignment4part2.cpp
 ** Author: Ragini Dindukurthi
 ** Date: 2/23/21
 ** Description: generates a fractal 
 ** Input: number of stars and columns 
 ** Output: a fractal 
*********************************************************/
#include <iostream> 

using namespace std;

void pattern(int, int);
/**********************************************************
 ** Function: pattern
 ** Description: draws a fractal using recursive
 ** Parameters: stars, cols
 ** Pre-conditions: an odd integer for amount of stars and 
 ** a nonnegative integer for amount of cols
 ** Post-conditions: a fractal should be printed
 **********************************************************/

int main(){
    
    int stars = 0;
    int cols = 0;
    
    cout << "Enter the number of stars: "; 
    cin >> stars; 
    cout << "Enter the number of columns: ";
    cin >> cols; 
    
    pattern(stars, cols);

    return 0; 
}

void pattern(int stars, int cols){
    if(stars > 0){
        
        pattern(stars - 2, cols+2);

        for(int i = 0; i < cols; i++){
            cout << " ";
        }
        for(int i = 0; i < stars; i++){
            cout << "* ";
        }
        cout << endl;

        pattern(stars - 2, cols+2);
        
    }

}

