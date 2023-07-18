using namespace std;

#include "Part.h"

Part::Part(const string& s) : name(s){
    flightHours = 0;
    installationDate = new Date();
}

Part::~Part(){
    delete installationDate;
}

string Part::getName() const { return name; }

void Part::addFlightHours(int h){
    flightHours += h;
}

void Part::install(Date& d){
    installationDate->setDate(d);
}




FH_Part::FH_Part(const string& s, int n) : Part(s), fh_inspect(n){}

FH_Part::~FH_Part(){}

bool FH_Part::inspection(Date){
    if (flightHours >= fh_inspect){
        return true;
    }
    return false;
}

//send to ostream
void FH_Part::print(ostream& out) const{
    out << "Part: " + name + "\nFlight hours: " + to_string(flightHours) + "\nInstallation Date: ";
    out << *installationDate;
    out << "Inspect every: " + to_string(fh_inspect) + " flight hours" << endl;
}






IT_Part::IT_Part(const string& s, int n) : Part(s), it_inspect(n){}

IT_Part::~IT_Part(){}

bool IT_Part::inspection(Date d){
    if (d.toDays() - installationDate->toDays() >= it_inspect){
        return true;
    }
    return false;
}

//send to ostream
void IT_Part::print(ostream& out) const{
    out << "Part: " + name + "\nFlight hours: " + to_string(flightHours) + "\nInstallation Date: ";
    out << *installationDate;
    out << "Inspect every: " + to_string(it_inspect) + " days installed" << endl;
}






FHIT_Part::FHIT_Part(const string& n, int fh, int it) : FH_Part(n, fh), IT_Part(n, it), Part(n){}

FHIT_Part::~FHIT_Part(){}

bool FHIT_Part::inspection(Date d){
    if (this->FH_Part::inspection(d) == true){
        return true;
    }

    if (this->IT_Part::inspection(d) == true){
        return true;
    }

    return false;
}

//send to ostream
void FHIT_Part::print(ostream& out) const{
    out << "Part: " + name + "\nFlight hours: " + to_string(flightHours) + "\nInstallation Date: ";
    out << *installationDate;
    out << "Inspect every: " + to_string(FH_Part::fh_inspect) + " flight hours" << endl;
    out << "Inspect every: " + to_string(IT_Part::it_inspect) + " days installed" << endl;
}

ostream& operator<<(ostream& out, const Part& part){
    part.print(out);
    return out;
}