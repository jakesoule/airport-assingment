#include "Airline.h"

using namespace std;

Airline::Airline(const string& n) : name(n){}

Airline::~Airline(){
    for (int i = 0; i < parts.getSize(); i++){
        delete parts[i];
    }

    for (int i = 0; i < aircraft.getSize(); i++){
        delete aircraft[i];
    }
}

Aircraft* Airline::getAircraft(const string& r) const{
    for (int i = 0; i < aircraft.getSize(); i++){
        if (aircraft[i]->getRegistration() == r){
            return aircraft[i];
        }
    }
    return NULL;
}

Part* Airline::getPart(const string& n) const{
    for (int i = 0; i < parts.getSize(); i++){
        if (parts[i]->getName() == n){
            return parts[i];
        }
    }
    return NULL;
}

void Airline::addAircraft(const string& type, const string& reg){
    Aircraft* a = new Aircraft(type, reg);
    aircraft.add(a);
}

void Airline::addPart(const string& part, int fh_inspect, int it_inspect){
    if (fh_inspect == 0){
        IT_Part* p = new IT_Part(part, it_inspect);
        parts.add(p);
        return;
    }

    if (it_inspect == 0){
        FH_Part* p = new FH_Part(part, fh_inspect);
        parts.add(p);
        return;
    }

    FHIT_Part *p = new FHIT_Part(part, fh_inspect, it_inspect);
    parts.add(p);
}

void Airline::takeFlight(const string& reg, int hours){
    for (int i = 0; i < aircraft.getSize(); i++){
        if (aircraft[i]->getRegistration() == reg){
            aircraft[i]->takeFlight(hours);
            return;
        }
    }
    cout << "Error Aircraft not found." << endl;
}

void Airline::printParts() const{
    for (int i = 0; i < parts.getSize(); i++){
        cout << *parts[i] << endl;;
    }
}

void Airline::printAircraft() const{
    for (int i = 0; i < aircraft.getSize(); i++){
        cout << *aircraft[i];
    }
}

void Airline::inspectionReport(const string& reg, Date& d){
    Array<Part*> a;
    for (int i = 0; i < aircraft.getSize(); i++){
        if (aircraft[i]->getRegistration() == reg){
            aircraft[i]->inspectionReport(d, a);
            cout << "The following parts from " + aircraft[i]->getRegistration() + " require inspection:" << endl;
            for (int i = 0; i < a.getSize(); i++){
                cout << *a[i] << endl;
            }
            cout << endl;
            return;
        }
    }





    // Array<Part*> a;
    // for (int i = 0; i < aircraft.getSize(); i++){
    //     if (aircraft[i]->getRegistration() == reg){
    //         aircraft[i]->inspectionReport(d, a);
    //         cout << "The following parts from ";
    //         cout << aircraft[i]->getRegistration();
    //         cout << " require inspection:" << endl;
    //         cout << a << endl;
    //         return;
    //     }
    // }
    cout << "Error Aircraft not found." << endl;
}

bool Airline::install(const string& reg, const string& name, Date& d){
    for (int i = 0; i < aircraft.getSize(); i++){
        if (aircraft[i]->getRegistration() == reg){
            for (int j = 0; j < parts.getSize(); j++){
                if (parts[j]->getName() == name){
                    aircraft[i]->install(parts[j], d);
                    return true;
                }
            }
        }
    }
    return false;
}