#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>
#include <dos.h>
using namespace std;

//==================================================================================================
class Bank
{
public:
    double limit;

};


//==================================================================================================
class ATMAccountHolders:public Bank
{
    string nume;
    string prenume;
    string accountHoldersAddress, location;
    int accountNumber;
    double accountBalance;
    double amount;
    int count;

public:
    void deposit();
    void withdraw();
    void details();
    void payBills();
    void accountExit();
    void createAccount();
    void login(void);
    ATMAccountHolders()
    {


        ifstream sold;
        sold.open("sold.txt",ios::out | ios::in);
        sold >> accountBalance;
        ifstream numarcont;
        numarcont.open("numarcont.txt",ios::out | ios::in);
        numarcont >> accountNumber;
        ifstream numecont;
        numecont.open("numecont.txt",ios::out | ios::in);
        numecont >> nume >> prenume;
        ifstream adresacont;
        adresacont.open("adresacont.txt",ios::out | ios::in);
        adresacont >> accountHoldersAddress;
        ifstream locatia;
        locatia.open("locatia.txt",ios::out | ios::in);
        locatia >> location;

    }
};


//==================================================================================================
void ATMAccountHolders::deposit()
{
    system("cls");
    cout<<"\n===========================ATM ACCOUNT DEPOSIT SYSTEM==========================\n\n";

    cout<<"\n\nNumele de cont asociat cardului este :"<<nume<< " " <<prenume<<"\n\n";
    cout<<"\tAdresa de cont asociat cardului este :"<<accountHoldersAddress<<"\n\n";
    cout<<"\tLocatia :"<<location<<"\n\n";
    cout<<"\tNumarul de cont:"<<accountNumber<<"\n\n";
    cout<<"============================+++++++++++++++++++++++============================\n\n";
    cout<<"\tSold Disponibil :"<<accountBalance<<" lei\n\n";
    cout<<"\tIntroduceti suma (in lei) pe care urmeaza sa fie depozitata:  ";

    double amount;
    cin>>amount;
    accountBalance=accountBalance+amount ;
    cout<<"\n\tAcum ai in total "<<accountBalance<<"lei"<<endl ;
    cout<<"\n\t\t\tMultumim!\n\n"<<endl;
    cout<<"Apasa orice buton pentru a ajunge la meniul principal\n\n";
    ofstream sold;
    sold.open("sold.txt",ios::out | ios::in);
    sold << accountBalance;
    system("PAUSE");
}
//==================================================================================================
void ATMAccountHolders::withdraw()//Withdrawal Transactions
{
    system("cls");
    cout<<"\n============================ATM Retragere Bani CONT=============================\n\n";

    cout<<"\n\nNumele de cont asociat cardului este :"<<nume<<" "<<prenume<<"\n\n";
    cout<<"\tAdresa de cont asociat cardului este :"<<accountHoldersAddress<<"\n\n";
    cout<<"\tLocatia :"<<location<<"\n\n";
    cout<<"\tNumarul de cont:"<<accountNumber<<"\n\n";
    cout<<"============================+++++++++++++++++++++++============================\n\n";
    cout<<"\tSold Disponibil : "<<accountBalance<<" lei\n\n";
    cout<<"\tIntrodu suma (in lei) pe care vrei sa o retragi din cont (maxim 9000 de lei): ";

    double amount;
    cin>>amount;

    if(amount>accountBalance||amount>9000)
    {
        system("cls");
        cout<<"\n============================ATM Retragere Bani CONT=============================\n\n";
        cout<<"\n\nNumele de cont asociat cardului este :"<<nume<<" "<<prenume<<"\n\n";
        cout<<"\tAdresa de cont asociat cardului este :"<<accountHoldersAddress<<"\n\n";
        cout<<"\tLocatia :"<<location<<"\n\n";
        cout<<"\tNumarul de cont:"<<accountNumber<<"\n\n";
        cout<<"============================+++++++++++++++++++++++============================\n\n";
        cout<<"\n\tInsuficiente fonduri in cont pentru a retrage suma de bani . \n\n"<<endl;
        cout<<"\t\t\n Ne pare rau !\n"<<endl;
        system("PAUSE");
    }
    else
    {
        double b;
        accountBalance=accountBalance-amount ;
        system("cls");
        cout<<"\n============================ATM Retragere Bani CONT=============================\n\n";
        cout<<"\n\nNumele de cont asociat cardului este :"<<nume<<" "<<prenume<<"\n\n";
        cout<<"\tAdresa de cont asociat cardului este :"<<accountHoldersAddress<<"\n\n";
        cout<<"\tLocatia :"<<location<<"\n\n";
        cout<<"\tNumarul de cont:"<<accountNumber<<"\n\n";
        cout<<"============================+++++++++++++++++++++++============================\n\n";
        cout<<"Acum in cont ai in total: "<<accountBalance<<" de lei"<< endl ;
        cout<<"Apeasa pe orice buton pentru a reveni in meniul principal\n\n";
        system("PAUSE");
    }
    ofstream sold;
    sold.open("sold.txt",ios::out | ios::in);
    sold << accountBalance;

}
//==================================================================================================
void ATMAccountHolders::payBills()
{
    system("cls");

    int r;

    cout<<"\n===========================ATM Plati Facturi Online==========================\n";

    cout<<"\n\nNumele de cont asociat cardului este :"<<nume<<" "<<prenume<<"\n\n";
    cout<<"\tAdresa de cont asociat cardului este :"<<accountHoldersAddress<<"\n\n";
    cout<<"\tLocatia :"<<location<<"\n\n";
    cout<<"\tNumarul de cont:"<<accountNumber<<"\n\n";
    cout<<"\tSold Disponibil:"<<accountBalance<<"\n\n";
    cout<<"====================++ ! ++============================\n\n";
    cout<<"Doriti sa platiti factura de la compania de electricitate in valoare de 200 de lei acum ?\n\n";
    cout<<"\t\tApasa 1 pentru DA sau apasa 0 pentru NU\n\n";
    cin>>r;
    if(r==1)
    {
        accountBalance=accountBalance-200;
        system("cls");
        cout<<"\n===========================ATM Plati Facturi Online==========================\n";
        cout<<"\n\tFactura de la electricitate in valoare de 2000 de lei a fost platita !\n\n";
        cout<<"\tIn cont mai aveti suma de : "<<accountBalance<<" de lei" << endl ;
        cout<<"\n============================+++++++++++++++++++++++===========================\n\n";
        cout<<"Apasa orice buton pentru a reveni la meniul principal\n\n";
    }
    if(r==0)
    {
        cout<<"\n===========================ATM Plati Facturi Online==========================\n\n";
        cout<<"\n\n\tPlata la factura a fost refuzata ...\n\n";
        cout<<"====================++Va multumim !++============================\n\n";
    }
    system("PAUSE");
    ofstream sold;
    sold.open("sold.txt",ios::out | ios::in);
    sold << accountBalance;
};

