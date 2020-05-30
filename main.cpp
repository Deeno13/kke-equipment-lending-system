#include <fstream>
#include <cstring>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "registration.h"
#include "booking.h"
#include "manage.h"
using namespace std;

void mainCleanUp() {
    system("cls");
}

int main() {
    Registration r;
    Manage m;
    Booking b;
    Payment p;

    char option;
    bool attemptStatus = true, logStatus = false, adminLogStatus = false, useStatus = true, result;

    do { //FOR PROGRAM
        do { //FOR GETTING BACK TO LOGIN PAGE
            mainCleanUp();
            do {
                option = r.menu();

                if ( option == '1' ) {
                    r.login();
                    logStatus = true;
                    attemptStatus = false;
                } else if ( option == '2' ) {
                    r.signUp();
                    attemptStatus = false;
                } else if ( option == '3' ) {
                    r.adminLogin();
                    attemptStatus = false;
                    adminLogStatus = true;
                } else if ( option == '4' ) {
                    r.quit();
                    attemptStatus = false;
                } else {
                    mainCleanUp();
                    cout << "Please enter a valid choice\n\n";
                }
            } while ( attemptStatus == true);

            if ( logStatus == true ) {
                while ( logStatus == true ) {
                    mainCleanUp();
                    do {
                        option = b.menu();

                        if ( option == '1' ) {
                            b.book();
                            b.confirm();
                            b.display();
                            attemptStatus = false;
                        } else if ( option == '2' ) {
                            r.logout();
                            attemptStatus = false;
                            logStatus = false;
                        } else {
                            mainCleanUp();
                            cout << "Please enter a valid choice\n\n";
                        }
                    } while ( attemptStatus == true );
                }
            } else if ( adminLogStatus == true ) {
                while ( adminLogStatus == true ) {
                    mainCleanUp();
                    do {
                        option = m.menu();
                        
                        if ( option == '1' ) {
                            m.addItem();
                            attemptStatus = false;
                        } else if ( option == '2' ) {
                            m.updItem();
                            attemptStatus = false;
                        } else if ( option == '3' ) {
                            m.delItem();
                            attemptStatus = false;
                        } else if ( option == '4' ) {
                            m.schItem();
                            attemptStatus = false;
                        } else if ( option == '5' ) {
                            m.display();
                            attemptStatus = false;  
                        } else if ( option == '6' ) {
                            m.logout();
                            attemptStatus = false;
                            adminLogStatus = false;
                        } else {
                            mainCleanUp();
                            cout << "Please enter a valid choice\n\n";
                        }
                    } while ( attemptStatus == true );
                }
            }
        } while ( logStatus == false && adminLogStatus == false);
        mainCleanUp();
        do {
            cout << "Do you want to continue using the program? (Y/N)"; cin >> option;
            if ( option == 'y' || option == 'Y' ) {
                attemptStatus = false;
            } else if ( option == 'n' || option == 'N' ) {
                cout << "THANK YOU FOR USING OUR PROGRAM!";
                for ( int i = 0; i < 3; i++ ) { Sleep(500); cout << " . "; }
                Sleep(1000);
                attemptStatus = false;
                exit(0);
            } else {
                cout << "Please enter a valid choice\n\n";
                attemptStatus = true;
            }
        } while ( attemptStatus == true );

    } while ( useStatus == true );

    return 0;
}