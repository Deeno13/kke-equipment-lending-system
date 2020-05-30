#include "payment.h"

using namespace std;

class List {
        string itemID;
        string itemName;
        int itemUnits;
        double itemDepo;
        List* next;
    public:
        List() {};

        void setData(string id, string name, int units, double depo) {
            itemID = id;
            itemName = name;
            itemUnits = units;
            itemDepo = depo;
        };

        void setNext(List* aNext) { next = aNext; };
        string getID() { return itemID; };
        string getName() { return itemName; };
        int getUnits() { return itemUnits; };
        double getDepo() { return itemDepo; };
        List* Next() { return next; };
};

class Booking : public Payment {
    public:
        Payment p;
        List* bh;
        string fileID, fileName, fileUnits, fileDepo;
        string name, location, purpose, duration;
        string itemID;
        int itemUnits;
        bool attemptStatus, bookStatus;
        char option;
        double total = 0;
        Booking() { bh = NULL; };
        char menu();
        void display();
        void book();
        void confirm();
        void bookCleanUp();

        string getName() { return name; };
        string getLocation() { return location; };
        string getPurpose() { return purpose; };
        string getDuration() { return duration; };

};

char Booking::menu() {
    char option;
    bookCleanUp();
    cout << "===== KKE Equipment Lending System =====\n\n";
    cout << "\t1. Book Item\n";
    cout << "\t2. Logout\n";
    cout << "========================================\n";
    cout << "\nChoice: "; cin >> option;
    return option;
}


void Booking::display() {
    bookCleanUp();
    cout << "===== KKE Equipment Lending System =====\n\n";
    cout << "-----------------RECEIPT----------------\n";
    cout << "ID" << "\tNAME" << "\t\tUNITS" << "\tDEPOSIT\n";
    cout << "----------------------------------------\n";

    List* bt = bh;
    if ( bt == NULL ) {
        cout << "EMPTY\n";
        return;
    }

    if (bt->Next() == NULL ) {
        ifstream read(".\\items\\item" + bt->getID() + ".txt");
        if (read) {
            getline(read, fileID);
            getline(read, fileName);
            getline(read, fileUnits);
            getline(read, fileDepo);

            cout << fileID << "\t";
            cout << fileName << "\t\t";
            cout << itemUnits << "\t";
            cout << "RM" << fileDepo << "\t\n";
            total += stod(fileDepo);
        }
    } else {
        do {
            ifstream read(".\\items\\item" + bt->getID() + ".txt");
            if (read) {
                getline(read, fileID);
                getline(read, fileName);
                getline(read, fileUnits);
                getline(read, fileDepo);

                cout << fileID << "\t";
                cout << fileName << "\t\t";
                cout << itemUnits << "\t";
                cout << "RM" << fileDepo << "\t\n";
                total += stod(fileDepo);
            }
            bt = bt->Next();
        } while ( bt != NULL );
    }
    cout << "\n=========================================\n";

    cout << "NAME     : " << name << "\n";
    cout << "LOCATION : " << location << "\n";
    cout << "PURPOSE  : " << purpose << "\n";
    cout << "DURATION : " << duration << "\n";
    cout << "TOTAL    : RM" <<  fixed << setprecision(2) << total << "\n";
    cout << "DATE     : " << p.getDate() << "\n";
    cout << "TIME     : " << p.getTime() << "\n";
    cout << "=========================================\n";

/*     ofstream write(".\\bookings\\book" + name + p.getDate() + ".txt");
    if (write) {
        write << "===== KKE Equipment Lending System =====\n\n";
        write << "-----------------RECEIPT----------------\n";
        write << "ID" << "\tNAME" << "\t\tUNITS" << "\tDEPOSIT\n";
        write << "----------------------------------------\n";
        
    } */
    system("pause");
}

