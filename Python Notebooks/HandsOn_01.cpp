#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
using namespace std;

class Vector3D{
  public:

    //Cartesian(x,y,z)
    static Vector3D Cartesian(double x, double y, double z) {
      return Vector3D(x, y, z);
    }

    //Polar(r, theta, phi)
    static Vector3D Polar(double r, double theta, double phi) {
      return Vector3D(r*sin(theta)*cos(phi), r*sin(theta)*sin(phi), r*cos(theta));
    }

    //setters
    void set_x(double value) { x_ = value; }
    void set_y(double value) { y_ = value; }
    void set_z(double value) { z_ = value; }

    /* if we wish to implement setters for polar coordinates
    we'd actually have to add r, theta, phi as attributes of the class
    and work with both of them all the time.*/

    //getters
    double get_x () { return x_; }
    double get_y () { return y_; }
    double get_z () { return z_; }
    double magnitude () { return sqrt(pow(x_,2) + pow(y_,2) + pow(z_,2)); }
    double theta () { return atan(z_ / sqrt(pow(x_,2) + pow(y_,2)))* (180/M_PI); }
    double phi () { return atan(y_/x_)* (180/M_PI); }

    //print method
    void print() {
      cout << "(" << x_ << "," << y_ << "," << z_ << ")" << endl;
    }

    void printPolar() {
      cout << "(" << this->magnitude() << "," << this->theta() << "," << this->phi() << ")" << endl;
    }

    //functions
    double scalarProduct (Vector3D Prime) {
      return x_*Prime.x_ + y_*Prime.y_ + z_*Prime.z_;
    }
    Vector3D vectorProduct(Vector3D Prime) {
      double newx, newy, newz;
      newx = y_*Prime.z_ - Prime.y_*z_;
      newy = z_*Prime.x_ - Prime.z_*x_;
      newz = x_*Prime.y_ - Prime.x_*y_;
      return Vector3D(newx, newy, newz);
    }

    //operators overloading
    Vector3D operator+(Vector3D Prime) {
      return Vector3D(x_ + Prime.x_, y_ + Prime.y_, z_ + Prime.z_);
    }
    Vector3D operator-(Vector3D Prime) {
      return Vector3D(x_ - Prime.x_, y_ - Prime.y_, z_ + Prime.z_);
    }
    void operator=(Vector3D Prime) {
      x_ = Prime.x_;
      y_ = Prime.y_;
      z_ = Prime.z_;
    }

  private:
  double x_, y_,z_;

  //constructor
  Vector3D(double x, double y, double z) {
    x_ = x;
    y_ = y;
    z_ = z;
  };

};

double angle (Vector3D v1, Vector3D v2){
  return acos(v1.scalarProduct(v2) / (v1.magnitude()*v2.magnitude())) * (180/M_PI);
}

/************************************************/

int main() {
  double x, y, z;

  Vector3D Vec1 = Vector3D::Cartesian(1,0,0);
  Vector3D Vec2 = Vector3D::Cartesian(2,2,0);

  cout << endl;
  cout << "The coordinates stored in Vec1 are : ";
  Vec1.print();
  cout << "The coordinates stored in Vec2 are : ";
  Vec2.print();

  cout << "In polar coordinates Vec2 is : ";
  Vec2.printPolar();

  cout << "The scalar product is : " << Vec1.scalarProduct(Vec2) << endl;
  cout << "The vector product is : ";
  (Vec1.vectorProduct(Vec2)).print();

  cout << "The angle between them is : " << angle(Vec1, Vec2) << " degrees " << endl;

  cout << "Let's sum Vec1 and Vec2 : ";
  (Vec1+Vec2).print();

  cout << "Let's subtract Vec1 and Vec2 : ";
  (Vec1-Vec2).print();

  cout << "If we make Vec1 and Vec2 equal: ";
  Vec2 = Vec1;
  Vec2.print();
  cout << endl;

  return 0;
}
