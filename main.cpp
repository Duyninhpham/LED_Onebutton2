#include <OneButton.h>

#define LED1_PIN 13 // Chân LED đầu tiên (built-in LED)
#define LED2_PIN 12 // Chân LED thứ hai
#define BUTTON_PIN 14 // Chân nút nhấn mới

OneButton button(BUTTON_PIN); // Tạo đối tượng OneButton

bool led1State = false; // Trạng thái LED1
bool led2State = false; // Trạng thái LED2
bool isBlinking = false; // Trạng thái nhấp nháy
bool controlLED1 = true; // Biến để theo dõi LED đang điều khiển

void setup() {
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN, OUTPUT);
    button.begin();
    button.attachClick(clickHandler); // Đăng ký hàm xử lý click đơn
    button.attachDoubleClick(doubleClickHandler); // Đăng ký hàm xử lý click đôi
    button.attachLongPressStart(longPressHandler); // Đăng ký hàm xử lý giữ nút
}

void loop() {
    button.tick(); // Cập nhật trạng thái nút nhấn

    // Nháy LED nếu đang ở chế độ nháy
    if (isBlinking) {
        if (controlLED1) {
            digitalWrite(LED1_PIN, HIGH);
        } else {
            digitalWrite(LED2_PIN, HIGH);
        }
        delay(200);
        if (controlLED1) {
            digitalWrite(LED1_PIN, LOW);
        } else {
            digitalWrite(LED2_PIN, LOW);
        }
        delay(200);
    }
}

// Hàm xử lý click đơn
void clickHandler() {
    if (controlLED1) {
        led1State = !led1State; // Chuyển đổi trạng thái LED1
        digitalWrite(LED1_PIN, led1State ? HIGH : LOW); // Bật/tắt LED1
    } else {
        led2State = !led2State; // Chuyển đổi trạng thái LED2
        digitalWrite(LED2_PIN, led2State ? HIGH : LOW); // Bật/tắt LED2
    }
}

// Hàm xử lý click đôi
void doubleClickHandler() {
    controlLED1 = !controlLED1; // Chuyển đổi chế độ điều khiển giữa LED1 và LED2
}

// Hàm xử lý giữ nút
void longPressHandler() {
    isBlinking = true; // Bắt đầu nhấp nháy
    while (button.isPressed()) {
        // Chờ cho đến khi nút nhấn được thả
        delay(10);
    }
    isBlinking = false; // Dừng nhấp nháy
}
