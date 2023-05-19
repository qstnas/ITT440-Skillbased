from socket import * 
host = “10.0.2.15”
port = 8080

clientSocket = socket(AF_INET, SOCK_STREAM) 
clientSocket.connect((host,port)) 
temp = input('Input any value in Degree Celsius: ') 
clientSocket.send(temp.encode()) #sending to server 
tempModified = clientSocket.recv(1024) 
print('Your input in fahrenheit is:') 
print(tempModified.decode('utf8','strict')) 
clientSocket.close()  
