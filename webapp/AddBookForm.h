
#ifndef ADDBOOKFORM_H
#define ADDBOOKFORM_H
#define BOOST_SIGNALS_NO_DEPRECATION_WARNING

#include <Wt/WTable>

using namespace Wt;

namespace Wt {
  class WContainerWidget;
  class WText;
  class WTextArea;
  class WLineEdit;
  class WComboBox;
  class WFormWidget;
  class WDatePicker;
}

class AddBookForm : public WTable
{
public:
  AddBookForm(WContainerWidget *parent = 0);

private:
  void publisherChanged();

  void submit(); 

  void createUI();
 
  WContainerWidget *feedbackMessages_;
//subject, title, author,synopsis, date-of-publish,ISBN, q-code, price


  WComboBox *publisherEdit_;
  WLineEdit *subjectEdit_;
  WLineEdit *titleEdit_;
  WLineEdit *authorEdit_;

  WTextArea *synopsisEdit_;

  WDateEdit *publishDateEdit_;
  WLineEdit *SBNEdit_;
  WLineEdit *priceEdit_;
  WLineEdit *qcodeEdit_;


  void addValidationStatus(int row, WFormWidget *field);

  bool validate();

  bool checkValid(WFormWidget *edit, const WString& text);
};
#endif 

