
#include <MainForm.h>
#include <AddBookForm.h>

#include <Wt/WApplication>
#include <Wt/WText>
#include <Wt/WStringUtil>

MainForm::MainForm(WContainerWidget *parent)
  : WContainerWidget(parent)
{
  WContainerWidget *langLayout = new WContainerWidget(this);
  langLayout->setContentAlignment(AlignRight);

/*
  new WText(tr("language"), langLayout);
  const char *lang[] = { "en", "nl" };

  for (int i = 0; i < 2; ++i) {
    WText *t = new WText(widen(lang[i]), langLayout);
    t->setMargin(5);
    t->clicked().connect(this, &FormExample::changeLanguage);

    languageSelects_.push_back(t);
  }

  setLanguage(wApp->locale().name());

  AddBookForm *form = new AddBookForm(this);
  form->setMargin(20);
*/
}


