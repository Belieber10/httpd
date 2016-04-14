#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include "sql_connect.h"  // sql_connect.h

const std::string _remote_ip = "127.0.0.1";
const std::string _remote_user = "root";
const std::string _remote_passwd = "123456";
const std::string _remote_db = "remote_db";

int main()
{
	int content_length = -1;
	char method[1024];
	char query_string[1024];
	char post_data[1024];
	memset(method, '\0', sizeof(method));
	memset(query_string, '\0', sizeof(query_string));
	memset(post_data, '\0', sizeof(post_data));

	std::cout<<"<html>"<<std::endl;
	std::cout<<"<head>show student</head>"<<std::endl;
	std::cout<<"<body>"<<std::endl;

	char name[64];
	char age[64];
	char school[64];
	char hobby[64];
	memset(name, '\0', sizeof(name));
	memset(age, '\0', sizeof(age));
	memset(school, '\0', sizeof(school));
	memset(hobby, '\0', sizeof(hobby));

	strcpy(method, getenv("REQUEST_METHOD"));
	std::cout<<"<p>method:"<<method<<"</p>"<<std::endl;
	
	if(strcasecmp("GET",method) == 0){
		strcpy(query_string, getenv("QUERY_STRING"));
		std::cout<<"<p>query_string:"<<query_string<<"</p>"<<std::endl;
		sscanf(query_string,"name=%[a-z]&age=%[0-9]&school=%[a-z]&hobby=%[a-z]",name,age,school,hobby);
	}else{
		content_length = atoi(getenv("CONTENT_LENGTH"));
		int i = 0;
		for(; i<content_length; i++){
			read(0, &post_data[i], 1);
	    }
		post_data[i] = '\0';
		for(int i = 0;i<content_length;i++){
			if(post_data[i] == '&' || post_data[i] == '=')
				post_data[i] = ' ';
		}
		std::cout<<"<p>post_data:"<<post_data<<"</p>"<<std::endl;
		sscanf(post_data,"%*s %s %*s %s %*s %s %*s %s",name,age,school,hobby);
	  } 
		std::cout<<"<p>name:"<<name<<"</p>"<<std::endl;
		std::cout<<"<p>age:"<<age<<"</p>"<<std::endl;
		std::cout<<"<p>school:"<<school<<"</p>"<<std::endl;
		std::cout<<"<p>hobby:"<<hobby<<"</p>"<<std::endl;

	std::string insert_data = "\'";
	insert_data += name;
	insert_data += "\',";
	insert_data += age;
	insert_data += ",\'";
	insert_data += school;
	insert_data += "\',\'";
	insert_data += hobby;
	insert_data += "\'";
	//std::cout<"<p>"<<insert_data<<"</p>"<<std::endl;
	const std::string _host = _remote_ip;
	const std::string _user = _remote_user;
	const std::string _passwd = _remote_passwd;
	const std::string _db = _remote_db;
	sql_connecter conn(_host, _user, _passwd, _db);
	conn.begin_connect();
	conn.insert_sql(insert_data);
	//else{
	//   //DO NOTHING
	//   return 1;
	//}
	
	std::cout<<"</body>"<<std::endl;
	std::cout<<"</html>"<<std::endl;
}
