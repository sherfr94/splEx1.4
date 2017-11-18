//
// Created by User on 11/11/2017.
//
#include "../include/FileSystem.h"
FileSystem::FileSystem(): rootDirectory(new Directory("",nullptr)), workingDirectory(new Directory("", nullptr)){}
Directory& FileSystem::getRootDirectory() const {return *rootDirectory;}
Directory& FileSystem::getWorkingDirectory() const {return *workingDirectory; }
void FileSystem::setWorkingDirectory(Directory *newWorkingDirectory) {workingDirectory=newWorkingDirectory;}
//RULE OF 5
void FileSystem::clear() {
    rootDirectory= nullptr;
    workingDirectory= nullptr;
}
void FileSystem::copy(FileSystem &other) {
    rootDirectory=&(other.getRootDirectory());
    workingDirectory=&(other.getWorkingDirectory());
}
FileSystem::~FileSystem() {
    delete rootDirectory;
    delete workingDirectory;//option
    clear();
}//Destructor
FileSystem::FileSystem(FileSystem &other) {
    copy(other);
}//Copy constructor
FileSystem &FileSystem::operator=(FileSystem &other) {
    if(this!=&other){
        clear();
        copy(other);

    }
    return *this;
}//Assignment operator
FileSystem::FileSystem(FileSystem &&other) {
    copy(other);
    other.clear();
    delete &other;

}//Move constructor
FileSystem &FileSystem::operator=(FileSystem &&other) {
    if(this!=&other){
        clear();
        copy(other);
        delete &other;
    }
    return *this;
}//Move assignment


