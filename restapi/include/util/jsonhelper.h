
#include <iostream>
using  namespace std;
#include <cstdlib>
#include <mongo/bson/bson.h>
#include <Wt/Json/Array>
#include <Wt/Json/Value>
#include <Wt/Json/Object>
#include <Wt/Json/Parser>
using mongo::BSONObj;

class JsonHelper 
{

	public:

	 std::string BSONArray2JSONStr( std::list<BSONObj> &li);
	 Wt::Json::Array JsonStrToArray(std::string jstr);

};
