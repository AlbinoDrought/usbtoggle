# USB Toggle

Toggle an external circuit over serial with an ESP8266 and some components

## Usage

```sh
# change this device to 9600 baud
stty 9600 -F /dev/ttyUSB0 
# turn it on
echo -ne 'E' > /dev/ttyUSB0
# turn it off
echo -ne 'D' > /dev/ttyUSB0
```
## Building

See [./circuit](./circuit)

![Circuit diagram](./circuit/circuit.svg)
