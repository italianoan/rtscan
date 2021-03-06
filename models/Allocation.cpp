#include <Allocation.hpp>
	
Allocation::Allocation():feasible(false),minNumProc(1){
}

Allocation::Allocation(const Allocation &a)
{
    feasible=a.feasible;
    for(int i=0; i< a.pipes.size();i++)
    {
        pipes.push_back(a.pipes.at(i));
    }
    minNumProc=a.minNumProc;
}

Allocation::Allocation(vector< pair<double,double> >period_deadline):feasible(false),minNumProc(1)
{

    for(int i=0; i<period_deadline.size();i++)
    {
        Transaction t=  Transaction(period_deadline[i].first, period_deadline[i].second);
        pipes.push_back(t);
    }
}
bool Allocation::get_feas()const
{
    return feasible;
}

int Allocation::get_minNumProc()const
{
    return minNumProc;
}

Transaction& Allocation::get_transaction(int i)
{
    if(i <pipes.size())
    return pipes.at(i);
    else{}
        //lanciare ecezione
}
void Allocation::allocTask(const Task&t, int node,int pipe_index)
{
    pipes.at(pipe_index).add_task(t,node);

}

void Allocation::setMinProc(int i)
{
    minNumProc=i;
}

void Allocation::setFeasible(bool f)
{
    feasible=f;
}

void Allocation::printAllocation()
{
        if(feasible)
        cout<<"---ALLOCATION IS FEASIBLE WITH " << minNumProc <<" PROCESSOR---"<<endl;
        else
        {
            cout<<"---ALLOCATION IS **NOT**FEASIBLE  "<<endl;
        }
        for(int i=0; i< pipes.size();i++)
        {
            cout<<pipes.at(i);
        }

}
void Allocation::clear()
{
    for(int i=0;i<pipes.size();i++)
    {
        pipes.at(i).clear();
    }

}
