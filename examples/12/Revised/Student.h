#ifndef Student_h
#define Student_h

#include "Person.h"
#include <vector>
#include <string>

class Student : public Person {
  public:
    Student(const std::string& name, int id);
    virtual ~Student();
    int id() const { return id_; }
    virtual void print() const;

    void addCourse(const std::string& course);
    const std::vector<std::string>* getCourses() const;
    void printCourses() const;

  private:
    int id_;
    std::vector<std::string>* courses_;
};
#endif
