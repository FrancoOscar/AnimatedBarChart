#include <iostream>
#include "barchartanimate.h"
using namespace std;

// bar.h
bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool testGetters() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }

  Bar ab("Malibu", 12620, "US");
    if (ab.getName() != "Malibu") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (ab.getValue() != 12620) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (ab.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }

    cout << "testGetters: all passed!" << endl;
    return true;
}

bool testLessThan(){
  Bar b1("a", 1, "cat");
  Bar b2("b", 2, "cat");
  if (!(b1<b2)){
    cout << "Less than operator does not work." << endl;
    cout << "Comparing smaller element to bigger returns false." << endl;
    return false;
  } else if (b2<b1){
    cout << "Less than operator does not work." << endl;
    cout << "Comparing bigger element to smaller returns true." << endl;
    return false;
  }
  cout << "testLessThan: all passed!" << endl;
  return true;
}

bool testGreaterThan(){
  Bar b1("a", 1, "cat");
  Bar b2("b", 2, "cat");
   if (!(b2>b1)){
    cout << "Greater than operator does not work." << endl;
    cout << "Comparing bigger element to smaller returns false." << endl;
    return false;
  } else if (b1>b2){
    cout << "Greater than operator does not work." << endl;
    cout << "comparing smaller element to bigger returns true." << endl;
    return false;
  }
  cout << "testGreaterThan: all passed!" << endl;
  return true;
}

bool testGreaterThanOrEqual(){
  Bar b1("a", 1, "cat");
  Bar b2("b", 2, "cat");
  Bar b3("c", 2, "cat");
  if (!(b2>=b1)){
    cout << "Greater Than Or Equal operator does not work." << endl;
    cout << "Comparing bigger element to smaller returns false." << endl;
    return false;
  } else if (!(b2>=b3)){
    cout << "Greater Than Or Equal operator does not work." << endl;
    cout << "Comparing equal elements returns false." << endl;
  } else if (b1>b2){
    cout << "Greater Than Or Equal operator does not work." << endl;
    cout << "Comparing smaller element to bigger returns true." << endl;
  }
  cout << "testGreaterThanOrEqual: all passed!" << endl;
  return true;
}

bool testlessThanOrEqual(){
  Bar b1("a", 1, "cat");
  Bar b2("b", 2, "cat");
  Bar b3("c", 2, "cat");
  if (!(b1<=b2)){
    cout << "Less Than Or Equal operator does not work." << endl;
    cout << "Comparing smaller element to bigger returns false." << endl;
    return false;
  } else if (!(b2<=b3)){
    cout << "less Than Or Equal operator does not work." << endl;
    cout << "Comparing equal elements returns false." << endl;
  } else if (b2<b1){
    cout << "Greater Than Or Equal operator does not work." << endl;
    cout << "Comparing bigger element to smaller returns true." << endl;
  }
  cout << "testLessThanOrEqual: all passed!" << endl;
  return true;
}

// barchart.h
bool testBCDefaultConstructor(){
  BarChart bc;
  if (bc.getSize() != 0){
    cout << "testBCDefaultConstructor failed... ";
    cout << "Default constructor size is not 0" << endl;
    return false;
  }
  if (bc.getFrame() != ""){
    cout << "testBCDefaultConstructor failed... ";
    cout << "Get Frame is not an empty string." << endl;
    return false;
  }
  cout << "testBCDefaultConstructor: all passed!" << endl;
  return true;
}

bool testBCParamatizedConstructor(){
  int capacity = 1000;
  BarChart bc(capacity);
  int count = 0;
  // Bar b("a", 1, "cat");
  // bc.setFrame("2000");
  for (int i = 0; i < capacity; i++){
    bc.addBar("a", 1, "cat");
    count++;
  }
  
  if (bc.getSize()!=capacity){
    cout << "testBCParamatizedConstructor failed. ";
    cout << "Memory allocated is not correct." << endl;
    return false;
  } 
  
  for (int i = 0; i < bc.getSize(); i++){
    
  }

  
  cout << "testParamatizedConstructor: all passed!" << endl;
  return true;
}

bool testBCCopyConstructor(){
  BarChart bc(10);
  BarChart bcCopy(bc);
  if (bc.getSize() != bcCopy.getSize()){
    cout << "testCopyConstructor failed. ";
    cout << "Memory allocated is not equal.";
    return false;
  }
  cout << "testCopyConstructor: all passed!" << endl;
  return true;
}

