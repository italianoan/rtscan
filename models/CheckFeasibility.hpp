#ifndef CHEACKFEASIBILITY_HPP_INCLUDED
#define CHEACKFEASIBILITY_HPP_INCLUDED

#include <vector>
#include <map>
#include <algorithm>
#include <models/task.hpp>
#include <models/taskset.hpp>
#include <models/Processor.hpp>
#include <models/Allocation.hpp>
#include <models/record.hpp>
using namespace std;
using namespace Scan;
namespace Scan
{
enum orderTaskSelection { precedence, decrease_wcet, increase_wcet };
enum precSelectionAlg { bestFit, worstFit, firstFit };









class CheckFeasibility
{
    int num_proc_try;
    int verbose;
    int num_proc_available;
    orderTaskSelection order_task;
    precSelectionAlg proc_algorithm;
    vector<Processor> processors;
    vector <TaskSet> task_sets;
    vector<record> tasks_for_selection;
    Allocation *result;
    vector <Processor> processor_utilised;

public:
    /**
       Default constructor: num_proc_try is equal to 1;
    */
    CheckFeasibility();
    /**
      Constructor:
      @param orderTAsk : assigned to order_task that is type of algorithm used to select task.
      @param Alg : assigned to proc_algorithm ; It's type of algorithm used to select processor.
      @param tss: assigned to task_sets. Each task_Set contains tasks of one pipe.
      @param period_deadline: used to inizialized Allocation result.
      @param ps: assigned to processors.
        */
    CheckFeasibility( int orderTask, int Alg,  vector<  TaskSet> tss,vector< pair<double,double> >period_deadline, vector<Processor> ps,int v);

    /** select processor according algorithm in proc_algorithm and update selected processor data
      @param indexPipe: index of pipe(transaction) of task.
      @param positionTask: position of task inside pipe.
      @param t: task must be execute.
    */
    int selectProcessor(int indexPipe,int positionTask,Task &t );

    /*** check if pipes are feasible */
    Allocation & check();


    void initTaskSelectionSet();
    template<class Cmp>

    /// sort processor_utilised
    void sort_proc();

    /// select task according algorithm in order_task
    record& selectTask();


    double computeBandwidth(int indexPipe,int procSelected, double dead_line, double wcet);
    /** set the values of processors ​​to their initial value */
    void  clean_processors();
    void initProcessor();
    void printProcessor();
};



template<class Cmp>
void CheckFeasibility::sort_proc()
{
    std::sort(processor_utilised.begin(),processor_utilised.end(), Cmp());
    std::sort(processors.begin(),processors.end(), Cmp());
    /*for(int i=0; i< processors.size(); i++)
     {
         cout<< "IL VETTORE DEI PROCESSORI **DISPONIBILI** SONO :"<<endl;
              cout <<processors.at(i);
     }
      for(int i=0; i< processor_utilised.size(); i++)
     {
         cout<< "IL VETTORE DEI PROCESSORI UTILIZZATI SONO :"<<endl;
              cout <<processor_utilised.at(i);
     }*/
}
}
#endif // CHEACKFEASIBILITY_HPP_INCLUDED
