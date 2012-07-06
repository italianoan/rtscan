#ifndef RECORD_HPP_INCLUDED
#define RECORD_HPP_INCLUDED
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <models/task.hpp>

using namespace std;
using namespace Scan;
namespace Scan
{

class record
{

    int index_Pipe;
    int index_Task_In_Pipe;
    Task * task;

public:
    /**
       Default constructor, indexPipe and indexTasInPipe are init to -1 and
       task is initialized using its default constructor.
    */
    record();
    /**
           Constructor of record.
           @param i index of pipe
           @param j index of taks
           @param t task
    */
    record(Task&t, int i, int j);
    /** Copy constructor */
    record( const record &r);
    /// return index of Pipe
    int get_Index_Pipe();
    /// return index of task inside Pipe
    int get_Index_In_Pipe();
    /// return task
    const Task& get_Task() const;

    bool operator==(const record &other) const;


    bool equal(int indexP, int position);



    record & operator=(const record &r);
};

/**
    Outputs the record parameters on ostream. The output consists of
    the index of pipe in which ther is task, the index of task inside the pipe
    and task wcet value .
*/
std::ostream &operator<<(ostream &s, record &r);

}

#endif // RECORD_HPP_INCLUDED
