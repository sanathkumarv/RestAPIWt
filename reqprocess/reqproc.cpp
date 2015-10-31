/* This program reads all pending requests and process the same */

/* Read all pending search requests
* for each search request
* Search books as per specified search criteria
* prepare an email with result set
* format: publisher title subject synapsis cost link-to-place-order
* update status as search processed
*/
#include "reqproc.h"
#include <util/CSmtp.h>

void RequestProcess::Process()
{
	db.connect();

	pbk = new Book(BSONObj(),db);

	Search s(BSONObj(), db) ;
	std::list<BSONObj> bres = s.getAll(1);
	std::list<BSONObj>::const_iterator i;

	for(i=bres.begin(); i!=bres.end(); ++i){
        	BSONObj v = (*i);
		//extrace email id
		std::string emailId = "varamballysanathkumar@gmail.com";
		if(v.hasField("custemail"))
		{
			emailId = v["custemail"].String();
		}

		std::list<BSONObj> bookslist = searchBook(v);		
		if(bookslist.size() >0)
		{	
			std::string emailBody = prepareEmailBody(bookslist);

			std::cout << emailBody << std::endl;
			sendEmail(emailId, emailBody);
		}
    	}


}
std::list<BSONObj> RequestProcess::searchBook(BSONObj &search)
{
	std::string s = "";//"{query:";
	int i=0;

	//search on ISBN if present in search
	
	BSONElement fval  ;
	std::list<BSONObj> bookslist;		
	if(search.hasField("isbn"))
	{
		fval =  search["isbn"];
		if(!fval.isNull())
		{
			s += "{"+  fval.toString()+ "}";
			i++;
		}
	}
	if(search.hasField("author"))
	{
		fval = search["author"];
		if(!fval.isNull())
		{
			if(i >0)
				s += " AND ";
			s += "{ "+ fval.toString() + "}";
			i++;
		}
	

	}
	if(search.hasField("title"))
	{
		fval = search["title"];
		if(!fval.isNull())
		{
			if(i >0)
				s += " AND ";
			s += "{"+ fval.toString() + "}";
			i++;
		}
	

	}

	if(s !="")
	{
		s += "{ query: " + s + "}";

		std::cout << "SearchBook: " << s << std::endl;

		return	pbk->get(s,1);
	}
	return bookslist;	
}
std::string RequestProcess::prepareTextBody(std::list<BSONObj> sr)
{

	std::string link ="http://192.168.1.191:8090/order/";
	 std::list<BSONObj>::const_iterator i;
        int fcount =0; // col count
        int rcount =0; // row count

	std::string strHead = "Subject\t\t\t\tTitle\t\tAuthor\t\tPrice\t\tPublisher\t\tClick to Order\n";
	std::string htmlBody = "";

        for(i=sr.begin(); i!=sr.end(); ++i){
                fcount = 0;
                BSONObj v = (*i);

        std::cout << "SR: " << v << std::endl;

                BSONElement fval  ;
                std::string colVal = "";
                std::string rw = "";

                if(v.hasField("subject"))
                {
                        fcount++;
                        fval = v["subject"];
                        colVal = fval.String();
                }
                rw += colVal +"\t\t";
                colVal = "";
 if(v.hasField("title"))
                {
                        fcount++;      

                        fval = v["title"];
                        colVal = fval.String();
                }
                rw += colVal +"\t\t";
                colVal = "";

                if(v.hasField("author"))
                {
                        fcount++;      

                        fval = v["author"];
                        colVal = fval.String();
                }
                rw += colVal +"\t\t";
                colVal = "";
                if(v.hasField("price"))
                {

                        fcount++;      
                        fval = v["price"];
                        colVal = fval.String();
                }
                rw += colVal +"\t\t";
                colVal = "";
                if(v.hasField("publisher"))
                {

                        fcount++;      
                        fval = v["publisher"];
                        colVal = fval.String();
                }
                rw += colVal +"\t\t";
		if(v.hasField("_id"))
                {

                        fval = v["_id"];
        std::cout << fval << std::endl;

                        colVal = fval.OID().toString();
                }

                rw += link +"?id="+ colVal+ "\n";
                if(fcount >0)
                {
                        htmlBody += rw;
                        rcount++;
                }

        }


        return  strHead + htmlBody;

}
std::string RequestProcess::prepareEmailBody(std::list<BSONObj> sr)
{
	return prepareTextBody( sr);
}
std::string RequestProcess::prepareHtmlBody(std::list<BSONObj> sr)
{
	std::string link ="<a href =http://192.168.1.191:8090/";
	std::string htmlHead = "<html><h1>Your Book Search Result</h1>";
	std::string htmlTail = "</html>";
	std::string htmlStyle = "<head> <style>table { border-collapse: collapse; } table, th, td { border: 1px solid black; }  </style> </head>";

	std::string htmlBody = "<body><table width=800><tr><td><b>Subject</b></td><td>Title</td><td>Author</td><td><b>Price</b></td><td>Publisher</td><td>Click to Order</td></tr>";

	std::list<BSONObj>::const_iterator i;
	int fcount =0; // col count
	int rcount =0; // row count
	for(i=sr.begin(); i!=sr.end(); ++i){
		fcount = 0;	
        	BSONObj v = (*i);

	std::cout << "SR: " << v << std::endl;

		BSONElement fval  ;
		std::string colVal = "";
		std::string rw = "<tr>";

		if(v.hasField("subject"))
		{
			fcount++;	
			fval = v["subject"];
			colVal = fval.String();
		}
		rw += "<td>" +colVal +"</td>";
		colVal = "";

		if(v.hasField("title"))
		{
			fcount++;	
		
			fval = v["title"];
			colVal = fval.String();
		}
		rw += "<td>" +colVal +"</td>";
		colVal = "";
	
		if(v.hasField("author"))
		{
			fcount++;	
		
			fval = v["author"];
			colVal = fval.String();
		}
		rw += "<td>" +colVal +"</td>";
		colVal = "";
		if(v.hasField("price"))
		{
		
			fcount++;	
			fval = v["price"];
			colVal = fval.String();
		}
		rw += "<td>" +colVal +"</td>";
		colVal = "";
		if(v.hasField("publisher"))
		{
		
			fcount++;	
			fval = v["publisher"];
			colVal = fval.String();
		}
		rw += "<td>" +colVal +"</td>";
		colVal = "";

		if(v.hasField("_id"))
		{
		
			fval = v["_id"];
	std::cout << fval << std::endl;

			colVal = fval.OID().toString();
		}

		rw += "<td>" +link +"?id="+ colVal +">Place Order</a></td></tr>";
		if(fcount >0)
		{
			htmlBody += rw;
			rcount++;
		}

	}

	htmlBody += "</table></body>";

	return htmlHead + htmlStyle +  htmlBody+ htmlTail;

}
bool RequestProcess::sendEmail(std::string emailid, std::string emailBody)
{
 bool bError = false;

        try
        {
                CSmtp mail;
                mail.SetSMTPServer("smtp.gmail.com",465);
                mail.SetSecurityType(USE_SSL);
std::cout << "To:" << emailid << std::endl;

                mail.SetLogin("varamballysanathkumar@gmail.com");
                mail.SetPassword("Gayathri123");
                mail.SetSenderName("Sanath");
                mail.SetSenderMail("demosanath@gmail.com");
                mail.SetReplyTo("demosanath@gmail.com");
                mail.SetSubject("Your Books Search Results ");
                mail.SetSubject("Your Books Search Results ");
                mail.AddRecipient(emailid.c_str());
                mail.SetXPriority(XPRIORITY_NORMAL);
                mail.SetXMailer("The Bat! (v3.02) Professional");
                mail.AddMsgLine("Hello,");
                mail.AddMsgLine("");
                mail.AddMsgLine("");
                mail.AddMsgLine(emailBody.c_str());
                mail.AddMsgLine("");
                mail.AddMsgLine("Regards");
                mail.ModMsgLine(5,"regards");
                mail.DelMsgLine(2);
                mail.AddMsgLine("Books Sales Service");

                //mail.AddAttachment("../test1.jpg");
                //mail.AddAttachment("c:\\test2.exe");
                //mail.AddAttachment("c:\\test3.txt");
                mail.Send();
        }
        catch(ECSmtp e)
        {
                std::cout << "Error: " << e.GetErrorText().c_str() << ".\n";
                bError = true;
        }
	if(!bError)
                std::cout << "Mail was send successfully.\n";

	return true;
}
bool RequestProcess::updateStatus(std::string id)	
{

	return true;
}
int main()
{
	RequestProcess p;
	p.Process();

}
