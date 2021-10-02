/**********************************************************
 ** Program: assignment3.cpp
 ** Author: Ragini Dindukurthi
 ** Date: 2/10/21
 ** Description: Calculates total fee and
 ** reimbursement for a business trip 
 ** Input: user is asked about trip related fees 
 ** Output: questions, information about total and 
 ** reimbursement fee
*********************************************************/
#include <iostream> 
#include <cstdlib> 
#include <string> 
#include <cstring>

using namespace std;

void update_total(double&, double&, double, double);
/**********************************************************
 ** Function: update_total
 ** Description: updates the reimbursement fee and total 
 ** expenses as more information is gained  
 ** Parameters: total_expense, total_reimbursement, 
 ** expense_to_add, reimbursement_to_add
 ** Pre-conditions: expense and reimbursement to add 
 ** for the fee should be calculated 
 ** Post-conditions: total expense and total reimbursement 
 ** should be updated
 **********************************************************/

void meal_fee(int, int, int, double&, double&); 
/**********************************************************
 ** Function: meal_fee
 ** Description: calculates the meal fees   
 ** Parameters: days_of_trip, departure_time, arrival_time, 
 ** meal_expense, meal_reimbursement 
 ** Pre-conditions: departure and arrival time should be known
 ** Post-conditions: meal fees should be added to 
 ** total reimbursement and expenses
 **********************************************************/

void reimbursementCalc(double, int, double&, double&);
/**********************************************************
 ** Function: reimbursementCalc
 ** Description: calculates reimbursement fee for 
 ** each expense type
 ** Parameters: feeType, maxReimbursement, total_expense, 
 ** total_reimbursement  
 ** Pre-conditions: feeType must be a double variable, 
 ** maxReimbursement's argument should be the maximum possible reimbursement for feeType
 ** Post-conditions: total expense and reimbursement must be 
 ** updated with the calculated expense and reimbursement to add
 **********************************************************/

bool intErrorCheck(string);
/**********************************************************
 ** Function: intErrorCheck
 ** Description: handles errors for integer data types
 ** Parameters: input 
 ** Pre-conditions: input must contain data
 ** Post-conditions: tells whether mssg is a valid int
 **********************************************************/

bool floatErrorCheck(string); 
/**********************************************************
 ** Function: floatErrorCheck
 ** Description: handles errors for float data types
 ** Parameters: mssg 
 ** Pre-conditions: mssg must correspond to fee
 ** Post-conditions: tells whether mssg is a valid float
 **********************************************************/

int getInt(string);
/**********************************************************
 ** Function: getInt
 ** Description: gets an integer from user
 ** Parameters: mssg
 ** Pre-conditions: mssg must correspond to fee  
 ** Post-conditions: a valid integer is returned
 **********************************************************/

double getFloat(string);
/**********************************************************
 ** Function: getFloat
 ** Description: gets a float from user
 ** Parameters: mssg
 ** Pre-conditions: mssg must correspond to fee
 ** Post-conditions: a valid float is returned
 **********************************************************/

void repeat(string, int, int, double&, double&);
/**********************************************************
 ** Function: repeat
 ** Description: repeatedly asks user for fee 
 ** based on amount of days
 ** Parameters: mssg, days, maxReimbursement, &total_expense, 
 ** &total_reimbursement
 ** Pre-conditions: mssg must correspond to fee
 ** Post-conditions: total expense and reimbursement 
 ** must be updated with data collected
 **********************************************************/

double oneTimeErrorCheck(string);
/**********************************************************
 ** Function: oneTimeErrorCheck
 ** Description: checks for error for one time fees 
 ** (fees that only need to be asked to the user once)
 ** Parameters: mssg
 ** Pre-conditions: mssg must correspond to fee
 ** Post-conditions: a valid float is returned
 **********************************************************/

int boolErrorCheck(string);
/**********************************************************
 ** Function: boolErrorCheck
 ** Description: checks to see if input is equal to 1 or 0
 ** Parameters: mssg
 ** Pre-conditions: mssg must correspond to fee 
 ** Post-conditions: a 0 or 1 is returned
 **********************************************************/

void transportControl(int, int, double&, double&);
/**********************************************************
 ** Function: transportControl
 ** Description: asks user about taxi or rental car fees and 
 ** related transportation fees
 ** Parameters: transport, days, total_expense, total_reimbusement
 ** Pre-conditions: user's trip transportation must be known 
 ** Post-conditions: transportation fees are added to total 
 ** expense and reimbursment 
 **********************************************************/

void getTime(int days, double& total_expense, double& total_reimbursement);
/**********************************************************
 ** Function: getTime
 ** Description: asks user for arrival and departure time
 ** Parameters: days, total_expense, total_reimbusement
 ** Pre-conditions: days of trip must be known 
 ** Post-conditions: meal fee is calculated based on times
 **********************************************************/

void departureMeals(int days, int departTime, double& total_expense, double& total_reimbursement);
/**********************************************************
 ** Function: departureMeals
 ** Description: asks user about departure day meals (day 1)
 ** Parameters: days, departTime, total_expense, total_reimbusement
 ** Pre-conditions: departure time must be known 
 ** Post-conditions: meal fees for departure day are added to 
 ** total reimbursement and expense
 **********************************************************/

