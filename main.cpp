// Luis Flores// Luis Flores
//  main.cpp
//  Copyright © Luis Flores. All rights reserved.
//
#include <iostream>
#include <time.h>

// Counter For Readers in CS
int readercount = 0;
// Counter For Writers in CS
int wrtcount = 0;
// Lock For readers and Writers
int mutex= 2;
// Lock For writers
int m_w = 1;

// Counters that enable the processes to advance and help simulate context switches, forcing the proccess to stop after one action.

int r1c = 0;
int r2c = 0;
int r3c = 0;
int w1c = 0;
int w2c = 0;


// Counter that enables loops within the Non Critical Section of the Processes, this is to simulate the a proccess being in the Non Critical Section

int r1_i;
int r2_i;
int r3_i;
int w1_i;
int w2_i;

// Checks to see if Any one is in The Critical section
void wait(int s)
{
    while(s<=0)
        ;
    
    s--;
}
// When done with CS this function enables others to enter
void signal(int s)
{
    s++;
}

// Meant to display if there is a problem while managing the critical Section
void panic()
{
    std::cout<<"PANIC!, There Is A Violation Of The Rules"<<std::endl;
}

int r1()
{
    switch(r1c)
    {
            // This is the Non Critical Section for r1
        case 0:
            std::cout<<"I am Reader 1 in the Non Critical Section"<<std::endl;
            r1c++;
            break;
            // In the NCS
        case 1:
            r1c++;
            break;
            // setting a loop counter to 0 and incrimenting r1c to move along the process, still in the NCS
        case 2:
            r1_i = 0;
            r1c++ ;
            break;
            // Begins loop to simulate doing work in the NCS
        case 3:
            if(r1_i<=10)
            {
                std::cout<<"Look at me(Reader 1) Being busy in the NCS"<<std::endl;
                r1c++;
            }
            else
                r1c = 5;
            break;
            // Increments the loop counter, reduces the case to check the condition whether to go back or go ahead, this is to simulate work done in Non Critical Section
        case 4:
            r1_i++;
            r1c--;
            break;
            // NCS Is done and now trying to Enter CS
        case 5:
            std::cout<<"I am reader 1 finished with the Non Critical Section, preparing to enter Critical Section"<<std::endl;
            r1c++;
            break;
        case 6:
            std::cout<<"I (reader 1) am now checking For Any writers and If there are less than 2 readers"<<std::endl;
            if(wrtcount==2)
            {
                panic();
            }
            if(readercount>2)
            {
                panic();
            }
            std::cout<<"The number of readers before (reader 1)enters CS is:"<<readercount<<"\t"<<"number of writers:"<<wrtcount<<std::endl;
                if(wrtcount == 1)
                {
                    std::cout<<"Reader 1 can not advance"<<std::endl;
                    r1c=5;
                }
                if(readercount==2)
                {
                    std::cout<<"Reader 1 can not advance"<<std::endl;
                    r1c=5;
                }
                if(readercount<=1&&wrtcount==0)
                {
                    wait(mutex);
                    readercount++;
                    wait(m_w);
                    signal(mutex);
                    std::cout<<"The coast is clear, Reader 1 Is GOING IN!"<<std::endl;
                    r1c++;
                }
                break;
            // The Critical Section
        case 7:
            std::cout<<"I (Reader 1)am now in the Critical Section"<<std::endl;
            r1c++;
            break;
        case 8:
            if(r1_i<25)
            {
            std::cout<<"I am (Reader 1) reading 'How To Pass CSC 375"<<std::endl;
                if(wrtcount==2)
                {
                    panic();
                }
                if(readercount>2)
                {
                    panic();
                }
            r1_i++;
            }
            else
            {
            r1c++;
            }
            break;
        case 9:
            std::cout<<"I am (reader 1) Done with the critical Section"<<std::endl;
    
                wait(mutex);
                readercount--;
                if(readercount==0)
                {
                    signal(m_w);
                }
                signal(mutex);
                std::cout<<"I am reader 1, Exiting The CS"<<std::endl;
                r1c++;
                break;
            
        case 10:
            std::cout<<"I am reader 1 back at the NCS, I am done with the Process"<<std::endl;
            r1c++;
            break;
    }
    return 0;
}

