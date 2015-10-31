
#ifndef SEARCHREQFORM_H
#define SEARCHREQFORM_H
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING

#include <Wt/WTable>
#include <Wt/Http/Client>
#include <boost/system/error_code.hpp>
using namespace Wt;

namespace Wt {
  class WContainerWidget;
  class WText;
  class WTextArea;
  class WLineEdit;
  class WComboBox;
  class WFormWidget;
  class WDatePicker;
  class WFileUpload;
}

class SearchReqForm : public WTable
{
public:
  SearchReqForm(WContainerWidget *parent = 0);

private:

  void submit(); 

  void createUI();
 
  WContainerWidget *feedbackMessages_;
  //subject, title, author,ISBN, q-code file upload

  WLineEdit *subjectEdit_;
  WLineEdit *titleEdit_;
  WLineEdit *authorEdit_;

  WLineEdit *SBNEdit_;
  WLineEdit *priceEdit_;
  WLineEdit *qcodeEdit_;
  WLineEdit *emailEdit_;
  WLineEdit *nameEdit_;

  WFileUpload *qcodeFu; // File uploader 
  void addValidationStatus(int row, WFormWidget *field);

  bool validate();

  bool checkValid(WFormWidget *edit, const WString& text);
  void handleHttpResponse(boost::system::error_code err, const Http::Message& response);
  bool Post(std::string url, std::string pdata);
};
#endif 

