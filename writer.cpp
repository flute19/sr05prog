#include <iostream>
#include <string>
#include <unistd.h>
#include <sys/poll.h>
//#include "windows.h"
#include <ctype.h>

using namespace std;

string readStdIn()
{
  struct pollfd pfd = { STDIN_FILENO, POLLIN, 0 };

  string line;
  int ret = 0;

    //cout<<"Saisissez votre message"<<endl;
    ret = poll(&pfd, 1, 5000);  // timeout of 1000ms
    if(ret == 1) // there is something to read
    {
      getline(cin, line);
    }

  return line;
}

int main(){
  static string msg;
  bool first = true;

  while(1){

    bool noString = true;


    while(noString){
      static string msgBis;

      //cin>>msgBis;
      msgBis=readStdIn();
      // absence de message

      if (msgBis.length() == 0){
        // ième demande de changement de message
        if (first == false) {
          break;
        }
      }else{
      // message non vide
        cerr<<" cerr: reception de: "<< msgBis <<endl;

        // caractère de fin
        if(msgBis.compare("@") == 0){
          return 0;
        }

        // vérification des caractères
        for(int i=0; i<msgBis.length();  i++){
          if(!isalpha(msgBis[i])) {
             cerr<<"cerr: please put only letter"<<endl;
             break;
          }
          else if(i == msgBis.length()-1) {
            noString = false;
            if (first) first = false;
            msg = msgBis;
        }
      }


    }
    }
    cout<< msg <<endl;
  }
  return 0;
}
