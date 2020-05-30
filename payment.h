using namespace std;

class payList {
    private:
        string itemID;
        string itemName;
        int itemUnits;
        double itemDepo;
        payList* next;

    public:
        payList() {};

        void setData(string id, string name, int units, double depo) {
            itemID = id;
            itemName = name;
            itemUnits = units;
            itemDepo = depo;
        };

        void setnNext(payList* aNext) { next = aNext; };
        string getID() { return itemID; };
        string getName() { return itemName; };
        int getUnits() { return itemUnits; };
        double getDepo() { return itemDepo; };
        payList* Next() { return next; };
};

class Payment {
    private:
        string date;
        double total = 0;
        string itemID;
        int itemUnits;
        payList* h;
    
    public:
        Payment() { h = NULL; };
        string getDate();
        string getTime();
        void getList(string id, string name, int unit, double depo);
        void payCleanUp();
        double calcTotal(double total);
        void printReceipt(string n, string l, string p, string d/* , string id, string name, int unit, double depo */);
};

string Payment::getDate() {
    time_t ttime = time(0);
    tm* local_time = localtime(&ttime);

    string day = to_string(local_time->tm_mday);
    string month = to_string(local_time->tm_mon);
    string year = to_string(1900 + local_time->tm_year);
    
    return (day + "/" + month + "/" + year);
}

string Payment::getTime() {
    time_t ttime = time(0);
    tm* local_time = localtime(&ttime);
    
    string time = to_string(local_time->tm_hour) + ":" + to_string(local_time->tm_min) + ":" + to_string(local_time->tm_sec);

    return time;
}

void Payment::getList(string id, string name, int unit, double depo) {


    payList* newNode = new payList();
    newNode->setData(id, name, unit, depo);
    newNode->setnNext(NULL);

    payList* t = h;
    if ( t != NULL ) {
        while ( t->Next() != NULL ) {
            t = t->Next();
        }
        t->setnNext(newNode);
    } else { 
        h = newNode;
        
    }
}


double Payment::calcTotal(double total) {
    payList* t = h;
    do {
        total += t->getDepo();
        t = t->Next();
    } while ( t != NULL );

    return total;
}

void Payment::printReceipt(string n, string l, string p, string d/* , string id, string name, int unit, double depo */) {
    // getList(id, name, unit, depo);

    payCleanUp();
    cout << "===== KKE Equipment Lending System =====\n\n";
    cout << "-----------------RECEIPT----------------\n";
    cout << "ID" << "\tNAME" << "\t\tUNITS" << "\tDEPOSIT\n";
    cout << "----------------------------------------\n";
    cout << "\n=========================================\n";
    cout << "NAME     : " << n << "\n";
    cout << "LOCATION : " << l << "\n";
    cout << "PURPOSE  : " << p << "\n";
    cout << "DURATION : " << d << "\n";
    // cout << "TOTAL : RM" <<  fixed << setprecision(2) << calcTotal() << "\n";
    cout << "DATE     : " << getDate() << "\n";
    cout << "TIME     : " << getTime() << "\n";
    cout << "=========================================\n";

/*     List* t = bh;
    if ( t == NULL ) {
        cout << "EMPTY\n";
        cout << "\n=========================================\n";
        cout << "NAME     : " << n << "\n";
        cout << "LOCATION : " << l << "\n";
        cout << "PURPOSE  : " << p << "\n";
        cout << "DURATION : " << d << "\n";
        // cout << "TOTAL : RM" <<  fixed << setprecision(2) << calcTotal() << "\n";
        cout << "DATE     : " << getDate() << "\n";
        cout << "TIME     : " << getTime() << "\n";
        cout << "=========================================\n";
    }

    if (t->Next() == NULL ) {
        cout << t->getID() << "\t";
        cout << t->getName() << "\t\t";
        cout << t->getUnits() << "\t";
        cout << t->getDepo() << "\t";
        cout << "\n";
    } else {
        do {
            cout << t->getID() << "\t";
            cout << t->getName() << "\t\t";
            cout << t->getUnits() << "\t";
            cout << "RM" << t->getDepo() << "\t";
            cout << "\n";
            t = t->Next();
        } while ( t != NULL );
    } */
}

void Payment::payCleanUp() {
    system("cls");
}