#include <Wt/WServer>
#include <Wt/WResource>
#include <Wt/Http/Response>
#include <rest/ApiRouter.h>

using namespace Wt;
class ApiService : public WResource
{
    protected:
	ApiRouter router;
    public:
        virtual ~ApiService(){}

	 ApiService(ApiRouter &r) ;
	void ServerSetup(WServer &s);

    protected:
        virtual void handleRequest(const Wt::Http::Request &request, Wt::Http::Response &response);
	void processPost(const Wt::Http::Request &request, Wt::Http::Response &response);
	void processGet(const Wt::Http::Request &request, Wt::Http::Response &response);
	
};

