
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>

using namespace std;

///Global constants
///Max string length
const short STRING_SIZE=16;

///New cost entries
const short COL=2;

///Name Length
const short SIZE = 24;

///Pay Structure
struct Pay
{
    char name[SIZE];
    int hours;
    float rate,
          expense=0,
          income=0,
          netpay=0,
          pay,
          total=0;

};


///Enter Name
char *enterName (char* ,short l);
///Displays Menu
void menu();Synthesizer
///Runs program
void default_function();
///Calculates Total pay
float totalpay(float &refPay);
///Calculates Net pay
float net(float t,float e);
///Enter Starting Expense values
void startingValues(char array[][STRING_SIZE],float cost[][COL],short ne);

///Starting Function [Main]
int main()
{

    ///Main Running function
    char choice;
    do{
         ///Decide wether you want to run this progam
        cout << "Do you want to run this program? (y/n)";
        cout << endl;
        cin  >> choice;

        choice = tolower(choice);

        switch(choice)
        {
            //continues the program the Program
            case'y': menu();
                     break;
            //Exits The Program
            case'n': cout << "Exit Stage Left! No Right! Launched!!!";
                     cout << endl;
                     break;
            //Come again another day
            default: cout << "Decide! Ok... No";
                     cout << endl;
        }
    } while(choice == 'y');

    return EXIT_SUCCESS;
}

void menu()
{
    for(;;)
    {
        ///Decide on your choice
        int choice;

        cout << "What would you like to do?";
        cout << endl;

        cout << "1. Calculate Budget";
        cout << endl;

        cout << "2. Exit";
        cout << endl;

        cin >> choice;

        switch (choice)
        {
            case 1: default_function();
                    break;

            default: break;

            case 2: return;
        }
    }
}

