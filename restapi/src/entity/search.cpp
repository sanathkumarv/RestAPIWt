
/* Entity class for Search */
#include <db/constants.h>
#include <entity/search.h>
#include <util/jsonhelper.h>
using mongo::BSONObj;

Search::Search(mongo::BSONObj obj , mongoWrapper &con)
{
	pCon = & con;
	pBsonObj = & obj;
}
std::string Search::addNew()//save new book and return ID
{
	//concatenate status column
        mongo::BSONObj o2 = BSON("status"<< 0 );

      mongo::BSONObj o1 = (mongo::BSONObjBuilder().appendElements(*pBsonObj).appendElements(o2)).obj();


	
	return 	pCon->insert(DB_SEARCH , o1);
}
std::string Search::get(std::string custemail) // return all search for a given customer email as JSON string
{
	
}
std::string Search::getAll() // return all pending search as JSON Array String
{

	std::list<BSONObj> list = getAll(1);	
	
	JsonHelper h;
	return h.BSONArray2JSONStr(list);

}
std::string Search::updateStatus(std::string id, int status)
{
	std::string sid = "ObjectId(" + id + ")";
	
        mongo::BSONObj q = BSON("_id" << mongo::OID(id) << "status"<< 0 );
	mongo::BSONObj val = BSON("$inc" << BSON( "status" << status));

	std::cout << q.toString() << std::endl;
	std::cout << val.toString() << std::endl;

	return pCon->update(DB_SEARCH, q,val);
}

std::list<BSONObj> Search::getAll(int r) // return all pending search as BSONlist
{

	//{ query: { ... }, orderby: { ... } } 

	std::string criteria = "{query: { status:0 }}";

	std::list<BSONObj> list = pCon->getAll(DB_SEARCH, criteria);
	return list;	

}

