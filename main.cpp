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
    /**
     * Constructor that initializes the cellular automaton with a specific rule and initial state.
     * @param rule The rule number for the cellular automaton, which determines state transitions.
     * @param initialState The starting configuration of the cellular automaton.
     */
    ElementaryCA(int rule, std::string initialState) {
        ruleset = createRuleset(rule);
        generation.push_back(initialState); 
    }

    /**
     * Generates the states of the cellular automaton for a specified number of steps.
     * @param steps The number of generations to simulate.
     */
    void run(int steps) {
        generation = generate(steps);
    }
    
    /**
     * Displays all states of the automaton, converting them to a visually-appealing format.
     */
    void display(){
        for (const std::string& state : generation) {
            std::cout << makePretty(state, '*', ' ') << std::endl;
        }
    }

private:
    /**
     * Creates a ruleset from a given rule number by converting it into a binary string
     * and mapping it to possible neighborhood states.
     * @param rule Integer representing the rule number.
     * @return Map of neighborhood configurations to their resulting states.
     */
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

    /**
     * Generates all states from the initial state up to a given number of steps.
     * @param steps The number of generations to simulate.
     * @return A vector of state strings representing each generation.
     */
    std::vector<std::string> generate(int steps) {
        std::string state = generation[0]; 
        std::vector<std::string> states;
        states.push_back(state);
        for (int i = 0; i < steps; i++) {
            state = nextState(state);
            states.push_back(state);
        }
        return states;
    }

    /**
     * Calculates the next state of the automaton based on the current state and the defined ruleset.
     * @param state The current state of the automaton.
     * @return The next state of the automaton.
     */
    std::string nextState(std::string state) {
        std::string newState;
        int len = state.length();
        for (int i = 0; i < len; i++) {
            char prev = state[(i - 1 + len) % len];
            char curr = state[i];
            char next = state[(i + 1) % len];
            std::string neighborhood = std::string() + prev + curr + next;
            int result = ruleset[neighborhood];
            newState += std::to_string(result);
        }
        return newState;
    }

    /**
     * Converts a binary state string into a human-readable string using specified characters.
     * @param state The state to convert.
     * @param on The character used to represent '1'.
     * @param off The character used to represent '0'.
     * @return The formatted state string.
     */
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

