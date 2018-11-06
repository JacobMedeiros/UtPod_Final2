//Song.cpp
//By:Reed Hopkins & Jacob Medeiros
//Date: 10/31/18

#include "song.h"
#include <vector>

using namespace std;

    Song::Song(){}

    Song::Song(string artist, string title, int size){
        this->artist = artist;
        this->title = title;
        this->size = size;
    }

    void Song::setTitle(string newTitle){
        title = newTitle;
    }

    void Song::setArtist(string newArtist){
        artist = newArtist;
    }

    void Song::setSize(int newSize){
        size = newSize;
    }

    string Song::getTitle() const{
        return title;
    }

    string Song::getArtist() const{
        return artist;
    }

    int Song::getSize() const{
        return size;
    }

    bool Song::operator >(Song const &rhs){
        int size = 0;
        if(artist != rhs.artist) {
            if(artist.length() < rhs.artist.length()) {
                size = artist.length();
            }
            else{
                size = rhs.artist.length();
            }
            for(int i = 0; i < size; i++) {
                if (artist.at(i) > rhs.artist.at(i)) {
                    return true;
                } else if (artist.at(i) < rhs.artist.at(i)) {
                    return false;
                }
            }
            if(artist.length() != rhs.artist.length()){
                if(artist.length() > rhs.artist.length()){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        if (title != rhs.title) {
            if(title.length() < rhs.title.length()) {
                size = title.length();
            }
            else{
                size = rhs.title.length();
            }
            for(int i = 0; i < size; i++) {
                if (title.at(i) > rhs.title.at(i)) {
                    return true;
                } else if (title.at(i) < rhs.title.at(i)) {
                    return false;
                }
            }
            if(title.length() != rhs.title.length()){
                if(title.length() > rhs.title.length()){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        if(size > rhs.size){
            return true;
        }
        else{
            return false;
        }
    }

    bool Song::operator <(Song const &rhs){
        int size = 0;
        if(artist != rhs.artist) {
            if(artist.length() < rhs.artist.length()) {
                size = artist.length();
            }
            else{
                size = rhs.artist.length();
            }
            for(int i = 0; i < size; i++) {
                if (artist.at(i) < rhs.artist.at(i)) {
                    return true;
                } else if (artist.at(i) > rhs.artist.at(i)) {
                    return false;
                }
            }
            if(artist.length() != rhs.artist.length()){
                if(artist.length() < rhs.artist.length()){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        if (title != rhs.title) {
            if(title.length() < rhs.title.length()) {
                size = title.length();
            }
            else{
                size = rhs.title.length();
            }
            for(int i = 0; i < size; i++) {
                if (title.at(i) < rhs.title.at(i)) {
                    return true;
                } else if (title.at(i) > rhs.title.at(i)) {
                    return false;
                }
            }
            if(title.length() != rhs.title.length()){
                if(title.length() < rhs.title.length()){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        if(size < rhs.size){
            return true;
        }
        else{
            return false;
        }
    }

    bool Song::operator ==(Song const &rhs){
        return(title == rhs.title &&
        artist == rhs.artist &&
        size == rhs.size);
    }
