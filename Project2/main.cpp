/// Philip Calderon
/// CSC-17A - 47975
/// December 9, 2013

#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include "Paycheck.h"
#include "Loan.h"

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
          pay,
          netpay=0,
          total=0;

};


///Enter Name
char *enterName (char* ,short l);
///Display Menu
void menu();
///Run program
void Budget();
///Calculate Total pay
float totalpay(float &refPay);
///Calculate Net pay
float net(float t,float e);
///Enter Starting Expense values
void startingValues(char array[][STRING_SIZE],float cost[][COL],short ne);
/// Calculates the loans
void LoanCalculator();
/// Calculates the Saving interests
void SavingInterestCal();

///Starting Function [Main]
int main()
{
    ///Main Running function
    char choice;
    do{
        ///Decide if you want to run this progam
        cout << "Do you want to run this program?(y/n)";
        cout << endl;
        cin  >> choice;

        choice = tolower(choice);
        switch(choice)
        {
            ///Run Programm
            case'y': menu();
                     break;
            ///Exit
            case'n': cout << "Exit Stage Left! No Right! Launched!!!";
                     cout << endl;
                     break;
            //Fuck you I no work for you
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
        ///Decide you want to do what to do
        int choice;

        /// Menu
        cout << "What would you like to do?";
        cout << endl;

        ///Caculate The Budget
        cout << "1. Calculate Budget";
        cout << endl;

        ///Calculate The Loan Amounts
        cout << "2. Loan Calculator";
        cout << endl;

        ///Calculate The Savings over time
        cout << "3. Savings Calculator";
        cout << endl;

        ///Exit
        cout << "4. Exit";
        cout << endl;

        cin >> choice;

        ///Choice loop
        switch (choice)
        {
            case 1: Budget();
                    break;
            case 2: LoanCalculator();
                    break;

            case 3: SavingInterestCal();
                    break;
            default: break;

            case 4: return;
        }
    }
}

void Budget()
{

    ///Declare and Initalize
    float otherincome = 0;
    float temp        = 0;


    int size = 0;

    ///Enter the amount off customers
    cout<< "How many customers are there: ";
    cin>>size;
    Pay customer[size];

    for(int i=0; i<size; i++)
    {
        char *p = customer[i].name;
        enterName (p,SIZE);

        ///Enter data needed to calculate salary

        cout << "Please enter hours the hours you worked this week ";
        cin >> customer[i].hours;

        cout << "Please enter your hourly pay rate $";
        cin >> customer[i].rate;
        Paycheck pay(customer[i].rate,customer[i].hours);
        cout << setprecision(2) << fixed << showpoint;

        ///Calculate salary

        if (customer[i].hours >= 0 && customer[i].hours <= 40)
        {
            ///Calculate a Normal Work Week
            customer[i].pay = pay.getPay();
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
            /// Calculate Work Week with Overtime

            customer[i].pay = pay.getPaywOT(customer[i].rate,customer[i].hours);

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

            ///Calculte Work Week with Overtime and Double Time
            customer[i].pay = pay.getpaywDT(customer[i].rate,customer[i].hours);

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

            ///Start again
            cout << " You either don't work or your a lazy person.";
            cout << endl;
        }

        ///Calculate other income

        cout << "Please enter income from SSI or pention.";
        cout << endl;

        cin >> temp;

        ///Validation looop
        while (temp<0)
        {
            ///Start Again
            cout << "Enter an amount 0 or greater.";
            cout << endl;
            cin >> temp;
        }

        otherincome += temp;
        cout << "Please enter income from stocks.";
        cout << endl;
        cin >> temp;

        ///Validation loop
        while (temp<0)
        {
            ///Start again
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

        ///Declare names of all expenses

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

        ///Enter what your honest monthly pay was this month

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

        ///Calculate expenses

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

        ///Calculate next months budget
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

        ///Calculate next months expected Net income
        customer[i].netpay = net(customer[i].income,customer[i].expense);

        cout << customer[i].name;
        cout << " your Net Income might be $";
        cout << customer[i].netpay;
        cout << " next month";
        cout << endl;

    }
}

void LoanCalculator()
{
    ///Calculate Loan Ammounts

    ///Declare variables
    float P=0, r=0, C=0, E=0, F=0, T=0, I=0, R=0;
    int N=0;

    ///Get user input
    cout<<"Enter amount of loan"<<endl;
    cin>>C;
    cout<<"Enter the Total loan fees"<<endl;
    cin>>E;
    cout<<"Enter the Interest rate(%)"<<endl;
    cin>>R;
    cout<<"Enter the number of Pay Terms "<<endl;
    cin>>N;
    cout<<"Enter the closing fees"<<endl;
    cin>>F;
    Loan pay;

    ///Calculations
    r = pay.calcRate(R);
    P=(C+E)*r*pow((1+r),N)/(pow((1+r),N)-1);
    T=(P*N)+F;
    I=(P*N)-C-E;
    pay.setMonthlypayment(P);
    pay.setTotalInterest(I);
    pay.setTotalPay(T);

    ///Display Menu
    cout<<showpoint<<fixed<<setprecision(2);
    cout<<"Monthly Payment $";
    cout<<pay.getMonthlypayment();
    cout<<endl;
    cout<<"Total Payment $";
    cout<<pay.getTotalPay();
    cout<<endl;
    cout<<"Total Interest $";
    cout<<pay.getTotalInterest();
    cout<<endl;
}

void SavingInterestCal()
{
    ///Calculate Savings over time

    ///Declare variables
    float S;
    float R;

    int N;
    int T;

    ///Get user input
    cout<<"What is your starting Amount? ";
    cout<<endl;
    cin>>S;
    cout<<"What is the annual interest rate? ";
    cout<<endl;
    cin>>R;
    cout<<"What is the number of times in a year your interst is compouned? ";
    cout<<endl;
    cin>>N;
    cout<<"How many years do you plan to leave the money in your account? ";
    cout<<endl;
    cin>>T;

    ///Calculations
    Loan profit;
    float r= profit.calcRate(R);
    float V=S*pow((1+r/N),(N*T));

    ///Display Menu
    cout<<"Your original amount was $";
    cout<< S;
    cout<< " your new total after ";
    cout<< T;
    cout<< " years is $";
    cout<< V;
}
char *enterName (char* array,short l)
{
    ///Enter your first name
    cout << "Name:";
    cin  >> array;
    return array;
}
void startingValues(char array[][STRING_SIZE],float cost[][COL],short ne)
{
    ///Enter your predicted estimates of this months expenses

    cout << "Enter the amount you expected to pay.";
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
    ///Calculate salary for how many weeks

    short weeks;
    float total=0.0f;

    cout << "How many weeks did you earn this? ";
    cout << endl;
    cin >> weeks;

    for (short week = 1; week <= weeks; week++)
    {
        total += ref;
    }

    return total;
}

float net(float t, float e)
{
    ///Calculate Net income
    float n;
    n = t - e;
    return n;
}
