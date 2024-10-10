# LED_Onebutton sửa đổi

## Mô Tả Dự Án
Dự án này sử dụng thư viện OneButton để điều khiển hai LED thông qua một nút nhấn. Có ba chức năng chính:
- **Chức năng ON/OFF**: Nhấn đơn nút để bật hoặc tắt LED đang được điều khiển (LED1 hoặc LED2).
- **Chức năng Nháy LED**: Giữ nút nhấn để LED đang được điều khiển nhấp nháy 200ms một lần.
- **Chuyển đổi LED điều khiển**: Nhấn đôi nút để chuyển đổi giữa hai LED (LED1 và LED2).

## Thiết Bị
- **ESP32/ESP8266 hoặc Arduino**: Có chân GPIO cho LED và nút nhấn.
- **LED1**: Được kết nối với chân GPIO 13 (LED built-in).
- **LED2**: Được kết nối với chân GPIO 12.
- **Nút nhấn**: Được kết nối với chân GPIO 14.

## Sơ Đồ Kết Nối
- Kết nối chân LED1 với chân GPIO 13.
- Kết nối chân LED2 với chân GPIO 12.
- Kết nối nút nhấn với chân GPIO 14.

## Cách Thức Hoạt Động
1. Khi nhấn đơn nút nhấn, LED1 hoặc LED2 sẽ bật hoặc tắt.
2. Khi nhấn đôi nút nhấn, LED sẽ chuyển đổi giữa LED1 và LED2.
3. Khi giữ nút nhấn, LED đang được điều khiển sẽ nhấp nháy 200ms một lần.

## Cài Đặt Thư Viện
Để sử dụng thư viện OneButton, bạn cần cài đặt nó thông qua Library Manager trong Arduino IDE hoặc sử dụng PlatformIO.

## Chạy Dự Án
- Tải mã nguồn lên board ESP32/ESP8266 hoặc Arduino.
- Mở Serial Monitor để theo dõi trạng thái LED.
