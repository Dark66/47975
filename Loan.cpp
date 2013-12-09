#include "Loan.h"
#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <iomanip>

using namespace std;

///Constructor
Loan::Loan()
{
}

///Rate Mutator
float Loan::calcRate(float R)
{
    float r=R*0.01/12;
    return r;
}

///Monthly Payment Mutator
void Loan::setMonthlypayment(float P)
{
    MonthlyPayment=P;
}

///Total Payment Mutator
void Loan::setTotalPay(float T)
{
    TotalPay=T;
}

///Total Interest Mutator
void Loan::setTotalInterest(float I)
{
    TotalInterest=I;
}
///Monthly Payment accessor
float Loan::getMonthlypayment()const
{
    return MonthlyPayment;
}

///Total Payment Accessor
float Loan::getTotalPay()const
{
    return TotalPay;
}

///Total Interest Accessor
float Loan::getTotalInterest()const
{
    return TotalInterest;
}
