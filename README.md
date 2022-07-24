# Communication Contract for Assignment 7 CS361 

## How to request & Retrieve data

1) Download recieve.py & send.py from the repo
2) You have to start RabbitMQ, I used homebrew with the command: 
#### brew services start rabbitmq
3) RECIEVE: Start by running the recieve first, do this by:
#### python3 recieve.py
4) REQUEST: Send the data by running send in another terminal tab:
#### python3 send.py
5) You will see the random recycling fact being printed in the send.py terminal & see a print statement stating the message was recieved in recieve.py

If there are any questions, feel free to reach out! We have been communicating over discord & text.

## UML sequence diagram

![CS361 Assignment 7](https://user-images.githubusercontent.com/88406501/180647287-d3deeeec-80b6-4dd6-a80e-4417cf5602f0.png)
