//
// Created by User on 10/11/2017.
//
#include <iostream>
#include "../include/Files.h"
#include <typeinfo>
#include <algorithm>
#include "../include/Environment.h"

// ... You may not change this file

unsigned int verbose = 0;

int main(int , char **) {


/*
     //Test BaseFile
    BaseFile bf1 ("bf1");
    bf1.setName("hi");
    //std::cout << bf1.getSize() << std::endl;
    std::cout << bf1.getName() << std::endl;

*/
/*
    //Test File
    File f1 ("f1",1000);
    std::cout << f1.getSize() << std::endl;
    std::cout << f1.getName() << std::endl;
    f1.setName("f2");
    std::cout << f1.getName() << std::endl;
    */

    //Test Directory
    /*
    Directory d1("d1", nullptr);
    Directory* d4=new Directory("d4", nullptr);

    Directory d2("d2", d4);
    Directory d3("d3",&d2);
    d1.addFile(&d3);
   // d1.addFile(d3);
    std::vector<BaseFile*> v1=d1.getChildren();
    for(std::vector<BaseFile*>::iterator it = v1.begin(); it != v1.end(); ++it)
        std::cout << (*it)->getName() << ' ';
    std::cout << d3.getAbsolutePath() << ' ';
    */
/*
    Directory di1("di1", nullptr);
    File f1("b",1000);
    File f2("a",1500);
    di1.addFile(&f1);
    di1.addFile(&f2);

    Directory di2("di2", nullptr);
    di1.addFile(&di2);
    File f3("d",1000);
    File f4("z",1500);
    di1.addFile(&f3);
    di1.addFile(&f4);


    std::cout << di2.getAbsolutePath() << endl;
    std::cout << &di1 << endl;
    std::cout << di2.getParent() << endl;
    std::cout << di1.getSize() << endl;
    std::cout << f3.getName().compare(f4.getName()) << endl;

    Directory di1New(di1);

    std::cout << "TEST CC" << endl;
    std::cout << &di1 << endl;
    std::cout << &di1New << endl;


    di1.sortByName();
    std::vector<BaseFile*> v1=di1.getChildren();
    for(std::vector<BaseFile*>::iterator it = v1.begin(); it != v1.end(); ++it)
        std::cout << (*it)->getName() << ' ';

    std::vector<int> v2;
    v2.push_back(1);
    v2.push_back(3);
    v2.push_back(2);

    std::sort(v2.begin(),v2.end());

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it=v2.begin(); it!=v2.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
*/

//    std::cout << "Test stoi: " << endl;
//    std::cout << "==================" << endl;
//    std::string str = "mkfile fr 200";
//    int pos1=str.find(" ");
//    std::string type=str.substr(0,pos1);
//
//    std::string namesize=str.substr(pos1+1);
//    int pos2=namesize.find(" ");
//    std::string name = namesize.substr(0,pos2+1);
//
//    std::string size=namesize.substr(pos2+1);
//
//
//
//    std::cout << pos1 << endl;
//    std::cout << pos2 << endl;
//    std::cout << str << endl;
//    std::cout << type << endl;
//    std::cout << "namesize: "+namesize << endl;
//    std::cout << "name: "+name << endl;
//
//    std::cout << "size: "+size << endl;




    std::cout << "Test Environment: " << endl;
    std::cout << "==================" << endl;
    Environment env;
    env.start();

}