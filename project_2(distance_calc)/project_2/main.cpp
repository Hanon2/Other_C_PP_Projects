#include <iostream>
#include <cmath>
using namespace std;
int input1; // takes the choice of the departure
int input2; // takes the choice of the destination
double lat1_input; // this variable is a global variable that will store the latitiude of the departure according to the input, I made it global so that it can work in the destination choice function and in the main function
double long1_input; // this variable is a global variable that will store the longitude of the departure according to the input, I made it global so that it can work in the destination choice function and in the main function
double lat2_input; // this variable is a global variable that will store the latitiude of the destination according to the input, I made it global so that it can work in the destination choice function and in the main function
double long2_input; // this variable is a global variable that will store the longitude of the destination according to the input, I made it global so that it can work in the destination choice function and in the main function
double r = 3958.8; // this variable represents the radius of the earth
double time_result; // this will display how much time it will take for the flight
double d; // this value is the distance of the flight, made it global so that I can use it in the haversine and the getflighttime function
int speed = 500; // this variable represents the speed of the plane
int counter = 0; // This variable is to count to 1 & 2 if the input is from 1-10 so that it can get out of the while loop



double haversine(
    double lat1,
    double long1,
    double lat2,
    double long2,
    double radius
) { // a function to calculate haversine formula

    d = 2.0 * r * asin(
        sqrt(pow((sin((lat2 - lat1) / 2.0)), 2.0) + (cos(lat1) * cos(lat2) * pow(sin((long2 - long1) / 2.0), 2.0)))
    ); // haversine formula
}


double getFlightTime(double lat1, double long1, double lat2, double long2) { // a function to calculate the time of the flight
    d = 2.0 * r * asin(
        sqrt(pow((sin((lat2 - lat1) / 2.0)), 2.0) + (cos(lat1) * cos(lat2) * pow(sin((long2 - long1) / 2.0), 2.0)))
    ); // haversine formula
    time_result = abs((d / speed)); // time = distance/speed and then divided by 3600 to display in hours, and used the absolute value if the value of the time is negative
    cout << "the estimated time for this flight is: " << time_result << " hrs" << endl; // display the time result
}


int main() {
    cout << "Hello user" << endl;
    cout << "This application should show you the distance and the flight time between two cities" << endl;
    string departure[] = {"Miami Beach, FL, USA","Fargo, ND, USA ","Idaho City, ID, USA","Peabody, MA, USA","Northampton, MA, USA","Newton, MA, USA","Newburyport, MA, USA","New Bedford, MA, USA","Medford, MA, USA","Malden, MA, USA"}; // a sting array that has all the locations
    double latitude_deg[] = {25.793449,46.877186,43.828850,42.536457,42.328674,42.341042,42.810356,41.638409,42.419331,42.429752}; // a double array that has all the latitude
    double longitude_deg[] = {-80.139198,-96.789803,-115.837860,-70.985786,-72.664658,-71.217133,-70.893875,-70.941208,-71.119720,-71.071022}; // a double array that has all the longitude
    cout << "please choose the departure location from 1-10 (latitiude and longitude are displayed next to the locations) " << endl;
    for (int i = 1; i <= 10; ++i) { // a for loop to display the choices
        cout << i << "- " << departure[i - 1] << "  " << latitude_deg[i - 1] << "  " << longitude_deg[i - 1] << endl;
    }
    while (counter == 0) { // a while loop to make the user keep choosing until he has an input from 1-10
        cin >> input1; // take the input (1-10)
        if (input1 > 10 || input1 < 1) { // if the is more than 10 or less than 1
            cout << "Wrong input, your input should be between 1-10, please reinput your choice" << endl;
        } else { // else (which means that the choice is between 1-10) then the counter becomes 1 which will get out of the while loop
            counter = 1;
        }
    }
    double latitiude_rad[10]; // an array to store the latitude values in radians
    double longitude_rad[10]; // an array to store the longitude values in radians
    for (int n = 1; n <= 10; ++n) { // a for loop to calculate the values of the latitude and the longitude and convert them to radians
        latitiude_rad[n - 1] = latitude_deg[n - 1] * (3.14 / 180);
        longitude_rad[n - 1] = longitude_deg[n - 1] * (3.14 / 180);
    }
    lat1_input = latitiude_rad[input1 - 1]; // this variable stores the latitude according to the input, used input -1 not input because array index starts at 0
    long1_input = longitude_rad[input1 - 1]; // this variable stores the longitude according to the input, used input -1 not input because array index starts at 0
    string destination[] = {"Leominster, MA, USA","Lawrence, MA, USA ","Holyoke, MA, USA","Greenfield, MA, USA","Framingham, MA, USA","Fitchburg, MA, USA","Everett, MA, USA","Chelsea, MA, USA","Amesbury, MA, USA","Takoma Park, MD, USA"}; // a sting array that has all the locations
    double latitude2_deg[] = {42.525482,42.701283,42.203217,42.587334,42.280418,42.586716,42.408623,42.392925,42.856842,38.981544}; // a double array that has all the latitude
    double longitude2_deg[] = {-71.764183,-71.175682,-72.625481,-72.603416,-71.423233,-71.814468,-71.056999,-71.037109,-70.963440,-77.010674}; // a double array that has all the longitude
    cout << "please choose the destination location from 1-10 (latitiude and longitude are displayed next to the locations)" << endl;
    for (int i = 1; i <= 10; ++i) { // a for loop to display the choices
        cout << i << "- " << destination[i - 1] << "  " << latitude2_deg[i - 1] << "  " << longitude2_deg[i - 1] << endl;
    }
    while (counter == 1) { // a while loop to make the user keep choosing until he has an input from 1-10
        cin >> input2; // take the input (1-10)
        if (input2 > 10 || input2 < 1) { // if the is more than 10 or less than 1
            cout << "Wrong input, your input should be between 1-10, please reinput your choice" << endl;
        } else { // else (which means that the choice is between 1-10) then the counter becomes 2 which will get out of the while loop
            counter = 2;
        }
    }
    double latitiude2_rad[10]; // an array to store the latitude values in radians
    double longitude2_rad[10]; // an array to store the longitude values in radians
    for (int n = 1; n <= 10; ++n) { // a for loop to calculate the values of the latitude and the longitude and convert them to radians
        latitiude2_rad[n - 1] = latitude2_deg[n - 1] * (3.14 / 180);
        longitude2_rad[n - 1] = longitude2_deg[n - 1] * (3.14 / 180);
    }
    lat2_input = latitiude2_rad[input2 - 1]; // this variable stores the latitude according to the input, used input -1 not input because array index starts at 0
    long2_input = longitude2_rad[input2 - 1]; // this variable stores the longitude according to the input, used input -1 not input because array index starts at 0
    haversine(lat1_input, long1_input, lat2_input, long2_input, r); // call the haversine function to calculate the disance between the destinations
    getFlightTime(lat1_input, long1_input, lat2_input, long2_input); // call the getflighttime to calcuate and dsiplay the flight time
}