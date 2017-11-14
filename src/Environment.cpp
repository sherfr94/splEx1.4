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
        std::string commandTypeStr = input.substr(0,pos);
        //std::cout << commandStr << endl;

        //execute command

        if(input.compare("pwd")==0){
            PwdCommand* command = new PwdCommand("pwd");
            command->execute(fs);
        }
        if(input.compare("ls")==0){
            //std::cout << "Running ls" << endl;
            LsCommand* command = new LsCommand("ls");
            command->execute(fs);
        }
        std::string executeStr = input.substr(pos);
        if(commandTypeStr.compare("mkfile")==0){
            //std::cout << "Running mkfile" << endl;
            MkfileCommand* command = new MkfileCommand(executeStr);
            command->execute(fs);
        }



        //print curr dir & get new input
        std::cout << fs.getWorkingDirectory().getName() << "/>";
        std::getline(std::cin,input);
        //std::cout << input << endl;
    }

}
FileSystem& Environment::getFileSystem() {return fs;}//TODO

void Environment::addToHistory(BaseCommand *command) {
    commandsHistory.push_back(command);
}
const vector<BaseCommand*>& Environment::getHistory() const {return commandsHistory;}

