#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Airports{

private :
    string airport_id;
    string airport_name;
    string city;
    string country;
    string IATA;
    string ICAO;

public:

    Airports();

    Airports(string airport_id,string airport_name,string city,string country,string IATA,string ICAO);

    string getAirportId();


    string getAirportName();


    string getCity();


    string getCountry();


    string getIata();


    string getIcao();

    void setAirportId(string airportId);

    void setAirportName(string airportName);

    void setCity(string city);

    void setCountry(string country);

    void setIata(string iata);

    void setIcao(string icao);

    void Retrieve_Airportdata();

    static unordered_map<string, list<Airports> > getAirport_Map();

};

