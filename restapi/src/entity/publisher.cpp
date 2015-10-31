#include <db/constants.h>
#include <entity/publisher.h>
#include <util/jsonhelper.h>
//#include <mongo/bson/bson.h>
//#include <mongo/bson/bsonobj.h>
using mongo::BSONObj;


/* Entity class for Publisher */


	Publisher::Publisher(mongo::BSONObj obj, mongoWrapper &con)
	{
		pCon = & con;
		pBsonObj = & obj;
	}
	std::string Publisher:: addNew()
	{
		return 	pCon->insert(DB_PUBLISHERS , *pBsonObj);
	}
	std::string Publisher:: getAll()
	{
		std::list<BSONObj> list = pCon->getAll(DB_PUBLISHERS);
	
		JsonHelper h;
		return h.BSONArray2JSONStr(list);

		return "";

	}
