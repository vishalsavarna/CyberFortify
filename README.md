CS 628: Computer Systems Security
IIT Kanpur, CSE
Credits:   3-0-0-0- [9]

Instructor: Prof. Angshuman Karmakar

****************************************************************************************************************************************************

Assignment 1 – Principles of Least Privilege

Problem Statement: Assignment1.c contains C programming code runs with root privilege
because some part of the code requires it. You have to create componentization of the program to
enforce the least privilege principle so that only the part which requires root privilege will be run
as root.

Deliverables: Assignment1.c contains different functions where only few functions require root
privilege to run it. You need to understand each function and analyze if that particular function
necessarily needs to be run with root privilege.


****************************************************************************************************************************************************

Assignment 2a (20 marks):
After extraction, in the Assignment_2a directory you will find two programs that contain use of multiple 
programs and functions that might contain buffer overflow, integer overflow and format string vulnerability. 
Task: Your task is to identify each of these problems, cite the vulnerable line(s) in the code and give precise 
argument about how you can exploit this vulnerability and give countermeasures to rectify such problems.

Assignment 2b (4x20 marks):
In the Assignment_2b directory, you are given directories named Task_1, Task_2, and Task_3. 
These directories contain essential files to complete the assignment. In each of these folders, 
you will be given a program with a buffer-overflow vulnerability named vulnerable.c; your task is to 
develop a scheme to exploit the vulnerability and finally gain the root privilege. In addition to the attack, 
students need to create a report on whether their schemes work or not and explain why.

****************************************************************************************************************************************************

Assignment 3 – Exploiting the Web Vulnerabilities (CSRF, XSS, SQL-injection)

You can access a vulnerable server DVWA (Damn Vulnerable web application), in your CS628 lab VM. In this lab exercise, you will learn to exploit vulnerabilities through SQL injection, 
cross-site scripting (XSS), and cross-site request forgery (CSRF) attacks.


****************************************************************************************************************************************************

Assignment 4 – Packet Capture Analysis

Problem Statement: You are provided with two '.PCAP' files that contain network traffic
captured during web attacks involving SQL injection and Cross-Site Scripting (XSS). As a
network analyst, your task is to analyze the provided .PCAP files and extract insights from the
attacks. You can perform packet capture analysis using the Wireshark tool [1] by uploading the
provided packet capture files and initiating your analysis [2].
