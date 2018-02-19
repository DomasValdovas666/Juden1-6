#pragma once
#ifndef CLIENTMAIN_H
#define CLIENTMAIN_H

#include<string>

using namespace std;

namespace game{
    namespace net{
        class Client{
        public:
            Client(string,int,int);
        private:
            void connect();
            void update();
            string ipAddress;
            int tcpPort,udpPort;
        };
    }
}

#endif /* CLIENTMAIN_H */

