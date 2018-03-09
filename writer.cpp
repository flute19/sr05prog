#include <iostream>
#include <string>
#include "windows.h"
#include <ctype.h>

using namespace std;

int main(){
    static string msg;
    while(1){

        bool noString = true;
		bool quit = false;

        while(noString){
            static string msgBis;
            cout<<"Saisissez votre message"<<endl;
            cin>>msgBis;
            if(msgBis.compare("@") == 0){
				quit = true;
				return 0;
			}
            cerr<<" std err: réception de: "<< msgBis <<endl;


            if(msgBis == "") break;
              else msg = msgBis;

            for(int i=0; i<msg.length();  i++){
                if(!isalpha(msg[i])) {
                 cerr<<"cerr: please put only letter"<<endl;
                 break;
                }
                else if(i== msg.length()-1 ) noString = false;
            }
        }

        cout<< msg <<endl;
		Sleep(1000);
    }
	return 0;
}


/*std::string readStdIn()
{
    struct pollfd pfd = { STDIN_FILENO, POLLIN, 0 };

    std::string line;
    int ret = 0;
    while(ret == 0)
    {
        ret = poll(&pfd, 1, 1000);  // timeout of 1000ms
        if(ret == 1) // there is something to read
        {
            std::getline(std::cin, line);
        }
        else if(ret == -1)
        {
            std::cout << "Error: " << strerror(errno) << std::endl;
        }
    }
    return line;
}
*/
