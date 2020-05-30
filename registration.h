using namespace std;

class Registration {
    public:
        char option;
        string username, password, usr, pwd, res, userCred, residency;
        char resStat;
        bool status = false;

        Registration() {};
        void regCleanUp();
        char menu();
        void adminLogin();
        void signUp();
        bool login();
        void logout();
        void quit();
        ~Registration() {};
};

void Registration::regCleanUp() {
    system("cls");
}

char Registration::menu() {
    char option;
    cout << "===== KKE Equipment Lending System =====\n\n";
    cout << "\t1. Login\n";
    cout << "\t2. Sign Up\n";
    cout << "\t3. Admin Login\n";
    cout << "\t4. Quit\n\n";
    cout << "========================================\n";
    cout << "\nChoice: "; cin >> option;
    return option;
}

void Registration::signUp() {
    regCleanUp();
    cout << "Please enter your desired credentials\n\n";
    cout << "Username   : "; cin >> username;
    cout << "Password   : "; cin >> password;

    string* usrCrd = &userCred;
    *usrCrd = ".\\users\\user" + username + ".txt";

    ofstream write(userCred);                                               //writes the credentials to the file
    if (write) {
        write << username << endl;
        write << password << endl;
        if ( resStat == 'y' || resStat == 'Y') {
            residency = "1";
            write << residency << endl;
        }
        else if ( resStat == 'n' || resStat == 'N') {
            residency = "0";
            write << residency << endl;
        }
    }
    write.close();

    ifstream read(userCred);                                                //checks if the file is successfully written, then proceeds to the Main Menu
    if (read) {
        regCleanUp();
        cout << "\nSigned up successfully!";
        for ( int i = 0; i < 3; i++ ) { Sleep(500); cout << " . "; }
        Sleep(1000);
        Registration();
    } else cout << "Oops! Something went wrong.";
    read.close();
}

bool Registration::login() {
    regCleanUp();
    if ( status == true ) return true;
    else {
        cout << "Please login\n\n";
        cout << "Username   : "; cin >> username;
        cout << "Password   : "; cin >> password;
        string* usrCrd = &userCred;
        *usrCrd = ".\\users\\user" + username + ".txt";

        //compares the credentials entered by the user with the ones stored in cred file
        ifstream read(userCred);
        if (read) {
            getline(read, usr);
            getline(read, pwd);

            if ( usr == username && pwd == password ) {
                regCleanUp();

                cout << "Logged in successfully!";
                for ( int i = 0; i < 3; i++ ) { Sleep(500); cout << " . "; }
                Sleep(1000);
                status = true;

            } else {
                status = false;
                cout << "\nIncorrect password!\n";
            }
        } else { 
            status = false; 
            cout << "\nUser does not exist!\n";
        }
                
        if ( status == false ) {
            bool attempt = true;
            do {
                cout << "\nNow what?\n\n";
                cout << "1. Try again\n" << "2. Sign Up\n" << "3. Back\n";
                cout << "\nChoice: "; cin >> option;

                if ( option == '1' ) {
                    login();
                    attempt = false;} else if ( option == '2' ) {
                    signUp();
                    attempt = false;
                } else if ( option == '3' ) {
                    Registration();
                    attempt = false;
                } else {
                    regCleanUp();
                    cout << "Please enter a valid choice\n\n";
                    attempt = true;
                }
            } while (attempt == true);

        }
    }
}

void Registration::adminLogin() {
    regCleanUp();
    if ( status == true ) return;
    else {
        cout << "Please login\n\n";
        cout << "Username   : "; cin >> username;
        cout << "Password   : "; cin >> password;
/*         string* usrCrd = &userCred;
        *usrCrd = "cred" + username + ".txt"; */
        string admCrd = ".\\admins\\admin" + username + ".txt";

        //compares the credentials entered by the user with the ones stored in cred file
        ifstream read(admCrd);
        if (read) {
            getline(read, usr);
            getline(read, pwd);
            //getline(read, res);

            if ( usr == username && pwd == password ) {
                status = true;
                regCleanUp();
                cout << "ADMIN LOGIN\n";
                cout << "Logged in successfully!";
                for ( int i = 0; i < 3; i++ ) { Sleep(500); cout << " . "; }
                Sleep(1000);
            } else {
                status = false;
                cout << "\nIncorrect password!\n";
            }
        } else { 
            status = false; 
            cout << "\nAdmin does not exist!\n";
        }
                
        if ( status == false ) {
            bool attempt = true;
            do {
                cout << "\nNow what?\n\n";
                cout << "1. Try again\n" << "2. Sign Up\n" << "3. Back\n";
                cout << "\nChoice: "; cin >> option;

                if ( option == '1' ) {
                    login();
                    attempt = false;} else if ( option == '2' ) {
                    signUp();
                    attempt = false;
                } else if ( option == '3' ) {
                    Registration();
                    attempt = false;
                } else {
                    regCleanUp();
                    cout << "Please enter a valid choice\n\n";
                    attempt = true;
                }
            } while (attempt == true);

        }
    }
}

void Registration::logout() {
    regCleanUp();
    bool attempt = true;
    do {
        cout << "Are you sure you want to logout?\n\n";
        cout << "1. Yes\n" << "2. No\n";
        cout << "\nChoice: "; cin >> option;

        if ( option == '1' ) {
            regCleanUp();
            cout << "Logging out";
            for ( int i = 0; i < 3; i++ ) { Sleep(500); cout << " . "; }
            Sleep(1000);
            // Registration();
            attempt = false;
        } else if ( option == '2' ) {
            attempt = false;
        } else {
            regCleanUp();
            cout << "Please enter a valid choice\n\n";
            attempt = true;
        }
    } while (attempt == true);
}

void Registration::quit() {
    regCleanUp();
    bool attempt = true;
    do {
        cout << "Are you sure you want to quit?\n\n";
        cout << "1. Yes\n" << "2. No\n";
        cout << "\nChoice: "; cin >> option;

        if ( option == '1' ) {
            regCleanUp();
            cout << "THANK YOU FOR USING OUR PROGRAM!";
            for ( int i = 0; i < 3; i++ ) { Sleep(500); cout << " . "; }
            Sleep(1000);
            regCleanUp();
            exit(0);
            attempt = false;
        } else if ( option == '2' ) {
            Registration();
            attempt = false;
        } else {
            regCleanUp();
            cout << "Please enter a valid choice\n\n";
            attempt = true;
        }
    } while (attempt == true);
}