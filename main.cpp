#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <bitset>
#include <cstdlib> 
#include <vector>

class ElementaryCA {
private:
 
    std::map<std::string, int> ruleset;
    std::vector<std::string> generation; 

public:
     
    ElementaryCA(int rule, const std::string& initialState) {
        ruleset = createRuleset(rule);
        generation.push_back(initialState); 
    }

    void run(int steps) {
        generation = generate(steps);
       
    }
    
    void display(){
        for (std::string state : generation) {
            std::cout << makePretty(state, '*', ' ') << std::endl;
        }
    }

private:
    static std::map<std::string, int> createRuleset(int rule) {
        std::string binaryRuleset = std::bitset<8>(rule).to_string();
        std::map<std::string, int> ruleset;
        ruleset["111"] = binaryRuleset.at(0) - '0';  
        ruleset["110"] = binaryRuleset.at(1) - '0';  
        ruleset["101"] = binaryRuleset.at(2) - '0';  
        ruleset["100"] = binaryRuleset.at(3) - '0';  
        ruleset["011"] = binaryRuleset.at(4) - '0';  
        ruleset["010"] = binaryRuleset.at(5) - '0';  
        ruleset["001"] = binaryRuleset.at(6) - '0';  
        ruleset["000"] = binaryRuleset.at(7) - '0'; 
        return ruleset;
    }

    std::vector<std::string> generate(int steps) {
        std::string state = generation[0]; 
        std::vector<std::string> states;
        states.push_back(state);
        for(int i = 0; i < steps; i++) {
            state = nextState(state);
            states.push_back(state);
        }
        return states;
    }

    std::string nextState(const std::string& state) {
        std::string newState;
        int len = state.length();
        for(int i = 0; i < len; i++) {
            char prev = state[(i - 1 + len) % len];
            char curr = state[i];
            char next = state[(i + 1) % len];
            std::string neighborhood = std::string() + prev + curr + next;
            int result = ruleset[neighborhood];
            newState += std::to_string(result);
        }
        return newState;
    }

    static std::string makePretty(const std::string& state, char on, char off) {
        std::string pretty;
        for (char c : state) {
            pretty += (c == '0') ? off : on;
        }
        return pretty;
    }
};

int main(int argc, char* argv[]) {
   
    int rule = std::stoi(argv[1]);
    std::string initialState = argv[2];
    int steps = std::stoi(argv[3]);

    ElementaryCA automaton(rule, initialState);
    automaton.run(steps);
    automaton.display(); 

    return 0;
}

