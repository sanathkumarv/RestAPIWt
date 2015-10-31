#ifndef MONGOWRAPPER_H
#define MONGOWRAPPER_H
#include <iostream>
using  namespace std;
#include <cstdlib>
#include <mongo/client/dbclient.h> // for the driver
#include <mongo/client/dbclientcursor.h> // for the driver
#include <mongo/bson/bsonobj.h> // for the driver
using mongo::BSONElement;
using mongo::BSONObj;
using mongo::BSONObjBuilder;

class mongoWrapper {

  	mongo::DBClientConnection c;
	std::string _error;

	public :
		mongoWrapper();
		bool connect();
		std::string error();
		std::string insert(std::string , BSONObj &);
		std::list<BSONObj> getAll(std::string, std::string searchcriteria="" );
		std::string update(std::string,mongo::Query q, BSONObj&);

};
#endif

