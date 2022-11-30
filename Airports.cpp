#include "Airports.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

Airports::Airports(){
}

Airports::Airports(string airport_id, string airport_name, string city, string country, string IATA, string ICAO) {
}

unordered_map<string, list<Airports> > Airport_map;
void Airports::Retrieve_Airportdata(){
    string airport_id,airport_name, city, country,IATA, ICAO;
    string newLine, data;
    vector<string> airport_data;
    list<Airports> airports;
    fstream fin;
    fin.open("airport.csv", ios::in);
    cout << "Stream 1 has been opened \n" << endl;
    getline(fin, newLine);

    while (getline(fin, newLine)) {
        airport_data.clear();
        stringstream s(newLine);

        while (getline(s, data, ',')) {
            airport_data.push_back(data);
        }


        airport_id = airport_data[0];
        airport_name = airport_data[1];
        city = airport_data[2];
        country = airport_data[3];
        IATA = airport_data[4];
        ICAO = airport_data[5];


        string key = city+country;

        Airports newairport;
        newairport.setAirportId(airport_id);
        newairport.setAirportName(airport_name);
        newairport.setCity(city);
        newairport.setCountry(country);
        newairport.setIata(IATA);
        newairport.setIcao(ICAO);

        airports.push_back(newairport);
        if(Airport_map.count(key) == 0) {
            Airport_map.insert({key, airports});
        } else {
            Airport_map.insert({key, airports});
        }
    }
    fin.close();
}

string Airports::getAirportId() {
    return airport_id;
}

string Airports::getAirportName() {
    return airport_name;
}

string Airports::getCity() {
    return city;
}

string Airports::getCountry() {
    return country;
}

string Airports::getIata() {
    return IATA;
}

string Airports::getIcao() {
    return ICAO;
}

void Airports::setAirportId(string airportId) {
    airport_id = airportId;
}

void Airports::setAirportName(string airportName) {
    airport_name = airportName;
}

void Airports::setCity(string city) {
    Airports::city = city;
}

void Airports::setCountry(string country) {
    Airports::country = country;
}

void Airports::setIata(string iata) {
    IATA = iata;
}

void Airports::setIcao(string icao) {
    ICAO = icao;
}

unordered_map<string, list<Airports> > Airports::getAirport_Map() {
    return Airport_map;
}







