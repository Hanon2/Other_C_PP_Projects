#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
int input1; // an integer to store the user's choice
int counter = 0; // an integer to count through the input while loop if the input is right


class employee {
    public: employee(string n, double h, double w) { // constructor to run methods for each object
        setEmployee(n);
        setHrsPerWeek(h);
        setWages(w);

    }
    // a set of setters to set the values of the wages - Employees - and hrs per
    // week
    void setWages(double wages) {
        if (wages < 0) {
            cout << "invalid" << endl;

        } else {
            wagePerHr = wages;
        }

    }

    void setEmployee(string name) {

        name_total = name;




    }

    void setHrsPerWeek(double hrs) {
        if (hrs < 0) {
            cout << "invalid" << endl;
        } else {
            hrsPerWeek = hrs;
        }


    }
    // a set of setters to return the values of the wages - Employees - and hrs per
    // week
    double getWages() {
        return wagePerHr;
    }

    string getEmployees() {
        return name_total;
    }

    double getHrsPerWeek() {
        return hrsPerWeek;
    }
    private:
    //  a set of private vectors that store the names - hrs per week - wage per hr
    string name_total;
    double hrsPerWeek;
    double wagePerHr;
    double addWages() {}

};



int main() {
    vector < employee > employee_storage; // a vector that stores the objects
    //vectors that has the data that will be used for the 5 employess that will just make it easier to populate the data
    vector<string> name_main = {"Bob","Mohamed","Marawan","Rob","Ahmed"};
    vector<double> hrsPerWeek_main = {40,38.5,36,33.5,50};
    vector<double> wagePerHr_main = {30,20,40,60,55,50};
    // a set of objects that use the structure parameters to run the methods
    employee Employees_obj1(name_main[0], hrsPerWeek_main[0], wagePerHr_main[0]);
    employee Employees_obj2(name_main[1], hrsPerWeek_main[1], wagePerHr_main[1]);
    employee Employees_obj3(name_main[2], hrsPerWeek_main[2], wagePerHr_main[2]);
    employee Employees_obj4(name_main[3], hrsPerWeek_main[3], wagePerHr_main[3]);
    employee Employees_obj5(name_main[4], hrsPerWeek_main[4], wagePerHr_main[4]);
    cout << "Please choose one of the following options 1-3" << endl;
    cout << "1- Print list of employees" << endl;
    cout << "2- Calculate total wages" << endl;
    cout << "3-Exit application" << endl;
    employee_storage.push_back(Employees_obj1);
    employee_storage.push_back(Employees_obj2);
    employee_storage.push_back(Employees_obj3);
    employee_storage.push_back(Employees_obj4);
    employee_storage.push_back(Employees_obj5);


    while (counter == 0) {

        cin >> input1; // take the input
        if (input1 == 1) {
            cout << "printing..." << endl;
            for (int count = 0; count <= employee_storage.size() - 1; ++count) {
                cout << count + 1 << "- name: " << employee_storage.at(count).getEmployees() << ", wage per hour : " << employee_storage.at(
                    count
                ).getWages() << ", Hour per week: " << employee_storage.at(count).getHrsPerWeek() << endl;
            }


            counter = 1;


        } else if (input1 == 2) {

            for (int count = 0; count <= employee_storage.size() - 1; ++count) {
                cout << " Enter the amount of hrs worked for: " << employee_storage.at(count).getEmployees() << endl;
                int hrsinput;
                cin >> hrsinput;
                employee_storage.at(count).setHrsPerWeek(hrsinput);
            }
            double sumWages = 0;
            double sumHrs = 0;
            for (int count = 0; count <= employee_storage.size() - 1; ++count) {

                if (count == 0) {
                    sumWages = employee_storage.at(count).getWages();
                    sumHrs = employee_storage.at(count).getHrsPerWeek();
                } else {
                    sumWages = employee_storage.at(count).getWages() + sumWages;
                    sumHrs = employee_storage.at(count).getHrsPerWeek() + sumHrs;

                }


            }
            int totalWages = sumWages * sumHrs;
            cout << "The total wage is: " << totalWages << endl;
            counter = 1;

        } else if (input1 == 3) {
            cout << "program terminated" << endl;
            exit(0);
        } else {
            cout << "Your input is wrong please reinput" << endl;
            cout << "1- Print list of employees" << endl;
            cout << "2- Calculate total wages" << endl;
            cout << "3- Exit application" << endl;

        }
    }


}