// Rat class i.e. a class for rational numbers
/** Rat Class -- a class for rational numbers
 *  Rat.cpp
 *  
 *  Purpose:
 *     To demonstrate concepts of Operator Overloading.    
 *  Fall, 2011
 *
 *  Problem:  
 *     Check File: 'Rat class assignment' 
 *      
 *  Input Format: 
 *    
 *  OutPut Format:     
 *
 * @Compiler version on which Program is Last Run before uploading to Github: Dev-C++ 5.4.1, Date: 1st July, 2013  
 * @author Gurpreet Singh
 */    

#include <iostream>
#include <cstdlib>
using namespace std;
class Rat{
  private:
    int n;
    int d;

  public:
    // constructors
// default constructor
    Rat(){
        n=0;
        d=1;
       }
  
  // 2 parameter constructor
    Rat(int i, int j){
        n=i;
        d=j;
      }
  // conversion constructor
    Rat(int i){
        n=i;
        d=1;
      }
//accessor functions (usually called get() and set(...)  )
   void Reduced(){
       if(d<=n){
         for(int i=2;i<=d; i){
             if(n%i==0&&d%i==0)
             {
                n=n/i;
                d=d/i;
                continue;               
             }     
             i++;
          }// for loop
       }// if loop ends 
       else{}
       
        
       }
 
       int getN(){ return n;}
       
       int getD(){ return d;}
       
       void setN(int i){ n=i;}
       
       void setD(int i){ d=i;}
       
       //arithmetic operators
        Rat operator+(Rat r){
             Rat t;
             t.n=n*r.d+d*r.n ;
             t.d=d*r.d; 
             return t;
       }
      Rat operator-(Rat r){
          Rat t;
          t.n= n*r.d-d*r.n ;          
          t.d= d*r.d;
          return t;
        }
      
      Rat operator*(Rat r){
          Rat t;
          t.n= n*r.n ;          
          t.d= d*r.d;
          return t;
          
        }
      Rat operator/(Rat r){
          Rat t;
          t.n= n*r.d ;          
          t.d= d*r.n;
          return t;
      }
  
    // 2 overloaded i/o operators
      friend ostream& operator<<(ostream& os, Rat r);
      friend istream& operator>>(istream& is, Rat& r);
  }; //end Rat

// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
   ostream& operator<<(ostream& os, Rat r){
        if(r.n>r.d){
         int a,b;
         a= r.n/r.d;
         b= r.n%r.d;
         os<<a<<" "<<b<<"/"<<r.d<<endl;           
        }
        else                
           os<<r.n<<" / "<<r.d<<endl;
   return os;}
// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its provate parts.
   istream& operator>>(istream& is, Rat& r){
    is>>r.n>>r.d;
    return is;
 }
 int  main(){
      Rat x(1,2), y(2,3), z;
         z=x+y;
         
    cout<<z;
    x.setN(3);
    y.setD(2);
    z=x+y;
    z.Reduced();
    cout<<z;
    cin>>x;
    cout<<x; 
    z= x+5;
    cout<<z;
    system("pause");
    return 0;
}

