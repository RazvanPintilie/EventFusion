#include "DataBase.h"
using namespace std;

#define rootUser "root"
#define rootPassword "root"
#define dbName "piu"
#define tableName std::string("test")

void Database::Connection() 
{
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, "localhost", rootUser, rootPassword, dbName, 3307, NULL, 0);

}

Database::Database() 
{
	Database::Connection();
}

bool Database::searchUser(string username)
{
	string query = "SELECT password from " + tableName + " where username = '" + username + "'";
	const char* q = query.c_str();
	if (mysql_query(conn, q) != 0) {
		return false;
	}
	res = mysql_store_result(conn);
	if (res == NULL) {
		return false;
	}
	while ((row = mysql_fetch_row(res))) {
		mysql_free_result(res);
		return true;
	}
	mysql_free_result(res);
	return false;
}

bool Database::signupUser(string username, string password)
{
	if (searchUser(username))
	{
		return false;
	}

	string query = "INSERT INTO " + tableName + " (username, password) VALUES('" + username + "', '" + password + "')";
	const char* q = query.c_str();

	if (mysql_query(conn, q) != 0) {
		return false;
	}
	return true;
}