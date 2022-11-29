#include "Airports.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

Airports::Airports() {
}

void Airports::Retrieve_Airportdata(){
    string airport_id,airport_name, city, country,IATA, ICAO;
    string newLine, data;
    unordered_map<string, list<Airports> > Airport_map;
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

//void Airports::Retrieve_Airportdata() {
//        unordered_map<string, list<string> > Airports_map;
//        string airport_id,airport_name, city, country,IATA, ICAO;
//        string newLine;
//        fstream fin;
//
//        fin.open("airports.csv", ios:: in);
//        getline(fin, newLine);
//        //cout<<"Stream has been opened \n"<<endl;
//        while(fin.good()) {
//            getline(fin, airport_id, ',');
//            getline(fin, airport_name, ',');
//            getline(fin, city, ',');
//            getline(fin, country, ',');
//            getline(fin, IATA, ',');
//            getline(fin, ICAO, ',');
//
//
//            list<string> routes_data;
//            routes_data.push_back(airport_id);
//            routes_data.push_back(airport_name);
//            routes_data.push_back(city);
//            routes_data.push_back(country);
//            routes_data.push_back(IATA);
//            routes_data.push_back(ICAO);
//            Airports_map.insert({ city+country, routes_data });
//        }
//
//        fin.close();
//        for(auto i: Airports_map) {
//            for(auto m:i.second);
//            list<string>::iterator it;
//            cout << i.first << "<<<<<<" << endl;
//            for (it = i.second.begin(); it != i.second.end(); ++it) {
//                cout << it->at(0) << endl;
//            }
//        }
//    std::unordered_map<string, list<string>>::iterator it = Routes_map.begin();
//    while(it != Routes_map.end()){
//        std::cout<<it->first << " :: " << &it->second<<std::endl;
//        it++;
//    }



