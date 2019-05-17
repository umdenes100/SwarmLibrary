# Swarm

## Network Setup

To keep this library compatible with networks that do not support self-assigned IP addresses, it is assumed that the nodes of the network will each have an IP address reserved with the DHCP server for the network. The last octet of the IP address (the last number in the IP address) acts as that node's static identifier and can be used to send messages directly to that node.

## Messages

A "message" is statically defined in the `Message` enum in Swarm.hpp. Messages can be sent to all members of the swarm using the `send()` method.

```
Coop.send(MESSAGE_ARRIVED);
```

To send to a specific member of the swarm, specify that member's static identifier as a second argument.

```
Coop.send(MESSAGE_WAITING, 6);
```

will send a `WAITING` message to the node at IP address 129.168.1.6.

Incoming messages can be retrieved with the `recv()` method.

```
Message incoming = Coop.recv();
```

If there are no messages waiting to be retrieved, `MESSAGE_NONE` is returned. `MESSAGE_NONE` is statically defined as 0 so that it can be used in coditionals as expected.

```
Message incoming = Coop.recv();
if (incoming != MESSAGE_NONE) {
    // ...
}
```

is also equivalent to

```
Message incoming = Coop.recv();
if (incoming) {
    // ...
}
```
