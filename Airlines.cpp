#include "Airlines.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>


Airlines::Airlines() {
}

void Airlines::Retrieve_Airlinedata(){
    string  airline_id,airline_name, airline_alias, airline_IATA,airline_ICAO, airline_callsign, airline_country, airline_active;
    string newLine, data;
    unordered_map<string, list<Airlines> > Airline_map;
    vector<string> airline_data;
    list<Airlines> airlines;

    fstream fin;
    fin.open("airline.csv", ios::in);
    cout << "Stream2 has been opened \n" << endl;
    getline(fin, newLine);

    while (getline(fin, newLine)) {
        airline_data.clear();
        stringstream s(newLine);

        while (getline(s, data, ',')) {
            airline_data.push_back(data);
        }


        airline_id = airline_data[0];
        airline_name = airline_data[1];
        airline_alias = airline_data[2];
        airline_IATA = airline_data[3];
        airline_ICAO = airline_data[4];
        airline_callsign = airline_data[5];
        airline_country = airline_data[6];
        airline_active= airline_data[7];

        string key = airline_IATA;

        Airlines newairline;
        newairline.setAirlineId(airline_id);
        newairline.setAirlineName(airline_name);
        newairline.setAirlineAlias(airline_alias);
        newairline.setAirlineIata(airline_IATA);
        newairline.setAirlineIcao(airline_ICAO);
        newairline.setAirlineCallsign(airline_callsign);
        newairline.setAirlineActive(airline_active);


        airlines.push_back(newairline);

        if (Airline_map.count(key) == 0) {
            Airline_map.insert({key, airlines});
        } else {
            Airline_map.insert({key, airlines});
        }
    }
    fin.close();
}


Airlines::Airlines(string airline_id, string airline_name, string airline_alias, string airline_IATA,
                   string airline_ICAO, string airline_callsign, string airline_country, bool active) {

}

string Airlines::getAirlineId() {
    return std::string();
}

string Airlines::getAirlineName() {
    return std::string();
}

string Airlines::getAirlineAlias() {
    return std::string();
}

string Airlines::getAirlineIata() {
    return std::string();
}

string Airlines::getAirlineIcao() {
    return std::string();
}

string Airlines::getAirlineCallsign() {
    return std::string();
}

string Airlines::getAirlineCountry() {
    return std::string();
}

bool Airlines::isAirlineActive() {
    return false;
}

void Airlines::setAirlineId(string airlineId) {
    airline_id = airlineId;
}

void Airlines::setAirlineName(string airlineName) {
    airline_name = airlineName;
}

void Airlines::setAirlineAlias(string airlineAlias) {
    airline_alias = airlineAlias;
}

void Airlines::setAirlineIata(string airlineIata) {
    airline_IATA = airlineIata;
}

void Airlines::setAirlineIcao(string airlineIcao) {
    airline_ICAO = airlineIcao;
}

void Airlines::setAirlineCallsign(string airlineCallsign) {
    airline_callsign = airlineCallsign;
}

void Airlines::setAirlineCountry(string airlineCountry) {
    airline_country = airlineCountry;
}

void Airlines::setAirlineActive(string airlineActive) {
    airline_active = airlineActive;
}
