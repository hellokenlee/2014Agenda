2014Agenda project of SS.SYSU
The socket version of Agenda Project.

==========
**Using boost::ptree lib to analyse JSON 
**Using boost::asio lib to send and recive socket

**INSTRUCTION-ALL**
1.To install boostlib ,just run:
 $ sudo apt-get install libboost-all-dev //download boost lib

2.if your gcc version is lower than 4.7:
	- change "-std=c++11" to "-std=c++0x"  in makefile(both in server/ and client)
	- change "std::array" to "boost::array" in server/server.cpp and client/client.cpp (you can use ctrl+f to find) 

**How to run Server**
1. cd server
2. make
3. ./server
4. press "ctrl+C" to stop server
5. YOU CAN ONLY RUN ONE SERVER AT THE SAME TIME!

**How to run CLient**
1. cd ../client
2. make
3. ./client/Agenda
4. run ./server/server
5. YOU CAN RUN AS MANY CLIENT AS YOU LIKE.
6. follow the screen instructs to quit client

**TODO**
1. use function pointer to replace if()else() in server.
2. change json format to suit function pointer.
==========

2014Agenda project of SS.SYSU