//==================================================================================================
void ATMAccountHolders::details()
{
    system("cls");


    cout<<"\n============================ATM Detalii CONT=============================\n\n";
    cout<<"\n\nNumele detinatorului contului este:"<<nume<<" "<<prenume<<"\n\n";
    cout<<"\tAdresa detinatorului contului:"<<accountHoldersAddress<<"\n\n";
    cout<<"\tLocatia este :"<<location<<"\n\n";
    cout<<"\tNumarul de cont :"<<accountNumber<<"\n\n";
    cout<<"\tSOLD Disponibil :"<<accountBalance<<"\n\n";
    cout<<"====================++Multumim++============================\n\n";
    cout<<"Apeasa orice tasta pentru a reveni la meniul principal\n\n";
    system("PAUSE");
}

//==================================================================================================

void ATMAccountHolders::accountExit()
{
    system("cls");


    cout<<"\n============================ATM ACCOUNT EXIT=============================\n\n";
    cout<<"\n\n\t\tIesire din cont ..... toate datele sunt verificate.\n\n";
    cout<<"====================++MULTUMIM !++============================\n\n";
    cout<<"============================+++++++++++++++++++++++============================\n\n";
    system("PAUSE");
    exit(1);
}

//==================================================================================================

class Limits:public Bank
{
public:
    void SetLimit(double NewLimit)
    {}

    double Getlimit()
    {}

};

