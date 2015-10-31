#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WDateEdit>
#include <Wt/WSelectionBox>
#include <Wt/WContainerWidget>
#include <Wt/WImage>
#include <Wt/WIntValidator>
#include <Wt/WLabel>
#include <Wt/WLineEdit>
#include <Wt/WPushButton>
#include <Wt/WTableCell>
#include <Wt/WTextArea>
#include <Wt/WText>
#include<Wt/WFileUpload>
#include<Wt/WProgressBar>
#include <SearchReqForm.h>
#include <functional>

#include<Wt/Json/Object>
#include<Wt/Json/Value>

using namespace Wt;

	std::string  serialize(Json::Object bookjsn)
	{
		std::map<std::string,Json::Value> ::iterator it;
		std::string strval ="";
		int n = 0;
	 	for(it=bookjsn.begin(); it!=bookjsn.end(); ++it)
		{
			std::string v = it->second.toString();

			 std::string sval = "\"" + it->first + "\": \"" + v + "\"";
			strval += sval;
	
    			//std::cout << it->first << " => " << it->second << '\n';
			if(n < bookjsn.size()-1)
				strval += ",";	
			n++;
		}
		return "{" + strval + "}";

	}

SearchReqForm::SearchReqForm(WContainerWidget *parent ) : WTable(parent)
{
	createUI();
}


void SearchReqForm::submit()
{
	if (validate()) {
    		// do something useful with the data...
    	std::wstring title = titleEdit_->text() ;
    	std::wstring subject = subjectEdit_->text();
    	std::wstring author = authorEdit_->text();
    	std::wstring isbn = SBNEdit_->text();
    	std::wstring emailid = emailEdit_->text();
    	std::wstring custname = nameEdit_->text();

	std::string strbookjson = "";
	Wt::Json::Object bookjsn;

	if(title != "")
	{
		bookjsn["title"] = Wt::Json::Value(title);
	}
	if(subject != "")
	{
		bookjsn["subject"] = Wt::Json::Value(subject);
	}
	if(author != "")
	{
		bookjsn["author"] = Wt::Json::Value(author);
	}
	if(isbn != "")
	{
		bookjsn["isbn"] = Wt::Json::Value(isbn);
	}
	if(emailid != "")
	{
		bookjsn["custemail"] = Wt::Json::Value(emailid);
	}
	if(custname != "")
	{
		bookjsn["custname"] = Wt::Json::Value(custname);
	}

std::cout << "submit before upload ..." << std::endl;
	strbookjson = serialize(bookjsn);
std::cout << "json  ..." << strbookjson << std::endl;

    	qcodeFu->upload();
		std::cout << "submit aftr upload ..." << std::endl;

	// React to a file upload problem.
	qcodeFu->fileTooLarge().connect(std::bind([=] () {
		feedbackMessages_->addWidget(new WText("File is too large."));

	}));
	// React to a succesfull upload.
	qcodeFu->uploaded().connect(std::bind([=] () {
    		//out->setText("File upload is finished.");
		std::string spoolf = qcodeFu->spoolFileName();

		// Now Post the data to API
		//prepare data
		
		if(Post("http://192.168.1.191:8080/api/Search",  strbookjson))
		{
		}
		else
		{

		}
	}));

  }


}

