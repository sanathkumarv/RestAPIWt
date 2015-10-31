
/* Entity class for Publisher */
#include <iostream>
//#include <mongo/bson/bson.h>
//#include <mongo/bson/bsonobj.h>
#include <db/mongowrapper.h>

class Publisher {
	mongoWrapper *pCon;
	mongo::BSONObj *pBsonObj;

	public:
		Publisher(mongo::BSONObj , mongoWrapper &con);
		std::string addNew();//save new publisher and return ID
		std::string getAll();// return all publishers as JSON Array String
};
