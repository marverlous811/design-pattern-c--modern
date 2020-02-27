- Khi muốn mở rộng 1 chức năng của class mà người khác đã viết nhưng không muốn sửa đổi nó

- Kế thừa cũng là 1 cách tiếp cận. Tuy nhiên không phải lúc nào nó cũng work tốt vì bạn sẽ muốn tách biệt các cái tiên đó so với với lớp cũ của nó

- Decorator pattern sẽ cho phép chúng ta cải tiến 1 lớp mà k phải sửa lớp gốc hay tạo ra 1 sự bùng nổ về các lớp dẫn suất.
 
  - Mở rộng được chức năng của lớp mà vân tuân thủ các qui tắc về lập trình hướng đối tượng

  - Ngoài ra việc kết hợp các decorator là k cần quan tâm đến thứ tự

Có 2 loại decorator:

- Dynamic decorator: cho phép tạo ra 1 đối tượng ngay trong runtime bằng cách truyền tham chiếu. Tuy nhiên không thể truy cập các property khác của đối tượng

- Static decorator: Các đối tượng phải được định nghĩa tại thời điểm compile thông qua các template. Có thể truy cập vào các property của đôị tượng thay vào đó sẽ bị mất đi sự linh hoạt khi runtime

- Function decorator: Có thể wrap 1 block code hoặc 1 function cụ thể