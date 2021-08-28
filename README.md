To run the application:
1) First, run **/AdvancedProgrammingTask2/Server/main.cpp**.  
2) Once you see this message in the console - <code>Listening on port: 54000</code> - run **/AdvancedProgrammingTask2/Client/main.cpp**.
3) The Client will be prompted to type first.  Once they type their message and press enter, the Server should see the Client's message in the console.
4) The Server can then type and message and press enter to send it to the Client, and so on.
5) The process can be terminated by entering "QUIT" in to the console at any time.

The Client and Server can be toggled by amending the Toggle.h files under Client and Server directories (by default, for testing purposes, SERVER is defined as false in the Client directory, and true in the Server directory).