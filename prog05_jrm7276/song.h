//song.h
//By: Reed Hopkins & Jacob Medeiros
//Date:10/31/18

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song{
    private:
    string title;
    string artist;
    int size;

    public:
    Song();
    Song(string artist, string title, int size);

    void setTitle(string newTitle);
    void setArtist(string newArtist);
    void setSize(int newSize);
    string getTitle() const;
    string getArtist() const;
    int getSize() const;

    bool operator >(Song const &rhs);
    bool operator <(Song const &rhs);
    bool operator ==(Song const &rhs);
};
#endif
