# Operating System
The repository contains all labs of course "Operating System" in NCKU.
## Overview
- Lab 1: Shared Memory & Message Passing  
This lab focuses on Inter-Process Communication (IPC) using both **Message Passing** and **Shared Memory** mechanisms. Students will implement `send()` and `receive()` functions in **sender.c** and **receiver.c** and measure communication performance. The goal is to understand the efficiency trade-offs between **message queues** and **shared memory** while handling synchronization using semaphores.  

- Lab 2: Shell Implementation  
This lab involves building a simple Unix shell that supports **built-in commands**, **external commands**, **input/output redirection**, and **pipelines**. Key functionalities include implementing the `cd` command, handling `fork()` and `exec()` system calls, managing file descriptors for redirection (`>`, `<`), and using `pipe()` for inter-process communication.  

- Lab 3: Multithreading & Linux Kernel Module  
This lab covers **multithreading programming** and **Linux kernel module development**. It focuses on handling **race conditions** using `pthread_spin_lock`, implementing **matrix multiplication** with single and multi-threading, and creating a **Linux `/proc` file system** module. The final goal is to interact with the kernel using `proc_read` and `proc_write` operations.  

- Lab 4: Virtual File System (VFS)  
This lab explores the **Linux Virtual File System (VFS)**, including structures such as **superblock, inode, and dentry**. The tasks involve implementing `osfs_create()` and `osfs_write()` functions for file creation and writing. The final step is to **load the module into the kernel, mount the `osfs` file system, and test file operations**.  
