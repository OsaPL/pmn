#include <windows.h>
#include <winsock.h>
#include <iostream>
#include <iterator>
#include <exception>
#include <algorithm>
#include <iomanip>

class use_WSA { 
    WSADATA d; 
    WORD ver;
public:
    use_WSA() : ver(MAKEWORD(1,1)) { 
        if ((WSAStartup(ver, &d)!=0) || (ver != d.wVersion))
            throw(std::runtime_error("Error starting Winsock"));
    }
    ~use_WSA() { WSACleanup(); }    
};

int main(int argc, char **argv) {
    if ( argc < 2 ) {
        std::cerr << "Usage: resolve <hostname>";
        return EXIT_FAILURE;
    }

    try { 
        use_WSA x;

        hostent *h = gethostbyname(argv[1]);
        unsigned char *addr = reinterpret_cast<unsigned char *>(h->h_addr_list[0]);
        std::copy(addr, addr+4, std::ostream_iterator<unsigned int>(std::cout, "."));
    }
    catch (std::exception const &exc) {
        std::cerr << exc.what() << "\n";
        return EXIT_FAILURE;
    }

    return 0;
}
