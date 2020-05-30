using namespace std;

class Manage {
    public:
        Manage() {};

        char menu();
        void cleanUp();
        void addItem();
        void delItem();
        void updItem();
        void schItem();
        void display();
        bool logout();

};

char Manage::menu() {
    char option;
    cout << "===== KKE Equipment Lending System =====\n\n";
    cout << "            ADMINISTRATOR\n";
    cout << "\t1. Add Item\n";
    cout << "\t2. Edit Item\n";
    cout << "\t3. Delete Item\n";
    cout << "\t4. Search Item\n";
    cout << "\t5. Display Items\n";
    cout << "\t6. Logout\n\n";
    cout << "========================================\n";
    cout << "\nChoice: "; cin >> option;

    return option;
}

void Manage::addItem() {
    string name, cat;
    int id, units;
    double depo;

    cleanUp();
    cout << "===== KKE Equipment Lending System =====\n\n";
    cout << "               ADD ITEM\n";
    cout << "\tEnter item ID: "; cin >> id;
    cout << "\tEnter item name: "; cin >> name;
    cout << "\tEnter no. of units: "; cin >> units;
    cout << "\tEnter deposit per unit: "; cin >> depo;

    string item = ".\\items\\item" + to_string(id) + ".txt";

    ofstream write(item);
    if (write) {
        write << id << endl;
        write << name << endl;
        write << units << endl;
        write << depo << endl;
    } 
    write.close();

    cout << "\n\tItem added successfully!\n\n";
    cout << "========================================\n";
    system("pause");
}


void Manage::updItem() {
    string id;

    cleanUp();
    cout << "===== KKE Equipment Lending System =====\n\n";
    cout << "               EDIT ITEM";
    cout << "\n\tEnter item ID to update: "; cin >> id;
    cout << "\n========================================\n";

    string fileID, fileName, fileUnits, fileDepo;
    string item = ".\\items\\item" + id + ".txt";
    ifstream read(item);
    if (read) {
        getline(read, fileID);
        getline(read, fileName);
        getline(read, fileUnits);        
        getline(read, fileDepo);
        
        if ( id == fileID ) {
            cleanUp();
            cout << "===== KKE Equipment Lending System =====\n\n";
            cout << "               EDIT ITEM";
            cout << "\n\tItem ID: " << fileID;
            cout << "\n\tItem Name: " << fileName;
            // cout << "\nItem Category: " << t->getCat();
            cout << "\n\tNo. of Units: " << fileUnits;
            cout << "\n\tItem Deposit: " << fileDepo;
            cout << "\n";

            string newName, newID, newUnits;
            double newDepo;
            int opt; 

            cout << "\n\tChoose what to update:";
            cout << "\n\t1. Item ID";
            cout << "\n\t2. Item Name";
            cout << "\n\t3. No. of Units";
            cout << "\n\t4. Item Deposit";
            cout << "\n\n\tChoice: "; cin >> opt;

            if ( opt == 1 ) {
                cout << "\n\tEnter new ID: "; cin >> newID;
                string itemUpdate = ".\\items\\item" + newID + ".txt";
                ofstream write(itemUpdate);
                if (write) {
                    write << newID << endl;
                    write << fileName << endl;
                    write << fileUnits << endl;
                    write << fileDepo << endl;
                } 
                write.close();
                read.close();

                bool delStatus = remove(item.c_str());
                if ( delStatus == 0 ) {
                    cout << "\n\tItem updated successfully!\n\n";
                    system("pause");
                } else {
                    cout << "\n\n\tERROR: Item couldn't be updated!\n\n";
                    system("pause");
                }
                return;
            }
            else if ( opt == 2 ) {
                cout << "\n\tEnter new Name: "; cin >> newName;
                ofstream write(item);

                if (write) {
                    write << fileID << endl;
                    write << newName << endl;
                    write << fileUnits << endl;
                    write << fileDepo << endl;
                } 
                write.close();

                cout << "\n\tItem updated successfully!\n\n";
                system("pause");
                return;
            }
            else if ( opt == 3 ) {
                cout << "\n\tEnter new No. of Units: "; cin >> newUnits;
                ofstream write(item);

                if (write) {
                    write << fileID << endl;
                    write << fileName << endl;
                    write << newUnits << endl;
                    write << fileDepo << endl;
                } 
                write.close();

                cout << "\n\tItem updated successfully!\n\n";
                system("pause");
                return;
            }
            else if ( opt == 4 ) {
                cout << "\n\tEnter new Deposit: "; cin >> newDepo;
                ofstream write(item);

                if (write) {
                    write << fileID << endl;
                    write << fileName << endl;
                    write << fileUnits << endl;
                    write << newDepo << endl;
                } 
                write.close();
                
                cout << "\n\tItem updated successfully!\n\n";
                system("pause");
                return;
            }
            else {
                cout << "\nPlease enter a valid option.";
            }
        }
    } else {
        cout << "Item not found.\n";
        updItem();
    }
}

