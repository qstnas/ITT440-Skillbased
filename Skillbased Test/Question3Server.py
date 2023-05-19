import random 
import threading 
import socket 

quotes = [“If you cannot do great things, do small things in a great way.
-	Napoleon Hill”] 

def handle_client(sockfd): 
quoteArray = random.choice(quotes) 
sockfd.sendall(quoteArray.encode()) 
sockfd.close() 
def main(): 

host = "192.168.0.152" 
port = 8888 

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM) 
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1) 
server.bind((host, port)) 
server.listen(5) 
print("Waiting %s:%d for request" % (host, port)) 
while True: 
client, addr = server.accept() 
print("Accepting client connection from %s" % str(addr)) 
client_handler = threading.Thread(target=handle_client, args=(client,)) 
client_handler.start() 
main()
