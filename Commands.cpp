//
// Created by User on 11/11/2017.
//
#include <iostream>
#include "../include/Commands.h"
//BaseCommand
BaseCommand::BaseCommand(string _args):args(_args) {}
string BaseCommand::getArgs() { return args;}
void BaseCommand::execute(FileSystem &fs) {}
string BaseCommand::toString() {}

//PwdCommand
PwdCommand::PwdCommand(string _args):BaseCommand(_args) {}
void PwdCommand::execute(FileSystem &fs) {
    std::cout << fs.getWorkingDirectory().getAbsolutePath() << endl;
}
string PwdCommand::toString() {return "pwd";}
BaseCommand* PwdCommand::clone()  {return new PwdCommand(getArgs());}

//MkfileCommand
MkfileCommand::MkfileCommand(string args) :BaseCommand(args){}
void MkfileCommand::execute(FileSystem &fs) {
    int pos1=getArgs().find(" ");
    std::string name=getArgs().substr(0,pos1);
    std::string namesize=getArgs().substr(pos1+1);

    fs.getWorkingDirectory().addFile(new File(name,std::stoi(namesize)));
}
string MkfileCommand::toString() {return "mkfile";}
BaseCommand* MkfileCommand::clone()  {return new MkfileCommand(getArgs());}

//LsCommand
LsCommand::LsCommand(string args) : BaseCommand(args){}
void LsCommand::execute(FileSystem &fs) {
    for(BaseFile* a : fs.getWorkingDirectory().getChildren()) {
        if (a->isFile()) std::cout << "FILE";
        else std::cout << "DIR";
        std::cout <<"\t" + a->getName() +"\t" << a->getSize() << endl;
    }
}
string LsCommand::toString() {return "ls";}
BaseCommand* LsCommand::clone()  {return new LsCommand(getArgs());}



CdCommand::CdCommand(string args) : BaseCommand(args) {}

void CdCommand::execute(FileSystem &fs) {
    Directory temp=fs.getWorkingDirectory();
    //if args start with / - work from root dir

    //if args start with dir1 work from current dir
    //cut string 1
    int pos=getArgs().find("/");

    // / not found - just1 1 dir
    if(pos>getArgs().length()){
        bool found=false;
        for(BaseFile* a: fs.getWorkingDirectory().getChildren()) {
            if (!a->isFile()) {
                if (a->getName().compare(getArgs()) == 0) {
                    found=true;
                    fs.setWorkingDirectory(dynamic_cast<Directory *>(a));
                    break;
                }
            }
        }
        if (!found){
            std:cout << "The system cannot find the path specified" <<endl;
            fs.setWorkingDirectory(temp);
        }
    }
    else{
        std::string dir = getArgs().substr(0,pos);//next dir
        std::string leftover = getArgs().substr(pos+1);//leftover of path

        bool found=false;
        for(BaseFile* a: fs.getWorkingDirectory().getChildren()){
            if(a->getName().compare(dir)==0){
                found=true;
                fs.setWorkingDirectory(dynamic_cast<Directory *>(a));
                CdCommand* newCd = new CdCommand(leftover);
            }
        }

    }





    //find if directory exits in children

    //
}

string CdCommand::toString() {
    return std::__cxx11::string();
}

BaseCommand *CdCommand::clone() const {
    return nullptr;
}