int r2()
{
    switch(r2c)
    {
            // This is the Non Critical Section for r2
        case 0:
            std::cout<<"I am Reader 2 in the Non Critical Section"<<std::endl;
            r2c++;
            break;
            // In the NCS
        case 1:
            r2c++;
            break;
            // setting a loop counter to 0 and incrimenting r1c to move along the process, still in the NCS
        case 2:
            r2_i = 0;
            r2c++ ;
            break;
            // Begins loop to simulate doing work in the NCS
        case 3:
            if(r2_i<=10)
            {
                std::cout<<"Look at me(Reader 2) Being busy in the NCS"<<std::endl;
                r2c++;
            }
            else
                r2c = 5;
            break;
            // Increments the loop counter, reduces the case to check the condition whether to go back or go ahead, this is to simulate work done in Non Critical Section
        case 4:
            r2_i++;
            r2c--;
            break;
            // NCS Is done and now trying to Enter CS
        case 5:
            std::cout<<"I am reader 2 finished with the Non Critical Section, preparing to enter Critical Section"<<std::endl;
            r2c++;
            break;
        case 6:
            std::cout<<"I (reader 2) am now checking For Any writers and If there are less than 2 readers"<<std::endl;
            if(wrtcount==2)
            {
                panic();
            }
            if(readercount>2)
            {
                panic();
            }
            std::cout<<"The number of readers before (reader 2)enters CS is:"<<readercount<<"\t"<<"number of writers:"<<wrtcount<<std::endl;
                if(wrtcount == 1)
                {
                    std::cout<<"Reader 2 can not advance"<<std::endl;
                    r2c--;
                }
                if(readercount==2)
                {
                    std::cout<<"Reader 2 can not advance"<<std::endl;
                    r2c--;
                }
                if(readercount<=1&&wrtcount==0)
                {
                    wait(mutex);
                    readercount++;
                    wait(m_w);
                    signal(mutex);
                    std::cout<<"The coast is clear, Reader 2 Is GOING IN!"<<std::endl;
                    r2c++;
                }
            break;
            
            // The Critical Section
        case 7:
            std::cout<<"I (Reader 2) am now in the Critical Section"<<std::endl;
            r2c++;
            break;
        case 8:
            if(r2_i<25)
            {
                std::cout<<"I am (Reader 2) reading 'How To Pass CSC 375"<<std::endl;
                if(wrtcount==2)
                {
                    panic();
                }
                if(readercount>2)
                {
                    panic();
                }
                r2_i++;
            }
            else
            {
                r2c++;
            }
            break;
        case 9:
            std::cout<<"I am (reader 2) Done with the critical Section"<<std::endl;
            
                
                wait(mutex);
                readercount--;
                if(readercount==0)
                {
                    signal(m_w);
                }
                signal(mutex);
                std::cout<<"I am reader 2, Exiting The CS"<<std::endl;
                r2c++;
                break;
        case 10:
            std::cout<<"I am reader 2 back at the NCS, I am done with the Process"<<std::endl;
            r2c++;
            break;
    }
    return 0;
}


