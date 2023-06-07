
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "gps_parser.h"

// Unit test for parse_gps_data function
void test_parse_gps_data(const char* ggaPacket) {
    GPSData gpsData;

    printf("Testing GGA Packet: %s\n", ggaPacket);

    if (parse_gps_data(ggaPacket, &gpsData)) {
        printf("Time: %s\n", gpsData.time);
        printf("Latitude: %f\n", gpsData.latitude);
        printf("Longitude: %f\n", gpsData.longitude);
        printf("------------------------------------------------------\n");
    } else {
        printf("Invalid GGA packet\n");
        printf("------------------------------------------------------\n");
    }
}

int app_main()
 {
    // Valid GGA packet
    test_parse_gps_data("$GPGGA,123519.6,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,");

    // Invalid GGA packet - Wrong sentence
    test_parse_gps_data("$GPGLL,3723.2475,N,12158.3416,W,000000,A,*");

    // Invalid GGA packet - Checksum mismatch
    test_parse_gps_data("$GPGGA,123519.6,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,*,");

    // Invalid GGA packet - Missing latitude field
    test_parse_gps_data("$GPGGA,123519.6,,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,");

    // Invalid GGA packet - Missing longitude field
    test_parse_gps_data("$GPGGA,123519.6,4807.038,N,,E,1,08,0.9,545.4,M,46.9,M,,");

    return 0;
}