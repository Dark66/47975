#ifndef LOAN_H
#define LOAN_H
#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <iomanip>

using namespace std;

///Declare Loan Class
class Loan
{
    ///Declare Public Functions
    public:
        Loan();
        void setMonthlypayment(float);
        void setTotalPay(float);
        void setTotalInterest(float);
        float getMonthlypayment()const;
        float getTotalPay()const;
        float getTotalInterest()const;
        float calcRate(float);

    ///Declare Private Variables
    private:
        float TotalInterest;
        float TotalPay;
        float MonthlyPayment;

};

#endif // LOAN_H
