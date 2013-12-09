#include "Paycheck.h"
#include <iostream>

using namespace std;

///Constructor
Paycheck::Paycheck(float r, int h)
: rate(r), hours(h)
{
}

///Rate Mutator
void Paycheck::setRate(float r)
{
    rate = r;
}

///Hours Mutator
void Paycheck::setHours(int h)
{
    hours = h;
}

///Pay Accessor
 float Paycheck::getPay()const
{
    return (rate * hours);
}

///Pay Overtime Accessor
float Paycheck::getPaywOT(float rate,int hours)
{
    int othours =  hours-40;
    hours   -= othours;
    float otrate  =  rate * 1.5;
    float otpay   =  otrate * othours;
    float regpay  =  rate * hours;
    return (regpay+otpay);
}

///Pay Doubletime Accessor
float Paycheck::getpaywDT(float rate,int hours)
{
    int othours = hours-40;
    int dthours = othours-20;
    hours   -= othours;
    othours -=dthours;
    float otrate  = rate * 1.5;
    float dtrate  = rate * 2;
    float otpay   = otrate * othours;
    float dtpay   = dtrate * dthours;
    float regpay  = rate * hours;
    return (regpay+otpay+dtpay);
}
