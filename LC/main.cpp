//
//  main.cpp
//  LCNew
//
//  Created by Abhishek Mishra on 16/08/22.
//

#include <iostream>
#include <map>
using namespace std;

void reverseStr(string &str, int i, int j)
{
    while(i <= j)
    {
        swap(str[i], str[j]);
        i++; j--;
    }
}

string smallestNumber(string pattern) {
    
    if((int)pattern.size() <= 0)
        return "";

    std::map<int, string> lengthMap;
    lengthMap[1] = "12";
    lengthMap[2] = "123";
    lengthMap[3] = "1234";lengthMap[4] = "12345";
    lengthMap[5] = "123456";
    lengthMap[6] = "1234567";
    lengthMap[7] = "12345678";lengthMap[8] = "123456789";
    
    
    string str = lengthMap[(int)pattern.size()];
    int start = -1;
    int end = -1;
    for(int index = 0;index < (int)pattern.size(); index++) {
        if(pattern[index] == 'D')
        {
            if(start == -1)
            {
                start = index ;
                end = index;
            }
            else
                end = index;
            
            if(index == (int)pattern.size()-1)
            {
                reverseStr(str, start, end+1);
                start = end = -1;
            }
        }
        else if(pattern[index] != 'D' && start != -1)
        {
            reverseStr(str, start, end+1);
            start = end = -1;
        }
        else
        {
            start = -1;
            end = -1;
        }
    }
    return str;
}


void MyfuncPtr(int** ptr)
{
    int* p = new int(45);
    *ptr = new int(20);
    *ptr = p;
}

//int main(int argc, const char * argv[]) {
//
//    //auto ret = smallestNumber("IIIIIIII");
//    
//    int* ptr = new int(30);
//    MyfuncPtr(&ptr);
//    
//    cout << *ptr << endl;
//    return 0;
//}