void SearchReqForm::createUI()
{
	WLabel *label;
  	int row = 0;


  	// Title
  	elementAt(row, 0)->setColumnSpan(3);
  	elementAt(row, 0)->setContentAlignment(AlignTop | AlignCenter);
  	elementAt(row, 0)->setPadding(10);
  	WText *caption = new WText(tr("srf.form"), elementAt(row, 0));
  	caption->decorationStyle().font().setSize(WFont::XLarge);

  	// error messages
  	++row;
  	elementAt(row, 0)->setColumnSpan(3);
  	feedbackMessages_ = elementAt(row, 0);
  	feedbackMessages_->setPadding(5);

  	WCssDecorationStyle& errorStyle = feedbackMessages_->decorationStyle();
  	errorStyle.setForegroundColor(Wt::red);
  	errorStyle.font().setSize(WFont::Smaller);
  	errorStyle.font().setWeight(WFont::Bold);
  	errorStyle.font().setStyle(WFont::Italic);

	//user name & email address
std::cout << "Publisher combo fill..." << std::endl;
  	++row;

  	nameEdit_ = new WLineEdit(elementAt(row, 2));
  	label = new WLabel(tr("srf.name"), elementAt(row, 0));
  	label->setBuddy(nameEdit_);
  	nameEdit_->enterPressed().connect(this, &SearchReqForm::submit);

  	++row;
  	emailEdit_ = new WLineEdit(elementAt(row, 2));
  	label = new WLabel(tr("srf.mail"), elementAt(row, 0));
  	label->setBuddy(emailEdit_);

  	// Subject

  	++row;
  	subjectEdit_ = new WLineEdit(elementAt(row, 2));
  	label = new WLabel(tr("srf.subject"), elementAt(row, 0));
  	label->setBuddy(subjectEdit_);
  	subjectEdit_->enterPressed().connect(this, &SearchReqForm::submit);

std::cout << "Book title fill..." << std::endl;
  	// Book title 

  	++row;
  	titleEdit_ = new WLineEdit(elementAt(row, 2));
  	label = new WLabel(tr("srf.title"), elementAt(row,0));
  	label->setBuddy(titleEdit_);


  	// Author  

  	++row;
  	authorEdit_ = new WLineEdit(elementAt(row, 2));
  	label = new WLabel(tr("srf.author"), elementAt(row,0));
  	label->setBuddy(authorEdit_);


std::cout << " ISBN   fill..." << std::endl;
	  // SBIN 
	  ++row;
	  SBNEdit_ = new WLineEdit( elementAt(row, 2));
	  label = new WLabel(tr("srf.sbin"), elementAt(row, 0));
	  label->setBuddy(SBNEdit_);


	//qr code
  	 ++row;
	  //qcodeEdit_ = new WLineEdit("", elementAt(row, 2));

	++row;
	qcodeFu = new WFileUpload(elementAt(row,2));
	qcodeFu->setFileTextSize(200); // Set the maximum file size to 200 kB.
	qcodeFu->setProgressBar(new Wt::WProgressBar());
	qcodeFu->setMargin(10, Wt::Right);
	//qcodeFu->setFilters("image/*");

	 label = new WLabel(tr("srf.qcode"),
		     elementAt(row, 0));
	  //label->setBuddy(qcodeFu);

/**
	// Provide a button to start uploading.
	Wt::WPushButton *uploadButton = new Wt::WPushButton("Send", elementAt(row,3));
	uploadButton->setMargin(10, Wt::Left | Wt::Right);
	// Upload when the button is clicked.
	uploadButton->clicked().connect(std::bind([=] () {
    //		qcodeFu->upload();
//    		uploadButton->disable();
	}));
**/
	// Upload automatically when the user entered a file.
/*
	qcodeFu->changed().connect(std::bind([=] () {
    		qcodeFu->upload();
 //   		uploadButton->disable();
	}));
*/
  	// Submit
std::cout << " submit   fill..." << std::endl;
  	++row;
  	WPushButton *submit = new WPushButton(tr("submit"),
					elementAt(row, 0));
  	submit->clicked().connect(this, &SearchReqForm::submit);
  	submit->setMargin(15, Top);
  	elementAt(row, 0)->setColumnSpan(3);
  	elementAt(row, 0)->setContentAlignment(AlignTop | AlignCenter);

  	// Set column widths for label and validation icon
  	elementAt(2, 0)->resize(WLength(30, WLength::FontEx), WLength::Auto);
  	elementAt(2, 1)->resize(20, WLength::Auto);

std::cout << "return from creat ui..." << std::endl;
}

void SearchReqForm::addValidationStatus(int row, WFormWidget *field)
{
}

bool SearchReqForm::validate()
{
	feedbackMessages_->clear();
  	bool valid = true;

  	if (!checkValid(titleEdit_, tr("error.title")))
    		valid = false;
  	if (!checkValid(subjectEdit_, tr("error.subject")))
    		valid = false;
  	if (!checkValid(authorEdit_, tr("error.author")))
    		valid = false;
  	if (!checkValid(SBNEdit_, tr("error.sbin")))
    		valid = false;

  	return valid;

}
bool SearchReqForm::checkValid(WFormWidget *edit, const WString& text)
{

	if (edit->validate() != WValidator::Valid) {
    		feedbackMessages_->addWidget(new WText(text));
   		 feedbackMessages_->addWidget(new WBreak());
    		edit->label()->decorationStyle().setForegroundColor(Wt::red);
    		edit->setStyleClass("Wt-invalid");

    		return false;
  	} else {
    		edit->label()->decorationStyle().setForegroundColor(WColor());    
    		edit->setStyleClass("");

    		return true;
  	}

}

bool SearchReqForm::Post(std::string url, std::string pdata)
{

	Http::Client *client = new Http::Client();
   	client->setTimeout(30);
   	client->setMaximumResponseSize(10 * 1024);
   	client->done().connect(boost::bind(&SearchReqForm::handleHttpResponse, this, _1, _2));
//   	if (client->get("http://www.webtoolkit.eu/wt/blog/feed/"))
	Http::Message *msg = new Http::Message();
	msg->setHeader ("Content-type","application/json");
	msg->addBodyText(pdata);
   	if (client->post(url,*msg))
	{
		std::cout << "Post " << url << std::endl;

     		WApplication::instance()->deferRendering();
   	} else {
     		// in case of an error in the %URL
   	}
}
void SearchReqForm::handleHttpResponse(boost::system::error_code err, const Http::Message& response)
{
		std::cout << "httpresponse " << std::endl;
   WApplication::instance()->resumeRendering();
   if (!err && response.status() == 200) {
	std::cout << "Post returned 200 OK" << std::endl;

      //... parse response.body()
	    	clear();
    		new WText(WString::fromUTF8("<p>Thanks for your query, We will get back to you soon {1}</p>").arg(""), elementAt(0, 0));
    		wApp->quit();
   }
}
