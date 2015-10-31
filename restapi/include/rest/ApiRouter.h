/* This class maps between all rest service api path to implementations */
#ifndef APIROUTER_H
#define APIROUTER_H
#include <iostream>
#include <map>
#include <rest/restapi.h>
class ApiRouter
{
	protected:
	std::map <std::string , RestApi *> oApi;

	public:

		void addEntry(std::string path, RestApi *);
		std::map<std::string ,RestApi *> getEntries();
		RestApi * getEntry(std::string path);
		
};
#endif

