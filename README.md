# Operating System
The repository contains all labs of course "Operating System" in NCKU.
## Overview
- lab1: Inplement two message sending ways, which are Message Passing/Shared Memory, and compare their total sending/receiving time.
- lab2: Create our own shell. Complete cd()/ls()/cat() command.
- lab3: Multithreading & Linux Kernel Module  
This lab covers multithreading programming and Linux kernel module development. It focuses on handling critical section problems, using `pthread_spin_lock` for synchronization, and creating a `/proc` file system to interact with the kernel. Finally, `proc_read` and `proc_write` operations are implemented to display and modify process information.  
- lab4: Virtual File System (VFS)  
This lab explores the Linux Virtual File System (VFS), including key structures such as superblock, inode, and dentry. The task involves implementing `osfs_create()` and `osfs_write()` functions to enable file creation and writing. The final step is loading the module into the kernel, mounting the `osfs` file system, and testing file operations.  
