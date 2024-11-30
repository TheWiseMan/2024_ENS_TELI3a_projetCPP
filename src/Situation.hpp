#include "GameEvent.hpp"
#include <string>

using namespace std;

class SituationChoice {
    public:
    string choiceName = "???";
    string choiceDescription = "";
    GameEvent eventToFire;
};

/**
 * Represents a game state in which the user has to make a choice.
 * Is used by the MainWindow display through the GameManager
 */
class Situation {

};