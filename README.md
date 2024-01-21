# UDP Client-Server Communication Project

This repository showcases a simple implementation of UDP client-server communication in C. The project includes a UDP client (`Client.c`) and a UDP server (`Serveur.c`). Common configurations and constants are defined in `Ser_Cl.h`, and a convenient compilation script (`script.sh`) is provided.

## Project Structure
- `Client.c`: Main client program file.
- `Serveur.c`: Main server program file.
- `Ser_Cl.h`: Header file for shared constants and configurations.
- `script.sh`: Compilation script.

## Requirements
- Linux environment
- [Additional requirements if any]

## Building and Running

### Client
To build and run the client:
```bash
./script.sh Client.c Serveur.c
./client <server_address> <server_port>
```
### Server
To build and run the server:
```bash
./script.sh Client.c Serveur.c
./server <server_port>


