#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h> 
#include<iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

static std::function<void(void *data, int argc, char **argv, char **azColName)> func;

static int callback(void *data, int argc, char **argv, char **azColName){
   func(data, argc, argv, azColName);
   return 0;
}

class SqliteClass
{
    public:
    sqlite3 *db;
    std::string SN;
    bool is_bounded;
    std::string phone;
    SqliteClass(){
    };
    ~SqliteClass(){
        sqlite3_close(db);
    };

    void InitDataBase()
    {
        func = [this](void *data, int argc, char **argv, char **azColName)
        {
               int i;
            fprintf(stderr, "%s: ", (const char*)data);
            for(i=0; i<argc; i++){
                printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
            }
            this->is_bounded = atoi(argv[1]);
            this->phone = argv[2];

            cout<<this->phone<<endl;
            cout<<this->is_bounded<<endl;
            printf("\n");
        };

        SN = "MavicAir";
        char *zErrMsg = 0;
        int  rc;
        /* Open database */
        rc = sqlite3_open("test.db", &db);
        if( rc ){
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
            exit(0);
        }else{
            fprintf(stdout, "Opened database successfully\n");
        }

        char table_sql[] = "CREATE TABLE BindingRecording(SN TEXT PRIMARY KEY NOT NULL, STATE INT NOT NULL, PHONE TEXT );";
        sqlite3_exec(db, table_sql, nullptr, 0, nullptr);
    };

    void UpdatePhone(bool is_bounded, std::string phone)
    {
        char insert_sql[100];
        sprintf(insert_sql, "INSERT INTO BindingRecording (SN,STATE,PHONE) "  \
        "VALUES ('%s', %d,  '%s' ); ",SN.c_str(), is_bounded, phone.c_str());
        printf("%s", insert_sql);
        
        int res = sqlite3_exec(db, insert_sql, callback, 0, nullptr);
        if(res != SQLITE_OK)
        {
            printf("SN exist !");
            char update_sql[100];
            sprintf(update_sql, "UPDATE BindingRecording SET STATE = %d, PHONE = '%s' WHERE SN = '%s';", is_bounded, phone.c_str(), SN.c_str() );
            int res = sqlite3_exec(db, update_sql, callback, 0, nullptr);
        }
    };

    void GetBindingStateFromCache()
    {
        char *zErrMsg = 0;
        char select_sql[100];
        sprintf(select_sql, "select * from BindingRecording where SN = '%s'",SN.c_str());
        int res = sqlite3_exec(db, select_sql, callback, 0, nullptr);
        if( res != SQLITE_OK ){
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }else{
            fprintf(stdout, "Operation done successfully\n");
        }    
    }

};


int main(int argc, char* argv[]) 
{
    SqliteClass sqlite = SqliteClass();
    sqlite.InitDataBase();
    sqlite.GetBindingStateFromCache();

    sqlite.UpdatePhone(0, "138329956777");
    sqlite.GetBindingStateFromCache();
    // printf("begin");
    return 0;
}

