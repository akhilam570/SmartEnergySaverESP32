#include <BluetoothSerial.h>

int energyThreshold = 1000; // Adjust this threshold based on your energy usage requirements
int smartPlugPin = 14;      // GPIO pin connected to the relay of the smart plug

BluetoothSerial SerialBT;

void checkEnergyConsumption() {
  // Simulate reading energy consumption from a sensor
  int energyConsumed = analogRead(A0); // Replace this with your actual energy sensor reading

  SerialBT.print("Energy Consumption: ");
  SerialBT.println(energyConsumed);

  // Adjust power consumption based on energy usage
  if (energyConsumed > energyThreshold) {
    // High energy usage, turn off or reduce power to certain devices
    digitalWrite(smartPlugPin, LOW); // Turn off the smart plug
  } else {
    // Normal energy usage, turn on or increase power to devices
    digitalWrite(smartPlugPin, HIGH); // Turn on the smart plug
  }
}

void processBluetoothCommands() {
  while (SerialBT.available()) {
    char command = SerialBT.read();

    // Process commands received over Bluetooth
    switch (command) {
      case '1':
        // Command to turn on the smart plug
        digitalWrite(smartPlugPin, HIGH);
        SerialBT.println("Smart Plug turned ON");
        break;
      case '0':
        // Command to turn off the smart plug
        digitalWrite(smartPlugPin, LOW);
        SerialBT.println("Smart Plug turned OFF");
        break;
      default:
        SerialBT.println("Invalid Command");
    }
  }
}

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Energy_Saver"); // Set your device name here

  pinMode(smartPlugPin, OUTPUT);

  // Set up a timer to check energy consumption every 10 seconds
  timer.setInterval(10000, checkEnergyConsumption);
}

void loop() {
  timer.run();
  processBluetoothCommands();
}
