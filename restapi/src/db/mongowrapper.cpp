
#include <iostream>
using  namespace std;
#include <cstdlib>
#include <db/mongowrapper.h>
#include <db/constants.h>

       mongoWrapper :: mongoWrapper()
	{
    		mongo::client::initialize();
	}
	bool mongoWrapper::connect()
	{
		bool bRet = true;

    		try {
			_error = "";
  			c.connect(DB_CONN_STR);
    		} catch( const mongo::DBException &e )
		 {
			_error = e.what();
			bRet = false;
		
		}
		return bRet;
	}

	std::string mongoWrapper::error()
	{ 
		return _error; 
	}
	std::string mongoWrapper::insert(std::string dbpath , BSONObj &obj)
	{
		if(!c.isStillConnected ())
		{
			connect();
		}
		std::string retId = "";
    		try {
			_error = "";
			c.insert(dbpath, obj);
			retId = obj["_id"];
    		} catch( const mongo::DBException &e )
		 {
			_error = e.what();
		
		}
		return retId;
	}
	std::string mongoWrapper::update(std::string dbpath ,mongo::Query query, BSONObj &obj)
	{
		if(!c.isStillConnected ())
		{
			connect();
		}
		std::string retId = "";
    		try {
			_error = "";
			c.update(dbpath,query, obj);
    		} catch( const mongo::DBException &e )
		 {
			_error = e.what();
		
		}
		return retId;
	}
	std::list<BSONObj>  mongoWrapper::getAll(std::string dbpath, std::string searchcri)
	{
		if(!c.isStillConnected ())
		{
			std::cout << "mongoWrapper::getAll():db not connected, connecting.." << endl;
			connect();
		}

		std::cout << "mongoWrapper::getAll():db connected :" <<dbpath << endl;
		int nc =c.count(dbpath);
		std::cout << "mongoWrapper::getAll():#" << nc << endl;
		std::list<BSONObj> retList;


		if(nc >0)
		{
			auto_ptr<mongo::DBClientCursor> cursor ;

			if(searchcri != "")
			{
				BSONObj bquery = mongo::fromjson(searchcri);
				mongo::Query q = mongo::Query(bquery);
				cursor = c.query(dbpath, q);
			}
			else
			{
				cursor = c.query(dbpath, BSONObj());

			}
			while (cursor->more())
			{
				BSONObj p = cursor->next().getOwned();
				if(p.isEmpty() || !p.isValid())
					break;
				std::string pval = p.toString();
	std::cout << ' ' << pval << std::endl;
				retList.push_back(p);

			}

		}
		return retList;

	}

/*************

#include <db/constants.h>
int main() {
	mongoWrapper mongo;
	if(mongo.connect("192.168.1.191"))	
        	std::cout << "connected ok" << std::endl;
	else
        std::cout << " failed to connect " << mongo.error() << std::endl;

	BSONObj o = BSON( "_id" << mongo::OID::gen() << "name" << "ABC Publishers") ;

	std::string id =  mongo.insert(DB_PUBLISHERS , o);
	std::cout <<"Id=" << id << endl;

	std::list<BSONObj> list = mongo.getAll(DB_PUBLISHERS);
	std::list<BSONObj>::iterator it;

	for (it=list.begin(); it!=list.end(); ++it)
	{

		std::string jstr = (*it).toString();
    		std::cout << ' ' << jstr;
	}



    return 0;
}
*********************/

