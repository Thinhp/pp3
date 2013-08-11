/*From Forum
*I finally got itall done, thanks for the help!
*
*/

//Help with Code Tags
//c Syntax (Toggle Plain Text)

   1.
      #include <iostream>
   2.
      #include <iomanip>
   3.
      #include <string>
   4.
      #include <cmath>
   5.
      using namespace std;
   6.
       
   7.
      void ProgrammerNote(void);
   8.
      // displays the message "Programmed by <type your name here>."
   9.
       
  10.
      int Menu(void);
  11.
      // displays menu of choices.
  12.
       
  13.
      double ComputeLength(int x1, int y1, int x2, int y2);
  14.
      // computes the length of the line between two points, p1, p2.
  15.
      // L = sqrt( (x2-x1)^2 + (y2-y1)^2 )
  16.
       
  17.
      double ComputePerimeter(double sideA, double sideB, double sideC);
  18.
      // computes the triangle's perimeter P = A + B + C.
  19.
       
  20.
      double ComputeArea(double Perimeter, double sideA, double sideB, double sideC);
  21.
      // computes the triangle's area by using the formula:
  22.
      // A = sqrt( S(S-A)(S-B)(S-C) ), where S is the semi perimeter, S = (A + B + C) / 2.
  23.
       
  24.
      void ReadPoint(string prompt, int& x, int& y);
  25.
      // reads in the x,y coordinates of a point.
  26.
       
  27.
      void DisplayMeasure(string prompt, double value);
  28.
      // displays the value along with its prompt. This function is used to display all
  29.
      // calculated measures,
  30.
      // i.e. perimeter, area and length.
  31.
       
  32.
      void main (void){
  33.
       
  34.
      int x1 = 0, y1 = 0,
  35.
      x2 = 0, y2 = 0,
  36.
      x3 = 0, y3 = 0,
  37.
      choice = 0;
  38.
       
  39.
      ProgrammerNote();
  40.
       
  41.
      cout << endl;
  42.
       
  43.
      ReadPoint("Enter point 1 [x y]: ", x1, y1);
  44.
      ReadPoint("Enter point 2 [x y]: ", x2, y2);
  45.
      ReadPoint("Enter point 3 [x y]: ", x3, y3);
  46.
       
  47.
      do{
  48.
      double Length = 0, Area = 0, Perimeter = 0,
  49.
      sideA = 0, sideB = 0, sideC = 0;
  50.
       
  51.
      choice = Menu();
  52.
      cout << endl;
  53.
       
  54.
      sideA = sqrt( pow(double(x2-x1),2) + pow(double(y2-y1),2) );
  55.
      sideB = sqrt( pow(double(x3-x2),2) + pow(double(y3-y2),2) );
  56.
      sideC = sqrt( pow(double(x3-x1),2) + pow(double(y3-y1),2) );
  57.
       
  58.
      if (choice == 1){
  59.
      Perimeter = ComputePerimeter(sideA, sideB, sideC);
  60.
      DisplayMeasure("Perimeter: ", Perimeter);
  61.
      }
  62.
      if (choice == 2){
  63.
      Perimeter = sideA + sideB + sideC;
  64.
      Area = ComputeArea(Perimeter, sideA, sideB, sideC);
  65.
      DisplayMeasure("Area: ", Area);
  66.
      }
  67.
      if (choice == 3){
  68.
      char side;
  69.
      double Length = 0;
  70.
      cout << "Which side would you like [A]p1-p2 [b]p2-p3 [C]p1-p3: ";
  71.
      cin >> side;
  72.
       
  73.
      if (side == 'A' || side == 'a'){
  74.
      Length = ComputeLength(x1, y1, x2, y2);
  75.
      DisplayMeasure("SideA: ", Length);
  76.
      }
  77.
       
  78.
      else if (side == 'B' || side == 'b'){
  79.
      Length = ComputeLength(x2, y2, x3, y3);
  80.
      DisplayMeasure("SideB: ", Length);
  81.
      }
  82.
       
  83.
      else if (side == 'C' || side == 'c'){
  84.
      Length = ComputeLength(x1, y1, x3, y3);
  85.
      DisplayMeasure("SideC: ", Length);
  86.
      }
  87.
      }
  88.
      }while (choice != 4);
  89.
      cout << endl;
  90.
      }//end main()
  91.
       
  92.
      void ProgrammerNote(void){
  93.
      cout << "Programmed by Paul Jones" << endl << endl;
  94.
      }// end ProgrammerNote()
  95.
       
  96.
      void ReadPoint(string prompt, int& x, int& y){
  97.
      cout << prompt;
  98.
      cin >> x >> y;
  99.
      }// end ReadPoint()
 100.
       
 101.
      int Menu(void){
 102.
      int choice;
 103.
      cout << endl;
 104.
      cout << setw(5) << " " << "1. Compute Perimeter" << endl
 105.
      << setw(5) << " " << "2. Compute Area" << endl
 106.
      << setw(5) << " " << "3. Compute Side Length" << endl
 107.
      << setw(5) << " " << "4. Quit" << endl;
 108.
      cout << "Enter choice [1-4]: ";
 109.
      cin >> choice;
 110.
      return choice;
 111.
      }// end Menu()
 112.
      double ComputeLength(int x1, int y1, int x2, int y2){
 113.
      double Length;
 114.
       
 115.
      Length = sqrt( pow(double(x2-x1),2) + pow(double(y2-y1),2) );
 116.
       
 117.
      return Length;
 118.
       
 119.
      }// end ComputeLength()
 120.
      double ComputePerimeter(double sideA, double sideB, double sideC){
 121.
      double P;
 122.
      P = sideA + sideB + sideC;
 123.
      return P;
 124.
      }// end ComputePerimeter()
 125.
       
 126.
      double ComputeArea(double Perimeter, double sideA, double sideB, double sideC){
 127.
      double S = 0, Area = 0;
 128.
      // S is the semi perimeter
 129.
      S = Perimeter / 2;
 130.
       
 131.
      Area = sqrt( S * ( (S-sideA) * (S-sideB) * (S-sideC) ) );
 132.
      return Area;
 133.
      }// end ComputeArea()
 134.
       
 135.
      void DisplayMeasure(string prompt, double value){
 136.
      cout << prompt << value << endl;
 137.
       
 138.
      }//end DisplayMeasure()