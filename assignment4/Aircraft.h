#ifndef AIRCRAFT_H
#define AIRCRAFT_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Part.h"

using namespace std;

class Aircraft{

    friend ostream& operator<<(ostream&, const Aircraft&);

    public:
        Aircraft(const string&, const string&);
        ~Aircraft();

        string getRegistration() const;
        void install(Part*, Date&);
        void takeFlight(int hours);
        void inspectionReport(Date&, Array<Part*>&);
        void print(ostream&) const;

    private:
        string type;
        string registration;
        int flighthours;
        Array<Part*> parts;
};

#endif