void default_function()
{

    //Declare and Initalize variables

    float regpay      = 0;
    float otrate      = 0;
    float otpay       = 0;
    float dtrate      = 0;
    float dtpay       = 0;
    float otherincome = 0;
    float temp        = 0;
    float total       = 0.0f;

    short hours   = 0;
    short othours = 0;
    short dthours = 0;
    int size = 0;
    char decision = 'y';

    ///Enter the amount off customers
    cout<< "How many customers are there: ";
    cin>>size;
    Pay customer[size];

    for(int i=0; i<size; i++)
    {
        char *p = customer[i].name;
        enterName (p,SIZE);

    ///Enter data needed to calculate the salary

        cout << "Please enter hours the hours you worked this week ";
        cin >> customer[i].hours;

        cout << "Please enter your hourly pay rate $";
        cin >> customer[i].rate;

        cout << setprecision(2) << fixed << showpoint;

    ///Calculate the salary

        if (customer[i].hours >= 0 && customer[i].hours <= 40)
        {
            //Calculate a normal work week
            customer[i].pay = customer[i].rate * customer[i].hours;
            cout << "pay $";
            cout << customer[i].pay;
            cout << endl;

            customer[i].total = totalpay(customer[i].pay);
            cout << "total pay $";
            cout << customer[i].total;
            cout << endl;
        }
        else if (customer[i].hours <= 60)
        {
            //Calculate the work week with Overtime
            othours =  customer[i].hours-40;
            hours   -= othours;
            otrate  =  customer[i].rate * 1.5;
            otpay   =  otrate * othours;
            regpay  =  customer[i].rate * customer[i].hours;
            customer[i].pay =  regpay + otpay;

            cout << "pay $";
            cout << customer[i].pay;
            cout << endl;

            customer[i].total = totalpay(customer[i].pay);
            cout << "total pay $";
            cout << customer[i].total;
            cout << endl;
        }
        else if (customer[i].hours > 60 && customer[i].hours <= 168)
        {
        //Calculte the work week with Overtime and Double time
            othours = customer[i].hours-40;
            dthours = othours-20;
            hours   -= othours;
            othours -=dthours;
            otrate  = customer[i].rate * 1.5;
            dtrate  = customer[i].rate * 2;
            otpay   = otrate * othours;
            dtpay   = dtrate * dthours;
            regpay  = customer[i].rate * customer[i].hours;
            customer[i].pay = regpay + otpay+ dtpay;

            cout << "pay $";
            cout << customer[i].pay;
            cout << endl;

            customer[i].total = totalpay(customer[i].pay);
            cout << "total pay $";
            cout << customer[i].total;
            cout << endl;
        }
        else
        {
        //Start again
            cout << " You either don't work or your a lazy person.";
            cout << endl;
        }

    ///Calculate other incomes

        cout << "Please enter income from SSI or pession.";
        cout << endl;

        cin >> temp;

    //Validation
        while (temp<0)
        {
        //Start again
            cout << "Enter an amount 0 or greater.";
            cout << endl;
            cin >> temp;
        }

        otherincome += temp;
        cout << "Please enter income from stocks.";
        cout << endl;
        cin >> temp;

    //Validation loop
        while (temp<0)
        {
        //Start again
            cout << "Enter an amount 0 or greater.";
            cout << endl;
            cin >> temp;
        }

        otherincome += temp;
        cout << "Other Income $";
        cout << otherincome;
        cout << endl;

        customer[i].income = customer[i].total + otherincome;
        cout << "Total Income $";
        cout << customer[i].income;
        cout << endl;

    ///Declare the names of expenses

        const short NUM_EXPENSES=7;
        char Expenses[NUM_EXPENSES][STRING_SIZE] =
        {
            "Rent/Morgage   ",
            "Groceries      ",
            "Phone          ",
            "Satallite/Cable",
            "Gas            ",
            "Car            ",
            "Utilites       "
        };
        float cost[NUM_EXPENSES][COL];

        startingValues(Expenses,cost,NUM_EXPENSES);

    ///Enter what your honest monthly pay this month

        cout << "Enter the amount you paid.";
        cout << endl;
        cout << "Expense\t\t\tCost";
        cout << endl;
        cout << "----------------------------";
        cout << endl;

        for(short j=0; j<NUM_EXPENSES; j++)
        {
            cout<<Expenses[j];
            cout<<"\t\t";
            cin>>cost[j][1];
            customer[i].expense += cost[j][1];
        }

        ///Calculate the expenses

        cout << "You expenses this month were $";
        cout << customer[i].expense;
        cout << endl;

        customer[i].netpay = net(customer[i].income, customer[i].expense);
        cout << customer[i].name;
        cout << " your Net Income is $";
        cout << customer[i].netpay;
        cout << " this month";
        cout << endl;
        customer[i].expense = 0;
        customer[i].netpay = 0;

    ///Calculate next months Budget
        cout << "Your next months budget should look like this:";
        cout << endl;
        cout << "Expense\t\t\tCost";
        cout << endl;
        cout << "----------------------------";
        cout << endl;
        for(short j=0; j<NUM_EXPENSES; j++)
        {
            cost[j][0]=(cost[j][0]+cost[j][1])/2;
            cout << Expenses[j];
            cout << "\t\t";
            cout << cost[j][0];
            cout << endl;
            customer[i].expense+=cost[j][0];
        }

        ///Calculate the following months expected Net Income
        customer[i].netpay = net(customer[i].income,customer[i].expense);
        cout << customer[i].name;
        cout << " your Net Income might be $";
        cout << customer[i].netpay;
        cout << " next month";
        cout << endl;

    }
}
char *enterName (char* array,short l)
{
    ///Enter your first name please

    cout << "Name: ";
    cin  >> array;
    return array;
}

void startingValues(char array[][STRING_SIZE],float cost[][COL],short ne)
{
    ///Enter your predicted estimates of this months expenses

    cout << "Enter the amount you expected to pay:";
    cout << endl;
    cout << "Expense\t\t\tCost";
    cout << endl;
    cout << "----------------------------";
    cout << endl;

    for(short i=0; i<ne; i++)
    {
        cout<<array[i];
        cout<<"\t\t";
        cin>>cost[i][0];
    }
}

float totalpay(float &ref)
{
    ///Calculate the salary for how many weeks

    short weeks;
    float total=0.0f;

    cout << "In how many weeks did you earn this? ";
    cout << endl;
    cin >> weeks;

    for (short week = 1; week <= weeks; week++)
    {
        total += ref;
    }

    return total;
}

float net(float t, float e)///Declare Public Functions
{
    ///Calculates The Net Income
    float n;
    n = t - e;
    return n;
}
