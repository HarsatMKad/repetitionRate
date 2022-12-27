/***********************************************************
*   Автор: Кадесников Михаил                               *
*   Дата: 08.12.2022                                       *
*   Название: Частота повторений                           *
************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

struct symbol{
  char capitalLetter;
  char cursiveLetter;
  int count;
};

symbol alphabet[26];

int main() {
  fstream file;
  fstream filec;
  file.open("text");
  filec.open("text");

  if (!file.is_open()) {
    cout << "Файл не найден.";
    return -1;
  }

  alphabet[0] = { 'A', 'a', 0 };
  alphabet[1] = { 'B', 'b', 0 };
  alphabet[2] = { 'C', 'c', 0 };
  alphabet[3] = { 'D', 'd', 0 };
  alphabet[4] = { 'E', 'e', 0 };
  alphabet[5] = { 'F', 'f', 0 };
  alphabet[6] = { 'G', 'g', 0 };
  alphabet[7] = { 'H', 'h', 0 };
  alphabet[8] = { 'I', 'i', 0 };
  alphabet[9] = { 'J', 'j', 0 };
  alphabet[10] = { 'K', 'k', 0 };
  alphabet[11] = { 'L', 'l', 0 };
  alphabet[12] = { 'M', 'm', 0 };
  alphabet[13] = { 'N', 'n', 0 };
  alphabet[14] = { 'O', 'o', 0 };
  alphabet[15] = { 'P', 'p', 0 };
  alphabet[16] = { 'Q', 'q', 0 };
  alphabet[17] = { 'R', 'r', 0 };
  alphabet[18] = { 'S', 's', 0 };
  alphabet[19] = { 'T', 't', 0 };
  alphabet[20] = { 'U', 'u', 0 };
  alphabet[21] = { 'V', 'v', 0 };
  alphabet[22] = { 'W', 'w', 0 };
  alphabet[23] = { 'X', 'x', 0 };
  alphabet[24] = { 'Y', 'y', 0 };
  alphabet[25] = { 'Z', 'z', 0 };
  
  int countChar = 0;
  char ch;
  while (filec >> ch){
    ++countChar;
  }
  filec.close();

  char text[countChar];

  for (int index = 0; index < countChar; ++index) {
    file >> text[index]; 
    cout << text[index];
  }
  cout << endl << "частота повторения букв:" << endl;

  for (int indexTEXT = 0; indexTEXT < countChar; ++indexTEXT) {
    for (int indexABC = 0; indexABC < 26; ++indexABC){
      if(text[indexTEXT] == alphabet[indexABC].capitalLetter || text[indexTEXT] == alphabet[indexABC].cursiveLetter){
        if (text[indexTEXT + 1] == alphabet[indexABC].capitalLetter || text[indexTEXT + 1] == alphabet[indexABC].cursiveLetter){
          ++alphabet[indexABC].count;
        }
      }
    }
  }

  for (int indexTEXT = 0; indexTEXT < 26; ++indexTEXT){
    if(alphabet[indexTEXT].count != 0){
      cout << alphabet[indexTEXT].capitalLetter << " - " << alphabet[indexTEXT].count << endl;
    }
  }

  cout << "частота повторения двухбуквенных сочетаний:" << endl;
  int count = 0;
  int coun[countChar];
  for (int indexTEXT = 0; indexTEXT < countChar; ++indexTEXT) {
    for (int indexABC = indexTEXT; indexABC < countChar; ++indexABC){
      if (text[indexTEXT] == text[indexABC] && text[indexTEXT + 1] == text[indexABC + 1]) {
        ++count;  
      }      
    }
    coun[indexTEXT] = count;
    count = 0;
  }  

  for(int indexTEXT = 0;indexTEXT < countChar; ++indexTEXT) {
    for (int indexABC = indexTEXT + 1;indexABC < countChar; ++indexABC) {
      if (text[indexTEXT] == text[indexABC] && text[indexTEXT + 1] == text[indexABC + 1]) {
        int wasBefore=0;
          for(int indexWB = 0; indexWB < indexTEXT; ++indexWB){
            if(text[indexWB] == text[indexTEXT] && text[indexWB + 1] == text[indexTEXT + 1]) {
              wasBefore=1; 
              break;
            }
          }
          if(wasBefore == 0){
            cout << text[indexTEXT] << text[indexTEXT + 1] << " - " << coun[indexTEXT]  << endl;
          }
          break;
      }
    }
  }
    
  file.close();
  return 0;
}
