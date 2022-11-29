#include <iostream>
#include <unordered_map>
using namespace std;

class Airlines {

private :

    string airline_id;
    string airline_name;
    string airline_alias;
    string airline_IATA;
    string airline_ICAO;
    string airline_callsign;
    string airline_country;
    string airline_active;

public:
    Airlines();

    Airlines(string airline_id, string airline_name, string airline_alias, string airline_IATA, string airline_ICAO, string airline_callsign, string airline_country, bool active);

    string getAirlineId();


    string getAirlineName();


    string getAirlineAlias();


    string getAirlineIata();


    string getAirlineIcao();


    string getAirlineCallsign();


    string getAirlineCountry();

    void setAirlineId(string airlineId);

    void setAirlineName(string airlineName);

    void setAirlineAlias(string airlineAlias);

    void setAirlineIata(string airlineIata);

    void setAirlineIcao(string airlineIcao);

    void setAirlineCallsign(string airlineCallsign);

    void setAirlineCountry(string airlineCountry);

    void setAirlineActive(string airlineActive);

    bool isAirlineActive();


    void Retrieve_Airlinedata();


};



