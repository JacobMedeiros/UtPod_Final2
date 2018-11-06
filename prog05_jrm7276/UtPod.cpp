//Jacob Medeiros & Reed Hopkins
#include "UtPod.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

UtPod::UtPod(){
    songs = NULL;
    memSize = MAX_MEMORY;
}

UtPod::UtPod(int size){
    songs = NULL;
    memSize = size;
}

int UtPod::addSong(Song const &s){
    if(s.getSize() <= getRemainingMemory()) { //if the size will allow
        SongNode *newSong = new SongNode; // create new song node
        newSong->song.setArtist(s.getArtist());
        newSong->song.setTitle(s.getTitle());
        newSong->song.setSize(s.getSize());
        newSong->next = songs;
        songs = newSong;
        return(SUCCESS);
    }
    else{
        return(NO_MEMORY);
    }

}

int UtPod::removeSong(Song const &s){

    SongNode *travel, *previous;

    previous = NULL;
    travel = songs;
    while(travel != NULL){
        if(travel->song == s){
            if(previous == NULL){ // if the first element is the song to be removed
                songs = travel->next; // head pointer points to next;
                return(SUCCESS);
            }
            previous->next = travel->next;
            delete(travel);// removes the song from actual memory
            return(SUCCESS);
        }
        previous = travel;
        travel = travel->next;
    }
    return(NOT_FOUND);
}

void UtPod::shuffle() {

    if(songs == NULL){
        return;
    }

    SongNode *travel, *current;
    Song sSwap;
    int sizeList = 0;
    int randomNum = 0;
    unsigned int ourTime;
    travel = songs;
    while(travel != NULL){ //traverses list to find size of it
        sizeList++;
        travel = travel->next;
    }

    ourTime  = (unsigned)time(0); //grabs calendar time
    srand(ourTime);
    if(sizeList >= 2){
        for(int i = 0; i < 100; i++){
            sSwap.setArtist(songs->song.getArtist());
            sSwap.setTitle(songs->song.getTitle());
            sSwap.setSize(songs->song.getSize());
            travel = songs;
            randomNum = (rand() % sizeList);
            travel = travel->next;
            if(randomNum !=0) {
                for (int index = 0; index < (randomNum-1); index++) {
                    travel = travel->next;
                }
            }

            songs->song.setArtist(travel->song.getArtist());
            songs->song.setTitle(travel->song.getTitle());
            songs->song.setSize(travel->song.getSize());
            travel->song.setArtist(sSwap.getArtist());
            travel->song.setTitle(sSwap.getTitle());
            travel->song.setSize(sSwap.getSize());
        }
    }


}

void UtPod::showSongList() {
    SongNode *travel;
    travel = songs;
    while(travel != NULL){
        cout << travel->song.getTitle() << ", " << travel->song.getArtist() << ", " << travel->song.getSize() << endl;
        travel = travel->next;
    }
}

void UtPod::sortSongList() {
    if(songs == NULL){
        return;
    }
    if(songs->next == NULL){
        return;
    }
    SongNode *travel1 = songs;
    SongNode *travel2 = songs;
    SongNode *temp;
    SongNode *prev = songs;
    int counter = 0;
    while(travel1 != NULL){
        counter++;
        travel1 = travel1->next;
    }
    for(int i = 0; i<counter; i++){
        while(travel2->next != NULL){
            if(travel2->song > travel2->next->song){
                if(prev == travel2){
                    temp = travel2->next;
                    travel2->next = temp->next;
                    temp->next = travel2;
                    songs = temp;
                }
                else {
                    while (prev->next != travel2) {
                        prev = prev->next;
                    }
                    temp = travel2->next;
                    travel2->next = temp->next;
                    temp->next = travel2;
                    prev->next = temp;
                }
                prev = songs;
            }
            else{
                travel2 = travel2->next;
            }
        }
        travel2 = songs;
    }
}

void UtPod::clearMemory() {
    SongNode *temp;
    while(songs != NULL){
        temp = songs->next;
        delete(songs);
        songs = temp;
    }
}

int UtPod::getRemainingMemory() {
    SongNode *travel;
    travel = songs;
    int usedMem = 0;
    while(travel != NULL){
        usedMem += travel->song.getSize();
        travel = travel->next;
    }
    return(memSize - usedMem);
}

UtPod::~UtPod() {
    clearMemory();
}