void ATMAccountHolders::createAccount()
{
    system("cls");
    string username;
    string password;
    cout << "Introdu un UserName:" << endl;
    cin >> username;
    cout << "Introdu o parola:" << endl;
    cin >> password;
    ofstream createaccount;
    createaccount.open("accounts.txt", ios::app);
    createaccount << username << " " << password << endl;
    createaccount.close();
    cout << "Cont creat!" << endl;


    system("PAUSE");

}
void ATMAccountHolders::login(void)
{
    system("cls");
    string username;
    string password;
    ifstream savedaccount;
    savedaccount.open("accounts.txt"); // accounts.txt will verify user information.
    cout << "UserName:" << endl;
    cin >> username;
    cout << "Password:" << endl;
    cin >> password;
    string username2, password2;
    savedaccount >> username2 >> password2;
    savedaccount.close();
    if (username != username2 || password != password2)
        cout << "Incorrect login! Create new account or try again." << endl;
    if (username == username2 || password == password2)
        cout << " Login corect " << endl;
    system("PAUSE");
}


int start()
{
    int e;
    ATMAccountHolders p;

    system ("Color 1b");
    cout<<"\n============================Bine ai venit la ATM============================\n\n";
    cout<<"\t\t\t--------------------\n"<<endl;

    cout << "\t\tData de azi: ";

    time_t now;
    time(&now);

    printf("%s\n", ctime(&now));;

    cout<<"\t\t\t--------------------\n"<<endl;
    cout<<"============================Suport tehnic 24/24 : 0231.231.231==================================\n\n";
    //==================================================================================================

    cout<<"\tApasa 1 si apasa enter pentru a accesa contul folosind parola pin de la card.\n\n";
    cout<<"\t\t\t\t\t or \n\n";
    cout<<"\tApasa 0 si apasa enter pentru a primi ajutor.\n\n";

    int access;
    cin>>access;
    switch(access)
    {
    case 1:
        system("cls");
        int i, pin;

        cout<<"\n============================ATM ACCONT ACCESS==================================\n\n";
        cout<<"\n\nIntrodu codul PIN ! Doar o singura incercare este permisa !.\n\n"<<endl;
        cout<<"============================ATM ACCOUNT ACCESS==================================\n\n";
        cin>>pin;

        system("cls");

        if(pin==0000)

        {
            system("cls");

            do
            {
                system("cls");
                system ("Color 1a");
                cout << endl << "\n======================ATM MENIU======================\n" << endl << endl;
                cout << "\t\tApeasa (1) Pentru Depozitul de bani" << endl;
                cout << "\t\tApeasa (2) Pentru Retragere bani" << endl;
                cout << "\t\tApeasa (3) Pentru Interogare Sold" << endl;
                cout << "\t\tApeasa (4) Pentru Plati facturi Online" << endl;
                cout << "\t\tApeasa (0) Pentru a iesi din ATM" << endl << endl;
                cout << "\tSelecteaza te rog un numar si apeasa pe enter. \n\n";
                cout<<"==========================ATM Meniu================================\n\n";

                cin>>e;
                switch(e)
                {
                case 1:
                    p.deposit();
                    break;
                case 2:
                    p.withdraw();
                    break;
                case 3:
                    p.details();
                    break;
                case 4:
                    p.payBills();
                    break;
                case 5:
                    p.createAccount();
                    break;
                case 6:
                    p.login();
                    break;
                case 0:
                    p.accountExit();
                    break;
                default:
                    cout<<"Te rog introdu numarul corect!"<<endl;
                }
            }
            while(e!=0);

            break;
        }

        else
        {
            system("cls");
            system("Color 1c");
            cout<<"\n===========================Va multumim!===========================\n\n";
            cout<<"\nAi depasit numarul de incercari permise ! Cardul se va retrage";
            cout<<"===========================O zi buna !===========================\n\n";

            system("PAUSE");
            exit (1);
        }
    //==================================================================================================


    case 0:
        system("cls");
        cout<<"\n==========================ATM ACCOUNT STATUS================================\n\n";
        cout<<"\tPentru a accesa contul trebuie introdus parola pin de pe card. \n\n";
        cout<<"\t In caz de aveti probleme cu accesarea contului te rugam sa suni la:  \n\n";
        cout<<"\t\t+4072142131 (non stop 24/h asistenta)\n\n";
        cout<<"==========================ATM ACCOUNT STATUS================================\n\n";
        system ("PAUSE");
        exit(1);
        break;
        //==================================================================================================
    }

    system("PAUSE");
    return 0;

};
