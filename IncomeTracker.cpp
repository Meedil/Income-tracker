#include <iostream>

using namespace std;

double Wallet = 0;
struct Expense{
    string name;
    float price;

    Expense(string n = "", float p = 0){
        name = n;
        price = p;
        applyCharges();
    }
    void applyCharges(){
        Wallet -= price;
    }
    string to_string(){
        return "Name: " + name + "\nPrice: " + std::to_string(price) + "\n";
    }
};

Expense expenses[5000]; int num_of_expenses = 0;
Expense recurring_costs[100]; int num_of_costs = 0;

void prepTracker(){
    addRC("car fuel", 420);
    addRC("hosue rent", 69420);
    addRC("water", 100);
    addRC("electricity", 220);
    addRC("pet food", 200);
}

//TODO: Search for expense
//TODO: 

void addRC(string name, float price){
    recurring_costs[num_of_costs++] = Expense(name, price);
}

void mainMenu(){
    cout<<"Welcome to your income tracker"<<endl<<
        "Select an option: "<< endl <<
        "1. Manage expenses" << endl << 
        "2. Manage recurring costs" << endl <<
        "3. Manage income sources" << endl <<
        "4. View details" << endl <<
        "5. Exit" << endl;
    m:
        int choice;
        cin >> choice;
        switch(choice){
            case 1:
                // manageExpenses(); 
                break;
            case 2:
                // manageRC(); 
                break;
            case 3:
                // manageIncome(); 
                break;
            case 4:
                // details(); 
                break;
            case 5:
                exit(1);
            default:
                cout << "Please enter a valid choice" << endl; goto m;
        }
}


int main(){
    mainMenu();
    // expenses[0] = Expense("gas", 420);
    // cout << Wallet << endl;
    // expenses[0].applyCharges();
    // cout << Wallet;
}