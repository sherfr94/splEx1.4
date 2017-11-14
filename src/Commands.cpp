//
// Created by User on 11/11/2017.
//
#include <iostream>
#include "../include/Commands.h"
BaseCommand::BaseCommand(string _args):args(_args) {}
string BaseCommand::getArgs() { return args;}
void BaseCommand::execute(FileSystem &fs) {}

string BaseCommand::toString() {}

PwdCommand::PwdCommand(string _args):BaseCommand(_args) {}
void PwdCommand::execute(FileSystem &fs) {
    std::cout << fs.getWorkingDirectory().getAbsolutePath() << endl;
}
string PwdCommand::toString() {return "pwd";}


MkfileCommand::MkfileCommand(string args) :BaseCommand(args){}
void MkfileCommand::execute(FileSystem &fs) {

    int pos1=getArgs().find(" ");
    std::string type=getArgs().substr(0,pos1);
    std::string namesize=getArgs().substr(pos1+1);
    int pos2=namesize.find(" ");
    std::string name = namesize.substr(0,pos2);
    std::string size=namesize.substr(pos2+1);


    fs.getWorkingDirectory().addFile(new File(name,std::stoi(size)));
}
string MkfileCommand::toString() {return "mkfile";}

LsCommand::LsCommand(string args) : BaseCommand(args){}
void LsCommand::execute(FileSystem &fs) {
    for(BaseFile* a : fs.getWorkingDirectory().getChildren()) {
        if (a->isFile()) std::cout << "FILE";
        else std::cout << "DIR";
        std::cout <<"\t" + a->getName() +"\t" << a->getSize() << endl;
    }
}
string LsCommand::toString() {return "ls";}

