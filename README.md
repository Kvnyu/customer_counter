# Customer counter 

This application is used to track the number of customers entering and exiting a store, via the use of two physical sensors.

There are 3 main components:
 - Raspberry Pi which connects to sensors and sends information to the server via TCP
 - Server which sits in between the sensors and the frontend, relaying the counts to the frontend
 - Frontend which displays how many customers are currently in the store, and whether it has violated the occupancy limit

Demo can be viewed here https://www.youtube.com/watch?v=8q2_GYdBCG8&ab_channel=KevinYu