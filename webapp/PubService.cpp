/* Book Publisher - Booking Service **/
#include <MainForm.h>
#include <Wt/WApplication>
#include <Wt/WBootstrapTheme>
#include <Wt/WMenu>
#include <Wt/WStackedWidget>
#include <Wt/WText>
#include <Wt/WGlobal>
#include <AddBookForm.h>
#include <SearchReqForm.h>
using namespace Wt;

WApplication *createApplication(const WEnvironment& env)
{
  	WApplication *app = new WApplication(env);
  	app->messageResourceBundle().use(WApplication::appRoot() + "PublishService");
  	app->setTitle("Publishing Service");
	MainForm *mainForm = new MainForm();
  	app->root()->addWidget(mainForm);

  	WCssDecorationStyle langStyle;
  	langStyle.font().setSize(WFont::Smaller);
	  langStyle.setCursor(PointingHandCursor);
	  langStyle.setForegroundColor(blue);
	  langStyle.setTextDecoration(WCssDecorationStyle::Underline);
	  app->styleSheet().addRule(".lang", langStyle);

	  langStyle.setCursor(ArrowCursor);
	  langStyle.font().setWeight(WFont::Bold);
  	app->styleSheet().addRule(".langcurrent", langStyle);
  	app->setTheme(new WBootstrapTheme());
	//app->setCssTheme("polished");


	// create the stack where the contents will be located
	Wt::WStackedWidget *contents = new Wt::WStackedWidget(mainForm);

/*****
	// create a menu
	Wt::WMenu *menu = new Wt::WMenu(contents,Wt::Horizontal, mainForm);
	menu->setStyleClass("nav nav-pills nav-stacked");
	menu->setWidth(150);
	// add four items using the default lazy loading policy.
	menu->addItem("Introduction", new WText("intro"));
	menu->addItem("Download", new WText("Not yet available"));
	mainForm->addWidget(contents);
***/
	/*
	AddBookForm *form = new AddBookForm(mainForm);
  	form->setMargin(20);
	*/
	SearchReqForm *form = new SearchReqForm(mainForm);
  	form->setMargin(20);

  return app;
}

int main(int argc, char **argv)
{
   return WRun(argc, argv, &createApplication);
}

