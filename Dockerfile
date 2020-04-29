FROM ubuntu
RUN apt-get update && apt-get upgrade -y && apt install nano -y && apt install build-essential -y
COPY ./lab4_files /home/lab4
WORKDIR /home/lab4
RUN g++ -o lab4_1 lab4_1.cpp List.cpp && g++ -o lab4_2 lab4_2.cpp