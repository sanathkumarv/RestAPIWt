#include <Wt/WServer>
#include <Wt/WResource>
#include <Wt/Http/Response>

using namespace Wt;

class RestGetHello : public Wt::WResource
{
    public:
        virtual ~RestGetHello(){}

    protected:
        virtual void handleRequest(const Wt::Http::Request &request, Wt::Http::Response &response)
        {
		std::string method = request.method();

		if(method == "GET")

			response.out() << "Hello World! " << request.path() <<"\n";
		else
			response.out() <<" Not get \n";
        }
};


int main(int argc, char **argv)
{
    try {
        WServer server(argv[0]);

        server.setServerConfiguration(argc, argv);

        RestGetHello getHello;

        server.addResource(&getHello, "/api/hello");

        if (server.start()) {
            WServer::waitForShutdown();
            server.stop();
        }
    } catch (WServer::Exception& e) {
        std::cerr << e.what() << std::endl;
    } catch (std::exception &e) {
        std::cerr << "exception: " << e.what() << std::endl;
    }
}


