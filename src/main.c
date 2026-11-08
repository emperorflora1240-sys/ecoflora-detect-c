#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char imageName[150]; // ชื่อไฟล์รูปภาพที่อัปโหลด (เช่น plant_01.jpg)
    char plantName[100]; // ชื่อพืช
    char status[50];     // สถานะ: Local Species หรือ Invasive Species
    float latitude;      // ละติจูด
    float longitude;     // ลองจิจูด
} PlantImageRecord;

void saveImageRecord(PlantImageRecord p) {
    FILE *file = fopen("plant_image_log.csv", "a");
    if (file == NULL) {
        printf("ไม่สามารถเปิดไฟล์ฐานข้อมูลได้!\n");
        return;
    }
    // บันทึกข้อมูลลงในรูปแบบ CSV (ชื่อรูป, ชื่อพืช, สถานะ, ละติจูด, ลองจิจูด)
    fprintf(file, "%s,%s,%s,%.6f,%.6f\n", p.imageName, p.plantName, p.status, p.latitude, p.longitude);
    fclose(file);
    printf("\n[สำเร็จ] อัปโหลดรูปภาพและบันทึกข้อมูลพิกัดลงระบบเรียบร้อยแล้ว!\n");
}

int main() {
    PlantImageRecord p;
    
    printf("=== EcoFlora Detect - Image Upload & Scanner System ===\n");
    printf("ระบุชื่อไฟล์รูปภาพที่ต้องการอัปโหลด (เช่น leaf1.jpg): ");
    scanf(" %[^\n]s", p.imageName);
    
    printf("ระบุชื่อพืช (จากการวิเคราะห์ของ AI): ");
    scanf(" %[^\n]s", p.plantName);
    
    printf("ระบุสถานะพืช (Local Species / Invasive Species): ");
    scanf(" %[^\n]s", p.status);
    
    printf("ระบุพิกัดละติจูด (Latitude): ");
    scanf("%f", &p.latitude);
    
    printf("ระบุพิกัดลองจิจูด (Longitude): ");
    scanf("%f", &p.longitude);

    saveImageRecord(p);
    
    return 0;
}
