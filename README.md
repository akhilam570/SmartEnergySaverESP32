# SmartEnergySaverESP32

SmartEnergySaverESP32 is an ESP32-based Home Automation project that optimizes power consumption based on energy usage. It utilizes Bluetooth communication to receive commands from a mobile device, allowing manual control of connected smart devices or appliances.

## Features

- Monitors energy consumption using a simulated energy sensor (replace with actual sensor readings).
- Automatically adjusts power consumption based on predefined energy thresholds.
- Allows manual control via Bluetooth commands to turn devices on or off.

## Requirements

- Arduino IDE with ESP32 support.
- Bluetooth terminal app on a mobile device for manual control.
- Smart plug or relay-connected device for testing.

## Installation

1. Clone the repository or download the ZIP file.
2. Open the project in the Arduino IDE.
3. Install the required libraries (if not already installed):
   - [BluetoothSerial](https://www.arduino.cc/reference/en/language/functions/communication/serial/bluetoothserial/)

## Configuration

- Adjust the `energyThreshold` variable to set your desired energy consumption threshold.
- Modify the `smartPlugPin` variable to match the GPIO pin connected to the relay of your smart plug.

## Usage

1. Upload the sketch to your ESP32 board.
2. Pair your mobile device with the ESP32 via Bluetooth.
3. Open a Bluetooth terminal app on your mobile device.
4. Send '1' to turn on the smart plug or '0' to turn it off manually.

## Contributing

Feel free to contribute to the project by opening issues or pull requests.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
