#ifndef PROJ2_ROUTES_H
#define PROJ2_ROUTES_H
#include <iostream>
#include <list>
#include <unordered_map>
#include <fstream>
#include <cstdlib>
using namespace std;


class Routes {
private :
    string airline;
    string airline_id;
    string source_airportCode;
    string source_airportId;
    string destination_airportCode;
    string destination_airportId;
    int stops;
    string equipment;

public:
    Routes();

    Routes(string airline, string airline_id,string source_airportCode, string source_airportId, string destination_airportCode, string destination_airportId, int stops, string equipments);

    string getAirline();


    string getAirlineId();


    string getSourceAirportCode();


    string getSourceAirportId();


    string getDestinationAirportCode();


    string getDestinationAirportId();

    void setAirline(string airline);

    void setAirlineId(string airlineId);

    void setSourceAirportCode(string sourceAirportCode);

    void setSourceAirportId(string sourceAirportId);

    void setDestinationAirportCode(string destinationAirportCode);

    void setDestinationAirportId(string destinationAirportId);

    void setStops(int stops);

    void setEquipment(string equipment);

    int getStops();

    string getEquipment();

    void Retrieve_Routedata();

};







#endif //PROJ2_ROUTES_H
