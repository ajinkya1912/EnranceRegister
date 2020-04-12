#include <iostream>
#include<windows.h>
#include<mysql.h>
#include <sstream>
#include<stdio.h>

using namespace std;
// Functions
bool dbconn();
void addrec();
void editrec();
void findmed();
void view();
//main function start
int main()
{
    int runforever = 1;
    int ans;

    cout << endl << "\t \t \t-Swami Samarth Heights-";
    cout << endl;
    cout << "\t \t \t -Entrance Register-"<<endl<<endl<<endl;

    while(runforever == 1){

        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
        cout << endl << endl << "\t \t \t1. Add Visitors Record" << endl << "\t \t \t2. View Record" << endl << "\t \t \t3. End" << endl << endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";

        cout << endl << "\tYour Answer : ";

        cin >> ans;

        switch(ans){
        case 1:
            addrec();
            break;
        case 2:
            view();
            break;
        case 3:
            runforever = 0;
            break;
        }
        if(ans>3){
            cout<<"\t*Invalid Input*" << endl;
        }
    }

    return 0;
}

//main function end

//function for add record
void addrec(){
    string dummy;
    MYSQL* conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.43.70", "ajinkya", "ajinkya", "register", 0, NULL, 0);
    if(conn){
        int qstate = 0, flat, dist, num, time;
        string name, lname, address, mh, ch;

        cout << "\tEnter First name : ";
        cin >> name;

        cout << "\tEnter Last name : ";
        cin >> lname;

        cout << "\tEnter address : ";
        cin >> address;

        cout << "\tEnter flat number : ";
        cin >> flat;


        cout<< "\tEnter Bike Number : "<<endl;
        cout<< "\tEnter State Code : ";
        cin>> mh;
        cout<< "\tEnter RTO Code : ";
        cin>> dist;
        cout<< "\tEnter Character : ";
        cin>> ch;
        cout<< "\tEnter Number : ";
        cin>> num;

        cout<< "\tEnter Coming Time : ";
        cin>> time;


        stringstream ss;
        ss << "INSERT INTO visit(name, lname, address, flat, mh, dist, ch, num, time) VALUES('" << name << "','" << lname << "','" << address << "'," << flat << ",'" << mh << "'," << dist << ",'" << ch << "'," << num << "," << time << ")";

        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if(qstate == 0){
            cout << "\tRecord Inserted..." << endl;
            cout << "\tPress B to go back";
            cin >> dummy;
        }else{
            cout << "\tInsert Error" << mysql_error(conn) << endl;
            cout << "\tPress B to go back";
            cin >> dummy;
        }
    }else{
        cout << "\tConnection Error" << endl;
        cout << "\tPress B to go back";
        cin >> dummy;
    }

    system("pause");
    system("cls");

}

//function for view all records
void view(){
    string dummy;
    MYSQL* conn;
    MYSQL_ROW row;
    MYSQL_RES* res;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "192.168.43.70", "ajinkya", "ajinkya", "register", 0, NULL, 0);
    if(conn){
        int qstate = mysql_query(conn, "SELECT id, name, lname, address, flat, mh, dist, ch, num, time FROM visit");

        cout << "id \t | \t Name \t| \t address \t | \t flat number \t | \t bike Number \t | \t time \t | \t"<<endl <<endl;
        cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
        cout << endl;
        if(!qstate){
            res = mysql_store_result(conn);

            while(row = mysql_fetch_row(res)){
                cout << row[0] <<"\t | \t" << row[2] <<" " << row[1] <<"\t| \t" << row[3] <<"\t | \t" << row[4] <<"" << row[5] <<"" << row[6] <<"" << row[7] <<"\t | \t" << row[8] <<" \t | \t " << row[9] <<"\t" << endl << endl;
                cout << endl;
             }
        }
    }

    cout << "Press B to go back";
    cin >> dummy;

    system("pause");
    system("cls");
}
