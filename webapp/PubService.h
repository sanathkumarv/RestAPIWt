#ifndef PUBSERVICE_H
#define PUBSERVICE_H

#include <Wt/WContainerWidget>

namespace Wt {
  class WText;
}

using namespace Wt;

class PubService : public WContainerWidget
{
public:
  FormExample(WContainerWidget *parent = 0);

private:
  std::vector<WText *> languageSelects_;

  /*!\brief Change the language.
   */
  void changeLanguage();

  void setLanguage(const std::string lang);
};


#endif 

