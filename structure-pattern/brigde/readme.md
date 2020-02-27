# Brigde
- A mechanism that decouples an interface (hierachy) from an implementation (hierachy) 

### 1. Pimpl idiom 
Ưu điểm của phương pháp này:
- Phần lớn của class implementation sẽ được ẩn đi. Nếu Class Person required 1 API đầy đủ các thành phần private/protected, thì bạn sẽ bị lộ tất cả các chi tiết đo cho client, ngay cả khi client không thể truy cập vào các thành phần đó. Còn với Pimpl, client chỉ có thể được cung cấp interface chung ????

- Sửa đổi các thành của class Impl ẩn sẽ không ảnh hưởng đến khả năng tương thích

- header file chỉ cần include ccần thiết cho việc định nghĩa, không phải phần implement

Tuy nhiên, mặc dù nó sẽ giữ được file headers clean nhưng sẽ bị side effect đó là giảm tốc độ compiler