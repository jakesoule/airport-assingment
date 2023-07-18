#include "Aircraft.h"

using namespace std;

Aircraft::Aircraft(const string& t, const string& r) : type(t), registration(r){
    flighthours = 0;
}

Aircraft::~Aircraft(){}

string Aircraft::getRegistration() const{
    return registration;
}

void Aircraft::install(Part* p, Date& d){
    p->install(d);
    parts.add(p);
}

void Aircraft::takeFlight(int hours){
    flighthours += hours;
    for (int i = 0; i < parts.getSize(); i++){
        parts[i]->addFlightHours(hours);
    }
} 

void Aircraft::inspectionReport(Date& d, Array<Part*>& a){
    for (int i = 0; i < parts.getSize(); i++){
        if (parts[i]->inspection(d)){
            a.add(parts[i]);
        }
    }
}

void Aircraft::print(ostream& out) const{
    out << "Aircraft: " + type + "\nRegistration: " + registration << endl;
}

ostream& operator<<(ostream& out, const Aircraft& aircraft){
    aircraft.print(out);
    return out;
}