bool testBCCopyOperator(){
  BarChart bc1;
  BarChart bc2(10);
  bc1 = bc2;
  if (bc1.getSize() != bc2.getSize()){
    cout << "testCopyOperator failed. ";
    cout << "Memory allocated is not equal.";
    return false;
  }
  cout << "testCopyOperator: all passed!" << endl;
  return true;
}

bool testBCClear(){
  BarChart bc(10);
  bc.clear();
  if (bc.getSize() != 0){
    cout << "TestClear failed. ";
    cout << "size not cleared properly." << endl;
    return false;
  }
  cout << "testClear: all passed!" << endl;
  return true;
}

bool testBCFrame(){
  BarChart bc(3);
  string test = "1950";
  bc.setFrame(test);
  if (bc.getFrame()!= test){
      cout << "testFrame failed. ";
      cout << "Frame not initialized correctly." << endl;
    return false;
  }
  cout << "TestFrame: all passed!" << endl;
  return true;
}

bool testBCAddBar(){
  BarChart bc(3);
  bc.addBar("Chicago", 1020, "US");
  bc.setFrame("1950");
  for (int i = 0; i < bc.getSize(); i++){
      if (bc[i].getName() != "Chicago"){
        cout << "TestAddBar failed. ";
        cout << "Name not added correctly." << endl;
        return false;
      }
      if (bc[i].getValue() != 1020){
        cout << "TestAddBar failed. ";
        cout << "Value not added correctly." << endl;
        return false;
      }
      if (bc[i].getCategory() != "US"){
        cout << "TestAddBar failed. ";
        cout << "Category not added correctly." << endl;
        return false;
      }
  }
  cout << "TestAddBar: all passed!" << endl;
  return true;
}

bool testBCgetSize(){
  int capacity = 1000;
  BarChart a;
  BarChart b(capacity);
  BarChart c(0);
  
  for (int i = 0; i < capacity; i++){
    b.addBar("a", 1, "cat");
  }

  if (a.getSize() != 0){
    cout << "testBCgetSize failed... ";
    cout << "size is not 0" << endl;
    return false;
  }
  if (b.getSize() != 1000){
    cout << "testBCgetSize failed... ";
    cout << "size is not 1000" << endl;
    return false;
  }
  if (c.getSize() != 0){
    cout << "testBCgetSize failed... ";
    cout << "default size is not 0" << endl;
    return false;
  }
  
  cout << "testBCGetSize: all passed" << endl;
  return true;
}

bool testBCOperator(){
  BarChart bc(10);
  
  for (int i = 0; i < 10; i++){
    bc.addBar("a", 1, "cat");
  }

  for (int i = 0; i < 10; i++){
    if (bc[i].getName() != "a"){
      cout << "testBCOperator failed...";
      cout << "name at index " << i <<" not correct." << endl;
      return false;
    }
    if (bc[i].getValue() != 1){
      cout << "testBCOperator failed...";
      cout << "value at index " << i <<" not correct." << endl;
      return false;
    }
    if (bc[i].getCategory() != "cat"){
      cout << "testBCOperator failed...";
      cout << "category at index " << i <<" not correct." << endl;
      return false;
    }
  }

  cout << "testBCOperator: all passed!" << endl;
  return true;
}

bool testBCDump(){
  BarChart bc(3);
  bc.setFrame("1950");
  //bc added in wrong order to test if sort works.
  bc.addBar("Paris", 1200, "France");
  bc.addBar("NYC", 1300, "US");
  bc.addBar("Chicago", 1020, "US");

  stringstream ss;
  string line;
  bc.dump(ss);

  // Tests each line.
  getline (ss, line);
  if (line != "frame: 1950"){
    cout << "Dump failed. ";
    cout << "Frame is not right." << endl;
    return false;
  }
  getline (ss, line);
  if (line != "NYC 1300 US"){
    cout << "Dump failed. ";
    cout << "Line 1 is not right." << endl;
    cout << line << endl;
    return false;
  }
  getline (ss, line);
  if (line != "Paris 1200 France"){
    cout << "Dump failed. ";
    cout << "Line 2 is not right." << endl;
    cout << line << endl;
    return false;
  }
  getline (ss, line);
  if (line != "Chicago 1020 US"){
    cout << "Dump failed. ";
    cout << "Line 3 is not right." << endl;
    cout << line << endl;
    return false;
  }
  
  cout << "TestDump: all passed!" << endl;
  return true;
}