void Booking::book() {
    bookCleanUp();
    cout << "===== KKE Equipment Lending System =====\n\n";
    cout << "Please fill in the details below:\n";
    cout << "Full Name: "; cin >> name;
    cout << "Location : "; cin >> location;
    cout << "Purpose  : "; cin >> purpose;
    cout << "Duration : "; cin >> duration;

    bookCleanUp();
    cout << "===== KKE Equipment Lending System =====\n\n";
    cout << "               ITEMS LIST\n";
    cout << "----------------------------------------\n";
    cout << "ID" << "\tNAME" << "\t\tUNITS" << "\tDEPOSIT\n";
    cout << "----------------------------------------\n";

    int count = 50;
    string fileID, fileName, fileUnits, fileDepo;

    for ( int i = 0; i < count; i++ ) {
        ifstream read(".\\items\\item" + to_string(1000 + i) + ".txt");
        if (read) {
            getline(read, fileID);
            getline(read, fileName);
            getline(read, fileUnits);
            getline(read, fileDepo);

            cout << fileID << "\t";
            cout << fileName << "\t\t";
            cout << fileUnits << "\t";
            cout << "RM" << fileDepo << "\t\n";
        }
        read.close();
    }
    cout << "----------------------------------------\n";

    do {
        do {
            cout << "\t\nPlease fill in the booking details:\n";
            cout << "\tItem ID    : "; cin >> itemID;
            cout << "\tItem Units : "; cin >> itemUnits;

            string fileID, fileName, fileUnits, fileDepo;
            ifstream read(".\\items\\item" + itemID + ".txt");
            if (read) {
                getline(read, fileID);
                getline(read, fileName);
                getline(read, fileUnits);  
                getline(read, fileDepo);
            }
        
            List* newNode = new List();
            newNode->setData(fileID, fileName, stoi(fileUnits), stod(fileDepo));
            newNode->setNext(NULL);

            List* bt = bh;
            if ( bt != NULL ) {
                while ( bt->Next() != NULL ) {
                    bt = bt->Next();
                }
                bt->setNext(newNode);
            } else {
                bh = newNode;
            }

            cout << "\nWould you like to book anything else? (Y/N) : "; cin >> option;
            if ( option == 'Y' || option == 'y' ) {
                attemptStatus = false;
                bookStatus = true;
            } else if ( option == 'N' || option == 'n') {
                attemptStatus = false;
                bookStatus = false;
                return;
            }    
        } while ( attemptStatus == true );
    } while ( bookStatus == true );
}

void Booking::confirm() {
    bookCleanUp();
    cout << "===== KKE Equipment Lending System =====\n\n";
    cout << "----------------------------------------\n";
    cout << "ID" << "\tNAME" << "\t\tUNITS" << "\tDEPOSIT\n";
    cout << "----------------------------------------\n";

    List* bt = bh;
    if ( bt == NULL ) {
        cout << "EMPTY\n";
        return;
    }

    if (bt->Next() == NULL ) {
        ifstream read(".\\items\\item" + bt->getID() + ".txt");
        if (read) {
            getline(read, fileID);
            getline(read, fileName);
            getline(read, fileUnits);
            getline(read, fileDepo);

            if ( bt->getID() == fileID) {
                ofstream write(".\\items\\item" + bt->getID() + ".txt");
                if (write) {
                    write << fileID << endl;
                    write << fileName << endl;
                    write << (stoi(fileUnits) - itemUnits) << endl;
                    write << fileDepo << endl;
                }
            }

            cout << fileID << "\t";
            cout << fileName << "\t\t";
            cout << itemUnits << "\t";
            cout << "RM" << fileDepo << "\t\n";
        }
    } else {
        do {
            ifstream read(".\\items\\item" + bt->getID() + ".txt");
            if (read) {
                getline(read, fileID);
                getline(read, fileName);
                getline(read, fileUnits);
                getline(read, fileDepo);

                cout << fileID << "\t";
                cout << fileName << "\t\t";
                cout << itemUnits << "\t";
                cout << "RM" << fileDepo << "\t\n";
            }
            bt = bt->Next();
        } while ( bt != NULL );
    }
    cout << "----------------------------------------\n\n";

    do {
        cout << "Confirm booking? (Y/N): "; cin >> option;
        if ( option == 'y' || option == 'Y' ) {
            attemptStatus = false;
            return;
        } else if ( option == 'n' || option == 'N' ) {
            book();
            attemptStatus = false;
        } else {
            cout << "Please enter a valid choice\n\n";
            attemptStatus = true;
        }
    } while ( attemptStatus == true );
}

void Booking::bookCleanUp() {
    system("cls");
}