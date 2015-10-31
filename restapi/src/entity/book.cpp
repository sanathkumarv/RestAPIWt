
/* Entity class for Book */
#include <db/constants.h>
#include <entity/book.h>
#include <util/jsonhelper.h>
using mongo::BSONObj;

Book::Book(mongo::BSONObj obj , mongoWrapper &con)
{
	pCon = & con;
	pBsonObj = & obj;
}
std::string Book::addNew()//save new book and return ID
{
	
	return 	pCon->insert(DB_BOOKS , *pBsonObj);
}
std::string Book::get(std::string search) // return all books for a search crtieria
{
		
	std::list<BSONObj> list = get(search, 1);
	JsonHelper h;
	return h.BSONArray2JSONStr(list);
}
std::string Book::getAll() // return all books as JSON Array String
{

	std::list<BSONObj> list = pCon->getAll(DB_BOOKS);
	
	JsonHelper h;
	return h.BSONArray2JSONStr(list);

}

std::list<BSONObj> Book::get(std::string search, int notused) // return all books for a search crtieria in List
{
	std::list<BSONObj> list = pCon->getAll(DB_BOOKS, search);
	return list;
	
}
