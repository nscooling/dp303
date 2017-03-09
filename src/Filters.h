#ifndef FILTERS_H
#define FILTERS_H

#include "MessagQueue.h"
#include "Thread.h"


class LowPass;

class Generator : public feabhOS::IRunnable
{
public:
  Generator();
  virtual bool run();

private:
  // Association
  //
  LowPass* lowPass;
  friend void bind(Generator& g, LowPass& lp);
};

class Display;

class LowPass : public feabhOS::IRunnable
{
public:
  LowPass(int filterValue = 10);
  virtual bool run();

  // Asynchronous call
  //
  void process(int value);

private:
  int set_point;

  // Asynchronous message
  //
  typedef void (LowPass::* ptr_mem_fn)(int);
  struct CallFrame
  {
    ptr_mem_fn call;
    int        arg;

    CallFrame(ptr_mem_fn f = 0, int a = 0) : call(f), arg(a) {}
  };

  MessageQueue<CallFrame, 8> msgQ;

  void process_impl(int val);

  // Association
  //
  Display* display;
  friend void bind(LowPass& lp, Display& disp);
};


class Display : public feabhOS::IRunnable
{
public:
  Display();
  virtual bool run();

  // Asynchronous call
  //
  void show(int value);

private:
  // Asynchronous message
  //
  typedef void (Display::* ptr_mem_fn)(int);
  struct CallFrame
  {
    ptr_mem_fn call;
    int        arg;

    CallFrame(ptr_mem_fn f = 0, int a = 0) : call(f), arg(a) {}
  };

  MessageQueue<CallFrame, 8> msgQ;

  void show_impl(int val);

};

#endif // FILTERS_H