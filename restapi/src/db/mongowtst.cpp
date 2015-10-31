/*
#include <iostream>
using  namespace std;
#include <cstdlib>
*/
#include <db/mongowrapper.h>


#include <db/constants.h>
#include <Wt/Json/Array>
#include <Wt/Json/Parser>
#include <Wt/Json/Value>
#include <Wt/Json/Object>

#include <entity/search.h>

void testSearch()
{
	mongoWrapper mongo;
	if(mongo.connect())	
        	std::cout << "connected ok" << std::endl;
	else
        	std::cout << " failed to connect " << mongo.error() << std::endl;
	BSONObj o = BSON(  "title" << "C++ for Dummies" << "custemail" << "varamballysanathkumar@gmail.com" <<"custname" << "Sanath Kumar") ;
	Search s(o,mongo);
	s.addNew();
	std::cout << s.getAll() << std::endl;
	
	std::string sid = "562b29d0d21ae78507019476";
	s.updateStatus(sid,1);
	

}


int main() {

	 testSearch();
	/*
	mongoWrapper mongo;
	if(mongo.connect())	
        	std::cout << "connected ok" << std::endl;
	else
        std::cout << " failed to connect " << mongo.error() << std::endl;

	BSONObj o = BSON(  "name" << "ABC Publishers") ;
	//BSONObj o = BSON( "_id" << mongo::OID::gen() << "name" << "ABC Publishers") ;
	//BSONObj o1 = (mongo::BSONObjBuilder().appendElements(o)<<"_id"<<BSON("_id"<< mongo::OID::gen() )).obj();
	BSONObj o2 = BSON("_id"<< mongo::OID::gen() );

	BSONObj o1 = (mongo::BSONObjBuilder().appendElements(o2).appendElements(o)).obj();

	std::cout << o1.toString()<<endl;

	std::string id =  mongo.insert(DB_PUBLISHERS , o1);
	std::cout <<"Id=" << id << endl;

	std::list<BSONObj> list = mongo.getAll(DB_PUBLISHERS);
	std::list<BSONObj>::iterator it;

	for (it=list.begin(); it!=list.end(); ++it)
	{

		std::string jstr = (*it).jsonString();
		std::cout << " JSON "<< jstr << std::endl;

		BSONObj ob = (*it).getOwned();
 		Wt::Json::Value result;
                Wt::Json::ParseError err;
                if( Wt::Json::parse(jstr,result,err))
                {
			std::cout <<"parsed data " << (std::string)result << std::endl;
//                        jArr.push_back(result);
                }
		else
		std::cout << " failed to parse "<< std::endl;
	}

	*/

    return 0;
}

