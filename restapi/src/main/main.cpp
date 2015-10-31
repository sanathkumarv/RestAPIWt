#include <Wt/WServer>
#include <rest/ApiService.h>
#include <rest/ApiRouter.h>
#include <rest/PublisherApi.h>
#include <rest/BookApi.h>
#include <rest/SearchApi.h>
int main(int argc, char **argv)
{

    try {
        WServer server(argv[0]);

        server.setServerConfiguration(argc, argv);

	ApiRouter router;
	PublisherApi pubs;
	BookApi bks;
	SearchApi srch;
	
	router.addEntry("/api/Publisher", &pubs);
	router.addEntry("/api/Book", &bks);
	router.addEntry("/api/Search", &srch);
	
        ApiService apis(router);
	apis.ServerSetup(server);

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

