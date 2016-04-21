# Multithreading
========================
About program
-------------

These programs are written with the purpose of acquaintance with 
multithreaded programming and thread synchronization methods. 

The point is this: to realize a series-parallel starting threads 
in Windows using synchronization tools. Vertex - the point of 
start/end flows, arc flows. In the graph it is necessary to select 
three groups of streams. The first group is not synchronized, the 
second synchronized mutex (grabs a mutex on execution time), and the 
third synchronized semaphore (passes control to another thread after 
each iteration).

The graph presented in graph.png

Program written under Windows(WinAPI) and Linux(POSIX) respectively.

About threads
-------------

In a conventional operating system, each process corresponds to an address space and single control flow. 
In fact, this defines the process. However, often there are situations in which it is advantageous to have 
multiple quasi-parallel control flows in the same address space as if they were different processes.

When you run a multithreaded process on a system with a single processor, threads are running serially. 
The CPU quickly switches between threads, giving the impression of parallel work streams, although at a not 
so fast processor. In the case of three of the limited performance of the processor threads in a single process 
all the threads will run in parallel, and each thread will correspond to a virtual processor with a speed equal 
to one-third the performance of a real processor.

However, different threads within the same process are not as independent as separate processes. 
All such threads share the same address space. This means that they share the same global variables. 
All threads within a process always share the common objective of a single user, and the threading model 
used here for faster solution of the problem by parallelization. Thus, threads have their own:
 
– 	 program counter;

– 	 stack.

– 	 registers;

– 	 child;

– 	 state.


Threads share: 

– 	 address space;

– 	 global variables;

– 	 open files;

– 	 timers;

– 	 semaphores;

– 	 statistical information.

As with any process, the thread can be water from several States: working, blocked, ready or terminated.

Semaphores
----------

In 1965 Dijkstra (E. W. Dijkstra) proposed to use a variable for counting triggers, stored for the future. 
They were offered a new type of variables, the so-called semaphore, whose value can be zero (in the absence 
of stored signals activate) or some positive number corresponding to the number of pending trigger signals.

A semaphore can control the number of processes that have access to it. He is set to limit the number 
of processes which access is allowed. When this number is reached, subsequent processes will be suspended 
until one or more of the processes detach from the semaphore and frees the access.

Mutexes
---------

Sometimes uses a simplified version of the semaphore, called a mutex 
(mutex is short for mutual exclusion - mutual exclusion). The mutex is not able to count, 
he can only manage mutual exclusion access to shared resources or codes. The mutex implementation 
is simple and efficient, which makes the use of mutexes, especially useful in the case of flows, existing only in user space.

A mutex is a variable that can contain a water of two States: blocked or unblocked. Therefore, 
for the description of the mutex, only one bit is required, although most use a variable, in which 
0 means unlocked state, and all other values correspond to a blocked state. The value of the mutex is 
set with two procedures. If a thread (or process) is about to enter a critical region, it calls mutex_lock 
procedure. If the mutex is not locked (that is the entrance to a critical region are allowed), the query is 
executed and the calling thread can enter the critical region.

About thread functions
----------------------

WinAPI: https://msdn.microsoft.com/en-us/library/windows/desktop/ms684847(v=vs.85).aspx#thread_functions

POSIX: https://computing.llnl.gov/tutorials/pthreads/


