# Operating System, 2019 Spring

* Meetings
  - ITP30002-02 :clock1: Tue/Fri, 1PM-2:15PM :door: OH 401
  - ECE30021-02 :clock2: Tue/Fri, 2:30PM-3:45PM :door: OH 401
* Instructor: Shin Hong https://hongshin.github.io :email: hongshin@handong.edu :door: OH 313
* Teaching assistants
  - Jeewoong Kim :email: jeewoong@handong.edu https://arise.handong.edu
  - Juyoung Jeon :email: 21931009@handong.edu https://arise.handong.edu
  - Hyerin Lim :email: 21600602@handong.edu
* Class polices: [POLICY.md](POLICY.md)

### Learning Materials ###
#### Textbook ####
[Operating System Concepts, 9/E, International Student Version](http://www.kyobobook.co.kr/product/detailViewEng.laf?ejkGb=ENG&mallGb=ENG&barcode=9781118093757&orderClick=LAG&Kc=) authored by Abraham Silbershatz, Peter B. Galvin and Greg Gagne.
You can find this book in Handong Book on campus. It is **mandatory** for
each class participant to equip this main textbook: it will be assumed that
each student has a textbook for doing homework, programming assignments, etc.

#### Online Channels ####
* Piazza for news and Q&A
    - ITP30002-02 https://piazza.com/configure-classes/spring2019/itp3000202
    - ECE30021-02 https://piazza.com/configure-classes/spring2019/ece30021
* [Hisnet](http://hisnet.handong.edu) for online attendance check & homework/assignment submission
* This webpage for lecture notes, homework resources, etc.

#### Useful Links ####
* For studying Linux command lines
    - The Linux command line by William Shotts http://linuxcommand.org/tlcl.php
    - Linux command line basis @ Udacity https://www.udacity.com/course/linux-command-line-basics--ud595
    - Practical Unix @ Stanford Univ. https://practicalunix.org/
* For studying Linux programming
    - Linux man pages https://linux.die.net/man/
    - GNU C library https://www.gnu.org/software/libc/manual/
    - Advanced Linux programming http://www.makelinux.net/alp/
    - The Linux Programming Interface http://man7.org/tlpi/code/online/all_files_by_chapter.html

#### Lecture Notes ####
* [Course overview](notes/syllabus.pdf)
* [Chapter 1. Introduction](notes/ch1-intro.pdf)
  - [Syscall examples](https://github.com/hongshin/OperatingSystem/tree/sysprog/Syscall)
* [Chapter 2. System Structure](notes/ch2-os-structure.pdf)
* [Chapter 3. Process](notes/ch3-process.pdf)
  - [Fork examples](https://github.com/hongshin/OperatingSystem/tree/sysprog/Fork)
  - [IPC examples](https://github.com/hongshin/OperatingSystem/tree/sysprog/IPC)
* [Chapter 4. Multithreaded Programming](notes/ch4-threading-wip.pdf)
  - [PThread examples](https://github.com/hongshin/OperatingSystem/tree/sysprog/Pthread)
* [Chapter 5. Process Scheduling](notes/ch5-process_scheduling.pdf)
* [Chapter 6. Synchronization](notes/ch6-synchronization-rev.pdf)
* Midterm exam (Apr 19) [ [pdf] ](notes/midterm.pdf)
* [Deadlock detection](notes/deadlock.pdf)
* [Chapter 8. Memory Management](notes/ch8-memory-management.pdf)
  - [Build](notes/build.pdf)
* [Chapter 9. Virtual Memory](notes/ch9-vm.pdf)

#### Assignments ####
* PA1. LKM Rootkit (due on Apr 1) [[desc]](assignments/pa1.pdf) [[examples]](https://github.com/hongshin/OperatingSystem/tree/sysprog/PA1)
* PA2. InstaGrap (due on Apr 26) [[desc]](assignments/pa2.pdf) [[sample problem]](assignments/problem-description.pdf) [[testcases]](assignments/testcases.zip)
* PA3. Dynamic Deadlock Detection and Prediction (due on May 31) [[desc]](assignments/pa3.pdf) [[runtime interpositioning]](https://github.com/hongshin/OperatingSystem/tree/sysprog/PA3/interpositioning) [[deadlock examples]](https://github.com/hongshin/OperatingSystem/tree/sysprog/PA3/examples)
