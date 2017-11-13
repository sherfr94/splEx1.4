//
// Created by User on 11/11/2017.
//

#include "../include/Environment.h"
Environment::Environment() {}
void Environment::start() {}
FileSystem& Environment::getFileSystem() const {}//TODO

void Environment::addToHistory(BaseCommand *command) {
    commandsHistory.push_back(command);
}
const vector<BaseCommand*>& Environment::getHistory() const {return commandsHistory;}

