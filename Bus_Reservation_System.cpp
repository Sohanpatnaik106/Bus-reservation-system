#include"bits/stdc++.h"
using namespace std;

class BusCompany {
    private :
        string busNo;
        string driverName;
        string arrivalTime;
        string destinationTime;
        string arrivalDestination;
        string finalDestination;
        vector<string> seat;
        int noOfSeatsAvailable;

    public:
        BusCompany() {
            for(int i = 0; i < 52; i++) {
                seat.push_back("Empty");
            }
            noOfSeatsAvailable = 52;
        }
        void installBus(string, string, string, string, string, string);
        void seatAllotment(string, int);
        void showBusDetails();
        string returnBusNo();
        bool isBusEmpty();
        bool isSeatEmpty(int);
        void busAvailabilityStatus();
};

void BusCompany :: installBus(string busNo, string name, string arrivalTime, string destinationTime, string arrivalDestination, string finalDestination) {
    this->busNo = busNo;
    this->driverName = name;
    this->arrivalTime = arrivalTime;
    this->destinationTime = destinationTime;
    this->arrivalDestination = arrivalDestination;
    this->finalDestination = finalDestination;
}

void BusCompany :: seatAllotment(string passengerName, int seatNo) {
    this->seat[seatNo-1] = passengerName;
}

string BusCompany :: returnBusNo() {
    return this->busNo;
}

bool BusCompany :: isBusEmpty() {
    bool isEmpty = false;
    for(int i = 0; i < 52; i++) {
        if(this->seat[i].compare("Empty") == 0) {
            isEmpty = true;
            break;
        }
    }
    return isEmpty;
}

bool BusCompany :: isSeatEmpty(int seatNo) {
    bool isEmpty = false;
    if(this->seat[seatNo-1].compare("Empty") == 0)
        isEmpty = true;

    return isEmpty;
}

void BusCompany :: showBusDetails() {
    cout << "The bus number : " << this->busNo << endl;
    cout << "The name of the driver : " << this->driverName << endl;
    cout << "The arrival and destination time : " << this->arrivalTime << " " << this->destinationTime << endl;
    cout << "The arrival and final destination : " << this->arrivalDestination << " " << this->finalDestination << endl; 
} 

void BusCompany :: busAvailabilityStatus() {
    cout << "The bus number : " << this->busNo << endl;
    cout << "The availabilty status of the bus is : \n";
    for(int i = 0; i < this->seat.size(); i++) {
        if(i % 4 == 3) {
            cout << this->seat[i] << "\n";

        }
        else {
            cout << this->seat[i] << "\t";
        }
    } 
    cout << endl;
}

int main() {
    vector<BusCompany> Buses;
    BusCompany bus;
    int choice;
    string password;
    string encryptionPassword = "password";

    string busNo, name, arrivalTime, destinationTime, arrivalDestination, finalDestination;
    int seatNo;

    cout << "Welcome to XYZ Bus company" << endl << endl;
    cout << "1. Install Bus (only for owner)\n" << endl;
    cout << "2. Reservation of bus\n" <<endl;
    cout << "3. Show the bus details\n" << endl;
    cout << "4. Bus availbility status\n" << endl;
    cout << "5. Exit\n" <<endl;
    cin >> choice;

    while(choice != 5) {
        if(choice == 1) {
            cout << "Enter the password to install a bus : ";
            fflush(stdout);
            cin >> password;
            if(password.compare(encryptionPassword) == 0) {
                cout << "Welcome!!" << endl;
                cout << "Enter the Bus number : ";
                cin >> busNo;
                cout << "Enter the driver's name : ";
                cin >> name;
                cout << "Enter the arrival and departure time : ";
                cin >> arrivalTime >> destinationTime;
                cout << "Enter the arrival and final destination : ";
                cin >> arrivalDestination >> finalDestination;
                bus.installBus(busNo, name, arrivalTime, destinationTime, arrivalDestination, finalDestination);
                Buses.push_back(bus);
            }
            else {
                cout << "Sorry you are not authorized to install a bus\n" << endl;
            }
        }
        else if (choice == 2) {
            cout << "Enter the Bus Number : ";
            cin >> busNo;
            int flag = 0;
            for(int i = 0; i < Buses.size(); i++) {
                if(busNo.compare(Buses[i].returnBusNo()) == 0) {
                    bool isBusEmpty = Buses[i].isBusEmpty();
                    if(isBusEmpty) {
                        cout << "Enter the seat you want : ";
                        cin >> seatNo;
                        bool isSeatEmpty = Buses[i].isSeatEmpty(seatNo);
                        if(isSeatEmpty) {
                            cout << "Enter the name of the passenger : ";
                            cin >> name;
                            Buses[i].seatAllotment(name, seatNo);
                        }
                        else {
                            cout << "The seat is occupied\n";
                        }
                    }
                    else {
                        cout << "The bus is not empty. Please try with another bus\n";
                    }
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                cout << "We don't have any bus with that number\n";
            }
        }
        else if(choice == 3) {
            cout << "Enter the bus number : ";
            cin >> busNo;
            int flag = 0;
            for(int i = 0; i < Buses.size(); i++) {
                if(busNo.compare(Buses[i].returnBusNo()) == 0) {
                    Buses[i].showBusDetails();
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                cout << "We don't have any bus with that number\n";
            }
        }
        else if(choice == 4) {
            cout << "Enter the bus number : ";
            cin >> busNo;
            int flag = 0;
            for(int i = 0; i < Buses.size(); i++) {
                if(busNo.compare(Buses[i].returnBusNo()) == 0) {
                    Buses[i].busAvailabilityStatus();
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                cout << "We don't have any bus with that number\n";
            }
        }
        else if(choice == 5) { 
            cout << "Thank you!!" << endl;
            return 0;
        }
        cout << "1. Install Bus (only for owner)\n" << endl;
        cout << "2. Reservation of bus\n" <<endl;
        cout << "3. Show the bus details\n" << endl;
        cout << "4. Bus availbility status\n" << endl;
        cout << "5. Exit\n" <<endl;
        cin >> choice;
    }

    return 0;
}