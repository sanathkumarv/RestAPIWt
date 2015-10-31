/* Interface class for all rest entity map */
#include <rest/restapi.h>
class PublisherApi: public RestApi
{
	public:
	PublisherApi();
	virtual std::string post(std::string objJson) ;
	virtual std::string get(std::string objJson) ;
	virtual std::string getAll() ;
	virtual bool remove(std::string objJson) ;

};