bool testBCGraph(){
  stringstream ssToTest("");
  stringstream ssExpected("");
  stringstream ssWrong("");
  //string red("\033[1;36m");
  //string blue("\033[1;33m");
  map<string, string> colorMap;
  //colorMap["US"] = red;
  //colorMap["France"] = blue;
  BarChart bc(2);
  
  bc.addBar("Paris", 1200, "France");
  bc.addBar("Paris", 1200, "France");
  bc.addBar("Oaxaca", 5, "Mexico");
  bc.graph(ssToTest, colorMap, 1);
  bc.graph(ssExpected, colorMap, 1);
  string input = ssToTest.str();
  string result = ssExpected.str();
  string wrong = ssWrong.str();
  
  if (input != result) {
    cout << "TestBCGrpah failed... ";
    cout << "Graphing not the same." << endl;
    return false;
  }
  if (input == wrong) {
    cout << "TestBCGrpah failed... ";
    cout << "Graphing two different elements should not be the same." << endl;
    return false;
  }
  
  cout << "TestBCGraph: all passed!" << endl;
  return true;
}

bool testBarChartAnimateConstructor() {
  //Sources: SEDAC; United Nations; Demographia
  string title = "SEDAC";
  string xlabel = "United Nations";
  string source = "Demographia";
  BarChartAnimate bca(title, xlabel, source);
   if (bca.getTitle() !=  "SEDAC") {
     cout << "TBCA: Constructor failed... ";
     cout << "title not working." << endl;
     return false;
   }
  if (bca.getXLabel() !=  "United Nations") {
    cout << "TBCA: Constructor failed... ";
    cout << "xlabel not working." << endl;
     return false;
   }
  if (bca.getSource() !=  "Demographia") {
    cout << "TBCA: Constructor failed... ";
    cout << "source not working." << endl;
     return false;
   }
  cout << "testBarChartAnimateConstructor: all passed!" << endl;
  return true;
}

bool testAddFrame() {
  string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	int year = 1500;
  
	while (!inFile.eof()) {
		bca.addFrame(inFile);
    }

  for (int i  = 0; i < bca.getSize(); i++){
    if (stoi(bca[i].getFrame()) != year){
      cout << "testAddFrame failed... ";
      cout << "Frames not added right" << endl;
      return false;
      }
    year++;
  }
  
  cout << "testAddFrame: all passed!" << endl;
 	return true;
  }

bool testAnimate(){
  string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
    }
  
  bca.animate(cout, 12, 10);

  cout << "testAnimate: all passed!" << endl;
  return true;
}

bool testBCAgetSize(){
  string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
    }

  if (bca.getSize() != 519){
    cout << "testBCAgetSize failed... ";
    cout << "Incorrect size" << endl;
    return false;
  }

  cout << "testBCAgetSize: all passed!" << endl;
  return true; 
}

bool testBCAoperator(){
  string filename = "cities.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
  }

  int n = bca.getSize();
  int year = 1500;
  for (int i = 0; i < n; i++) {
    if (stoi(bca[i].getFrame()) != year){
      cout <<"testBCAoperator failed... ";
      cout << "operator not working." << endl;
        return false;
    }
  year++;
}
  cout << "testBCAoperator: all passed!" << endl;
  return true;
}

int main() {
  // Bar.h tests:
  cout << "***--Bar.h tests--***" << endl;
	testBarDefaultConstructor();
	testBarParamConstructor();
  testGetters();
  testLessThan();
  testGreaterThan();
  testGreaterThanOrEqual();
  testlessThanOrEqual();
  cout << endl;
  
  // Barchart.h tests: 
  cout << "***--Barchart.h tests--***" << endl;
  testBCDefaultConstructor();
  testBCParamatizedConstructor();
  testBCCopyConstructor();
  testBCCopyOperator();
  testBCClear();
  testBCFrame();
  testBCAddBar();
  testBCgetSize();
  testBCOperator();
  testBCDump();
  testBCGraph();
  cout << endl;
  
  // Barchartanimate.h tests:
  cout << "***--Barchartanimate.h tests--***" << endl;
  testBarChartAnimateConstructor();
  testAddFrame();
  testBCAgetSize();
  testBCAoperator();
  
    return 0;
}