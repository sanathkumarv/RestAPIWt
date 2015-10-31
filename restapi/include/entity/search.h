
/* Entity class for Publisher */
#include <iostream>
#include <db/mongowrapper.h>

class Search {
	mongoWrapper *pCon;
	mongo::BSONObj *pBsonObj;

	public:
		Search(mongo::BSONObj , mongoWrapper &con);
		std::string addNew();//save new book and return ID
		std::string get(std::string custemail); // return all search requests for a given customer as JSON string
		std::string getAll();// return all pending search requests as JSON Array String
		std::list<BSONObj> getAll(int);// return all pending search requests as BSON list
		std::string updateStatus(std::string id, int status);
};
