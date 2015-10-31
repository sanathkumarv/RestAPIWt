/* Interface class for all rest entity map */
#include<iostream>
#include <rest/BookApi.h>
#include <entity/book.h>

BookApi :: BookApi()
{
}
std::string BookApi::post(std::string objJson) 
{
      mongoWrapper con; 
      mongo::BSONObj o = mongo::fromjson(objJson);	

	con.connect();
      mongo::BSONObj o2 = BSON("_id"<< mongo::OID::gen() );

      mongo::BSONObj o1 = (mongo::BSONObjBuilder().appendElements(o2).appendElements(o)).obj();

      Book p(o1,con);
      return 	p.addNew();
	
}
std::string BookApi::get(std::string objJson) 
{
}
std::string BookApi::getAll() 
{
      mongoWrapper con; 
	con.connect();
      Book p(mongo::BSONObj(),con);
      return p.getAll();

}
bool BookApi::remove(std::string objJson)
{
	return true;
}

