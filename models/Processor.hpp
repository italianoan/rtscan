#ifndef PROCESSOR_HPP_INCLUDED
#define PROCESSOR_HPP_INCLUDED
#include <string>
#include <vector>
#include <common/exceptions.hpp>
#include <iostream>
#include <models/task.hpp>
#include <models/record.hpp>
using namespace std;
using namespace Scan;
namespace Scan
{
static int increment=0;
class Processor
{
private:

    vector <record> allocation_List;
    double start_Utilised_Bw;
    double utilised_Bw;
    double free;
    double proc_Utilisation;
    double computation_Time;
    int id;
    bool used_flag;


public:
    /**
       Default constructor: start_Utilised_Bw, utilised_Bw, proc_Utilisation and computation_Time are equal to 0;
       free =1; allocation_List is void;
    */
    Processor();
    /**
       Constructor: start_Utilised_Bw, utilised_Bw are equal to u;
       proc_Utilisation and computation_Time are equal to 0;
       free =1- u;
       allocation_List is void;

       @param u : start value of processor utilisation bandwidth .
    */
    Processor(double u);
    /*** Copy constructor */
    Processor(const Processor &p);

    /// return utilised_Bw
    double get_utilised_Bw()const;
    /// return id processor
    int get_Id() const;
    /// return free
    double get_free()const;

    bool get_flag_utilised() const;
    /// return computation_Time
    double get_Computation_Time()const;
    /// return proc_Utilisation
    double get_Utilisation()const;

    /** set the values ​​to their initial value */
    void clean_data();
    /** Update processor value adding a task to his execution task list.
        @param: indexPipe: index of pipe(transaction) of task.
        @param: positionTask: position of task inside pipe.
        @param: task: task to add.
        @param: bw: bandwidth adding to processor utilised_Bw
    */
    void update_Processor(int indexPipe,int positionTask ,Task &task, double bw);

    /** Compute the sum of computation time of task in this processo that
    precede task reconize using parameter
    @param indexPipe: index of pipe(transaction) of task.
    @param positionTask:position of task inside pipe.
    */
    double compute_Time(int indexPipe, int positionTask);


};
/**
    Outputs the processor parameters on ostream. The output consists of
    utilised_Bw, free, computation_Time, proc_Utilisation and id.
*/
std::ostream &operator<<(ostream &s, Processor &p);

class ProcCmpUtilizeIncr : public std::less<Processor>
{
public:
    bool operator()(const Processor &a,  const  Processor &b)
    {
        return a.get_free() <= b.get_free();
    }
};


class ProcCmpUtilizeDecr : public std::less<Processor>
{
public:
    bool operator()(const Processor &a,  const  Processor &b)
    {
        return a.get_free() >= b.get_free();
    }
};

}
#endif // PROCESSOR_HPP_INCLUDED
