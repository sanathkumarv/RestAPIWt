#include <Wt/HttpClient>
bool Post(std::string url, std::string pdata)
{

	Http::Client *client = new Http::Client(this);
   	client->setTimeout(15);
   	client->setMaximumResponseSize(10 * 1024);
   	client->done().connect(boost::bind(&MyWidget::handleHttpResponse, this, _1, _2));
//   	if (client->get("http://www.webtoolkit.eu/wt/blog/feed/"))
	Http::Message msg;
	msg.setHeader ("Content-type","application/json");
   	if (client->post(url,pdata))
     		WApplication::instance()->deferRendering();
   	} else {
     		// in case of an error in the %URL
   	}
}
void handleHttpResponse(boost::system::error_code err, const Http::Message& response)
{
   WApplication::instance()->resumeRendering();
   if (!err && response.status() == 200) {
      ... parse response.body()
   }
}
