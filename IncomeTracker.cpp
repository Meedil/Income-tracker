#include <iostream>

using namespace std;

void prepTracker();
void mainMenu();
    void manageExpenses();
        void listExpenses();
        void promptAddExpense();
            void addExpense(string name, float price);
        void promptRemoveExpense();
            int locateExpense(string name);
            void removeExpense(int index);

        void promptEditExpense();
            void editExpense();
    void manageRC(); //Manage repeated costs
        void listRecurringCosts(); 
        void promptAddRC();
            void addRC(string name, float price);
        void promptRemoveRC();
        void promptEditRC();
            void editRC();
    void manageIS();

double Wallet = 0;
struct Expense{
    string name;
    float price;

    Expense(string n = "", float p = 0){ //Constructor function
        name = n;
        price = p;
        applyCharges();
    }
    void applyCharges(){
        Wallet -= price;
    }
    void print(){
        cout << "Name: " + name + "\nPrice: " << price << endl << "------------------------------"<<endl;
    }
};

struct IncomeSource{
    string name; float size; 
    float rate; //Number of days between recieving money

    IncomeSource(string n = "", float val = 0, float r = 0){
        name = n; 
        size = val;
        rate = r;
    }

    void print(){
        cout << "Income Source: " + name + "\nProvides " << size << " every " << rate << " days" << endl;
    }
};

Expense expenses[5000]; int num_of_expenses = 0;
Expense recurring_costs[100]; int num_of_costs = 0;

void prepTracker(){
    addExpense("School", 42069);
    addExpense("Laptop", 4200);
    addRC("car fuel", 420);
    addRC("hosue rent", 69420);
    addRC("water", 100);
    addRC("electricity", 220);
    addRC("pet food", 200);
}

//TODO: Search for expense
//TODO: Remove expense

void addExpense(string name, float price){ //Addsd an expense to the expenses array
    // cout<<"number of expenses was: " << num_of_expenses;
    expenses[num_of_expenses++] = Expense(name, price);
    // cout<<"number of expenses became: " << num_of_expenses;
}

void addRC(string name, float price){ //Adds a repeating cost to the repeating_costs array
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
                manageExpenses(); 
                break;
            case 2:
                //manageRC(); 
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

void manageExpenses(){
    bool keepgoing = true;
    while(keepgoing){
        cout << "Select an option: " << endl <<
        "\t1.View all expenses" << endl <<
        "\t2.Add Expense" << endl << 
        "\t3.Remove Expense" << endl <<
        "\t4.Edit An Expense"<<endl <<
        "\t5.Go Back" << endl;
        int option; 
        m:
        cin >> option;
        switch(option){
            case 1:
                listExpenses(); break;
            case 2:
                promptAddExpense(); break;
            case 3:
                promptRemoveExpense(); break;
            case 4:
                // promptEditExpense(); break;
            case 5: 
                keepgoing = false; break;
            defalut:
                cout<<"Please enter a valid choice\n"; goto m;
        }
    }
}

void listExpenses(){
    if(!num_of_expenses){ cout << "There are currently no expenses\n"; return;}
    for(int i = 0 ; i < num_of_expenses; i++){
        cout<<i+1<<". "; expenses[i].print();
    }
    system("pause");
}

void promptAddExpense(){
    string name; float price; char yn;
    do{
        cout << "Enter expense name: ";
        cin>>name;
        cout << "Enter expense value: ";
        cin>>price;
        addExpense(name, price);
        cout<<endl<<"Expense added successfully"<< endl <<
        "do you want to add another expense? ";
        cin>>yn;
    }while(yn == 'y' || yn == 'Y');
}

int locateExpense(string name )
{
    int index = -1;
    for (int i = 0;  i<num_of_expenses; i++ )
    {
        if (expenses[i].name == name)
            index = i;
    }
    return index;
}



void removeExpense(int index)
{
    for (int i =index; i<num_of_expenses;i++)
    {
        expenses[i] = expenses[i+1];
    }
   expenses[--num_of_expenses] = Expense("", 0);
}

void promptRemoveExpense()
{
    string expenseName;
    cout << "Enter the name of the expense you want to remove: ";
    cin >> expenseName;
    int index = locateExpense(expenseName);
    if(index > -1)
    {
        removeExpense(index);
    }
    else
    {
        cout << "Expense not found\n";
    }
}

int main(){
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
//fadi has worked on this project 3alashan ma7adesh y2oo l7aga 8eor kda
    prepTracker();
    mainMenu();
    // expenses[0] = Expense("gas", 420);
    // cout << Wallet << endl;
    // expenses[0].applyCharges();
    // cout << Wallet;
    
}