int hourErrorCheck(string mssg);
/**********************************************************
 ** Function: hourErrorCheck
 ** Description: checks if input is between 0-24 (inclusive)
 ** Parameters: mssg
 ** Pre-conditions: mssg must correspond to fee 
 ** Post-conditions: a valid int between 0-24 is returned
 **********************************************************/

void arrivalMeals(int days, int departTime, double& total_expense, double& total_reimbursement);
/**********************************************************
 ** Function: arrivalMeals
 ** Description: asks user about arrival day meals (last day)
 ** Pre-conditions: days, departTime, total_expense, total_reimbursement
 ** Post-conditions: meal fees for arrival day are added to 
 ** total reimbursement and expense
 **********************************************************/

void mealAsk(int y, double& total_expense, double& total_reimbursement);
/**********************************************************
 ** Function: mealAsk
 ** Description: asks user about one full meal day
 ** (breakfast, lunch, dinner)
 ** Pre-conditions: y, total_expense, total_reimbursement
 ** Post-conditions: meal expenses are error checked and
 ** added to total expense and total reimbursement
 **********************************************************/

bool finalCalculation(double total_expense, double total_reimbursement, bool control);
/**********************************************************
 ** Function: finalCalculation
 ** Description: prints out final total expense and total reimbursement
 ** Pre-conditions: total_expense, total_reimbursement, control
 ** Post-conditions: control is returned 
 **********************************************************/

int main(){

    bool control = true;
    do{
        double totalExpense = 0, totalReimbursement = 0; 
        int days = getInt("number of days of trip");

        if(days > 1){
            cout << "Enter the hotel fee for each night of trip." <<endl;
            repeat("hotel fee", days - 1, 90, totalExpense, totalReimbursement); //asks hotel fee for each night for the trip
        }
        
        double airfare = oneTimeErrorCheck("airfare fees"); //asks airfare fees 
        reimbursementCalc(airfare, airfare, totalExpense, totalReimbursement);  //calculates airfare reimbursement
        double seminar = oneTimeErrorCheck("seminar fees"); //seminar/conference fees 
        reimbursementCalc(seminar, seminar, totalExpense, totalReimbursement); //calculates airfare reimbursement
        int transport = boolErrorCheck("transport, taxi or rental car?(1, 0)"); //transportation fees
        transportControl(transport, days, totalExpense, totalReimbursement);
        getTime(days, totalExpense, totalReimbursement); 
        control = finalCalculation(totalExpense, totalReimbursement, control); // prints out final costs
        
    }while(control == true);
    cout << "Goodbye!" <<endl;
    return 0;
}

int getInt(string mssg){
    bool valid;
    string input;
    do{
        cout << "Enter " << mssg << ": "; 
        getline(cin, input); 
        valid = intErrorCheck(input); 

    }while(valid == false);
    return atoi(input.c_str());
}

bool intErrorCheck(string input){
    for(int x = 0; x < input.length(); x++){

        if(!(input[x] >= 48 && input[x] <= 57)){
            return false;
        }
    }
    return true;

}

double getFloat(string mssg, int x){
    bool valid = 0;
    string input;
    ++x;
    do{
        cout << "Enter " << mssg << " in $ for day " << x << ": ";
        getline(cin, input); 
        valid = floatErrorCheck(input);

    }while(valid == false);
    return atof(input.c_str());
}

bool floatErrorCheck(string input){
    int counter = 0;
    for(int x = 0; x < input.length(); x++){
        if(input[x] == '.'){
            counter += 1;
            if(counter > 1){
                return false;
            }
        }
        else if(!(input[x] >= 48 && input[x] <= 57)){
            return false;
        }
    }
    return true;
}

void repeat(string mssg, int days, int maxReimbursement, double& total_expense, double& total_reimbursement){
    double fee = 0;
    for(int x = 0; x < days; x++){
        fee = getFloat(mssg, x); //error check input 
        reimbursementCalc(fee, maxReimbursement, total_expense, total_reimbursement); //calculate reimbursement and expense to add to totals
    }
}

void reimbursementCalc(double feeType, int maxReimbursement, double& total_expense, double& total_reimbursement){
    if(feeType < maxReimbursement){ //check to see if input exceeds than the max reimbursement allowed
        update_total(total_expense, total_reimbursement, feeType, feeType); //if true, then feeType becomes the reimbursement to add
    }
    else{ //otherwise, the max reimbursement is the reimbursement to add to the total
        update_total(total_expense, total_reimbursement, feeType, maxReimbursement); 
    }

}

void update_total(double& total_expense, double& total_reimbursement, double expense_to_add, double reimbursement_to_add){
    total_expense = expense_to_add + total_expense; 
    total_reimbursement = reimbursement_to_add + total_reimbursement; 
}

double oneTimeErrorCheck(string mssg){
    bool valid = 0;
    string input;
    do{
        cout << "Enter " << mssg << " in $: "; //this is for fees that don't repeat 
        getline(cin, input); 
        valid = floatErrorCheck(input);

    }while(valid == false);
    return atof(input.c_str());
}

