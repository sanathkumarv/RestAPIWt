#include <rest/ApiService.h>

using namespace Wt;

ApiService::ApiService(ApiRouter &r)
{
	router = r;
	//add all paths
}
 void ApiService::ServerSetup(WServer &s)
{
	std::map<std::string, RestApi *> m =router.getEntries();

	std::map<std::string,RestApi *>::iterator it;
	for ( it=m.begin(); it!=m.end(); ++it)
	{
        	s.addResource(this, it->first);
	}

}
void ApiService::handleRequest(const Wt::Http::Request &request, Wt::Http::Response &response)
{
	std::string method = request.method();

	std::cout << "ApiService::handleRequest method="<< method << " path=" << request.path()<< std::endl;

	if(method == "GET")
	{
		processGet(request,response);
	}
	else if(method == "POST")
	{
		processPost(request, response);
	}

}
void ApiService::processPost(const Wt::Http::Request &request, Wt::Http::Response &response)
{

        std::string path = request.path();
        std::string jsonPayload ;
        if(request.contentType() == "application/json")
        {
                int len = request.contentLength() ;
                std::istream & in = request.in();

                std::ostringstream buf;
                buf <<  in.rdbuf();
                jsonPayload =  buf.str();
        }
        else
        if(request.contentType() == "application/x-www-form-urlencoded")
        {
                //content in parameter
        }
        RestApi * pApi = router.getEntry(path);
        if(pApi)
        {
		std::string strval = 	pApi->post(jsonPayload);
		response.out() << strval ;
        }
	
}
void ApiService::processGet(const Wt::Http::Request &request, Wt::Http::Response &response)
{

        std::string path = request.path();
        std::string jsonPayload ;
	Wt::Http::ParameterMap map ;
	std::cout << "ApiService::processGet"<<" contentType=" << request.contentType()<< std::endl;

        if(request.contentType() == "application/json")
        {
                int len = request.contentLength() ;
                std::istream & in = request.in();

                std::ostringstream buf;
                buf <<  in.rdbuf();
                jsonPayload =  buf.str();
        }
        else
        if(request.contentType() == "application/x-www-form-urlencoded")
        {
                //content in parameter
		map = request.getParameterMap();	
        }
        RestApi * pApi = router.getEntry(path);
        if(pApi)
        {
                std::string strval ;

		if(map.size() >0)
		{
	        	strval =    pApi->get(jsonPayload);
		}
		else
		{
			std::cout << "ApiService::processGet before getAll"<< std::endl;
	        	strval =    pApi->getAll();

		}
		std::cout << strval << std::endl;
                response.out() << strval <<std::endl ;
        }
      
}


