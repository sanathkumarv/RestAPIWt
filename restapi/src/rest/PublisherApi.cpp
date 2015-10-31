/* Interface class for all rest entity map */
#include<iostream>
#include <rest/PublisherApi.h>
#include <entity/publisher.h>

PublisherApi :: PublisherApi()
{
}
std::string PublisherApi::post(std::string objJson) 
{
      mongoWrapper con; 
      mongo::BSONObj o = mongo::fromjson(objJson);	

	con.connect();
      mongo::BSONObj o2 = BSON("_id"<< mongo::OID::gen() );

      mongo::BSONObj o1 = (mongo::BSONObjBuilder().appendElements(o2).appendElements(o)).obj();

      Publisher p(o1,con);
      return 	p.addNew();
	
}
std::string PublisherApi::get(std::string objJson) 
{
}
std::string PublisherApi::getAll() 
{
      mongoWrapper con; 
	con.connect();
      Publisher p(mongo::BSONObj(),con);
      return p.getAll();

}
bool PublisherApi::remove(std::string objJson)
{
	return true;
}

