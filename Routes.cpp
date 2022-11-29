#include "Routes.h"
#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
#include <sstream>


using namespace std;

Routes::Routes() {
}

void Routes::Retrieve_Routedata() {
    string airline, airline_id, source_airportCode, source_airportId, destination_airportCode, destination_airportId, equipment;
    int stops;
    string newLine, data;
    unordered_map<string, list<Routes> > Routes_map;
    vector<string> routes_data;
    list<Routes> routes;

    fstream fin;
    fin.open("routes.csv", ios::in);
    cout << "Stream3 has been opened \n" << endl;
    getline(fin, newLine);

    while (getline(fin, newLine)) {
        routes_data.clear();
        stringstream s(newLine);

        while (getline(s, data, ',')) {
            routes_data.push_back(data);
        }


        airline_id = routes_data[0];
        source_airportCode = routes_data[1];
        source_airportId = routes_data[2];
        destination_airportCode = routes_data[3];
        destination_airportId = routes_data[4];
        stops = stoi(routes_data[6]);
        equipment = routes_data[7];

        Routes newroute;

        newroute.setAirlineId(airline_id);
        newroute.setSourceAirportCode(source_airportCode);
        newroute.setSourceAirportId(source_airportId);
        newroute.setDestinationAirportCode(destination_airportCode);
        newroute.setDestinationAirportId(destination_airportId);
        newroute.setStops(stops);
        newroute.setEquipment(equipment);



        string key = source_airportCode;
        routes.push_back(newroute);


        if (Routes_map.count(key) == 0) {
            Routes_map.insert({key, routes});
        } else {
            Routes_map.insert({key, routes});
        }
    }

    fin.close();
}
//    for (auto i: Routes_map) {
//        for (auto m: i.second);
//        list<string>::iterator it;
//        cout << i.first << "<<<<<<" << endl;
//        for (it = i.second.begin(); it != i.second.end(); ++it) {
//            cout << it->at(0) << endl;
//        }
//    }







//
//}
//    std::unordered_map<string, list<string>>::iterator it = Routes_map.begin();
//    while(it != Routes_map.end()){
//        std::cout<<it->first << " :: " << &it->second<<std::endl;
//        it++;
//    }


Routes::Routes(string airline, string airline_id, string source_airportCode, string source_airportId,
               string destination_airportCode, string destination_airportId,  int stops,
               string equipments) {

}

string Routes::getAirline() {
    return airline;
}

string Routes::getAirlineId() {
    return airline_id;
}

string Routes::getSourceAirportCode() {
    return source_airportCode;
}

string Routes::getSourceAirportId() {
    return source_airportId;
}

string Routes::getDestinationAirportCode() {
    return destination_airportCode;
}

string Routes::getDestinationAirportId() {
    return destination_airportId;
}

int Routes::getStops() {
    return stops;
}

string Routes::getEquipment() {
    return equipment;
}

void Routes::setAirline(string airline) {
    Routes::airline = airline;
}

void Routes::setAirlineId(string airlineId) {
    airline_id = airlineId;
}

void Routes::setSourceAirportCode(string sourceAirportCode) {
    source_airportCode = sourceAirportCode;
}

void Routes::setSourceAirportId(string sourceAirportId) {
    source_airportId = sourceAirportId;
}

void Routes::setDestinationAirportCode(string destinationAirportCode) {
    destination_airportCode = destinationAirportCode;
}

void Routes::setDestinationAirportId(string destinationAirportId) {
    destination_airportId = destinationAirportId;
}

void Routes::setStops(int stops) {
    Routes::stops = stops;
}

void Routes::setEquipment(string equipment) {
    Routes::equipment = equipment;
}






//    for (auto& route : routes_map) {
//        std::cout << route.first << " " << &route.second << "";
//    }
//    cout<<endl;



