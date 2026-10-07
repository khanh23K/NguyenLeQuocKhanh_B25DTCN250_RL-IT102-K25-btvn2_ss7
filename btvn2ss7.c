#include <stdio.h>

struct SmartDevice {
    int deviceID;
    char deviceName[50];
    int status;            
    float ratedPowerKW;
};

struct EnergySensor {
    float voltageVolts;
    float currentAmperes;
    int unoccupancyMinutes;
};

int main() {

    struct SmartDevice device;
    struct EnergySensor sensor;

    float operatingHours;
    float totalKWh;
    double electricityCost = 0;

    printf("=== NHAP THONG TIN THIET BI ===\n");

    printf("Device ID: ");
    scanf("%d", &device.deviceID);

    printf("Device Name: ");
    scanf(" %49[^\n]", device.deviceName);

    printf("Status (1-BAT, 0-TAT): ");
    scanf("%d", &device.status);

    printf("Rated Power (kW): ");
    scanf("%f", &device.ratedPowerKW);

    printf("\n=== NHAP DU LIEU CAM BIEN ===\n");

    printf("Voltage (V): ");
    scanf("%f", &sensor.voltageVolts);

    printf("Current (A): ");
    scanf("%f", &sensor.currentAmperes);

    printf("Unoccupancy Minutes: ");
    scanf("%d", &sensor.unoccupancyMinutes);

    printf("Operating Hours: ");
    scanf("%f", &operatingHours);

    if (sensor.voltageVolts < 0 ||
        sensor.currentAmperes < 0 ||
        sensor.unoccupancyMinutes < 0) {

        printf("\nLOI: DU LIEU CAM BIEN KHONG HOP LE!\n");
        return 0;
    }

    if (operatingHours <= 0 ||
        operatingHours > 744) {

        printf("\nLOI: SO GIO VAN HANH KHONG HOP LE!\n");
        return 0;
    }

    if (sensor.currentAmperes > 30.0f) {
        device.status = 0;

        printf("\nCANH BAO: QUA TAI DIEN (>30A)\n");
        printf("HE THONG DA TU DONG NGAT THIET BI.\n");
    }

    if (device.status == 1 &&
        sensor.unoccupancyMinutes >= 15) {

        device.status = 0;

        printf("\nTHONG BAO: PHONG TRONG TU 15 PHUT TRO LEN.\n");
        printf("THIET BI DA DUOC TU DONG TAT.\n");
    }

    totalKWh = device.ratedPowerKW * operatingHours;

    if (totalKWh <= 50) {

        electricityCost =
            totalKWh * 1806;

    } else if (totalKWh <= 100) {

        electricityCost =
            50 * 1806
            + (totalKWh - 50) * 1866;

    } else if (totalKWh <= 200) {

        electricityCost =
            50 * 1806
            + 50 * 1866
            + (totalKWh - 100) * 2167;

    } else {

        electricityCost =
            50 * 1806
            + 50 * 1866
            + 100 * 2167
            + (totalKWh - 200) * 2729;
    }

    printf("\n========== BAO CAO ==========\n");

    printf("Device ID: %d\n", device.deviceID);
    printf("Device Name: %s\n", device.deviceName);

    printf("Status: %s\n",
           device.status ? "BAT" : "TAT");

    printf("Tong dien nang: %.2f kWh\n",
           totalKWh);

    printf("Tien dien du kien: %.0lf VND\n",
           electricityCost);

    return 0;
}
