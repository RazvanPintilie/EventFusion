#ifndef DataBase_H
#define DataBase_H
#include <mysql.h>
#include <string>
using namespace std;

class Database 
{
private:
	MYSQL* conn;
	MYSQL_ROW row;
	MYSQL_RES* res;
public:
	void Connection();
	Database();
	bool searchUser(string username);
	bool signupUser(string username, string password);
	
};

#endif
