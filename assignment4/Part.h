#ifndef PART_H
#define PART_H

#include <string>
#include <iostream>
#include "Date.h"
using namespace std;

class Part{
    friend ostream& operator<<(ostream&, Part const&);

    public:
        Part(const string&);
        virtual ~Part();

        string getName() const;
        void addFlightHours(int);
        void install(Date&);

        virtual bool inspection(Date) = 0;
        virtual void print(ostream&) const = 0;

    protected:
        int flightHours;
        Date* installationDate;
        string name;

        
};

class FH_Part: virtual public Part {

    public:
        FH_Part(const string&, int);
        virtual ~FH_Part();

        virtual bool inspection(Date);

        void print(ostream&) const;

    protected:
        int fh_inspect;

};

class IT_Part: virtual public Part {

    public:
        IT_Part(const string&, int);
        virtual ~IT_Part();

        virtual bool inspection(Date);

        void print(ostream&) const;

    protected:
        int it_inspect;

};

class FHIT_Part: virtual public FH_Part, virtual public IT_Part {

    public:
        FHIT_Part(const string&, int, int);
        virtual ~FHIT_Part();

        virtual bool inspection(Date);

        void print(ostream&) const;

    private:
        int fh_inspect;
        int it_inspect;

};




#endif