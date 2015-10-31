
#include <iostream>
using  namespace std;
#include <cstdlib>
#include "mongo/client/dbclient.h" // for the driver

void run() {
  mongo::DBClientConnection c;
  c.connect("localhost");//mongodb://sanathkumarv:Sumantha123@ds031613.mongolab.com:31613/skv");
}

int main() {
    mongo::client::initialize();
    try {
        run();
        std::cout << "connected ok" << std::endl;
    } catch( const mongo::DBException &e ) {
        std::cout << "caught " << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
