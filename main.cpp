#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <bitset>
#include <cstdlib> 
#include <vector>

std::map<std::string, int> createRuleset(int rule); 
std::string nextState(std::map<std::string, int> ruleset, std::string state); 
std::vector<std::string> generate(std::map<std::string, int> ruleset, std::string initialState, int steps); 
std::string makePretty(std::string state, char on, char off); 
 

int main(int argc, char* argv[]) {
    
    // seperate out the argument
    int rule = std::stoi(argv[1]);
    int steps = std::stoi(argv[3]); 
    std::string initialState = argv[2];   
     
    // create ruleset
    std::map<std::string, int> ruleset = createRuleset(rule);  
    
    //run simulation
    std::vector<std::string> states = generate(ruleset, initialState, steps); 
    
    //print to terminal
    for (const std::string& curr : states) {
        std::cout << makePretty(curr, '*', ' ') << std::endl;
    }
    
    return 0; 
}

// returns a hasmap of the rules <neighborhood, resulting state>
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

//  returns the new state given a state and ruleset
std::string nextState(std::map<std::string, int> ruleset, std::string state){
    
    // new state to be returns
    std::string newState; 

    //length of state for wrapping 
    int len = state.size(); 
    
    // loop through the neighborhoods
    for(int i = 0; i < len; i++){
        char prev = state[(i - 1 + len) % len]; 
        char curr = state[i]; 
        char next = state[(i + 1) % len]; 
        std::string neighborhood = "";  
        neighborhood = neighborhood + prev + curr + next;
        int result = ruleset[neighborhood]; 
        newState += std::to_string(result);  
    } 
    
    //return new state
    return newState; 
}

// returns an vector of the simulation for n steps
std::vector<std::string> generate(std::map<std::string, int> ruleset, std::string initialState, int steps){
    
    // temp variable of current state
    std::string state = initialState; 
    
    // vector to add new state to
    std::vector<std::string> states; 
    states.push_back(state); 
    
    //run for n steps
    for(int i = 0; i < steps; i++){
        state = nextState(ruleset, state); 
        states.push_back(state); 
    }
    
    // return vector of states
    return states; 
}

// returns a state in a displayable format given on and off
std::string makePretty(std::string state, char on, char off){
    
    // length of state
    int len = state.size(); 
    
    // formatted string to be returned
    std::string pretty; 
    
    //run through the state replacing 0 with off and 1 with on representation
    for(int i = 0; i < len; i++){
        
        // current state at 
        int curr = state[i] - '0';
        if(curr == 0) {
            pretty += off; 
        }
        else {
            pretty += on; 
        }
    }
    
    // return newly formatted line
    return pretty; 
}

