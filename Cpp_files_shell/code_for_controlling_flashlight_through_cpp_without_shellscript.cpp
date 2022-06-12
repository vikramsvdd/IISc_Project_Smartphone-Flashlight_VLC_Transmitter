#include <iostream>

#include <fstream>

using namespace std;

int main() {
  fstream myFile;
  myFile.open("/sys/class/leds/flashlight/brightness", >
 if (myFile.is_open()) {
    cout << "0";
    string str;
    while (1) {
      getline(std::cin, str);
      if (str == "-1")
        break;
      else {
        myFile << str << endl;
      }
    }
    myFile.close();
  } else {
    cout << "Sorry could not open file";
  }
}




/*#include <fstream>
#include <iostream>

using namespace std;

int main()
{
   ifstream ifs("/sys/class/leds/flashlight/brightness">
   if ( ! ifs.is_open() ) {
      cout <<" Failed to open" << endl;
   }
   else {
cout <<"Opened OK" << endl;

}
}*/

/*#include <iostream>
int main(){
system("echo 100 > ~/sys/class/leds/flashlight/brightne>
return 0;
}*/
