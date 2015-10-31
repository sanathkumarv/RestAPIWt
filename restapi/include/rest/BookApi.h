/* Interface class for all rest entity map */
#include <rest/restapi.h>
class BookApi: public RestApi
{
	public:
	BookApi();
	virtual std::string post(std::string objJson) ;
	virtual std::string get(std::string objJson) ;
	virtual std::string getAll() ;
	virtual bool remove(std::string objJson) ;

};
