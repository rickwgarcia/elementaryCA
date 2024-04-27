#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <bitset>
#include <cstdlib> 


std::map<std::string, int> createRuleset(int rule); 


int main(int argc, char* argv[]) {
    
    // seperate out the argument
    int rule = std::stoi(argv[1]);
    int steps = std::stoi(argv[3]); 
    std::string initialState = argv[2];   
     
    // create ruleset
    std::map<std::string, int> ruleset = createRuleset(rule);  

    return 0; 
}


std::map<std::string, int> createRuleset(int rule) {
    
    // Converts an int to a binary string
    std::string binaryRuleset = std::bitset<8>(rule).to_string();

    // Save in hashmap
    std::map<std::string, int> ruleset;
    ruleset["111"] = binaryRuleset.at(0) - '0';  
    ruleset["110"] = binaryRuleset.at(1) - '0';  
    ruleset["101"] = binaryRuleset.at(2) - '0';  
    ruleset["100"] = binaryRuleset.at(3) - '0';  
    ruleset["011"] = binaryRuleset.at(4) - '0';  
    ruleset["010"] = binaryRuleset.at(5) - '0';  
    ruleset["001"] = binaryRuleset.at(6) - '0';  
    ruleset["000"] = binaryRuleset.at(7) - '0'; 

    //return hashmap of ruleset
    return ruleset;
}