int r3()
{
    switch(r3c)
    {
            // This is the Non Critical Section for r3
        case 0:
            std::cout<<"I am (Reader 3) in the Non Critical Section"<<std::endl;
            r3c++;
            break;
            // In the NCS
        case 1:
            r3c++;
            break;
            // setting a loop counter to 0 and incrimenting r1c to move along the process, still in the NCS
        case 2:
            r3_i = 0;
            r3c++;
            break;
            // Begins loop to simulate doing work in the NCS
        case 3:
            if(r3_i<=10)
            {
                std::cout<<"Look at me(Reader 3) Being busy in the NCS"<<std::endl;
                r3c++;
            }
            else
                r3c = 5;
            break;
            // Increments the loop counter, reduces the case to check the condition whether to go back or go ahead, this is to simulate work done in Non Critical Section
        case 4:
            r3_i++;
            r3c--;
            break;
            // NCS Is done and now trying to Enter CS
        case 5:
            std::cout<<"I am (reader 3) finished with the Non Critical Section, preparing to enter Critical Section"<<std::endl;
            r3c++;
            break;
        case 6:
            std::cout<<"I am (reader 3) now checking For Any writers and If there are less than 2 readers"<<std::endl;
            if(wrtcount==2)
            {
                panic();
            }
            if(readercount>2)
            {
                panic();
            }
            std::cout<<"The number of readers before (reader 3)enters CS is:"<<readercount<<"\t"<<"number of writers:"<<wrtcount<<std::endl;
                if(wrtcount == 1)
                {
                    std::cout<<"Reader 3 can not advance"<<std::endl;
                    r3c=5;
                }
                if(readercount==2)
                {
                    std::cout<<"Reader 3 can not advance"<<std::endl;
                    r3c=5;
                }
                if(readercount<=1&&wrtcount==0)
                {
                    wait(mutex);
                    readercount++;
                    wait(m_w);
                    signal(mutex);
                    std::cout<<"The coast is clear, Reader 3 Is GOING IN!"<<std::endl;
                    r3c++;
                    
                }
                break;
            // The Critical Section
        case 7:
            std::cout<<"I (Reader 3) am now in the Critical Section"<<std::endl;
            r3c++;
            break;
        case 8:
            if(r3_i<25)
            {
                std::cout<<"I am (Reader 3) reading 'How To Pass CSC 375"<<std::endl;
                if(wrtcount==2)
                {
                    panic();
                }
                if(readercount>2)
                {
                    panic();
                }
                r3_i++;
            }
            else
            {
                r3c++;
            }
            break;
        case 9:
            std::cout<<"I am (reader 3) Done with the critical Section"<<std::endl;
          
                wait(mutex);
                readercount--;
                if(readercount==0)
                {
                    signal(m_w);
                }
                signal(mutex);
                std::cout<<"I am (reader 3), Exiting The CS"<<std::endl;
                r3c++;
                break;
            
        case 10:
            std::cout<<"I am (reader 3) back at the NCS, I am done with the Process"<<std::endl;
            r3c++;
            break;
    }
    return 0;
}

int w1()
{
    switch(w1c)
    {
            // This is the Non Critical Section for w1
        case 0:
            std::cout<<"I am Writer 1 in the Non Critical Section"<<std::endl;
            w1c++;
            break;
            // In the NCS
        case 1:
            w1c++;
            break;
            // setting a loop counter to 0 and incrimenting w1c to move along the process, still in the NCS
        case 2:
            w1_i = 0;
            w1c++ ;
            break;
            // Begins loop to simulate doing work in the NCS
        case 3:
            if(w1_i<=10)
            {
                std::cout<<"Look at me(Writer 1) Being busy in the NCS"<<std::endl;
                w1c++;
            }
            else
                w1c = 5;
            break;
            // Increments the loop counter, reduces the case to check the condition whether to go back or go ahead, this is to simulate work done in Non Critical Section
        case 4:
            w1_i++;
            w1c--;
            break;
            // NCS Is done and now trying to Enter CS
        case 5:
            std::cout<<"I am Writer 1 finished with the Non Critical Section, Preparing to enter Critical Section"<<std::endl;
            w1c++;
            break;
        case 6:
            std::cout<<"I (Writer 1) am now checking For Any writers and If there are any readers or writers"<<std::endl;
            if(wrtcount==2)
            {
                panic();
            }
            if(readercount>2)
            {
                panic();
            }
            std::cout<<"The number of readers before (Writer 1)enters CS is:"<<readercount<<"\t"<<"number of writers:"<<wrtcount<<std::endl;
               if(wrtcount==0&&readercount==0)
               {
                   wait(m_w);
                   w1c++;
                   wrtcount++;
               }
                else
                {
                    std::cout<<"Writer 1 can not advance"<<std::endl;
                    w1c=5;
                }
            break;
            
            // The Critical Section
        case 7:
            std::cout<<"I (Writer 1)am now in the Critical Section"<<std::endl;
            w1c++;
            break;
        case 8:
            if(w1_i<25)
               {
                std::cout<<"I am (Writer 1) writing 'How To Pass CSC 375"<<std::endl;
                   if(wrtcount==2)
                   {
                       panic();
                   }
                   if(readercount>2)
                   {
                       panic();
                   }
                w1_i++;
               }
            else
            {
                w1c++;
            }
        break;
        case 9:
            std::cout<<"I am (Writer 1) Done with the critical Section, leaving now"<<std::endl;
                signal(m_w);
                wrtcount--;
                w1c++;
                break;
            
        case 10:
            std::cout<<"I Writer 1 back at the NCS, I am done with the Process"<<std::endl;
            w1c++;
            break;
    }
    return 0;
}