int boolErrorCheck(string mssg){
    bool valid = false;
    string input;
    do{
        cout << "Enter " << mssg << ": "; 
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


int hourErrorCheck(string mssg){
    bool valid = false;
    int num = 0;
    string input;
    do{
        num = getInt(mssg);
        if(!(num >= 0 && num <= 24)){ //valid input should be 0-24 hours 
            valid = false; 
        }
        else{
            valid = true;
        }
        
    }while(valid == false);
    return num;
}


void transportControl(int transport, int days, double& total_expense, double& total_reimbursement){
    if(transport == 1){
        repeat("taxi fee", days, 10, total_expense, total_reimbursement);
    }
    else if(transport == 0){
        int rentalFee = oneTimeErrorCheck("total rental car fees including gas fee");
        update_total(total_expense, total_reimbursement, rentalFee, rentalFee);
        repeat("parking fee", days, 6, total_expense, total_reimbursement); //ask about parking fee for each day of trip 
    }
        
}

void getTime(int days, double& total_expense, double& total_reimbursement){
    int departTime = hourErrorCheck("departure hour (in 24 hour format)");
    int arriveTime = hourErrorCheck("arrival hour (in 24 hour format)");
    meal_fee(days, departTime, arriveTime, total_expense, total_reimbursement); //call meal fee to ask about all the meals of trip
}

void departureMeals(int days, int departTime, double& total_expense, double& total_reimbursement){
    if(departTime <= 7){ //based on the departure time, different meals are asked 
        mealAsk(0, total_expense, total_reimbursement);
    }
    else if(departTime > 7 && departTime <= 12){
        cout << "Your breakfast is not allowed for reimbursement on day 1." <<endl;
        double lunch = getFloat("lunch fee", 0);
        reimbursementCalc(lunch, 12, total_expense, total_reimbursement);
        double dinner = getFloat("dinner fee", 0); 
        reimbursementCalc(dinner, 16, total_expense, total_reimbursement);
    }
    else if(departTime > 12 && departTime <= 18){
        cout << "Your breakfast and lunch are not allowed for reimbursement on day 1." <<endl;
        double dinner = getFloat("dinner fee", 0); 
        reimbursementCalc(dinner, 16, total_expense, total_reimbursement);
    }
    else if(departTime > 18){
        cout << "None of your meals are allowed for reimbursement on day 1." <<endl;
    }

}

void arrivalMeals(int days, int arriveTime, double& total_expense, double& total_reimbursement){
    if(arriveTime <= 8){
        cout << "None of your meals are allowed for reimbursement on day " << days <<endl;
    }
    else if(arriveTime > 8 && arriveTime <= 13){
        double breakfast = getFloat("breakfast fee", days - 1);
        reimbursementCalc(breakfast, 9, total_expense, total_reimbursement); 
        cout << "Your lunch and dinner are not allowed for reimbursement on day "<< days <<endl;
    }
    else if(arriveTime > 13 && arriveTime <= 19){
        double breakfast = getFloat("breakfast fee", days - 1);
        reimbursementCalc(breakfast, 9, total_expense, total_reimbursement); 
        double lunch = getFloat("lunch fee", days - 1);
        reimbursementCalc(lunch, 12, total_expense, total_reimbursement);
        cout << "Your dinner is not allowed for reimbursement on day " << days << endl;
    }
    else if(arriveTime > 19 && arriveTime <= 24){
        mealAsk(days - 1, total_expense, total_reimbursement);
    }
}

void mealAsk(int y, double& total_expense, double& total_reimbursement){
    double breakfast = getFloat("breakfast fee", y);
    reimbursementCalc(breakfast, 9, total_expense, total_reimbursement); 
    double lunch = getFloat("lunch fee", y);
    reimbursementCalc(lunch, 12, total_expense, total_reimbursement);
    double dinner = getFloat("dinner fee", y); 
    reimbursementCalc(dinner, 16, total_expense, total_reimbursement);

}

void meal_fee(int days_of_trip, int departure_time, int arrival_time, double &meal_expense, double &meal_reimbursement){
    departureMeals(days_of_trip, departure_time, meal_expense, meal_reimbursement); 
    if(days_of_trip > 1){ //only if days of trip is greater than 1, then ask about the rest of meals for those days 
        for( int x = 0; x < days_of_trip - 2; x++){
            mealAsk(x+1, meal_expense, meal_reimbursement);
        }
        arrivalMeals(days_of_trip, arrival_time, meal_expense, meal_reimbursement);
    }
   
}

bool finalCalculation(double total_expense, double total_reimbursement, bool control){
    double excess = total_expense - total_reimbursement; 
    cout << "Your total expense is: " << total_expense << "." <<endl; 
    cout << "Your total reimbursement is: " << total_reimbursement << "." <<endl; 
    cout << "You must pay: " << excess << "." <<endl; 
    cout <<endl; 
    cout << "Would you like to play again? Yes, No (1, 0)" << endl;
    control = boolErrorCheck("here"); 
    return control;

}