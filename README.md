# ThreadLibForC

<p><b>Warning:</b> Your implementation would be very specific to the underlying hardware. You are required
to comply with x86_64<p>

<p><b>Getting started:</b></p>

    Have a look at the main.c file. In that you have two blocks of code, enabled based on whether or not you have set the TESTING mode or not. It is recommended that you start work in the TESTING mode once you have done the development, undefine the TESTING flag and make sure the other block of code works. When marking your submissions we will run the same main file with the TESTING flag undefined.

<p><b>Background:</b></p>
<p>You will be implementing user-level, cooperating threads. Where user-level means that kernel does
not know that there exists more than one thread; so these threads will not be running in parallel even
if you have multiple CPUs which can accommodate multiple threads at a time. The threads will be
cooperating by releasing the CPU voluntarily. They do this by calling the yield() function.
So we make use of this yield() function to implement the illusion of multiple parallel threads. For a
C-function, something called the calling convention defines who to pass arguments, how to get the
results and what registers are preserved and what registers can be changed. This calling convention
is defined for a language and architecture pair; for example C-calling convention in x86_64 is
different to C-calling convention in ARM. For this lab, we will test your code on x86_64 so make
sure you test and develop on ``x86_64``.</p>
<p>If the calling convention is preserved, the calling function does not care if another thread ran before
yield() return. It will see as if yield() function returned, but after a long time.</p>
