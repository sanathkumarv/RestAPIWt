/* Interface class for all rest entity map */
#include<iostream>
#include <rest/SearchApi.h>
#include <entity/search.h>

SearchApi :: SearchApi()
{
}
std::string SearchApi::post(std::string objJson) 
{
      mongoWrapper con; 
      mongo::BSONObj o = mongo::fromjson(objJson);	

	con.connect();
      mongo::BSONObj o2 = BSON("_id"<< mongo::OID::gen() );

      mongo::BSONObj o1 = (mongo::BSONObjBuilder().appendElements(o2).appendElements(o)).obj();

      Search p(o1,con);
      return 	p.addNew();
	
}
std::string SearchApi::get(std::string objJson) 
{
}
std::string SearchApi::getAll() 
{
      mongoWrapper con; 
	con.connect();
      Search p(mongo::BSONObj(),con);
      return p.getAll();

}
bool SearchApi::remove(std::string objJson)
{
	return true;
}

