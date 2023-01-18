// barchart.h
#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h"
#include "bar.h"

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";

// Color codes for Mimir (light mode)
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const string RESET("\033[0m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for Replit (dark mode terminal)
// const string CYAN("\033[1;36m");
// const string GREEN("\033[1;32m");
// const string GOLD("\033[1;33m");
// const string RED("\033[1;31m");
// const string PURPLE("\033[1;35m");
// const string BLUE("\033[1;34m");
// const string WHITE("\033[1;37m");
// const string RESET("\033[0m");
// const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};

//
// BarChart
//
class BarChart {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    //
    Bar* bars;  // pointer to a C-style array
    int capacity;
    int size;
    string frame;
 public:
    // default constructor:
    BarChart() {
       this -> bars = nullptr;
       this -> capacity = 0;
       this -> size = 0;
       this -> frame = "";
    }
    // parameterized constructor:
    // Parameter passed in determines memory allocated for bars.
    BarChart(int n) {
       this -> bars = new Bar[n];  // Bars array intialized n.
       this -> capacity = n;
       this -> size = 0;
       this -> frame = "";
    }

    //
    // copy constructor:
    //
    // Called automatically by C++ to create a BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    //
    BarChart(const BarChart& other) {
      // Creates new bars array.
      this -> bars = new Bar[other.capacity];
      this -> capacity = other.capacity;
      this -> size = other.size;
      this -> frame = other.frame;

      // Copies all the elements into this array.
      for (int i = 0; i < other.size; i++) {
        this->bars[i] = other.bars[i];
      }
    }

    //
    // copy operator=
    //
    // Called when you assign one BarChart into another, i.e. this = other;
    //
    BarChart& operator=(const BarChart& other) {
    // special case: are we assigning to ourself?
        if (this == &other) {
          return *this;
          }
        delete[] bars;
        this -> bars = new Bar[other.capacity];
        this -> capacity = other.capacity;
        this -> size = other.size;
        this -> frame = other.frame;
        for (int i = 0; i < other.size; i++) {
          this -> bars[i] = other.bars[i];
        }
       return *this;  
    }

    // clear
    // frees memory and resets all private member variables to default values.
    void clear() {
        delete[] bars;
        bars = nullptr;
        capacity = 0;
        size = 0;
        frame = "";
    }
    
    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    //
    virtual ~BarChart() {
      if (bars != nullptr) {
         delete[] bars; 
         this -> bars  = nullptr;
        }
    }
    
    // setFrame
    void setFrame(string frame) { this -> frame = frame; }
    
    // getFrame()
    // Returns the frame of the BarChart oboject.
    string getFrame() const { return frame; }

    // addBar
    // adds a Bar to the BarChart.
    // returns true if successful
    // returns false if there is not room
    bool addBar(string name, int value, string category) {
        // If there is no more space the function will return false and exit.
        if (size >= capacity) {
          return false;
          }
      
        // If there is space then the function will proceed to add bar.  
        Bar bc(name, value, category);  //bar is created.
        bars[size] = bc;  //bc is added to the end of the c-style array.
        size++;  //size is updated after adding bar.
      
        return true;  //returns true when successful.
    }
    
    // getSize()
    // Returns the size (number of bars) of the BarChart object.
    int getSize() const { return size; }
    
    // operator[]
    // Returns Bar element in BarChart.
    // This gives public access to Bars stored in the Barchart.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChart: i out of bounds"
    Bar& operator[](int i) {
      // i>size...
        if (i < 0 || i >= size) {
           throw out_of_range("BarChart: i out of bounds\n");
        }
        return bars[i];
    }
    
    // dump
    // Used for printing the BarChart object.
    // Recommended for debugging purposes.  output is any stream (cout,
    // file stream, or string stream).
    // Format:
    // "frame: 1
    // aname 5 category1
    // bname 4 category2
    // cname 3 category3" <-newline here
    void dump(ostream &output) {
      // Will sort everything.
      sort(bars, bars+size, greater<Bar>());

      output << "frame: " << frame << endl;
      //Outputs the content in descending order.
      for (int i = 0; i < size; i++) {
          output << bars[i].getName() << " ";
          output << bars[i].getValue() << " ";
          output << bars[i].getCategory();
          output << endl;
      }
    }
    
    // graph
    // Used for printing out the bar.
    // output is any stream (cout, file stream, string stream)
    // colorMap maps category -> color
    // top is number of bars you'd like plotted on each frame (top 10? top 12?)
    void graph(ostream &output, map<string, string> &colorMap, int top) {
    	int lenMax = 60;  // this is number of BOXs that should be printed
                        // for the top bar (max value).
      int currentMax = 0;  // Current max.
      
      // Sorts in descending order.
      sort(bars, bars+size, greater<Bar>());

      // Finds the max.
      for (int i = 0; i < top; i++) {
        if (currentMax<= bars[i].getValue()) {
          currentMax = bars[i].getValue(); 
        }
      }

      // Prints the bars.
      for (int row = 0; row < top; row++) {
        string color = colorMap[bars[row].getCategory()];
        if (color.empty()) {
          color = BLACK;
        }
        string barstr = "";

        //Calculates the length for each row.
        int length = double((double(bars[row].getValue())/double(currentMax))*lenMax); 
        
        // Prints the boxes.
         for (int i = 0; i < length; i++) {
           barstr += BOX;
         } 
        
        // Outputs the bar with color.
        output << color << barstr << ' ';
        output << bars[row].getName() << ' ' << bars[row].getValue() << endl;
      }
    }
};