/* Interface class for all rest entity map */
#ifndef RESTAPI_H
#define RESTAPI_H
class RestApi
{
	public:
	virtual std::string post(std::string objJson) =0;
	virtual std::string get(std::string objJson) =0;
	virtual std::string getAll() =0;
	virtual bool remove(std::string objJson) =0;

};
#endif
