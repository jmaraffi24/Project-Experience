#Program 1
#server.py
#CSCI 4760
#Jacob Maraffi
#811-571-598
import socket
import sys
import pickle
import random

#creating the server socket
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print("Server socket successfully created")

#associate the server with localhost and Port
serverName = 'localhost'
serverPort = 8080
serverSocket.bind((serverName,serverPort))

#listen for incoming connections
serverSocket.listen(1)
print("Server is ready to recieve")

#infinite loop for accepting messages
while True:
    #wait for a connection, accept said connection
    clientConnection, address = serverSocket.accept()
    print("Connection created at", address)
    #recieving data from the client
    serverData = clientConnection.recv(1024)
    #decoding data from the client
    serverData = pickle.loads(serverData)
    #pulling the clientName from the first element of data
    name = serverData.get(0)
    print("Client name:", name)
    print("Server name:", serverName)
    #pulling the number from the first element of data
    number = serverData.get(1)
    #finding a random number
    randomNumber = random.randint(1,101)
    #getting the sum of clientNumber and randomNumber
    newNumber = float(number) + float(randomNumber)
    newNumber = pickle.dumps({0:serverName, 1:newNumber, 2: randomNumber})
    #sending the newNumber back to the client (encoded)
    clientConnection.send(newNumber)
    #closing the connection between client and server
    clientConnection.close()
    
