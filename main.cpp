// Jordan Steer-Furderer
// CIS 25
// This programs simulates spongebob and patrick making krabby patties. They make
// patties at the same rate but Patrick ruins 1 in 5 patties on average.
// This program calculates the total cost to produce 1000 GOOD patties. The final cost
// includes the cost of the patties that Patrick ruined.
//#include "pch.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

int totalPattiesPatrick() {
/*time_t t;
time (&t);
srand(t);*/
//srand(time(NULL));
    return 1 + (rand() % 625);
    }

float badPattiesPatrick(int totalPattiesPatrick) {

    float result;
    result = (totalPattiesPatrick * .2);
    return(result);
    }

int goodPattiesPatrick(int totalPattiesPatrick, float badPattiesPatrick) {

    float result;
    result = (totalPattiesPatrick - badPattiesPatrick);
    return (result);
    }

float totalPattiesSpongebob(int goodPattiesPatrick) {

    float result;
    result = (1000 - goodPattiesPatrick);
    return (result);
    }

float totalPattiesFinal(int goodPattiesPatrick, float badPattiesPatrick, float totalPattiesSpongebob) {

    float result;
    result = ((goodPattiesPatrick + badPattiesPatrick + totalPattiesSpongebob));
    return (result);
    }

int main() {
srand(time(0));
int index = 1;
int pattiesSum = 0;
do {

int randomNumberMax = totalPattiesPatrick();

cout << "If Patrick makes " << randomNumberMax << " patties total" << endl;

int outputPat;

outputPat = badPattiesPatrick(randomNumberMax);

cout << "then he ruins " << outputPat << " patties " << endl;

int goodPatties;

goodPatties = goodPattiesPatrick(randomNumberMax, outputPat);

cout << "and makes " << goodPatties << " good patties" << endl;

int pattiesSpongebob;

pattiesSpongebob = totalPattiesSpongebob(goodPatties);

cout << "and Spongebob makes " << pattiesSpongebob << " patties." << endl;

int totalPatties;

totalPatties = totalPattiesFinal(goodPatties, outputPat, pattiesSpongebob);

pattiesSum = pattiesSum + totalPatties;

index++;

cout << pattiesSum << " patties made after 50 trials" << endl;

cout << pattiesSum / 50 << " is the average number of patties" << endl;

cout << "required to complete the order after 50 trials" << endl;

cout << "$" << (pattiesSum / 10000) * 2.92 << " is the average cost to make " << pattiesSum / 10000 << " patties" << endl;

}

while (index <= 10000);

return 0;
}
