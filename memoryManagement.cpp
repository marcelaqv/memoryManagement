#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int PAGE_SIZE = 1024;
const int FRAME_SIZE = 1024;
const int NUM_PAGES = 64;
const int NUM_FRAMES = 8;



vector<int> pageFrameTable(NUM_PAGES);

int main() {
    srand(time(nullptr));

    vector<int> physicalMemory(NUM_FRAMES, -1);

   
    for (int i = 0; i < NUM_PAGES; ++i) {
        pageFrameTable[i] = i % NUM_FRAMES;
    }
    int logicalAddress;
    cout << "Enter a logical address: ";
    cin >> hex >> logicalAddress; //need to fix
    //int logicalAddress = 0x5678;

    int pageNumber = logicalAddress / PAGE_SIZE;
    int offset = logicalAddress % PAGE_SIZE;

    if (pageNumber < NUM_PAGES) {
        int frameNumber = pageFrameTable[pageNumber];
        int physicalAddress = frameNumber * FRAME_SIZE + offset;

        cout << "Logical Address: 0x" << hex << setw(4) << setfill('0') << logicalAddress
            << " => Page Number: 0x" << setw(2) << setfill('0') << pageNumber
            << ", Offset: 0x" << setw(2) << setfill('0') << (offset % 256) << endl;
    }
    else {
        cout << "Invalid Page Number: " << pageNumber << endl;
    }


    return 0;
}


