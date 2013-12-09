#ifndef PAYCHECK_H
#define PAYCHECK_H

#include <iostream>
#include <cstdlib>

using namespace std;

///Declare Class Paycheck
class Paycheck
{
    ///Declare Private Variables
    private:

        int hours;
        float rate;
    ///Declare Public Functions
    public:
        Paycheck(float,int);
        void setRate(float);
        void setHours(int);
        float getRate(float);
        float getPay()const;
        int getHours(int);
        float getPaywOT(float,int);
        float getpaywDT(float,int);


};
#endif // PAYCHECK_H
