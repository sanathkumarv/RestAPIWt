
/* Entity class for Publisher */
#include <iostream>
#include <db/mongowrapper.h>

class Book {
	mongoWrapper *pCon;
	mongo::BSONObj *pBsonObj;

	public:
		Book(mongo::BSONObj , mongoWrapper &con);
		std::string addNew();//save new book and return ID
		std::string get(std::string search); // return all books for a search condition as JSON string
		std::list<BSONObj> get(std::string search,int); // return all books for a search conditionr as List<BSONObj>
		std::string getAll();// return all books as JSON Array String
};
