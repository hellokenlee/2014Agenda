<!DOCTYPE html><html><head><meta charset="utf-8">
<title>README</title></head><body><p>2014Agenda project of SS.SYSU<br />
The socket version of Agenda Project.</p>
<p>==========<br />
<strong>Using boost::ptree lib to analyse JSON <br />
</strong>Using boost::asio lib to send and recive socket</p>
<p><strong>INSTRUCTION-ALL</strong><br />
1.To install boostlib ,just run:<br />
 $ sudo apt-get install libboost-all-dev //download boost lib</p>
<p>2.if your gcc version is lower than 4.7:<br />
    - change &ldquo;-std=c++11&rdquo; to &ldquo;-std=c++0x&rdquo;  in makefile(both in server/ and client)<br />
    - change &ldquo;std::array&rdquo; to &ldquo;boost::array&rdquo; in server/server.cpp and client/client.cpp (you can use ctrl+f to find) </p>
<p><strong>How to run Server</strong><br />
1. cd server<br />
2. make<br />
3. ./server<br />
4. press &ldquo;ctrl+C&rdquo; to stop server<br />
5. YOU CAN ONLY RUN ONE SERVER AT THE SAME TIME!</p>
<p><strong>How to run CLient</strong><br />
1. cd ../client<br />
2. make<br />
3. ./client/Agenda<br />
4. run ./server/server<br />
5. YOU CAN RUN AS MANY CLIENT AS YOU LIKE.<br />
6. follow the screen instructs to quit client</p>
<p><strong>TODO</strong><br />
1. use function pointer to replace if()else() in server.<br />
2. change json format to suit function pointer.<br />
==========</p>
<p>2014Agenda project of SS.SYSU</p></body></html>