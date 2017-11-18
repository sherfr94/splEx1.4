//
// Created by User on 11/11/2017.
//

#include <iostream>
#include "../include/Environment.h"
Environment::Environment(){}
void Environment::start() {
    std::cout << fs.getRootDirectory().getName() << "/>";
    std::string input;
    std::getline(std::cin,input);
    //std::cout << input << endl;

    while(input.compare("exit")!=0){
        //generate command string
        std::size_t pos = input.find(" ");
        if(pos>input.length()) pos=input.length();//Fix bug std::out_of_range after input.substr(0,pos)
        std::string commandType = input.substr(0,pos);
        //std::cout << commandStr << endl;

        //execute command 

        if(input.compare("pwd")==0){
            PwdCommand* command = new PwdCommand("pwd");
            command->execute(fs);
            addToHistory(command);
        }
        if(input.compare("ls")==0){
            //std::cout << "Running ls" << endl;
            LsCommand* command = new LsCommand("ls");
            command->execute(fs);
            addToHistory(command);
        }

        if(commandType.compare("mkfile")==0){
            std::string execute = input.substr(pos+1);
            //std::cout << "Running mkfile" << endl;
            MkfileCommand* command = new MkfileCommand(execute);
            command->execute(fs);
            addToHistory(command);
        }

        //print curr dir & get new input
        std::cout << fs.getWorkingDirectory().getName() << "/>";
        std::getline(std::cin,input);
        //std::cout << input << endl;
    }

}
FileSystem& Environment::getFileSystem()  {return fs;}
void Environment::addToHistory(BaseCommand *command) {
    commandsHistory.push_back(command);
}
const vector<BaseCommand*>& Environment::getHistory() const {return commandsHistory;}
//RULE OF 5
void Environment::clear() {
    commandsHistory.clear();
    fs.clear();
}
void Environment::copy(Environment &other) {
    fs.copy(other.getFileSystem());

    for(BaseCommand* a: other.getHistory()){
        commandsHistory.push_back(a->clone());
    }
}
Environment::~Environment() {

    for(BaseCommand* a : commandsHistory){
        delete a;
        a= nullptr;
    }

    delete &fs; //option
    clear();

}//Destructor
Environment::Environment(Environment &other){
    copy(other);
}//Copy constructor
Environment& Environment::operator=(Environment& other){
    if(this != &other){
        clear();
        copy(other);
    }
    return *this;
}//Copy assignment
Environment::Environment(Environment &&other){
    copy(other);
    other.clear();
    delete &other;
}//Move constructor
Environment& Environment::operator=(Environment&& other){
    if(this != &other){
        clear();
        copy(other);
        delete &other;
    }
    return *this;

}//Move assignment


