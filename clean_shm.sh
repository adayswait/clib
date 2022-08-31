#!/bin/sh

USER=`whoami`
USER=${USER:0:10}

echo "stop ${USER}'s all sharemem"; 
shmid=`ipcs -m | grep ${USER} | awk '$NF==0{printf " -m  " $2  " "}'`;
echo "ipcrm $shmid";
ipcrm $shmid;
sleep 1;