int w2()
{
    switch(w2c)
    {
            // This is the Non Critical Section for w2
        case 0:
            std::cout<<"I am Writer 2 in the Non Critical Section"<<std::endl;
            w2c++;
            break;
            // In the NCS
        case 1:
            w2c++;
            break;
            // setting a loop counter to 0 and incrimenting w1c to move along the process, still in the NCS
        case 2:
            w2_i = 0;
            w2c++ ;
            break;
            // Begins loop to simulate doing work in the NCS
        case 3:
            if(w2_i<=10)
            {
                std::cout<<"Look at me(Writer 2) Being busy in the NCS"<<std::endl;
                w2c++;
            }
            else
                w2c = 5;
            break;
            // Increments the loop counter, reduces the case to check the condition whether to go back or go ahead, this is to simulate work done in Non Critical Section
        case 4:
            w2_i++;
            w2c--;
            break;
            // NCS Is done and now trying to Enter CS
        case 5:
            std::cout<<"I am Writer 2 finished with the Non Critical Section, preparing to enter Critical Section"<<std::endl;
            w2c++;
            break;
        case 6:
            std::cout<<"I (Writer 2) am now checking For Any writers and If there are any readers or writers"<<std::endl;
            if(wrtcount==2)
            {
                panic();
            }
            if(readercount>2)
            {
                panic();
            }
            std::cout<<"The number of readers before (Writer 2)enters CS is:"<<readercount<<"\t"<<"number of writers:"<<wrtcount<<std::endl;
                if(wrtcount==0&&readercount==0)
                {
                    wait(m_w);
                    w2c++;
                    wrtcount++;
                    break;
                }
                else
                {
                    std::cout<<"Writer 2 can not advance"<<std::endl;
                    w2c=5;
                }
                break;
            
        // The Critical Section
        case 7:
            std::cout<<"I (Writer 2)am now in the Critical Section"<<std::endl;
            w2c++;
            break;
        case 8:
            if(w2_i<25)
            {
                std::cout<<"I am (Writer 2) writing 'How To Pass CSC 375"<<std::endl;
                if(wrtcount==2)
                {
                    panic();
                }
                if(readercount>2)
                {
                    panic();
                }
                w2_i++;
            }
            else
            {
                w2c++;
            }
            break;
        case 9:
            std::cout<<"I am (Writer 2) Done with the critical Section, leaving now"<<std::endl;
            w2c++;
            signal(m_w);
            wrtcount--;
            break;
        case 10:
            std::cout<<"I Writer 2 back at the NCS, I am done with the Process"<<std::endl;
            w2c++;
            break;
    }
    return 0;
}



int main()
{
    std::cout<<"Luis Flores, Project 2, CSC 375"<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"The Simulation Of context Switching"<<std::endl;
    std::cout<<""<<std::endl;
    
    
    srand(time(0));
    
    for(int i=0;i<=10000;i++)
    {
        int id = rand()%5;
        
        switch(id)
        {
            case 0: r1();
                break;
            case 1: r2();
                break;
            case 2: r3();
                break;
            case 3: w1();
                break;
            case 4: w2();
                break;
                
        }
    }
    
    return 0;
}


