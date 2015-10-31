

#include <util/jsonhelper.h>
#include <Wt/Json/Array>
#include <Wt/Json/Parser>
#include <Wt/Json/Value>
#include <Wt/Json/Object>


 std::string JsonHelper::BSONArray2JSONStr(std::list<BSONObj > &li)
{
	std::string retval;
	std::list<BSONObj>::iterator it;
	int cc = 0;

	retval = "[";
	for (it=li.begin(); it!=li.end(); ++it)
	{
		std::string jstr = (*it).jsonString();
		retval += jstr +",";
		cc++;
	}
	if(cc >0)
		retval = retval.substr(0, retval.size()-1);

	retval += "]";
	

	return retval;
  
}
Wt::Json::Array JsonHelper::JsonStrToArray(std::string jstr)
{
	try
	{
		Wt::Json::Value value;

		Wt::Json::parse(jstr,value);
		if(!value.isNull())
		{
			if(value.type() == Wt::Json::ArrayType)
			{
				 Wt::Json::Array& arr = value;
				return arr;
			}
		}
		
	}catch(Wt::Json::ParseError &er)
	{

	}
	return Wt::Json::Value();
}


