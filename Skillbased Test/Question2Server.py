from socket import * 
host = "10.0.2.15" 
port = 8080

serverSocket = socket(AF_INET, SOCK_STREAM) 
serverSocket.bind((host, port)) 
serverSocket.listen(1) 

print('Waiting for connection: ') 
while True: 
connectionSocket,addr = serverSocket.accept() 
temp = connectionSocket.recv(1024).decode() 
tempCelsius=float(temp) 
tempFahrenheit = (tempCelsius*1.8)+32 
tempModified=str(tempFahrenheit) 
connectionSocket.send(tempModified.encode()) 
connectionSocket.close()
