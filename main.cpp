#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "cmake-build-debug/Routes.h"
#include "cmake-build-debug/Airlines.h"
#include "cmake-build-debug/Node.h"

using namespace std;



int main() {
    Airports airport;
    airport.Retrieve_Airportdata();
    Airlines airline;
    airline.Retrieve_Airlinedata();
    Routes route;
    route.Retrieve_Routedata();

    string Scity,Scountry,Ecity,Ecountry; //strings to store names
    vector<string> row; // a vector to store each row of the csv
    string line,word, temp; //helper variables for file reading
    fstream fin;
    fin.open("TestData.txt", ios::in);
        while(getline(fin,line)){
            stringstream s(line);
            row.push_back(line);
        }
    fin.close();

    //Splitting the start city and country into two different variables
    string row1 = row[0];
    vector<string> stemp;
    stringstream s(row1);
    while(getline(s,word,',')){
        stemp.push_back((word));
    }
    Scity=stemp[0] ;
    Scountry=stemp[1] ;

    //Splitting the end city and country into two different variables
    string row2 = row[1];
    vector<string> etemp;
    stringstream k (row2);
    while(getline(k,word,',')){
        etemp.push_back((word));
    }
    Ecity=etemp[0] ;
    Ecountry=etemp[1] ;
    string Sdata=Scity+Scountry;
    cout<<Sdata<<endl;


    return 0;
}

//Check this
list<Node> Generate_airports(string Sdata){
    list<Node> Potential_Airports;
    list<Airports> Airdata = Airports::getAirport_Map()[Sdata];
    for(Airports data: Airdata){
        Node node(data);
        Potential_Airports.push_back(node);
    }

    return Potential_Airports;
}

void bfs(string Scity, string Scountry, string Ecity, string Ecountry){
};

//bool GoalTest(){
//};