void Manage::delItem() {
    string id;

    cleanUp();
    cout << "===== KKE Equipment Lending System =====\n\n";
    cout << "             DELETE ITEM";
    cout << "\n\tEnter item ID to delete: "; cin >> id;

    string fileID, fileName, fileUnits, fileDepo;
    string item = ".\\items\\item" + id + ".txt";
    ifstream read(item);
    if (read) {
        getline(read, fileID);
        getline(read, fileName);
        getline(read, fileUnits);        
        getline(read, fileDepo);

        if ( id == fileID ) {
            cout << "\n\n\tItem ID: " << fileID;
            cout << "\n\tItem Name: " << fileName;
            // cout << "\nItem Category: " << t->getCat();
            cout << "\n\tNo. of Units: " << fileUnits;
            cout << "\n\tItem Deposit: " << fileDepo;

            char option;
            bool attemptStatus = true;
            do {
                cout << "\n\n\tConfirm delete?\n\n";
                cout << "\t1. Yes\n";
                cout << "\t2. No\n";
                cout << "\n\tChoice: "; cin >> option;

                if ( option == '1' ) {
                    read.close();
                    bool delStatus = remove(item.c_str());
                    if ( delStatus == 0 ) {
                        cout << "\n\tItem deleted successfully!\n\n";
                        cout << "========================================\n";
                        system("pause");
                    } else {
                        cout << "\n\tERROR: Item couldn't be deleted!\n\n";
                        cout << "========================================\n";
                        system("pause");
                    }
                    attemptStatus = false;
                } else if ( option == '2' ) {
                    attemptStatus = false;
                } else {
                    cleanUp();
                    cout << "Please enter a valid choice\n\n";
                    attemptStatus = true;
                }
            } while (attemptStatus == true);
        }
    } else {
        cout << "Item not found.\n";
        delItem();
    }
}

void Manage::schItem() {
    string id;
    bool again, attemptStatus;
    char option;

    do {
        cleanUp();
        cout << "===== KKE Equipment Lending System =====\n\n";
        cout << "             SEARCH ITEM";
        cout << "\n\tEnter item ID to search: "; cin >> id;

        string fileID, fileName, fileUnits, fileDepo;
        string item = ".\\items\\item" + id + ".txt";
        ifstream read(item);
        if (read) {
            getline(read, fileID);
            getline(read, fileName);
            getline(read, fileUnits);        
            getline(read, fileDepo);

            if ( id == fileID ) {
                do {
                    cout << "\n\tItem ID: " << fileID;
                    cout << "\n\tItem Name: " << fileName;
                    // cout << "\nItem Category: " << t->getCat();
                    cout << "\n\tNo. of Units: " << fileUnits;
                    cout << "\n\tItem Deposit: " << fileDepo;
                
                    cout << "\n\n\tSearch again?\n\n";
                    cout << "\t1. Yes\n";
                    cout << "\t2. No\n";
                    cout << "\n\tChoice: "; cin >> option;

                    if ( option == '1') {
                        attemptStatus = false;
                        again = true;
                    } else if ( option == '2') {
                        attemptStatus = false;
                        again = false;
                    } else {
                        cleanUp();
                        cout << "Please enter a valid choice\n\n";
                        attemptStatus = true;
                    }
                } while (attemptStatus == true);
            } else {
                cout << "file not found";
                system("pause");
            }
        } else {
        cout << "Item not found.\n";
        updItem();
        }
    } while ( again == true );
/*     Node* t = h;
    while (t != NULL) {
        if (t->getID() == id) {
            cout << "\nItem ID: " << t->getID();
            cout << "\nItem Name: " << t->getName();
            // cout << "\nItem Category: " << t->getCat();
            cout << "\nNo. of Units: " << t->getUnits();
            cout << "\nItem Deposit: " << t->getDepo();
            cout << "\n";
            return;
        }
        t = t->Next();
    } 
*/
}

void Manage::display() {
/*     Node* t = h;

    if ( t == NULL ) {
        cout << "Manage is empty\n";
        return;
    }

    if ( t->Next() == NULL ) {
        cout << "\n";
        cout << "=======================================\n";
        cout << "ID" << "\tNAME" << "\t\tUNITS" << "\tDEPOSIT\n";
        cout << "=======================================\n";
        cout << t->getID() << "\t";
        cout << t->getName() << "\t\t";
        // cout << t->getCat() << "\t";
        cout << t->getUnits() << "\t";
        cout << t->getDepo() << "\t";
        cout << "\n";
    } 
    else {
        cout << "\n";
        cout << "=======================================\n";
        cout << "ID" << "\tNAME" << "\t\tUNITS" << "\tDEPOSIT\n";
        cout << "=======================================\n";
        do {
            cout << t->getID() << "\t";
            cout << t->getName() << "\t\t";
            // cout << t->getCat() << "\t";
            cout << t->getUnits() << "\t";
            cout << "RM" << t->getDepo() << "\t";
            cout << "\n";
            t = t->Next();
        } while ( t != NULL );
    } 
*/
    cleanUp();
    cout << "===== KKE Equipment Lending System =====\n\n";
    cout << "\n            DISPLAY ITEMS\n";
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
    }
    cout << "----------------------------------------\n\n";
    system("pause");
}

void Manage::cleanUp() {
    system("cls");
}

bool Manage::logout() {
    cleanUp();
    int option;
    bool attempt = true;

    do {
        cout << "Are you sure you want to logout?\n\n";
        cout << "1. Yes\n" << "2. No\n";
        cout << "\nChoice: "; cin >> option;

        if ( option == 1 ) {
            cleanUp();
            cout << "Logging out";
            for ( int i = 0; i < 3; i++ ) { Sleep(500); cout << " . "; }
            Sleep(1000);
            // Registration();
            attempt = false;
        } else if ( option == 2 ) {
            //mainMenu();
            attempt = false;
        } else {
            cleanUp();
            cout << "Please enter a valid choice\n\n";
            attempt = true;
        }
    } while (attempt == true);
}