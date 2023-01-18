// barchartanimate.h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" 
#include "barchart.h"
  
using namespace std;

// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    map<string, string> colorMap;
    string title;
    string xlabel;
    string source;
    int wcol;
 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        barcharts = new BarChart[4];
        size = 0;
        capacity = 4;
        wcol = 0;
        this -> title = title;
        this -> xlabel = xlabel;
        this -> source = source;
    }

    string getTitle() const { return title; }
    string getXLabel() const  { return xlabel; }
    string getSource() const { return source; }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        // TO DO:  Write this destructor.
        if (barcharts != nullptr) {
          for (int i = 0; i < size; i++) {
            barcharts[i].clear();
          }
          delete[] barcharts;
          barcharts = nullptr;
          }
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    //
    void addFrame(ifstream &file) {
        // is the vector full?  if so, we have to double in size before we can add.
        if (size == capacity) {
        int newcapacity = capacity * 2;
        BarChart* newbarcharts = new BarChart[newcapacity];
 
        // copy the elements from A to the new array:
        for (int i = 0; i < size; ++i) {
          newbarcharts[i] = barcharts[i];
        }
 
        // now delete A, and update private data members to point to new array
        // and reflect new capacity:
        delete[] barcharts;
        barcharts = newbarcharts;
        capacity = newcapacity;
        newbarcharts = nullptr;
        }

      int rows, value;
      string line, year, name, country, val, category, color;
      //gets blank.
      getline(file, line, '\n');

      if (!file.fail()) {
      //gets number of line.
      getline(file, line, '\n');
      rows = stoi(line);
      BarChart bc(rows);
        
      // getline(file, line, '\n');
      // cout << "2: " << line << endl;
      for (int i = 0; i < rows; i++) {
        getline(file, line, ',');
        year = line;
        getline(file, line, ',');
        name = line;
        getline(file, line, ',');
        country = line;
        getline(file, line, ',');
        value = stoi(line);
        getline(file, line, '\n');
        category = line;

        bc.addBar(name, value, category);
        bc.setFrame(year);
        //check if category is in map.
      //if not will be added to map/
      if (colorMap.count(category) == 0) {
        if (wcol == 0){
          color  = COLORS[0];
        } else if (wcol == 1) {
          color  = COLORS[1];
        } else if (wcol == 2) {
          color  = COLORS[2];
        } else if (wcol == 3) {
          color  = COLORS[3];
        } else if (wcol == 4) {
          color  = COLORS[4];
        } else if (wcol == 5) {
          color  = COLORS[5];
        } else if (wcol == 6) {
          color  = COLORS[6];
        } else if (wcol == 7) {
          color  = COLORS[0];
          wcol = 0;
        }
        wcol++;
        colorMap.emplace(category, color);
        }
        }
        barcharts[size] = bc;
        size++;
      }
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
    if (endIter == -1){ endIter = size; }
    
		for (int i = 0; i < endIter; i++) {
      usleep(3 * microsecond);
      output << CLEARCONSOLE;
      output << BLACK << title << endl;
      output << BLACK << source << endl;
      barcharts[i].graph(output, colorMap, top);
      output << BLACK << xlabel << endl;
      output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
    }	
	}

    // animate(time frame)/ C R E A T I V E:
    // this function plays each frame stored in barcharts similar to the original animate function
    // the difference is that this does it in a time frame chosen by the user.
    // 
	void animate(ostream &output, int top, int startIter, int endIter) {
		unsigned int microsecond = 50000;
    if (endIter == -1){ endIter = size; }
    
		for (int i = startIter; i < endIter; i++) {
      usleep(3 * microsecond);
      output << CLEARCONSOLE;
      output << BLACK << title << endl;
      output << BLACK << source << endl;
      barcharts[i].graph(output, colorMap, top);
      output << BLACK << xlabel << endl;
      output << BLACK << "Frame: " << barcharts[i].getFrame() << endl;
    }	
	}

    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize() const { return size;  }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i) {
        if (i < 0 || i >= size) {
          throw out_of_range("BarChartAnimate: i out of bounds");  
        }
      
        return barcharts[i];
    }
};