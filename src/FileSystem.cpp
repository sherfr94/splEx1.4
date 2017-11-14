//
// Created by User on 11/11/2017.
//
#include "../include/FileSystem.h"
FileSystem::FileSystem(): rootDirectory(new Directory("",nullptr)), workingDirectory(new Directory("", nullptr)){}
Directory& FileSystem::getRootDirectory() const {return *rootDirectory;}
Directory& FileSystem::getWorkingDirectory() const {return *workingDirectory; }
void FileSystem::setWorkingDirectory(Directory *newWorkingDirectory) {workingDirectory=newWorkingDirectory;}
