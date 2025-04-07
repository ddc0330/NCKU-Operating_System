# NCKU Operating System – Linux Labs

This repository contains lab assignments for the **Operating System** course at **National Cheng Kung University (NCKU)**, focusing on Linux system programming, kernel modules, and file system development.

## Course Topics

The course explores essential concepts in operating system design and implementation, including:

- Process creation and shell interaction
- Inter-process communication (IPC)
- Multithreading and race condition handling
- Linux kernel module development
- Virtual File System (VFS) design and extension

## Labs Overview

| Lab | Focus Area | Description |
|-----|------------|-------------|
| **Lab 1** | Shared Memory & Message Passing | Implement `send()`/`receive()` using shared memory and message queues; compare communication performance |
| **Lab 2** | Unix Shell | Build a custom shell supporting built-in commands (`cd`, `exit`), I/O redirection, and pipelines |
| **Lab 3** | Multithreading & Kernel Module | Create matrix multiplication with threads, and implement a `/proc` interface kernel module |
| **Lab 4** | Virtual File System | Develop `osfs_create()` and `osfs_write()` functions and test with a custom mounted file system |

## Repository Structure

```
NCKU-Operating_System/
│
├── os_lab1/      # Lab 1 – IPC: Shared memory and message passing
├── os_lab2/      # Lab 2 – Custom shell with redirection and piping
├── os_lab3/      # Lab 3 – pthreads and kernel module with /proc
├── os_lab4/      # Lab 4 – Simple virtual file system implementation
└── README.md     # Course overview
```

Each lab folder includes source code (`.c`), Makefiles, and scripts for testing on a Linux environment.
