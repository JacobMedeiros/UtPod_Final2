/* utPod_driver.cpp
Driver for UtPod Testing
 Jacob Medeiros & Reed Hopkins
This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    //int memory;
    //cin >> memory;
    UtPod h(30);
    Song s1("Chromatics", "Kill For Love", 5);
    Song s2("Death Grips", "No Love", 2);
    Song s3("Shawn Mendes", "In My Blood", 3);
    Song s4("Panoram", "Awake Walk", 3);
    Song s5("Deerhunter", "Death in Midsummer", 5);
    Song s6("Lil Baby", "Yes Indeed", 1);
    Song s7("Shawn Mendes", "Stitches", 3);
    Song s8("Shawn Mendes", "In My Blood", 2);

    h.addSong(s1);
    h.addSong(s2);
    h.addSong(s3);
    h.addSong(s4);
    h.addSong(s5);
    h.addSong(s6);
    cout << "Total Memory: "<< h.getTotalMemory() << endl;
    cout << endl;
    cout << "List Before: " << endl;
    cout << endl;
    h.showSongList();
    h.shuffle();
    cout << endl;
    cout << "List After Shuffle: " << endl;
    cout << endl;
    h.showSongList();
    cout << endl;
    cout << "List After Removing Lil Baby: " << endl;
    cout << endl;
    h.removeSong(s6);
    h.showSongList();
    cout << endl;
    cout << "Sorted: "<< endl;
    cout << endl;
    h.sortSongList();
    h.showSongList();
    cout << endl;
    h.addSong(s7);
    h.addSong(s8);
    cout << "Added: " << endl;
    h.showSongList();
    cout << endl;
    cout << "Sorted: " << endl;
    cout << endl;
    h.sortSongList();
    h.showSongList();
    h.clearMemory();
    h.addSong(s1);
    cout << endl;
    cout << "Cleared: " << endl;
    cout << endl;
    h.showSongList();
    cout << endl;
    cout << "Trying to Sort and Shuffle" << endl;
    cout << endl;
    h.sortSongList();
    h.shuffle();
    h.showSongList();




}
