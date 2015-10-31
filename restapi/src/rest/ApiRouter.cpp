#include <rest/ApiRouter.h>


void ApiRouter::addEntry(std::string path, RestApi * api)
{
	oApi.insert(std::pair<std::string ,RestApi *>(path,api));
}
std::map<std::string ,RestApi *> ApiRouter::getEntries()
{
	return oApi;
}
RestApi * ApiRouter::getEntry(std::string path)
{
	return  oApi[path];
}	
