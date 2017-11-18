//
// Created by User on 10/11/2017.
//

#include "../include/Files.h"
#include <iostream>
#include <algorithm>

//BaseFile
BaseFile::BaseFile(std::string _name):name(_name){}
string BaseFile::getName() const {return name;}
void BaseFile::setName(string newName) {name=newName;}
int BaseFile::getSize() {return 0;}
BaseFile::~BaseFile() {setName("");}

//File
File::File(string _name, int _size): BaseFile(_name),size(_size){}
int File::getSize() {return size;}
bool File::isFile() {return true;}
 File::~File() {
    setName("");
    size=0;
}

//Directory
Directory::Directory(string _name, Directory *parent) : BaseFile(_name), parent(parent){}
Directory * Directory::getParent() const {return parent;}
void Directory::setParent(Directory *newParent) {parent=newParent;}
bool Directory::isFile() {return false;}
void Directory::addFile(BaseFile *file) {
    children.push_back(file);
    if(!(*file).isFile()){//Dir
        //(*((Directory*)(file))).setParent(this);
        ((Directory*)(file))->setParent(this);
    }
}
void Directory::removeFile(string name) {
    int index=0;
    for(std::vector<BaseFile*>::iterator it = children.begin(); it != children.end(); ++it){
        if(children.at(index)->getName().compare(name) == 0){
            children.erase(it);
            break;
        }
        ++index;
    }
}
void Directory::removeFile(BaseFile *file) {
    std::string name=file->getName();
    removeFile(name);
}
vector<BaseFile*> Directory::getChildren() {return children;}
string Directory::getAbsolutePath() {
    std::string output="/"+this->getName();
    Directory curr=*this;
    while(curr.getParent()!= nullptr) {
        curr = *curr.getParent();
        output = "/" + curr.getName() + output;
    }
    return output;
}
bool nameComparator(BaseFile* bf1, BaseFile* bf2) {
    std::string bf1Name = (*bf1).getName();
    std::string bf2Name = (*bf2).getName();
    return ((bf1Name.compare(bf2Name))<0);
}
bool sizeComparator(BaseFile* bf1, BaseFile* bf2) {
    int bf1Size = (*bf1).getSize();
    int bf2Size = (*bf2).getSize();
    return (bf1Size < bf2Size);
}
void Directory::sortByName() {
    std::sort(children.begin(),children.end(),nameComparator);
}
void Directory::sortBySize() {
    std::sort(children.begin(), children.end(), sizeComparator);
}
int Directory::getSize() {
    int total=0;
    for(std::vector<BaseFile*>::iterator it = children.begin(); it != children.end(); ++it) {
        if ((*it)->isFile()) {//File
            total = total + (*it)->getSize();
        } else {//Dir
            total = total + (*it)->getSize();
        }
    }
    return total;
}
//RULE OF 5
void Directory::myclear(){
    children.clear();
    parent= nullptr;

}
void Directory::copy(Directory& other){
    for(BaseFile* a: other.children){
        if(a->isFile()){
            //file
            BaseFile* newFile = new File(a->getName(),a->getSize());
            children.push_back(newFile);
        }
        else{
            //dir
            BaseFile* newDir = new Directory(*(dynamic_cast<Directory*>(a)));//Danger
            children.push_back(newDir);
        }
    }
    setParent(other.getParent());
}
Directory::~Directory() {//Destructor

    //option 1
    for(BaseFile* a : children){
        delete a;
        a= nullptr;
    }

    //option 2
    /*
    for(BaseFile* a : children){
        if(a->isFile()){
            //File
            delete a;
        }
        if(!a->isFile()){
            //Dir
            delete(a)
        }
    }
     */
    myclear();
    delete parent;
    delete &children;
}
Directory::Directory (Directory &other) : BaseFile((&other)->getName()){copy(other);}//Copy constructor
Directory& Directory::operator=( Directory &other) {//Assignemt copy
    if(this!=&other){
        myclear();
        copy(other);
    }
    return *this;
}
Directory::Directory(Directory &&other):Directory(other){ delete &other; }//Move constructor
Directory& Directory::operator=(Directory &&other) {
    if(this!=&other){
        myclear();
        copy(other);
        delete &other;
    }

    return *this;
}//Move assignment operator



