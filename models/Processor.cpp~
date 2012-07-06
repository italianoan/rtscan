#include <Processor.hpp>

namespace Scan{

Processor::Processor():utilised_Bw(0),free(1),allocation_List(),start_Utilised_Bw(0),proc_Utilisation(0),computation_Time(0),id(increment++),used_flag(false)
{

}

Processor::Processor(double u):start_Utilised_Bw(u), utilised_Bw(u),free(1-u),allocation_List(),proc_Utilisation(0),computation_Time(0),id(increment++),used_flag(false)
{

}


Processor::Processor(const Processor &p)
{
    utilised_Bw=p.utilised_Bw;
    start_Utilised_Bw=p.start_Utilised_Bw;
    computation_Time=p.computation_Time;
    proc_Utilisation=p.proc_Utilisation;
    free= p.free;
    id=p.id;
    for(int i=0; i< p.allocation_List.size();i++)
    allocation_List.push_back(p.allocation_List.at(i));
    used_flag=p.used_flag;
}
double Processor::get_free()const
{
    return free;
}

double Processor::get_utilised_Bw()const
{
    return utilised_Bw;
}
bool Processor::get_flag_utilised() const
{
    return used_flag;
}
int Processor::get_Id() const
{
    return id;
}


 double Processor::get_Computation_Time()const
 {
     return computation_Time;
 }

double Processor::get_Utilisation()const
{
    return proc_Utilisation;
}


void Processor::clean_data()
{
    utilised_Bw=start_Utilised_Bw;
    free=1-utilised_Bw;

    computation_Time=0;
    proc_Utilisation=0;
    allocation_List.clear();
}


    void Processor::update_Processor(int indexPipe,int positionTask ,Task &task, double bw)
    {
        computation_Time=computation_Time+task.get_wcet();
        proc_Utilisation=proc_Utilisation+(task.get_wcet()/task.get_period());
        record * r = new record( task,indexPipe,positionTask);
        allocation_List.push_back(*r);
    }

    double Processor::compute_Time(int indexPipe, int positionTask)
    {
        double result=0;
        for(int i=0; i< allocation_List.size();i++)
        {
            Task t=allocation_List.at(i).get_Task();
            result=result+ t.get_wcet();
            if(allocation_List.at(i).equal(indexPipe,positionTask))
            {
                return result;
            }
        }
        return -1;
    }
    std::ostream &operator<<(ostream &s, Processor &p)
{
    s<<"UtilisedBW :"<<p.get_utilised_Bw()<<endl;
    s<<"free bw :"<<p.get_free()<<endl;
    s<<"computation  :"<<p.get_Computation_Time()<<endl;
    s<<"Processor Utilization :"<< p.get_Utilisation()<<endl;
    s<<"ID :"<<p.get_Id()<<endl;
    s << "-------------------" << endl;
    return s;
}


}
