#ifndef __SQL_CONNECT__
#define __SQL_CONNECT__

#include<iostream>
#include<string>
#include<stdlib.h>
#include<mysql.h>


class sql_connecter{
public:
       sql_connecter(const std::string &_host,\
                     const std::string &_user,\
                     const std::string &_passwd,\
                     const std::string &_db);
       bool begin_connect();
	   bool insert_sql(const std::string &sql);
       bool select_sql(std::string [], std::string _out_str[][5], int &_out_row);
	  bool close_connect();
	  ~sql_connecter();
       void show_info();
private:
       //int status;
	   MYSQL_RES *res;
       MYSQL *mysql_base;
       std::string host;
       std::string passwd;
       std::string user;
       std::string db;
};

#endif
