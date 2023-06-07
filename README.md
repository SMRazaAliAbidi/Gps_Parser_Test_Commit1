GPS Parser Library

(*)Introduction:
The GPS Parser Library is a C/C++ library for parsing GPS data in NMEA format (specifically, the GGA sentence) on ESP-32 using ESP-IDF v5.0 stable. It provides a convenient way to extract individual GPS data parameters from a GGA packet and verify packet integrity.

(*)Features:
->Parsing of GGA packets: The library can parse GGA packets and extract relevant information such as time, latitude, and longitude.
->Packet integrity verification: It validates the GGA packet integrity using a checksum to ensure the data is not corrupted.
->Handling of empty or incorrect strings: The library handles cases where the input string is empty or does not conform to the expected GGA format.


(*)Usage:
1) Include the gps_parser.h header file in your ESP-IDF project:

-> #include "gps_parser.h"

2) Create an instance of the GPSData structure to store the parsed GPS data:

-> GPSData gpsData;


3) Call the "parse_gps_data function" with a GGA packet and the GPSData structure as arguments:

-> const char* ggaPacket = "$GPGGA,123519.6,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,";
  if (parse_gps_data(ggaPacket, &gpsData)) {
    // Parsed data is available in the gpsData structure
    printf("Time: %s\n", gpsData.time);
    printf("Latitude: %f\n", gpsData.latitude);
    printf("Longitude: %f\n", gpsData.longitude);
} else {
    // Invalid GGA packet
    printf("Invalid GGA packet\n");
}

4) The function returns true if the parsing is successful and false otherwise.

5) Build and run your ESP-IDF project, ensuring that you have the necessary ESP-IDF libraries linked.

(*)Example:
An example program is provided in the repository that demonstrates the usage of the GPS Parser Library. It includes a unit test that tests various scenarios with valid and invalid GGA packets.

To run the example program:

1) Clone the repository:

bash
git clone <repository_url>

2) Navigate to the example directory:

bash
cd example

3)Build and flash the example program to your ESP-32 using the ESP-IDF build system.

4)Check the console output to observe the parsed GPS data and any error messages.

(*)License:
This library is released under a freeware license. 

(*)Contributing:
Contributions are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request.

(*)Credits:
The GPS Parser Library is developed by Raza Ali and is based on the ESP-IDF framework by Espressif Systems as a test program for Cowlar inc.

Contact
For any inquiries or questions, please contact smabidi32@gmail.com
