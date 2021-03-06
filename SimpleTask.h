//***********************************************************************************
// MIT License
// 
// Copyright (c) 2018 Kamon Singtong
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//***********************************************************************************
// Version : 0.1 beta
// Owner : Kamon Singtong (MakeArduino.com)
// facebook : makearduino 
//***********************************************************************************

#ifndef _SIMPLE_TASK_H
#define _SIMPLE_TASK_H

#ifndef MAX_TASK
#define MAX_TASK 16
#endif

#ifndef TASK_OVERFLOW_BIT
#define TASK_OVERFLOW_BIT      31
#endif

#define TASK_OVERFLOW_BITMASK    ((1<<(TASK_OVERFLOW_BIT))-1)

typedef struct task_t{
    void (*callback)(task_t&);
    unsigned long interval;
    unsigned long timestamp;
    unsigned long timeoffset;
    unsigned long offset;
    bool enabled;
};

class SimpleTask{
public : 
    SimpleTask();
    task_t* create(void (*callback)(task_t&),int interval);
    void loop(unsigned long t=0);
protected:
    struct task_t tasks[MAX_TASK];
    int taskCount = 0;
    const unsigned long overflow_bitmask = TASK_OVERFLOW_BITMASK;
};

extern SimpleTask Task;

#endif /*_SIMPLE_TASK_H*/
