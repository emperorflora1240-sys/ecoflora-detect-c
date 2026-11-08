#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char plantName[100];
    char status[50]; // เช่น Local Species หรือ Invasive Species
    float latitude;
    float longitude;
} PlantRecord;

void saveRecord(PlantRecord p) {
    FILE *file = fopen("plant_log.csv", "a");
    if (file == NULL) {
        printf("ไม่สามารถเปิดไฟล์ฐานข้อมูลได้!\n");
        return;
    }
    fprintf(file, "%s,%s,%.6f,%.6f\n", p.plantName, p.status, p.latitude, p.longitude);
    fclose(file);
    printf("บันทึกข้อมูลพืชและพิกัดลงระบบสำเร็จ!\n");
}

int main() {
    PlantRecord p;
    printf("=== EcoFlora Detect (C Console System) ===\n");
    printf("ระบุชื่อพืช: ");
    scanf(" %[^\n]s", p.plantName);
    printf("สถานะ (Local/Invasive): ");
    scanf(" %[^\n]s", p.status);
    printf("ละติจูด (Latitude): ");
    scanf("%f", &p.latitude);
    printf("ลองจิจูด (Longitude): ");
    scanf("%f", &p.longitude);

    saveRecord(p);
    return 0;
}
```[cite: 1]
