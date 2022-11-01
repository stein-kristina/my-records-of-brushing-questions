#include "point.h"
#include <string>
#include <cstring>

using namespace std;

Novel::Novel(const Novel &novel) {
    if(novel.title!= nullptr) {
        title = new char[strlen(novel.title) + 1];
        for (int i = 0; i < strlen(novel.title) + 1; i++) {
            title[i] = novel.title[i];
        }
    }
    content=new char[strlen(novel.content)+1];
    for(int i=0;i<strlen(novel.content)+1;i++){
        content[i]=novel.content[i];
    }
    contentSize=novel.contentSize;
}

Novel::Novel(const char *title_, const char *content_) {
    title=new char[strlen(title_)+1];
    for(int i=0;i<strlen(title_)+1;i++){
        title[i]=title_[i];
    }
    content=new char[strlen(content_)+1];
    for(int i=0;i<strlen(content_)+1;i++){
        content[i]=content_[i];
    }
    contentSize= strlen((content_));
}

Novel &Novel::operator=(const Novel &novel) {
    if(title) delete[] title;
    if(content) delete[] content;
    bool flag1=false,flag2=false;
    if(novel.title== nullptr) {
        flag1= true;
        title= nullptr;
    }
    if(novel.content== nullptr) {
        flag2= true;
        content= nullptr;
    }
    if(!flag1) {
        title = new char[strlen(novel.title) + 1];
        for (int i = 0; i < strlen(novel.title) + 1; i++) {
            title[i] = novel.title[i];
        }
    }
    if(!flag2) {
        content = new char[strlen(novel.content) + 1];
        for (int i = 0; i < strlen(novel.content) + 1; i++) {
            content[i] = novel.content[i];
        }
    }
    contentSize=novel.contentSize;
    return *this;
}
Novel::~Novel() {
    if(content) delete[] content;
    if(title) delete[] title;
}
NovelServer::NovelServer(const NovelServer &novelServer) {
    maxNum=novelServer.maxNum;
    novelNum=novelServer.novelNum;
    if(novelServer.novelList== nullptr){
        novelList= nullptr;
        return;
    }
    novelList=new Novel[maxNum];
    for(int i=0;i<novelNum;i++){
        novelList[i]=novelServer.novelList[i];
    }
}
NovelServer &NovelServer::operator=(const NovelServer &novelServer) {
    if(novelServer.novelList==this->novelList) return *this;
    maxNum=novelServer.maxNum;
    novelNum=novelServer.novelNum;
    if(novelServer.novelList== nullptr){
        novelList= nullptr;
        return *this;
    }
    if(novelList== nullptr) novelList=new Novel[maxNum];
    for(int i=0;i<novelNum;i++){
        novelList[i]=novelServer.novelList[i];
    }
    return *this;
}

void NovelServer::addNovelInTheEnd(Novel &novel) {
    if(novelNum==maxNum){
        return;
    }
    else{
        novelList[novelNum]=novel;
        novelNum++;
    }
}

void NovelServer::removeNovelInTheEnd() {
    if(novelNum>0){
        novelList[novelNum]=Novel();
        novelNum--;
    }
}
NovelServer::~NovelServer() {
    if(novelList) delete[] novelList;
}