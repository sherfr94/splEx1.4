//
// Created by User on 11/11/2017.
//
#include <iostream>
#include "../include/Commands.h"
BaseCommand::BaseCommand(string _args):args(_args) {}
string BaseCommand::getArgs() { return args;}
void BaseCommand::execute(FileSystem &fs) {}
string BaseCommand::toString() {return "";}

PwdCommand::PwdCommand(string _args):BaseCommand(_args) {}
void PwdCommand::execute(FileSystem &fs) {
    std::cout << "/"+fs.getWorkingDirectory().getName() << endl;
}
string PwdCommand::toString() {return "";}//TODO





