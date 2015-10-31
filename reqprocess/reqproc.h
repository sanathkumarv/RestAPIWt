/* This program reads all pending requests and process the same */

/* Read all pending search requests
* for each search request
* Search books as per specified search criteria
* prepare an email with result set
* format: publisher title subject synapsis cost link-to-place-order
* update status as search processed
*/
#include <iostream>

#include <entity/search.h>
#include <entity/book.h>

class RequestProcess
{
	public:
	RequestProcess() {}

	void Process();
	protected:
	mongoWrapper db;
	Book *pbk;

	std::list<BSONObj> searchBook(BSONObj &search);

	std::string prepareEmailBody(std::list<BSONObj> booksList);
	std::string prepareTextBody(std::list<BSONObj> booksList);
	std::string prepareHtmlBody(std::list<BSONObj> booksList);
	bool sendEmail(std::string emailid, std::string emailBody);
	bool updateStatus(std::string id);	

};
