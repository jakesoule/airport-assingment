#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>
#include <iostream>
#include "Aircraft.h"

using namespace std;

class Airline{

    public:
        Airline(const string&);
        ~Airline();

        void addAircraft(const string&, const string&);
        void addPart(const string&, int fh_inspect, int it_inspect);
        void takeFlight(const string&, int);
        void printAircraft() const;
        void printParts() const;
        void inspectionReport(const string&, Date&);
        bool install(const string&, const string&, Date&);


    private:
        string name;
        Array<Part*> parts;
        Array<Aircraft*> aircraft;

        Aircraft* getAircraft(const string&) const;
        Part* getPart(const string&) const;
};

#endif