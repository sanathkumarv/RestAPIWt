/* REST API For Search *
* Post implemented for search request upload */

#include <rest/restapi.h>
class SearchApi: public RestApi

{
	public:
	SearchApi();
	virtual std::string post(std::string objJson) ;
	virtual std::string get(std::string objJson) ;
	virtual std::string getAll() ;
	virtual bool remove(std::string objJson) ;

};
