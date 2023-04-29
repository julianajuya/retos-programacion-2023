#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>

std::map<char, std::string> addLeetAlphabet(){
    std::map<char, std::string> letter_map; 
    letter_map['A'] = "4"; 
    letter_map['B'] = "I3";
    letter_map['C'] = "[";
    letter_map['D'] = ")";
    letter_map['E'] = "3";
    letter_map['F'] = "|=";
    letter_map['G'] = "&";
    letter_map['H'] = "#";
    letter_map['I'] = "|";
    letter_map['J'] = ",_|";
    letter_map['K'] = ">|";
    letter_map['L'] = "|_";
    letter_map['M'] = "/\\/\\";
    letter_map['N'] = "^/";
    letter_map['O'] = "0";
    letter_map['P'] = "|*";
    letter_map['Q'] = "(_,)";
    letter_map['R'] = "I2";
    letter_map['S'] = "5";
    letter_map['T'] = "7";
    letter_map['U'] = "(_)";
    letter_map['V'] = "\\/";
    letter_map['W'] = "\\/\\/";
    letter_map['X'] = "><";
    letter_map['Y'] = "j";
    letter_map['Z'] = "2";
    letter_map['0'] = "o";
    letter_map['1'] = "L";
    letter_map['2'] = "R";
    letter_map['3'] = "E";
    letter_map['4'] = "A";
    letter_map['5'] = "S";
    letter_map['6'] = "b";
    letter_map['7'] = "T";
    letter_map['8'] = "B";
    letter_map['9'] = "g";

    return letter_map; 
}

std::string to_UpperCase(std::string chain){
    std::transform(chain.begin(), chain.end(), chain.begin(), [](unsigned char c) {
        return std::toupper(c);
    });
    return chain; 
}

std::string to_LeetSpeak(std::string chain){
    std::string text_Upper = to_UpperCase(chain); 
    std::map<char, std::string> letter_map = addLeetAlphabet();
    std::string leet_text = "";

    for (char c : text_Upper) { 
        auto it = letter_map.find(c);
        if (it != letter_map.end()) {
            leet_text += it->second;
        }
        else {
            leet_text += c;
        }
    }

    return leet_text;
}

int main(){
    std::string text; 
    std::cout <<"Write some text to be translated to hacker language: ";
    std::getline(std::cin, text); 
    std::string converted_text = to_LeetSpeak(text); 
    std::cout << converted_text << std::endl;
    
   return 0;
}
