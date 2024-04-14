# simple_sockets

A simple TCP client &amp; server implementation in C++.

The project utilizes such concepts as concurrency, Linux network programming,
Object-Oriented Design.

Made for fun & learning.

## Description

The server waits for connections and logs the data sent by the clients into
file `log.txt`. Every client connection is processed in a separate thread.

The client connects to the server every `<connection_period>`
seconds (provided as an argument) and sends it a string with the current
timestamp (down to milliseconds) with the `<client_name>` (also provided
as an argument), like so:

```
[2024-04-14 13:37:48.817] client1 
```

## Building

To build this project you need [CMake](https://cmake.org).

Assuming you're in the root folder of the project, enter the following
commands in your terminal:

```shell
$ cmake . -B build 
$ cd build && make
```

This will create the `build` directory with the `simple_client` and
`simple_server` binaries inside.

## Usage

```shell
$ ./simple_server <port>
```

```shell
$ ./simple_client <client_name> <server_port> <connection_period>
```

So, basically you run the server in the detached mode with a command like:

```bash
$ ./simple_server 6969 &
```

And then run a bunch of clients:

```bash
$ ./simple_client client1 6969 1 &
$ ./simple_client client2 6969 2 &
$ ./simple_client client3 6969 5 &
$ ./simple_client client4 6969 3 &
```

Now you can `tail -f log.txt` to conveniently watch in real-time how they
interact with each other. So wow, much fun :moyai:

```bash
$ tail -f log.txt
```

## Contacts

Telegram: [@antonomore](https://t.me/antonomore)

Email: <aaoratos@pm.me>

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.