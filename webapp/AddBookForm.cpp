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

#include <AddBookForm.h>

using namespace Wt;


AddBookForm::AddBookForm(WContainerWidget *parent ) : WTable(parent)
{
	createUI();
}

void AddBookForm::publisherChanged()
{
}

void AddBookForm::submit()
{
	if (validate()) {
    		// do something useful with the data...
    	std::wstring title = titleEdit_->text() ;

    	std::wstring subject = subjectEdit_->text();

    	clear();

    	new WText(WString::fromUTF8("<p>Thank you, {1}, "
				"for all this precious data.</p>").arg(title),
	      elementAt(0, 0));

    	wApp->quit();
  }


}

void AddBookForm::createUI()
{
	WLabel *label;
  	int row = 0;

  	// Title
  	elementAt(row, 0)->setColumnSpan(3);
  	elementAt(row, 0)->setContentAlignment(AlignTop | AlignCenter);
  	elementAt(row, 0)->setPadding(10);
  	WText *caption = new WText(tr("abf.form"), elementAt(row, 0));
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
std::cout << "Publisher combo fill..." << std::endl;

  	// Publisher combo

  	++row;
  	publisherEdit_ = new WComboBox(elementAt(row, 2));
  	publisherEdit_->addItem("McGrow Hill");
  	publisherEdit_->addItem("Wrox Publications");
  	publisherEdit_->addItem("Ace Books");
  	publisherEdit_->addItem("Addison Wesley");
  	label = new WLabel(tr("abf.publisher"), elementAt(row, 0));
  	label->setBuddy(publisherEdit_);
  	publisherEdit_->setValidator(new WValidator(true));
  	publisherEdit_->changed().connect(this, &AddBookForm::publisherChanged);

  	// Subject

  	++row;
  	subjectEdit_ = new WLineEdit(elementAt(row, 2));
  	label = new WLabel(tr("abf.subject"), elementAt(row, 0));
  	label->setBuddy(subjectEdit_);
  	subjectEdit_->setValidator(new WValidator(true));
  	subjectEdit_->enterPressed().connect(this, &AddBookForm::submit);

std::cout << "Book title fill..." << std::endl;
  	// Book title 

  	++row;
  	titleEdit_ = new WLineEdit(elementAt(row, 2));
  	label = new WLabel(tr("abf.title"), elementAt(row,0));
  	label->setBuddy(titleEdit_);


  	// Author  

  	++row;
  	authorEdit_ = new WLineEdit(elementAt(row, 2));
  	label = new WLabel(tr("abf.author"), elementAt(row,0));
  	label->setBuddy(authorEdit_);

	// Synopsis
	++row;	
  	synopsisEdit_ = new WTextArea(elementAt(row, 2));
  	synopsisEdit_->setColumns(40);
  	synopsisEdit_->setRows(5);
  	label = new WLabel(tr("abf.synapsis"),
		     elementAt(row, 0));
  	label->setBuddy(synopsisEdit_);

  	// Publish  date
  	++row;

std::cout << " Publish date  fill..." << std::endl;
  	publishDateEdit_ = new WDateEdit(elementAt(row, 2));
	  publishDateEdit_->setBottom(WDate(1900, 1, 1));
	  publishDateEdit_->setTop(WDate::currentDate());
	  label = new WLabel(tr("abf.publishdate"), elementAt(row, 0));
	  label->setBuddy(publishDateEdit_);
	  publishDateEdit_->setFormat("dd/MM/yyyy");
	  publishDateEdit_->validator()->setMandatory(true);

std::cout << " SBIN   fill..." << std::endl;
	  // SBIN 
	  ++row;
	  SBNEdit_ = new WLineEdit( elementAt(row, 2));
	  label = new WLabel(tr("abf.sbin"), elementAt(row, 0));
	  label->setBuddy(SBNEdit_);
//	  SBNEdit_->validator()->setMandatory(true);

std::cout << " price   fill..." << std::endl;

	//price
	  ++row;
	  priceEdit_ = new WLineEdit("0", elementAt(row, 2));
	  label = new WLabel(tr("abf.price"),
		     elementAt(row, 0));
	  label->setBuddy(priceEdit_);
	  priceEdit_->setValidator(new WIntValidator(0,1000));

	//q code
  	 ++row;
	  qcodeEdit_ = new WLineEdit("", elementAt(row, 2));
	  label = new WLabel(tr("abf.qcode"),
		     elementAt(row, 0));
	  label->setBuddy(qcodeEdit_);
	  //qcodeEdit_->setValidator(new WIntValidator(0,1000));

  	// Submit
std::cout << " submit   fill..." << std::endl;
  	++row;
  	WPushButton *submit = new WPushButton(tr("submit"),
					elementAt(row, 0));
  	submit->clicked().connect(this, &AddBookForm::submit);
  	submit->setMargin(15, Top);
  	elementAt(row, 0)->setColumnSpan(3);
  	elementAt(row, 0)->setContentAlignment(AlignTop | AlignCenter);

  	// Set column widths for label and validation icon
  	elementAt(2, 0)->resize(WLength(30, WLength::FontEx), WLength::Auto);
  	elementAt(2, 1)->resize(20, WLength::Auto);

std::cout << "return from creat ui..." << std::endl;
}
/* 
subject, title, author,synopsis, date-of-publish,ISBN, q-code, price

*/

void AddBookForm::addValidationStatus(int row, WFormWidget *field)
{
}

bool AddBookForm::validate()
{
	feedbackMessages_->clear();
  	bool valid = true;

  	if (!checkValid(titleEdit_, tr("error.title")))
    		valid = false;
  	if (!checkValid(subjectEdit_, tr("error.subject")))
    		valid = false;
  	if (!checkValid(authorEdit_, tr("error.author")))
    		valid = false;
  	if (!checkValid(publishDateEdit_, tr("error.publishdate")))
    		valid = false;
  	if (!checkValid(priceEdit_, tr("error.price")))
    		valid = false;
  	if (!checkValid(SBNEdit_, tr("error.sbin")))
    		valid = false;
  	if (!checkValid(synopsisEdit_, tr("error.synopsis")))
    		valid = false;

  	return valid;

}
bool AddBookForm::checkValid(WFormWidget *edit, const WString& text)
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
