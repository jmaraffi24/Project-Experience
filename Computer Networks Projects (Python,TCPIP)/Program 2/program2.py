#------------------------------------------------------------------------------------------
# Program #2 Web Server
# CSCI 4760
# Jacob Maraffi
# Created: 3/18/19
#------------------------------------------------------------------------------------------

#import socket module
from socket import *
import sys #allows for termination of the program
serverPort = 80

#initializing the server socket
serverSocket = socket(AF_INET, SOCK_STREAM)

#preparing the server socket
serverSocket.bind(('', serverPort))
serverSocket.listen(1)

#outputting the resulting web server's location
print 'The web server is up on port:' , serverPort
while True:
    #establish the connection
    print('Ready to serve...')

    #intializing the connection socket
    connectionSocket, addr = serverSocket.accept()

    try:
        #receving the intial message from the server through the connection socket
        message = connectionSocket.recv(1024)

        #parseing the filename from the message array(2nd element is the filename)
        filename = message.split()[1]

        #opening the corresponding file
        f = open(filename[1:])

        #reading the file and storing within variable
        outputdata = f.read()

        #outputting the contents of the file
        print outputdata

        #Send one HTTP header line into socket
        connectionSocket.send('\nHTTP/1.1 200 OK \n\n')
        connectionSocket.send(outputdata)

        #Send the content of the requested file to client
        for i in range(0, len(outputdata)):
            connectionSocket.send(outputdata[i].encode())

        connectionSocket.send("\r\n".encode())

        #closing the connectionSocket
        connectionSocket.close()

    except IOError:
        #Send repsonse message for file not found
        connectionSocket.send('HTTP/1.1 404 Not Found\r\n')
        connectionSocket.send("Content-Type: text/html\r\n\r\n")
        connectionSocket.send('<html><body><h1>Error</h1><h2>404 Not Found</h2></body></html>')

        #Close client socket
        connectionSocket.close()

    #closing the server socket
    serverSocket.close()

    #terminate the program after sending the corresponding data
    sys.exit()
