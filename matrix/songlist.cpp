
#include "../point.h"
using namespace std;

SongList::SongList(const std::string _owner, unsigned int _size, unsigned int _capacity, std::string *_songs){
    owner=_owner;
    size=_size;
    capacity=_capacity;
    songs=_songs;
}

SongList::SongList(const SongList &songList){
    owner=songList.owner;
    size=songList.size;
    capacity=songList.capacity;
    if(songList.songs==NULL){
        songs=NULL;
    }
    else {
        //(if(songs!=NULL) delete[] songs;
        string *newsong = new string[capacity];
        for (int i = 0; i < size; i++) {
            newsong[i] = songList.songs[i];
        }
        songs = newsong;
    }
}

// 添加歌曲，请考虑去重的情况（如果歌曲已经存在则不添加）、歌单已经满了需要扩容的情况，扩容方案自选
// 扩容方案1：原地扩容，C语言中有个realloc函数可以实现
// 扩容方案2：重新开辟一个更大容量songs歌曲列表，并将当前的数据迁移过去
void SongList::addSong(const std::string &song){
    for(int i=0;i<size;i++){
        if(songs[i]==song) return;
    }//检查
    if(size==capacity){
        string *newsong=new string[capacity+2];//扩容
        for(int i=0;i<size;i++){
            newsong[i]=songs[i];//复制过去
        }
        newsong[size]=song;
        size++;
        capacity=capacity+2;
        songs=newsong;
    }//需要扩容
    else{
        songs[size]=song;
    }

}

// 删除指定歌曲，歌曲不存在则无动作
void SongList::removeSong(const std::string &song){
    int p,flag=0;//找位置
    for(p=0;p<size;p++){
        if(songs[p]==song) {
            flag=1;//you
            break;
        }
    }
    if(flag){
        for(int i=p;i<size;i++){
            if(i+1<=capacity)
                songs[i]=songs[i+1];
        }
        songs[size-1]="";
        size--;
    }
}

// 清空歌曲
void SongList::clearSong(){
    if(songs!=NULL){
        delete[] songs;
    }
    songs=NULL;
}

SongList &SongList::operator=(const SongList &songList){
    if(songList.songs==this->songs) return *this;
    owner=songList.owner;
    size=songList.size;
    capacity=songList.capacity;
    if(songList.songs==NULL){
        songs=NULL;
        return *this;
    }
    if(songs!=NULL) {
        delete[] this->songs;
    }
    this->songs=new string[capacity];
    for(int i=0;i<size;i++){
        this->songs[i]=songList.songs[i];
    }
    return *this;

}

ostream &operator<<(ostream &os, const SongList &songList){
    if(songList.songs==NULL){
        os<<songList.owner<<"'s SongList is Empty.";
        return os;
    }
    else {
        os << "owner:" << songList.owner << endl;
        os<<"Songs:"<<endl;
        for(int i=0;i<songList.size;i++){
            os << songList.songs[i]<<endl;
        }
        return os;
    }

}

SongList::~SongList(){
    if(songs!=NULL){
        delete[] songs;
    }
}